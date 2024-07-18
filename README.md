# get_next_line

## Description

`get_next_line` is a custom implementation of the classic function for reading lines from a file descriptor in C. This particular implementation uses a linked list where each node contains a single character from the line. This method ensures efficient memory management and ease of manipulation for each character read.

## Features

- Reads a line from a file descriptor.
- Uses a linked list data structure where each node stores a single character.
- Efficient memory management and dynamic line length support.
- Handles different buffer sizes and multiple file descriptors.

## Algorithm

1. **Node Structure**: Each character read from the file is stored in a node of a linked list. The node contains:
    - A character.
    - A pointer to the next node.

2. **Reading Characters**: Characters are read from the file descriptor one at a time and stored in nodes.

3. **Building the Line**: As characters are read, they are added to the linked list. The line is constructed by traversing the linked list from the head node to the end.

4. **Line Termination**: The end of a line is determined by encountering a newline character (`\n`) or the end of the file.

## Usage

### Function Prototype

```c
char *get_next_line(int fd);
