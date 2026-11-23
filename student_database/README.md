# Student database assignments

| File | What it contains |
|------|------------------|
| `student.h` / `student.cpp` | The `Student` class (one record). |
| `student_database.h` / `student_database.cpp` | Shared helpers: `make_student_database()` builds 20 sample students; `display_student()` prints one. |
| `assignment_2_build_database_with_reserve.cpp` | Assignment 2: builds the database with `reserve()` and lists every student. |
| `assignment_3_index_cache_survives_reallocation.cpp` | Assignment 3: a lookup cache that stores an **index**, so it stays valid when the vector reallocates. |

## Design notes

**Why `reserve()` in Assignment 2?** The final size (20) is known before any
student is added. Reserving up front means one allocation and no element moves.
Without it the vector would grow 1 → 2 → 4 → … → 32, moving every `Student`
each time it grows.

**Why an index instead of an iterator in Assignment 3?** After `reserve(20)` and
20 insertions, `size() == capacity()`, so the next `emplace_back` reallocates.
Reallocation invalidates every iterator, pointer and reference into the vector,
but not indices. The program prints the buffer address before and after the
appends so you can see the move. An index is only stable for appends:
inserting or erasing earlier elements would shift it. That is why
`find_student()` checks the ID at the cached index before it reports a hit.

## Build and run

From `~/sample_code`, enter the assignment folder.

```bash
cd student_database
```

Compile and run Assignment 2 (build the database with `reserve`).

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic \
    assignment_2_build_database_with_reserve.cpp student.cpp student_database.cpp \
    -o assignment_2 && ./assignment_2
```

Compile and run Assignment 3 (index-based lookup cache) from the same folder.

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic \
    assignment_3_index_cache_survives_reallocation.cpp student.cpp student_database.cpp \
    -o assignment_3 && ./assignment_3
```
