#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="${1:-}"

if [[ -z "$ROOT_DIR" || ! -d "$ROOT_DIR" ]]; then
    echo "Usage: $0 <root-directory>"
    exit 1
fi

# Process deepest directories first to avoid path conflicts
find "$ROOT_DIR" -type d -depth | while IFS= read -r dir; do
    base="$(basename "$dir")"
    parent="$(dirname "$dir")"

    case "$base" in
        t12) new="t1" ;;
        t34) new="t2" ;;
        sov) new="t3" ;;
        *) continue ;;
    esac

    target="$parent/$new"

    if [[ -e "$target" ]]; then
        echo "Skipping (target exists): $dir → $target"
        continue
    fi

    # Only use git mv if tracked; fallback to mv otherwise
    if git ls-files --error-unmatch "$dir" >/dev/null 2>&1; then
        echo "git mv: $dir → $target"
        git mv -- "$dir" "$target"
    else
        echo "mv (untracked): $dir → $target"
        mv -- "$dir" "$target"
    fi
done