#!/bin/bash
# Suggest large files/directories to consider removing or moving out of the workspace.

echo "Top 20 largest directories (depth=2):"
du -h --max-depth=2 2>/dev/null | sort -hr | head -n 20

echo
echo "Top 50 largest files:"
find . -type f -exec du -h {} + 2>/dev/null | sort -hr | head -n 50

echo
echo "Suggestion: consider excluding build/, archive/, node_modules/, and large vendor folders from the workspace or moving them outside the repo." 
