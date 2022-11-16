#!/bin/bash

echo "Starting program at $(date)" # Date will be substituted
echo ""
echo "Running program $0 with $# arguments with pid $$"
echo ""

for file in maps/*.cub; do
	echo $file
	./cub3d "./$file"
	echo ""
done