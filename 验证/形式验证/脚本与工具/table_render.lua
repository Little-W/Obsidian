-- Markdown source uses GFM table escaping: `a \|-> b`.
-- Pandoc's markdown reader preserves the backslash in Code, so remove it
-- only inside table cells. Fenced source code is never modified.
local chapter_index = 0

function Table(table)
  return table:walk({
    Code = function(code)
      code.text = code.text:gsub('\\|', '|')
      return code
    end
  })
end

function Header(header)
  if FORMAT:match('latex') and header.level == 1 then
    chapter_index = chapter_index + 1
    header.identifier = string.format('chapter-%02d', chapter_index)
  end
  return header
end
