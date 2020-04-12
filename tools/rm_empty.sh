#!/bin/bash
find -type f -size 0c | while read file
do
    echo "rm" "$file"
    rm "$file"
done