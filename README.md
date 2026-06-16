# Autodesk  Assignment

This repository contains solutions for:

1. Reverse Words
2. Build Version Update Refactoring

## Assignment 1

Language: C++

The solution scans the input string once and reverses each contiguous
alphanumeric word while preserving separators and punctuation.

Complexity:
- Time: O(n)
- Space: O(n)

## Assignment 2

Language: Python 3

The original implementation contained duplicated logic and lacked
error handling.

The refactored solution:
- Removes duplication
- Uses reusable functions
- Validates environment variables
- Uses context managers
- Detects failed replacements

## Running

### Assignment 1

```bash
g++ -std=c++17 reverse_words.cpp -o reverse_words
./reverse_words
./a.out
```


## Running Assignment 2

Set environment variables:

export SourcePath=/Users/sejalnayak/Desktop/Autodesk/assignment2/test_data
export BuildNum=123

Then verify:

echo $SourcePath
echo $BuildNum

Run:
python assignment2/update_build_version.py