# Systems Programming Portfolio

**Context:** Projects for Intermediate Programming Concepts (CSE374) at the University of Washington

**Tech Stack:** C, C++, Bash, GDB, Valgrind, Python (Linter)

## Overview
This repository contains low-level systems projects demonstrating proficiency in **manual memory management**, **pointer arithmetic**, and **Linux automation**. Unlike high-level application development, these projects required interacting directly with system resources and operating system interfaces.

## Projects

### [T9 Word Predictor](./t9-word-predictor/)
**Language:** C
* **Trie Data Structure:** Implemented a predictive text algorithm using a **Trie** to map numeric keypads to dictionary words.
* **Resource Management:** Engineered node allocation and deallocation logic using `malloc` and `free` to build dynamic data structures.
* **File I/O:** Built efficient parsers to read and process large dictionary files into the Trie structure at runtime.

### [C++ Smart Pointers & Memory](./cpp-classes-operators-smart-pointers/)
**Language:** C++
* **RAII Principles:** Implemented custom classes utilizing **Smart Pointers** (unique_ptr, shared_ptr) to ensure exception-safe memory management.
* **Operator Overloading:** Overloaded standard operators to create intuitive, clean APIs for vector operations.
* **Object-Oriented Design:** applied inheritance and encapsulation to model complex systems.

### [C Systems & Debugging](./c-systems-and-debugging/)
**Tools:** Valgrind, GDB, C
* **Leak Resolution:** Analyzed a codebase intentionally riddled with memory errors, achieving a clean memory report using **Valgrind**.
* **Root Cause Analysis:** Traced segmentation faults (segfaults) to their source using **GDB** to ensure program stability.
* **Word Frequency Analysis:** Built a C-based text analyzer to process files and track word occurrences using manual memory buffers.

### [Linux Shell Utilities](./linux-shell-utilities/)
**Language:** Bash
* **Automation:** Developed shell scripts to automate text processing and system file management tasks.
* **Regex Integration:** Utilized **Regular Expressions (Regex)** to filter and format complex data streams.
* **Process Management:** Handled standard input/output (stdin/stdout) piping to chain commands effectively in a Unix environment.
