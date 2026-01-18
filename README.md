# Sherbeeny Programming Language

A custom programming language compiler built from scratch in C++. 

Sherbeeny compiles `.sherb` files and features a tokenization system that recognizes keywords, identifiers and numbers. Currently in the lexical analysis phase with plans to add parsing and code generation.

## Building for now lmao

```bash
cd src/
g++ -std=c++17 -I. main.cpp tokenizer.cpp -o sherbeeny
./sherbeeny sherbeeny main.sherb
```


