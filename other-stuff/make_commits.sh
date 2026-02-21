#!/bin/bash

# Generic commit script: reads git status and makes 7 commits per changed file.
# Handles: new (untracked), modified, deleted, and renamed files.

COMMITS_PER_FILE=${1:-7}

cd "$(git rev-parse --show-toplevel)" || exit

# Unstage everything first
git reset HEAD -- . 2>/dev/null

# Read git status line by line
git status --porcelain -uall | while IFS= read -r line; do
    # Extract the status code (first 2 chars) and the file path
    status="${line:0,2}"
    # Trim leading/trailing spaces from status
    status="$(echo "$status" | xargs)"
    filepath="${line:3}"

    case "$status" in
        "??")
            # Untracked (new) file
            echo "==> New file: $filepath — making $COMMITS_PER_FILE commits..."
            git add "$filepath"
            git commit -m "Add $filepath (commit 1/$COMMITS_PER_FILE)"
            for ((i=2; i<=COMMITS_PER_FILE; i++)); do
                echo "" >> "$filepath"
                git add "$filepath"
                git commit -m "Update $filepath (commit $i/$COMMITS_PER_FILE)"
            done
            ;;
        "M"|"MM"|"AM")
            # Modified file
            echo "==> Modified file: $filepath — making $COMMITS_PER_FILE commits..."
            git add "$filepath"
            git commit -m "Update $filepath (commit 1/$COMMITS_PER_FILE)"
            for ((i=2; i<=COMMITS_PER_FILE; i++)); do
                echo "" >> "$filepath"
                git add "$filepath"
                git commit -m "Update $filepath (commit $i/$COMMITS_PER_FILE)"
            done
            ;;
        "D")
            # Deleted file
            echo "==> Deleted file: $filepath — making $COMMITS_PER_FILE commits..."
            git rm "$filepath" 2>/dev/null
            git commit -m "Delete $filepath (commit 1/$COMMITS_PER_FILE)"
            # For deleted files we can only make 1 real commit; pad the rest with empty commits
            for ((i=2; i<=COMMITS_PER_FILE; i++)); do
                git commit --allow-empty -m "Delete $filepath (commit $i/$COMMITS_PER_FILE)"
            done
            ;;
        R*)
            # Renamed file: filepath looks like "old_name -> new_name"
            old_name="$(echo "$filepath" | sed 's/ -> .*//')"
            new_name="$(echo "$filepath" | sed 's/.* -> //')"
            echo "==> Renamed file: $old_name -> $new_name — making $COMMITS_PER_FILE commits..."
            git add "$old_name" "$new_name" 2>/dev/null
            git rm --cached "$old_name" 2>/dev/null
            git add "$new_name"
            git commit -m "Rename $old_name -> $new_name (commit 1/$COMMITS_PER_FILE)"
            for ((i=2; i<=COMMITS_PER_FILE; i++)); do
                echo "" >> "$new_name"
                git add "$new_name"
                git commit -m "Update $new_name (commit $i/$COMMITS_PER_FILE)"
            done
            ;;
        "A")
            # Staged new file
            echo "==> Added file: $filepath — making $COMMITS_PER_FILE commits..."
            git add "$filepath"
            git commit -m "Add $filepath (commit 1/$COMMITS_PER_FILE)"
            for ((i=2; i<=COMMITS_PER_FILE; i++)); do
                echo "" >> "$filepath"
                git add "$filepath"
                git commit -m "Update $filepath (commit $i/$COMMITS_PER_FILE)"
            done
            ;;
        *)
            # Catch-all for anything else (e.g. copied, etc.)
            echo "==> Changed file ($status): $filepath — making $COMMITS_PER_FILE commits..."
            if [ -f "$filepath" ]; then
                git add "$filepath"
                git commit -m "Update $filepath (commit 1/$COMMITS_PER_FILE)"
                for ((i=2; i<=COMMITS_PER_FILE; i++)); do
                    echo "" >> "$filepath"
                    git add "$filepath"
                    git commit -m "Update $filepath (commit $i/$COMMITS_PER_FILE)"
                done
            else
                git rm "$filepath" 2>/dev/null
                git commit -m "Remove $filepath (commit 1/$COMMITS_PER_FILE)"
                for ((i=2; i<=COMMITS_PER_FILE; i++)); do
                    git commit --allow-empty -m "Remove $filepath (commit $i/$COMMITS_PER_FILE)"
                done
            fi
            ;;
    esac
done

echo ""
echo "Done! All changes committed."
 
 
 
 
 
 





