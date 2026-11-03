"""Insert original figures into the researched Markdown report."""
from pathlib import Path
import re,json
from diagram_common import ROOT
NAME="FRAM_特殊故障与测试算法调研_20261101.md"
FIGURES=[
(1,"fig01_cell_read_restore","电容型FRAM的单元连接与读后恢复","2.2","同一次访问的数字输出与恢复后状态需要分别观察。电路只表示1T1C的概念连接；逻辑极性由实际读出电路定义。[1][7]"),
(2,"fig02_read_margin","读信号、有效参考与读裕量","2.3","两态名义信号分别为V₀、V₁，有效参考为R。分布形状仅用于说明弱裕量与尾部错误，不代表任何器件的实测数据。[7][13]"),
(3,"fig03_hysteresis_mechanisms","正常回线、印记与可切换幅度变化","3.3","横向偏移与可切换幅度降低属于不同变化。曲线均为定性示意，不能由图中形状直接推导寿命，也不表示所有材料具有相同退化规律。[10][13][25][26]"),
(4,"fig04_model_layers","物理状态、电路响应与功能故障原语","4.1","模型同时保留返回值、操作后状态和模拟裕量，再据此提取功能行为；校准与独立验证用于修正参数及遗漏机理。结构为本文综合设计。"),
(5,"fig05_march_restore_escape","March C−掩盖恢复故障的最小反例","4.5","上半图中，后续写0覆盖了读后状态破坏的证据；下半图的第二次读1观察到错误。本图对应第4.5节的教学模型，不是实物实验。"),
(6,"fig06_pund","PUND脉冲与切换电荷提取","5.7","先建立负向初态，再按P、U、N、D施加脉冲。图中只画输入激励；差分电荷仍须由实际测量获得，并检查非切换分量是否可比。[11][12]"),
(7,"fig07_retention_first_read","保持测试的独立恢复组与首次读","6.4","图中假定访问会恢复整行、后续地址需要重新激活且未保留原始行快照。若宏可导出首激活时锁存的整行结果，应按实际行为保留该次首读数据。[2][4]"),
(8,"fig08_rad_timing","RAD访问间隔与终点首次读","6.6","扫描的空闲间隔位于完整访问之间。终点裕量在目标等待后的首次感测时捕获；图示为本文测试框架，不是复原的论文March序列。[15]"),
(9,"fig09_half_select","共享板线、浮置节点与半选分压","6.7","按图中电压方向，铁电电容端电压为V_PL−V_SN；仅在选通且压降较小时可近似采用V_PL−V_BL。本图是通用等效示意，未复原某篇论文的具体阵列。[17]"),
(10,"fig10_fefet_windows","FeFET窗口收窄与阈值共同漂移","7.2","三行使用同一概念横轴；ACT使两态靠近，TVS示例使两阈值共同负移。虚线是便于比较的等效参考，实际读出仍基于电流判决。[30][31]"),
(11,"fig11_fefet_tests","FeFET专用序列与模拟参考测试","7.4","每个March段先完成全地址遍历，再执行下一段。3N／2N／3N只是对应专用段的操作数；U状态与参考测试均须遵循原论文模型和校准条件。[29][30][31]"),
(12,"fig12_mbist_architecture","可配置FRAM MBIST与可选宏内DfT","8.2","正常接口测试、首次失败记录、历史计数与宏内可选控制分别组织。架构为本文工程建议；没有内部测试端口时，不能假定可调参考或恢复脉宽。"),
(13,"fig13_evidence_gaps","已有证据与仍需验证的问题","10.2","四行区分已有结果、不能自动推出的结论及可实施的检验。此图归纳本文研究分析，不代表相关方向无人研究，也不把未取得全文视为论文缺项。"),
(14,"fig14_research_routes","按可获得资源选择研究路线","10.9","按数字接口、RTL与模型、宏内DfT及样本三类条件组织课题。路线为本文建议；可获得的资源决定可验证的结论层级，不表示研究创新性或发表保证。"),
]
def block(n,stem,title,section,caption):
    return f'\n![图{n}　{title}](figures/png/{stem}.png)\n\n**图{n}　{title}。** {caption} [可编辑SVG](figures/svg/{stem}.svg)。\n'
def main():
    base=ROOT/"source/report_before_illustration.md"
    s=base.read_text()
    if "<!-- FRAM_FIGURES_20261101 -->" in s: raise ValueError("Use the original report as input")
    s=s.replace("示意图保留 Mermaid 源码。","插图以PNG嵌入，另附可编辑SVG和Python绘图源码；原Mermaid流程图源码一并保留。")
    s=s.replace("$...$ 与 $$...$$", "`$...$` 与 `$$...$$`")
    mermaids=list(re.finditer(r"```mermaid\n(.*?)\n```",s,re.S))
    if len(mermaids)!=2:raise ValueError("Expected two original Mermaid diagrams")
    for m,name,f in reversed(list(zip(mermaids,["original_read_restore.mmd","original_model_workflow.mmd"],[FIGURES[0],FIGURES[3]]))):
        (ROOT/"source"/name).write_text(m.group(1)+"\n")
        s=s[:m.start()]+block(*f).strip()+s[m.end():]
    inserts={2:"### 2.4",3:"### 3.4",5:"### 4.6",6:"### 5.8",7:"### 6.5",8:"### 6.7",9:"### 6.8",10:"### 7.3",11:"### 7.5",12:"### 8.3",13:"### 10.3",14:"### 10.10"}
    for f in FIGURES:
        if f[0] in inserts:
            pat=re.compile(r"^"+re.escape(inserts[f[0]])+r"　.*$",re.M)
            m=pat.search(s)
            if not m:raise ValueError("Missing section "+inserts[f[0]])
            s=s[:m.start()]+block(*f)+"\n"+s[m.start():]
    index=f"\n<!-- FRAM_FIGURES_20261101 -->\n\n## 插图索引\n\n全套{len(FIGURES)}图采用中文标注，图形与曲线为原创概念示意。图中引用编号与第12章一致；所有测试条件仍以正文说明为准。\n\n| 图号 | 主题 | 正文位置 |\n| --- | --- | --- |\n"
    for n,stem,title,section,caption in FIGURES:
        index+=f"| {n} | [{title}](figures/svg/{stem}.svg) | 第{section}节 |\n"
    s=s.replace("\n---\n\n## 1",index+"\n---\n\n## 1",1)
    # Adjacent numeric references such as [1][7] are a full reference link
    # in CommonMark; separate them so both source numbers remain correct.
    s=re.sub(r"(\[\d+\])(?=\[\d+\])",r"\1 ",s)
    (ROOT/NAME).write_text(s.rstrip()+"\n")
    (ROOT/"source/figures.json").write_text(json.dumps([dict(number=n,stem=stem,title=title,section=section,caption=caption) for n,stem,title,section,caption in FIGURES],ensure_ascii=False,indent=2)+"\n")
    print(ROOT/NAME)
if __name__=="__main__":main()

