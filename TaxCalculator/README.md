## Compilation commands

Each complete program can be compiled using C++17.

For the procedural example:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic \
    procedural_add_subtract.cpp -o procedural_add_subtract
```

For the single-file class example:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic \
    tax_calculator_single_file.cpp -o tax_calculator_single_file
```

For the separated class implementation:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic \
    main.cpp TaxCalculator.cpp -o tax_calculator
```
