// C++17; deterministic teaching model, not a vendor MBIST insertion program.
// Each group executes synchronously; power=sum(member power), duration=max(member duration).
// The constant group-power reservation is a deliberately conservative scheduling model.
#include <algorithm>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

using Group = std::vector<int>;
using Partition = std::vector<Group>;
struct Memory {
    std::string id, clock, interface;
    int x, y, power, duration;
};
struct Limits { int count=3, power=10, hpwl=300, global_power=20, concurrent=2; };
struct Stats { int power=0, duration=0, hpwl=0; };
struct Event { int group, start, end, power; };
struct Schedule { int makespan=0, peak=0; std::vector<Event> events; };

static std::vector<std::string> split(const std::string& line) {
    std::vector<std::string> out; std::stringstream ss(line); std::string item;
    while (std::getline(ss,item,',')) out.push_back(item);
    return out;
}
static int integer(const std::string& text) {
    std::size_t pos=0; int value=std::stoi(text,&pos);
    if(pos!=text.size()) throw std::runtime_error("Not an integer: "+text);
    return value;
}
static std::vector<Memory> read_csv(const std::string& path) {
    std::ifstream in(path); if(!in) throw std::runtime_error("Cannot open "+path);
    std::string line; std::getline(in,line);
    if(!line.empty() && line.back()=='\r') line.pop_back();
    if(line!="id,clock,interface,x_um,y_um,power_mw,duration_us")
        throw std::runtime_error("Unexpected CSV header");
    std::vector<Memory> m; std::set<std::string> seen;
    while(std::getline(in,line)) {
        if(!line.empty() && line.back()=='\r') line.pop_back();
        if(line.empty()) continue;
        auto a=split(line);
        if(a.size()!=7 || a[0].empty() || a[1].empty() || a[2].empty())
            throw std::runtime_error("Invalid CSV row: "+line);
        if(!seen.insert(a[0]).second) throw std::runtime_error("Duplicate ID: "+a[0]);
        Memory z{a[0],a[1],a[2],integer(a[3]),integer(a[4]),integer(a[5]),integer(a[6])};
        // Small integer ranges also make all summed arithmetic safe in this demo.
        if(z.power<0 || z.power>1000000 || z.duration<=0 || z.duration>1000000 ||
           z.x<-1000000 || z.x>1000000 || z.y<-1000000 || z.y>1000000)
            throw std::runtime_error("Value outside demo ranges: "+z.id);
        m.push_back(z);
    }
    if(m.empty() || m.size()>20) throw std::runtime_error("Demo requires 1..20 memories");
    return m;
}
static Stats stats(const Group& g,const std::vector<Memory>& m) {
    Stats s; if(g.empty()) return s;
    int xmin=m[g[0]].x,xmax=xmin,ymin=m[g[0]].y,ymax=ymin;
    for(int i:g) {
        s.power+=m[i].power; s.duration=std::max(s.duration,m[i].duration);
        xmin=std::min(xmin,m[i].x); xmax=std::max(xmax,m[i].x);
        ymin=std::min(ymin,m[i].y); ymax=std::max(ymax,m[i].y);
    }
    s.hpwl=xmax-xmin+ymax-ymin; return s;
}
static bool legal(const Group& g,const std::vector<Memory>& m,const Limits& l) {
    if(g.empty() || static_cast<int>(g.size())>l.count) return false;
    for(int i:g) if(m[i].clock!=m[g[0]].clock || m[i].interface!=m[g[0]].interface) return false;
    auto s=stats(g,m); return s.power<=l.power && s.hpwl<=l.hpwl;
}
static void validate(const Partition& p,const std::vector<Memory>& m,const Limits& l) {
    std::vector<int> count(m.size(),0);
    for(const auto& g:p) {
        for(int i:g) { if(i<0 || i>=static_cast<int>(m.size())) throw std::runtime_error("Bad index"); ++count[i]; }
        if(!legal(g,m,l)) throw std::runtime_error("Illegal group");
    }
    if(std::any_of(count.begin(),count.end(),[](int n){return n!=1;}))
        throw std::runtime_error("Partition must cover every memory exactly once");
}
static std::pair<int,int> cost(const Partition& p,const std::vector<Memory>& m) {
    int h=0; for(const auto& g:p) h+=stats(g,m).hpwl;
    return {static_cast<int>(p.size()),h};
}
static Partition first_fit(const std::vector<Memory>& m,const Limits& l,bool best_decreasing) {
    Group order(m.size()); std::iota(order.begin(),order.end(),0);
    if(best_decreasing) std::stable_sort(order.begin(),order.end(),[&](int a,int b){
        if(m[a].power!=m[b].power) return m[a].power>m[b].power;
        return m[a].id<m[b].id;
    });
    Partition p;
    for(int i:order) {
        int chosen=-1,best_rem=std::numeric_limits<int>::max();
        for(int g=0;g<static_cast<int>(p.size());++g) {
            Group q=p[g]; q.push_back(i); if(!legal(q,m,l)) continue;
            int rem=l.power-stats(q,m).power;
            if(chosen<0 || rem<best_rem) {chosen=g;best_rem=rem;}
            if(!best_decreasing) break;
        }
        if(chosen<0) p.push_back({i}); else p[chosen].push_back(i);
    }
    return p;
}
static Partition geometry_greedy(const std::vector<Memory>& m,const Limits& l) {
    Group left(m.size()); std::iota(left.begin(),left.end(),0); Partition out;
    while(!left.empty()) {
        auto it=std::min_element(left.begin(),left.end(),[&](int a,int b){
            return std::tie(m[a].x,m[a].y,m[a].id)<std::tie(m[b].x,m[b].y,m[b].id);
        });
        Group g{*it}; left.erase(it);
        while(true) {
            int best=-1; std::tuple<int,std::string> key{std::numeric_limits<int>::max(),""};
            for(int i:left) {
                Group q=g; q.push_back(i); if(!legal(q,m,l)) continue;
                auto k=std::make_tuple(stats(q,m).hpwl,m[i].id);
                if(best<0 || k<key) {best=i;key=k;}
            }
            if(best<0) break;
            g.push_back(best); left.erase(std::find(left.begin(),left.end(),best));
        }
        out.push_back(g);
    }
    return out;
}
static Partition dsatur(const std::vector<Memory>& m,const Limits& l) {
    int n=static_cast<int>(m.size()); std::vector<std::vector<int>> edge(n,std::vector<int>(n));
    std::vector<int> degree(n),label(n,-1);
    for(int i=0;i<n;++i) for(int j=i+1;j<n;++j)
        if(!legal({i,j},m,l)) {edge[i][j]=edge[j][i]=1;++degree[i];++degree[j];}
    Partition p;
    for(int step=0;step<n;++step) {
        int chosen=-1; std::tuple<int,int,int> key{-1,-1,-1};
        for(int i=0;i<n;++i) if(label[i]<0) {
            std::set<int> colors;
            for(int j=0;j<n;++j) if(edge[i][j] && label[j]>=0) colors.insert(label[j]);
            auto k=std::make_tuple(static_cast<int>(colors.size()),degree[i],m[i].power);
            if(chosen<0 || k>key || (k==key && m[i].id<m[chosen].id)) {chosen=i;key=k;}
        }
        int g=0;
        for(;g<static_cast<int>(p.size());++g) {
            Group q=p[g]; q.push_back(chosen); if(legal(q,m,l)) break;
        }
        if(g==static_cast<int>(p.size())) p.push_back({});
        p[g].push_back(chosen); label[chosen]=g;
    }
    return p;
}
// Exhaustive legal-subset generation + exact set-partitioning dynamic programming.
// All group costs are additive here. This does NOT optimize the subsequent schedule.
static Partition exact_partition(const Group& ids,const std::vector<Memory>& m,const Limits& l) {
    const unsigned n=static_cast<unsigned>(ids.size());
    if(n==0) return {};
    if(n>20) throw std::runtime_error("Exact solver limited to 20");
    const std::uint32_t total=1u<<n;
    std::vector<int> hpwl(total,-1);
    std::vector<std::vector<std::uint32_t>> by_first(n);
    for(std::uint32_t mask=1;mask<total;++mask) {
        if(__builtin_popcount(mask)>l.count) continue;
        Group g; for(unsigned j=0;j<n;++j) if(mask&(1u<<j)) g.push_back(ids[j]);
        if(legal(g,m,l)) {
            hpwl[mask]=stats(g,m).hpwl;
            for(unsigned j=0;j<n;++j) if(mask&(1u<<j)) by_first[j].push_back(mask);
        }
    }
    using Score=std::pair<int,int>;
    const Score inf{1000000000,1000000000};
    std::vector<Score> dp(total,inf); std::vector<bool> done(total,false);
    std::vector<std::uint32_t> pick(total,0); dp[0]={0,0};done[0]=true;
    std::function<Score(std::uint32_t)> solve=[&](std::uint32_t mask)->Score {
        if(done[mask]) return dp[mask];
        done[mask]=true;
        unsigned first=__builtin_ctz(mask);
        for(auto g:by_first[first]) if((g&mask)==g) {
            auto old=solve(mask^g); if(old==inf) continue;
            Score cand{old.first+1,old.second+hpwl[g]};
            if(cand<dp[mask]) {dp[mask]=cand;pick[mask]=g;}
        }
        return dp[mask];
    };
    if(solve(total-1)==inf) throw std::runtime_error("No feasible partition");
    Partition out; std::uint32_t remain=total-1;
    while(remain) {
        auto mask=pick[remain]; if(mask==0) throw std::runtime_error("DP reconstruction failure");
        Group g; for(unsigned j=0;j<n;++j) if(mask&(1u<<j)) g.push_back(ids[j]);
        out.push_back(g); remain^=mask;
    }
    return out;
}
static Partition repair(Partition p,const std::vector<Memory>& m,const Limits& l) {
    // Exact re-partitioning of each 2- or 3-group neighborhood; first improvement.
    bool changed=true;
    while(changed) {
        changed=false; int size=static_cast<int>(p.size());
        for(int a=0;a<size && !changed;++a) for(int b=a+1;b<size && !changed;++b)
        for(int c=b;c<size && !changed;++c) {
            Group ids=p[a]; ids.insert(ids.end(),p[b].begin(),p[b].end());
            if(c!=b) ids.insert(ids.end(),p[c].begin(),p[c].end());
            if(ids.size()>18) continue;
            auto q=exact_partition(ids,m,l); Partition cand;
            for(int g=0;g<size;++g) if(g!=a && g!=b && g!=c) cand.push_back(p[g]);
            cand.insert(cand.end(),q.begin(),q.end());
            if(cost(cand,m)<cost(p,m)) {p=std::move(cand);changed=true;}
        }
    }
    return p;
}
static Schedule schedule(const Partition& p,const std::vector<Memory>& m,const Limits& l) {
    int n=static_cast<int>(p.size()); Group pending(n); std::iota(pending.begin(),pending.end(),0);
    std::vector<Stats> st; for(const auto& g:p) st.push_back(stats(g,m));
    for(auto s:st) if(s.power>l.global_power) throw std::runtime_error("Group exceeds global power");
    std::stable_sort(pending.begin(),pending.end(),[&](int a,int b){
        return std::tie(st[a].duration,st[a].power)>std::tie(st[b].duration,st[b].power);
    });
    Schedule out; std::vector<Event> running; int t=0;
    while(!pending.empty() || !running.empty()) {
        running.erase(std::remove_if(running.begin(),running.end(),[&](const Event& e){return e.end<=t;}),running.end());
        int used=0; for(auto e:running) used+=e.power;
        for(std::size_t k=0;k<pending.size();) {
            int g=pending[k];
            if(static_cast<int>(running.size())<l.concurrent && used+st[g].power<=l.global_power) {
                Event e{g,t,t+st[g].duration,st[g].power};
                running.push_back(e);out.events.push_back(e);used+=e.power;
                out.peak=std::max(out.peak,used);out.makespan=std::max(out.makespan,e.end);
                pending.erase(pending.begin()+static_cast<std::ptrdiff_t>(k));
            } else ++k;
        }
        if(running.empty()) {if(!pending.empty()) throw std::runtime_error("Scheduler stalled");break;}
        t=std::min_element(running.begin(),running.end(),[](auto a,auto b){return a.end<b.end;})->end;
    }
    return out;
}
static std::string quote(const std::string& s) {
    std::string out="\""; for(unsigned char c:s) {
        if(c=='"' || c=='\\') out+='\\';
        if(c<32) throw std::runtime_error("Control character in ID");
        out+=static_cast<char>(c);
    } return out+'"';
}
static void write_result(const std::string& path,const std::string& name,const Partition& p,
                         const std::vector<Memory>& m,const Limits& l) {
    validate(p,m,l); auto s=schedule(p,m,l); auto c=cost(p,m);
    std::ofstream out(path); if(!out) throw std::runtime_error("Cannot write "+path);
    out<<"{\n  \"algorithm\": "<<quote(name)<<",\n  \"groups\": [\n";
    for(std::size_t g=0;g<p.size();++g) {
        auto st=stats(p[g],m);out<<"    {\"members\": [";
        for(std::size_t j=0;j<p[g].size();++j) {if(j)out<<", ";out<<quote(m[p[g][j]].id);}
        out<<"], \"power_mw\": "<<st.power<<", \"duration_us\": "<<st.duration
           <<", \"hpwl_um\": "<<st.hpwl<<"}"<<(g+1<p.size()?",":"")<<"\n";
    }
    out<<"  ],\n  \"group_count\": "<<c.first<<",\n  \"sum_hpwl_um\": "<<c.second
       <<",\n  \"estimated_makespan_us\": "<<s.makespan<<",\n  \"reserved_peak_mw\": "<<s.peak<<",\n  \"schedule\": [\n";
    for(std::size_t k=0;k<s.events.size();++k) {
        auto e=s.events[k];out<<"    {\"group\": "<<e.group<<", \"start_us\": "<<e.start
          <<", \"end_us\": "<<e.end<<", \"power_mw\": "<<e.power<<"}"<<(k+1<s.events.size()?",":"")<<"\n";
    }
    out<<"  ]\n}\n";
    std::cout<<name<<","<<c.first<<","<<c.second<<","<<s.makespan<<","<<s.peak<<"\n";
}
int main(int argc,char** argv) {
    try {
        if(argc!=3 && argc!=8) {
            std::cerr<<"Usage: mbist_demo memories.csv results_dir [K Pgroup HPWL Pchip Bmax]\n";return 2;
        }
        Limits l; if(argc==8) l={integer(argv[3]),integer(argv[4]),integer(argv[5]),integer(argv[6]),integer(argv[7])};
        if(l.count<=0 || l.power<0 || l.hpwl<0 || l.global_power<0 || l.concurrent<=0)
            throw std::runtime_error("Invalid limits");
        auto m=read_csv(argv[1]);
        for(int i=0;i<static_cast<int>(m.size());++i) if(!legal({i},m,l))
            throw std::runtime_error("Singleton infeasible: "+m[i].id);
        std::filesystem::create_directories(argv[2]);
        Group all(m.size());std::iota(all.begin(),all.end(),0);
        std::vector<std::pair<std::string,Partition>> results;
        auto ff=first_fit(m,l,false);
        results.push_back({"first_fit",ff});
        results.push_back({"best_fit_decreasing",first_fit(m,l,true)});
        results.push_back({"geometry_greedy",geometry_greedy(m,l)});
        results.push_back({"capacity_dsatur",dsatur(m,l)});
        results.push_back({"greedy_local_exact_repair",repair(ff,m,l)});
        results.push_back({"exact_subset_dp",exact_partition(all,m,l)});
        std::cout<<"algorithm,groups,sum_hpwl_um,makespan_us,reserved_peak_mw\n";
        for(auto& item:results) write_result(std::string(argv[2])+"/"+item.first+".json",item.first,item.second,m,l);
    } catch(const std::exception& e) {std::cerr<<"ERROR: "<<e.what()<<"\n";return 1;}
}
