#!/bin/bash

function crun() {
if [ $# -eq 0 ]; then
    echo "Usage: $0 <name>"
    exit 1
fi

name="$1"

if ! [ -f "$name.c" ]; then
    echo "Error: $name.c not found"
    exit 1
fi

gcc -Wall -Wextra -Werror -o "$name" "$name.c"

if [ $? -eq 0 ]; then
    echo "Compilation successful. Running $name..."
    "./$name"
else
    echo "Compilation failed"
fi
}