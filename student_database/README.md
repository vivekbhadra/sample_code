# Student database assignments

From `~/sample_program`, enter the assignment folder.

```bash
cd student_database
```

Compile and run Assignment 2 (student database).

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic \
    assignment_2_student_database.cpp student.cpp student_records.cpp \
    -o assignment_2 && ./assignment_2
```

Compile and run Assignment 3 (student lookup cache) from the same folder.

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic \
    assignment_3_student_lookup_cache.cpp student.cpp student_records.cpp \
    -o assignment_3 && ./assignment_3
```
