-- Stable chapter identifiers and invisible wrapping opportunities in inline code.
local chapter_index = 0
function Header(h)
  if FORMAT:match('latex') and h.level == 1 then
    chapter_index = chapter_index + 1
    h.identifier = string.format('chapter-%02d', chapter_index)
  end
  return h
end
function Code(c)
  if not FORMAT:match('latex') then return c end
  local s = c.text
  local escaped = {}
  local escapes = {['\\']='\\textbackslash{}',['{']='\\{',['}']='\\}',
    ['%']='\\%',['$']='\\$',['#']='\\#',['&']='\\&',
    ['_']='\\_\\allowbreak{}',['~']='\\textasciitilde{}',['^']='\\textasciicircum{}'}
  for _,v in utf8.codes(s) do
    local ch=utf8.char(v)
    if escapes[ch] then table.insert(escaped,escapes[ch])
    elseif ch=='/' or ch=='.' then table.insert(escaped,ch..'\\allowbreak{}')
    else table.insert(escaped,ch) end
  end
  return pandoc.RawInline('latex','\\texttt{'..table.concat(escaped)..'}')
end
