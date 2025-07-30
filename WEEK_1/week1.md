# 📚 System Calls

This file explains some important system calls used in process management:

---

## a) `fork()`
- Used to create new processes.
- The new process consists of a copy of the address space of the original process.
- System call returns:
  - `0` in the child process.
  - Child process ID in the parent process.

---

## b) `getpid()`
- Each process is identified by its ID value.
- This function is used to get the ID value of the **current process**.

---

## c) `getppid()`
- Used to get the **parent process's** ID value of the current process.

---

## d) `wait()`
- The parent waits for the child process to complete using the `wait` system call.
- `wait` returns the process identifier (PID) of a terminated child.
- Useful when the parent has multiple children — helps the parent know **which child** has terminated.

---

## e) `exit()`
- A process terminates when it finishes executing its final statement and asks the operating system to delete it by using the `exit` system call.
- At that point, the process may return data (output) to its parent process (via the `wait` system call).

---
