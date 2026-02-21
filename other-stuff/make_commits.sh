#!/bin/bash

# Generic commit script: reads git status and makes 1 commit per changed file.
# Handles: new/untracked, modified, deleted, and renamed files.

cd "$(git rev-parse --show-toplevel)" || exit

# Unstage everything first
git reset HEAD -- . 2>/dev/null

# Read git status line by line
git status --porcelain -uall | while IFS= read -r line; do
    status="${line:0:2}"
    status="$(echo "$status" | xargs)"
    filepath="${line:3}"

    case "$status" in
        "??"|"A")
            echo "==> Add $filepath"
            git add "$filepath"
            git commit -m "Add $filepath"
            ;;
        "M"|"MM"|"AM")
            echo "==> Modify $filepath"
            git add "$filepath"
            git commit -m "Modify $filepath"
            ;;
        "D")
            echo "==> Delete $filepath"
            git rm "$filepath" 2>/dev/null
            git commit -m "Delete $filepath"
            ;;
        R*)
            old_name="$(echo "$filepath" | sed 's/ -> .*//')"
            new_name="$(echo "$filepath" | sed 's/.* -> //')"
            echo "==> Rename $old_name -> $new_name"
            git add "$old_name" "$new_name" 2>/dev/null
            git rm --cached "$old_name" 2>/dev/null
            git add "$new_name"
            git commit -m "Rename $old_name -> $new_name"
            ;;
        *)
            echo "==> Update $filepath"
            if [ -f "$filepath" ]; then
                git add "$filepath"
                git commit -m "Modify $filepath"
            else
                git rm "$filepath" 2>/dev/null
                git commit -m "Delete $filepath"
            fi
            ;;
    esac
done

echo ""
echo "Done! All changes committed."
 
 
 
 
 
 






