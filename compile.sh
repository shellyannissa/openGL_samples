#!/bin/bash

# Check if a filename is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <filename.c>"
    exit 1
fi

# Extract filename without extension
filename="${1%.*}"

# Compilation command
gcc "$1" -o "$filename" -lglut -lGL -lGLU -lm

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Executable: ./$filename"
else
    echo "Compilation failed."
fi

