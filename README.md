# Anagram Solver (Amirza Solver) — Trie + Backtracking

## Overview

This project implements an **Anagram Solver** inspired by the game *Amirza*.
Given a dictionary of valid English words and multiple queries of shuffled letters, the program outputs all dictionary words that can be formed using those letters.

The solution uses:

* **Trie (Prefix Tree)** for dictionary storage
* **Recursive Backtracking (DFS)** for word generation
* **Frequency-based pruning** for efficiency

---

## Problem Summary

### Input

1. Integer `n`: number of dictionary words
2. `n` lines: dictionary words (lowercase English letters only)
3. Integer `q`: number of queries
4. `q` lines: each query contains space-separated letters (shuffled)

Example:

```
3
amir
amin
arian
2
a i r s n m
n i a s p
```

---

### Output

For each query:

* First line: number of valid words
* Next lines: all valid words in **lexicographically sorted order**
* If no word can be formed, print `0`

Example:

```
2
amin
amir
0
```

---

## Core Idea

Instead of checking each dictionary word independently, the solution:

> Builds words dynamically by traversing a Trie while consuming available letters.

This ensures:

* No unnecessary dictionary scanning
* Early pruning of invalid paths
* Efficient generation of valid words

---

## Data Structure: Trie

Each node contains:

* `child[26]`: pointers to next characters
* `isWord`: marks completion of a valid dictionary word

### Why Trie?

* Enables prefix-based traversal
* Allows early stopping when no valid continuation exists
* Naturally supports backtracking over valid word paths

---

## Algorithm

### 1. Build Dictionary (Trie Construction)

Each dictionary word is inserted character by character into the Trie.

---

### 2. Query Processing

For each query:

* Convert input letters into a frequency array `freq[26]`
* Run DFS from Trie root

---

### 3. Backtracking (DFS)

At each step:

1. Check if current node is a valid word → store result
2. Try all possible next characters (a–z)
3. Move only if:

   * Character exists in Trie
   * Character is available in frequency array
4. Recursively explore
5. Backtrack (restore state)

---

### DFS Logic

```
if node.isWord:
    save current word

for each letter i:
    if child exists AND freq[i] > 0:
        choose letter
        recurse
        undo choice
```

---

## Key Components

### Trie Node

```cpp
struct Node {
    Node* child[26];
    bool isWord;
};
```

---

### Insert Word

Builds Trie from dictionary input.

---

### DFS Backtracking

Generates all valid words using available letters.

---

### Query Handling

* Converts query string into frequency array
* Runs DFS
* Collects and sorts results

---

## Complexity

Let:

* `N` = number of dictionary words
* `L` = average word length
* `Q` = number of queries
* `A` = alphabet size (26)

### Preprocessing

* Trie construction: **O(N × L)**

### Per Query

* DFS depends on pruning efficiency
* Worst case: exponential
* Practical performance: very fast due to pruning

---

## Strengths

* Efficient pruning using Trie structure
* Avoids scanning full dictionary per query
* Backtracking ensures correctness under constraints
* Handles repeated letters correctly via frequency array

---

## Limitations

* DFS can still grow large for extreme cases
* Memory usage increases with Trie size
* No advanced caching or memoization applied

---

## How to Run

### Compile

```bash
g++ main.cpp -o solver
```

### Run

```bash
./solver
```

---

## Design Summary

This project demonstrates:

* Trie-based dictionary modeling
* Recursive backtracking with state restoration
* Frequency-constrained search space reduction
* Clean separation between preprocessing and query handling

---

## Author Intent

The solution prioritizes:

* Algorithmic correctness
* Backtracking compliance (assignment requirement)
* Readable recursive structure
* Practical efficiency through pruning
