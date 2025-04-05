# 🐚 Mini Shell Program in C

This project implements a simple command-line shell in C. It reads user input, checks if the command is valid by scanning directories in the system's `$PATH`, and executes it using `fork()` and `execv()`.

## 📋 Features

- Prompt-based user interface
- Supports running any valid binary found in `$PATH`
- Handles command-line arguments (e.g. `ls -l`)
- Exits cleanly on `leave` command
- Uses `fork()`, `execv()`, and `wait()` to manage child processes
- Manual implementation of path lookup using `getenv("PATH")` and `strtok()`

## 📁 Files

- `assignment1.c`: Main source file with all logic
- `README.md`: This file

## ⚙️ Compilation

Use `gcc` to compile the program:

```bash
gcc assignment1.c -o shell
```

## ▶️ Usage

After compiling, run the program:

```bash
./shell
```

You'll see a prompt like this:
```
$
```

You can type a command like:
```
$ ls -l
```

To exit the shell, simply type:
```
$ leave
```

## 🚫 Error Handling

- If an invalid command is entered (not found in `$PATH`), you'll see:
  ```
  command - INVALID COMMAND
  ```
- If `execv()` fails, an error will be printed using `perror()`.

## 🧠 Concepts Used

- `fgets()` for input
- `strtok()` for tokenizing command and arguments
- `fork()` to create a child process
- `execv()` to run external programs
- `wait()` to wait for the child process
- `getenv("PATH")` to find valid executables

## 📌 Notes

- This shell does **not** support piping (`|`), redirection (`>`, `<`), or built-in shell commands (`cd`, `export`, etc.)
- The max number of arguments supported is 9 (`args[10]`)

## 👨‍💻 Author

Created as an assignment for an Operating Systems course.  
Author: Gilad

