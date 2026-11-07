# Student Example

A small example of a `Student` type with private data members and public getter/setter methods, split across a header, an implementation file and a driver program.

| File | Purpose |
|---|---|
| `student.h` | Declares the `Student` type |
| `student.cpp` | Defines the `Student` member functions |
| `main.cpp` | Creates a `Student`, sets its fields and prints them |
| ``Study Notes- Structuring a `Student` Type.pdf`` | Accompanying study notes |

## Compile and run

Run these commands from inside the `Students` folder.

### One step

Compile both source files and link them into one program:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp student.cpp -o student_app
./student_app
```

Use `clang++` in place of `g++` if you prefer Clang.

### Separate compile and link

Compile each `.cpp` file into an object file, then link the object files together:

```bash
g++ -std=c++17 -Wall -Wextra -c student.cpp -o student.o
g++ -std=c++17 -Wall -Wextra -c main.cpp -o main.o
g++ student.o main.o -o student_app
./student_app
```

When you change only `main.cpp`, you only need to recompile `main.o` and link again.

### Expected output

```
Name: Alice
Age: 20
Pocket Money: $100.5
```

## Clean up

Delete the build output:

```bash
rm -f student.o main.o student_app
```
