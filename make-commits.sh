#!/bin/bash

# Script to make individual commits for changed files (one commit per file)
# Usage: ./make-commits.sh [number_of_commits]
# Default: 20 commits

NUM_COMMITS=${1:-20}
count=0

# Process git status output
while read -r line && [ $count -lt $NUM_COMMITS ]; do
    # Parse status and file from line
    status=$(echo "$line" | awk '{print $1}')
    file=$(echo "$line" | awk '{for(i=2;i<=NF;i++) printf "%s ", $i; print ""}' | sed 's/[[:space:]]*$//')
    
    # Skip if file path is empty
    if [ -z "$file" ]; then
        continue
    fi
    
    # Handle deleted files
    if [[ "$status" =~ ^D ]]; then
        if git rm "$file" 2>/dev/null; then
            git commit -m "Remove $file" && echo "Committed: $file (deleted)"
            count=$((count + 1))
        fi
    # Handle untracked files/directories
    elif [[ "$status" =~ ^\?\? ]]; then
        if git add "$file" 2>/dev/null; then
            git commit -m "Add $file" && echo "Committed: $file (new)"
            count=$((count + 1))
        fi
    # Handle modified files
    elif [[ "$status" =~ ^M ]]; then
        if git add "$file" 2>/dev/null; then
            git commit -m "Update $file" && echo "Committed: $file (modified)"
            count=$((count + 1))
        fi
    # Handle other changes
    else
        if git add "$file" 2>/dev/null; then
            git commit -m "Change $file" && echo "Committed: $file"
            count=$((count + 1))
        fi
    fi
done < <(git status --porcelain)

echo ""
echo "Finished making $count commits"
