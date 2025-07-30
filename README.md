# 🖥️ Operating System Lab Manual

This repository contains programs and notes for Operating Systems Lab, organized **week-wise** as per syllabus.

---

## 📅 **Week 1: Demonstration of system calls**

### 🔧 System calls used:
- `fork()` – create a new process.
- `getpid()` – get current process ID.
- `getppid()` – get parent process ID.
- `wait()` – parent waits for child to complete.
- `exit()` – process terminates and returns status.

---

### ✅ Programs:
1. Create a child process using `fork()`.
2. Print process IDs: parent prints its PID & child's PID; child prints its PID & parent's PID.
3. Create a child process to list all files (`ls -l`). Parent waits using `wait()`. Also, create another child to show what happens if parent dies before child.

---

## 📅 **Week 2: More system calls & directory/file operations**

### 🔧 System calls used:
- `opendir()`, `readdir()`, `closedir()` – to work with directories.
- `open()`, `close()`, `read()`, `write()` – to handle files.
- `execlp()` – to run external commands (e.g., `ls`).
- `grep()` – find matching lines in files.

---

### ✅ Programs:
1. Open a directory & list its contents.
2. Execute `ls` command using `execlp()` in child process.
3. Read & write details to two files; print matching lines.

---

## 📅 **Week 3: Process Scheduling – FCFS & SJF**

### ✅ Objectives:
- Implement:
  - FCFS
  - SJF Non-Preemptive
  - SJF Preemptive
- Print Gantt chart, average waiting & turnaround time.


---

## 📅 **Week 4: Scheduling – Priority, Round Robin, Multilevel queue**

### ✅ Objectives:
- Implement:
  - Priority scheduling
  - Round Robin (time quantum = 2)
  - Multi-level queue scheduling (system & user processes)

---

## 📅 **Week 5: Deadlock**

### ✅ Programs:
1. Simulate Banker's algorithm (safe sequence).
2. Implement deadlock detection algorithm.

---

## 📅 **Week 6: Process Synchronization**

### ✅ Programs:
1. Communication between parent & child using:
   - a) Pipe
   - b) Message passing
   - c) Shared memory
2. Producer-Consumer using semaphores.
3. Dining-Philosopher problem.

---

## 📅 **Week 7: Page Replacement Algorithms**

### ✅ Algorithms:
- FIFO
- LRU

## 📅 **Week 8: Memory Allocation Techniques**

### ✅ Techniques:
- Best Fit
- First Fit
- Worst Fit

---

## 📅 **Week 9-10: File Allocation Strategies**

### ✅ Techniques:
- Contiguous
- Linked
- Indexed

### 📌 Input:
File name, starting block, number of blocks.

### 📊 Output:
File details: name, start block, number of blocks, allocated blocks.

---

## 📅 **Week 11-12: Disk Scheduling Algorithms**

### ✅ Algorithms:
- FCFS
- SCAN
- C-SCAN

  
---

## 📅 **Week 13-14: Writing a Shell**

### ✅ Features:
- Custom shell with prompt.
- Parse command into tokens.
- Built-in commands: `exit`, `ls`, `mv`, `cat`, `cd`.
- Execute external commands with arguments.
- Error handling.

---

## ✍️ **Author:**  
👨‍💻 Priyanshu Pant

> 📝 *For more, check source codes & comments inside each C file.*

