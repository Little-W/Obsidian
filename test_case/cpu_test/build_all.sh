#!/bin/bash

# 自动构建所有Makefile项目脚本

echo -e "\033[34m=== 自动构建所有Makefile项目 ===\033[0m"
echo -e "当前目录: \033[32m$(pwd)\033[0m"
echo -e "构建参数: \033[33m$*\033[0m"
echo ""

# 保存原始目录（绝对路径）
ORIGINAL_DIR=$(cd "$(pwd)" && pwd)
echo -e "原始目录(绝对路径): \033[32m$ORIGINAL_DIR\033[0m"

# 临时文件存储Makefile路径
TEMP_FILE=$(mktemp)
trap 'rm -f "$TEMP_FILE"' EXIT  # 确保临时文件被清理

# 查找所有Makefile（仅保留存在的文件，输出绝对路径）
echo -e "\033[34m查找Makefile文件...\033[0m"
find "$ORIGINAL_DIR" -type f \( -name "Makefile" -o -name "makefile" \) -print0 | \
    xargs -0 -I {} bash -c 'if [ -f "{}" ]; then echo "$(cd "$(dirname "{}")" && pwd)/$(basename "{}")"; fi' | \
    grep -v '^$' > "$TEMP_FILE"

# 统计数量
FILE_COUNT=$(wc -l < "$TEMP_FILE")
echo -e "找到 \033[32m$FILE_COUNT\033[0m 个Makefile文件"

if [ "$FILE_COUNT" -eq 0 ]; then
    echo -e "\033[31m错误: 没有找到任何Makefile文件!\033[0m"
    exit 1
fi

# 显示找到的文件列表
echo -e "\n\033[34m找到的Makefile列表:\033[0m"
cat -n "$TEMP_FILE"
echo ""

# 初始化统计变量
SUCCESS=0
FAILED=0
COUNT=0

# 逐行处理每个Makefile（确保cd进入目录）
while IFS= read -r MAKEFILE_ABS_PATH; do
    [ -z "$MAKEFILE_ABS_PATH" ] && continue
    ((COUNT++))

    # 提取Makefile所在目录（绝对路径）
    MAKEFILE_DIR=$(dirname "$MAKEFILE_ABS_PATH")
    MAKEFILE_NAME=$(basename "$MAKEFILE_ABS_PATH")

    echo -e "\033[34m========================================\033[0m"
    echo -e "[$COUNT/$FILE_COUNT] 处理目录: \033[32m$MAKEFILE_DIR\033[0m"
    echo -e "目标Makefile: \033[33m$MAKEFILE_NAME\033[0m"

    # ========== 核心：强制切换到目标目录 ==========
    echo -e "\033[34m执行cd命令进入目录...\033[0m"
    if ! cd "$MAKEFILE_DIR"; then
        echo -e "\033[31m✗ 严重错误: 无法进入目录 $MAKEFILE_DIR\033[0m"
        ((FAILED++))
        # 切回原始目录，继续处理下一个
        cd "$ORIGINAL_DIR" || {
            echo -e "\033[31m✗ 致命错误: 无法切回原始目录 $ORIGINAL_DIR\033[0m"
            exit 1
        }
        continue
    fi

    # 验证当前目录是否正确（双重确认）
    CURRENT_DIR=$(pwd)
    if [ "$CURRENT_DIR" != "$MAKEFILE_DIR" ]; then
        echo -e "\033[31m✗ 目录切换验证失败: 预期 $MAKEFILE_DIR，实际 $CURRENT_DIR\033[0m"
        ((FAILED++))
        cd "$ORIGINAL_DIR" || exit 1
        continue
    fi
    echo -e "\033[32m✓ 已成功进入目录: $CURRENT_DIR\033[0m"

    # ========== 确认目录后执行make ==========
    echo -e "\033[34m------------------------\033[0m"
    echo -e "执行命令: \033[33mmake $*\033[0m"
    echo -e "\033[34m------------------------\033[0m"

    # 执行make（目录已确认正确）
    if make "$@"; then
        echo -e "\033[32m✓ make执行成功\033[0m"
        ((SUCCESS++))
    else
        MAKE_EXIT_CODE=$?
        echo -e "\033[31m✗ make执行失败 (退出码: $MAKE_EXIT_CODE)\033[0m"
        ((FAILED++))
    fi

    # ========== 切回原始目录 ==========
    echo -e "\033[34m------------------------\033[0m"
    echo -e "切回原始目录: $ORIGINAL_DIR"
    if ! cd "$ORIGINAL_DIR"; then
        echo -e "\033[31m✗ 致命错误: 无法切回原始目录，脚本终止\033[0m"
        exit 1
    fi

done < "$TEMP_FILE"

# 输出最终统计结果
echo -e "\n\033[34m========================================\033[0m"
echo -e "\033[34m构建完成！统计结果:\033[0m"
echo -e "总计处理: \033[32m$FILE_COUNT\033[0m 个项目"
echo -e "成功构建: \033[32m$SUCCESS\033[0m 个"
echo -e "失败构建: \033[31m$FAILED\033[0m 个"

if [ "$FAILED" -eq 0 ]; then
    echo -e "\033[32m✓ 所有项目构建成功！\033[0m"
    exit 0
else
    echo -e "\033[31m✗ 有 $FAILED 个项目构建失败\033[0m"
    exit 1
fi