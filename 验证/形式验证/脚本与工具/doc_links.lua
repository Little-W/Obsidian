-- Stable chapter identifiers for PDF links. No content escaping or table filter.
local chapter_index = 0
function Header(header)
  if FORMAT:match('latex') and header.level == 1 then
    chapter_index = chapter_index + 1
    header.identifier = string.format('chapter-%02d', chapter_index)
  end
  return header
end
