#!/bin/bash

# 🔁 Change directory to the project
project_dir="E:/projects/c++ course/12 - Data Structures - Level1"
cd "$project_dir" || exit

# 🗓️ Create or read project creation date
created_file=".created_at"
if [ ! -f "$created_file" ]; then
    created_date=$(date '+%Y-%m-%d_%H-%M-%S')
    echo "$created_date" > "$created_file"
    echo "🆕 Created project date: $created_date"
else
    created_date=$(cat "$created_file")
    echo "📅 Project originally created at: $created_date"
fi

# 🧷 Create snapshot if not exists
snapshot_dir="E:/projects/_snapshots_DataStructures_Level1"
snapshot_path="$snapshot_dir/$created_date"

if [ ! -d "$snapshot_path" ]; then
    mkdir -p "$snapshot_path"
    cp -r "$project_dir" "$snapshot_path"
    echo "📁 Snapshot created at: $snapshot_path"
else
    echo "📦 Snapshot already exists at: $snapshot_path"
fi

# ⛔ Ensure .gitignore exists and includes .vs/
gitignore_file=".gitignore"
if [ ! -f "$gitignore_file" ]; then
    echo ".vs/" > "$gitignore_file"
else
    grep -qxF ".vs/" "$gitignore_file" || echo ".vs/" >> "$gitignore_file"
fi

# ⚙️ Initialize Git repo if not exists
if [ ! -d ".git" ]; then
    echo "🚀 Initializing new Git repository..."
    git init --quiet
    git branch -M main
fi

# 🔥 Remove .vs/ from Git index if tracked
if git ls-files --error-unmatch ".vs/" > /dev/null 2>&1; then
    git rm -r --cached .vs/
fi

# 🧠 Git operations
git remote remove origin 2>/dev/null
git remote add origin "https://github.com/osama-mohamoud2006/12---Data-Structures---Level1.git"

git fetch origin main 2>/dev/null || echo "ℹ️ Remote main branch not found yet (probably first push)."
git pull origin main --rebase 2>/dev/null || echo "⚠️ Skipping rebase (no remote main yet)."

git add -u
git add .

commit_msg="Auto commit: $(date '+%Y-%m-%d %H:%M:%S')"
git commit -m "$commit_msg" --quiet || echo "⚠️ Nothing to commit."

git push -u origin main || echo "🚫 Push failed (check repo or auth)."
