#!/bin/bash

# Make sure to set SESSION_COOKIE environment variable to whatever your value for your Advent of Code cookie is
# Usage : ./scripts/download.sh {x}
            # where x is a given day for Advent Of Code

download_puzzle_input() {
    url="https://adventofcode.com/2024/day/$1/input"
    dir="day$1"
    mkdir -p "$dir"
    curl -H "Cookie: session=$SESSION_COOKIE" -o "$dir/input.txt" "$url"
}

download_puzzle_input "$1"
