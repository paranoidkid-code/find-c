# Simple C `find` Utility

A lightweight C implementation of a recursive directory search utility inspired by the Unix `find` command. It traverses directories starting from the current folder (`.`) and finds any files or subdirectories whose names match the given keyword.

---

## Features

* **Recursive Directory Traversal:** Searches subdirectories recursively using standard POSIX directory APIs (`dirent.h`, `sys/stat.h`).
* **Sub-string Matching:** Locates any file or directory containing the target keyword using `strstr`.
* **Colored Output:** Highlights successful matches in bright green in ANSI-supported terminals.
* **Directory Loop Prevention:** Automatically ignores `.` and `..` special entries.

---

## Getting Started

### Prerequisites

* A C compiler such as `gcc` or `clang`

### Compilation

Compile the source code using `gcc`:

```bash
gcc -Wall -Wextra -O2 find.c -o myfind
```

---

## Usage

Run the program by passing the keyword or substring you wish to locate:

```bash
./myfind <keyword>
```

### Example

```bash
$ ./myfind test
Searching for 'test'...
Found a match: ./tests
Found a match: ./tests/test_main.c
Found a match: ./src/test_utils.c

Search completed
```

---

## Error Handling

* **Missing keyword argument:**
  ```text
  Usage: find <keyword>
  ```
* **Unreadable directories:**
  If a folder lacks read/open permissions, `search_dir` skips it quietly without crashing the rest of the search.

---

## License

This project is open-source and available under the [MIT License](LICENSE).
