#!/bin/bash

# Unstage all files first to ensure we commit them one by one
git reset

# Change to the root of the git repository
cd "$(git rev-parse --show-toplevel)" || exit

# Get all changed/untracked files
changed_files=$(git status --porcelain -uall | sed s/^...//)

for file in $changed_files; do
    # Skip if it's not a regular file
    if [ ! -f "$file" ]; then
        continue
    fi

    # Skip this script itself to avoid committing it 7 times if not desired
    # (Optional, but usually a good idea. We'll include it since the user said "all the files changed")
    
    echo "Making 7 commits for $file..."

    # First commit: add the file as is
    git add "$file"
    git commit -m "Add $file (commit 1/7)"

    # Next 6 commits: append a space and commit
    for i in {2..7}; do
        echo " " >> "$file"
        git add "$file"
        git commit -m "Update $file (commit $i/7)"
    done
done

echo "Finished making 7 commits for each changed file."
 
