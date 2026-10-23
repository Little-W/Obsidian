#!/usr/bin/env python3
"""Conservative offline Step editor for an exported DftSpecification.
Preserves existing Controller/MemoryInterface objects; never merges controllers.
Not a general Tessent parser or a replacement for process_dft_specification.
"""
from __future__ import annotations
import argparse, hashlib, json, re, textwrap
from dataclasses import dataclass
from pathlib import Path

TOKEN = re.compile(r'\s+|//[^\n]*|/\*[\s\S]*?\*/|"(?:\\.|[^"\\])*"|[{}:;]|[^\s{}:;"/]+|/(?![/*])')
HEADER = re.compile(r"^([A-Za-z_][A-Za-z_0-9]*)(?:\s*\((.*)\))?$")

@dataclass
class Tok:
    value: str
    start: int
    end: int

@dataclass
class Element:
    name: str
    argument: str | None
    value: str | None
    children: list['Element']
    start: int
    end: int


def tokenize(text: str) -> list[Tok]:
    out=[]; pos=0
    while pos < len(text):
        match=TOKEN.match(text,pos)
        if not match: raise ValueError(f"unsupported or unterminated token near character {pos}")
        value=match.group(); end=match.end()
        if value.startswith('/*') and not value.endswith('*/'):
            raise ValueError("unterminated comment")
        if not value.isspace() and not value.startswith(('//','/*')):
            out.append(Tok(value,pos,end))
        pos=end
    return out


def parse(text: str) -> list[Element]:
    tokens=tokenize(text); index=0
    def sequence(nested=False):
        nonlocal index
        children=[]
        while index < len(tokens):
            if tokens[index].value == '}':
                if not nested: raise ValueError("unmatched closing brace")
                end=tokens[index].end; index+=1
                return children,end
            start=tokens[index].start; head=[]
            while index < len(tokens) and tokens[index].value not in '{}:;':
                head.append(tokens[index].value); index+=1
            if not head or index >= len(tokens): raise ValueError("incomplete configuration entry")
            delim=tokens[index].value; index+=1
            h=''.join(head)  # identifiers/paths/parameters may be separated by whitespace
            if delim=='{':
                m=HEADER.fullmatch(h)
                if not m: raise ValueError(f"unsupported wrapper header: {h}")
                sub,end=sequence(True)
                children.append(Element(m.group(1),m.group(2),None,sub,start,end))
            elif delim==':':
                vals=[]
                while index < len(tokens) and tokens[index].value != ';':
                    if tokens[index].value in '{}': raise ValueError("unquoted brace in property value")
                    vals.append(tokens[index].value); index+=1
                if index>=len(tokens): raise ValueError("missing semicolon")
                end=tokens[index].end; index+=1
                children.append(Element(h,None,''.join(vals),[],start,end))
            else: raise ValueError(f"unexpected delimiter {delim}")
        if nested: raise ValueError("unclosed wrapper")
        return children,len(text)
    return sequence()[0]


def only(elements: list[Element], name: str) -> Element:
    found=[e for e in elements if e.name==name and e.value is None]
    if len(found)!=1: raise ValueError(f"expected one {name}, found {len(found)}")
    return found[0]


def controllers(text: str) -> dict[str,Element]:
    root=only(parse(text),'DftSpecification')
    mb=only(root.children,'MemoryBist')
    out={}
    for element in mb.children:
        if element.name=='Controller' and element.value is None:
            if not element.argument or element.argument in out: raise ValueError("missing/duplicate controller ID")
            out[element.argument]=element
    return out


def instance_name(interface: Element) -> str:
    props=[e for e in interface.children if e.name=='instance_name' and e.value is not None]
    if len(props)!=1: raise ValueError("MemoryInterface needs exactly one instance_name")
    val=props[0].value
    if val.startswith('"'):
        # Only simple quoted paths accepted; escaped naming needs a site-specific parser.
        if '\\' in val: raise ValueError("escaped instance path is outside editor's supported subset")
        val=val[1:-1]
    return val


def step_members(controller: Element) -> list[list[str]]:
    return [[instance_name(m) for m in s.children if m.name=='MemoryInterface' and m.value is None]
            for s in controller.children if s.name=='Step' and s.value is None]


