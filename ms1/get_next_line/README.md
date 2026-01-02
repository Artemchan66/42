*This project has been created as part of the 42 curriculum by arabdull.*

# get_next_line

## Description

The `get_next_line` project consists of implementing a C function capable of reading a file descriptor line by line.
Each call to the function returns the next line from the input, allowing files or standard input to be processed incrementally instead of loading everything into memory at once.

The main goal of this project is to deepen understanding of:
- File descriptors
- Static variables
- Memory allocation and management
- Handling edge cases related to input/output operations

A line is defined as a sequence of characters ending with a newline character (`\n`) or the end of file (EOF).

---

## Instructions

### Compilation

The function is compiled together with your source files. `BUFFER_SIZE` controls how many bytes are read at each system call.

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

## Resources

- man 3 read
- man 3 malloc
- man 3 free
- GNU C Library documentation
- Official 42 subject PDF for get_next_line
- [Guidebook](https://42-cursus.gitbook.io/guide/1-rank-01/get_next_line)

## Extras

### Algorithm Explanation and Justification

The implementation of `get_next_line` is based on an incremental reading algorithm using a **static buffer**.

A static variable is used to store any data read from the file descriptor that was **not returned in the previous call**. This allows the function to continue reading from exactly where it stopped.

The algorithm works as follows:

1. A static buffer stores leftover characters between calls.
2. The function reads `BUFFER_SIZE` bytes from the file descriptor using `read()`.
3. The read data is appended to the static buffer.
4. The buffer is scanned for a newline character (`\n`).
5. If a newline is found:
   - The substring up to and including the newline is extracted and returned.
   - The remaining data is kept in the static buffer for the next call.
6. If the end of file (EOF) is reached:
   - Any remaining data in the buffer is returned as the final line.
   - Subsequent calls return `NULL`.

#### Justification

This approach is chosen because:

- It **minimizes system calls** by reading data in chunks.
- It allows the function to work with **arbitrarily large files**.
- It correctly handles cases where **lines are longer than `BUFFER_SIZE`**.
- It ensures **memory is allocated only when necessary**.
