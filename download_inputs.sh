#!/bin/bash

if [ "$#" -eq 0 ]; then
    echo "Error: session token must be provided as the first argument" >&2
    echo "Usage: $0 <session_token>" >&2
    exit 1
fi

puzzle_input_dir="./puzzle_input"
base_url="https://adventofcode.com/2025/day/"
session_token=$1

mkdir -p $puzzle_input_dir

for day in {1..12}; do
    echo "Trying to download puzzle input for day $day...";
    full_url="${base_url}${day}/input"
    curl $full_url --cookie "session=${session_token}" -o "$puzzle_input_dir/input_${day}.txt"
done