def normalized_raw(text: str, node: Element) -> str:
    line_start=text.rfind('\n',0,node.start)+1
    prefix=text[line_start:node.start]
    if prefix.strip(): prefix=''
    return textwrap.dedent(prefix+text[node.start:node.end])


def rewrite(text: str, plan: dict[str,list[list[str]]]) -> str:
    ctrls=controllers(text)
    if not isinstance(plan,dict) or not plan: raise ValueError("plan must be a nonempty controller dictionary")
    edits=[]
    for cid,new_steps in plan.items():
        if cid not in ctrls: raise ValueError(f"unknown controller: {cid}")
        if not isinstance(new_steps,list) or not new_steps: raise ValueError("controller needs steps")
        steps=[s for s in ctrls[cid].children if s.name=='Step' and s.value is None]
        if not steps: raise ValueError(f"no existing steps in {cid}")
        by_name={}
        for step in steps:
            if step.argument is not None: raise ValueError("named Step wrappers are not supported")
            for obj in step.children:
                if obj.name!='MemoryInterface' or obj.value is not None:
                    raise ValueError("Step-level properties/options found: refusing to drop or reinterpret them")
                name=instance_name(obj)
                if name in by_name: raise ValueError("duplicate source memory")
                by_name[name]=obj
        flattened=[]
        for group in new_steps:
            if not isinstance(group,list) or not group or not all(isinstance(v,str) for v in group):
                raise ValueError("every Step must be a nonempty list of instance names")
            flattened.extend(group)
        if len(flattened)!=len(set(flattened)): raise ValueError("duplicate memory in plan")
        if set(flattened)!=set(by_name):
            raise ValueError("plan must cover exactly the original controller's memories; no cross-controller moves")
        first=steps[0]
        line_start=text.rfind('\n',0,first.start)+1
        indent=text[line_start:first.start]
        if indent.strip(): indent='      '
        new_blocks=[]
        for group in new_steps:
            members='\n'.join(textwrap.indent(normalized_raw(text,by_name[name]),indent+'  ') for name in group)
            new_blocks.append(indent+'Step {\n'+members+'\n'+indent+'}')
        joined='\n'.join(new_blocks)
        # Keep the existing whitespace before the first Step token.
        edits.append((first.start,first.end,joined[len(indent):]))
        edits.extend((s.start,s.end,'') for s in steps[1:])
    result=text
    for start,end,replacement in sorted(edits,reverse=True):
        result=result[:start]+replacement+result[end:]
    after=controllers(result)
    for cid,groups in plan.items():
        if step_members(after[cid])!=groups: raise AssertionError("internal rewrite verification failed")
    # The token sequence inside each MemoryInterface is preserved exactly.
    def interface_tokens(txt):
        result={}
        for cid,controller in controllers(txt).items():
            for step in controller.children:
                if step.name=='Step' and step.value is None:
                    for m in step.children:
                        if m.name=='MemoryInterface' and m.value is None:
                            result[(cid,instance_name(m))]=[t.value for t in tokenize(txt[m.start:m.end])]
        return result
    if interface_tokens(text)!=interface_tokens(result): raise AssertionError("memory interface content changed")
    return result


def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('input',type=Path); ap.add_argument('plan',type=Path)
    ap.add_argument('output',type=Path)
    args=ap.parse_args()
    try:
        if args.input.resolve()==args.output.resolve(): raise ValueError("refusing to overwrite original specification")
        source=args.input.read_text(encoding='utf-8')
        plan=json.loads(args.plan.read_text(encoding='utf-8'))
        result=rewrite(source,plan)
        args.output.parent.mkdir(parents=True,exist_ok=True)
        args.output.write_text(result,encoding='utf-8')
        manifest={'input_sha256':hashlib.sha256(source.encode()).hexdigest(),
                  'output_sha256':hashlib.sha256(result.encode()).hexdigest(),
                  'controllers_edited':sorted(plan),'offline_checks':'passed',
                  'tessent_validation':'NOT RUN'}
        args.output.with_suffix(args.output.suffix+'.audit.json').write_text(json.dumps(manifest,indent=2)+'\n',encoding='utf-8')
        print(json.dumps(manifest,indent=2))
    except (OSError,ValueError,KeyError) as exc: ap.exit(2,f'error: {exc}\n')

if __name__=='__main__': main()
