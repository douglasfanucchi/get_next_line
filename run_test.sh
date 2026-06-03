#!/bin/bash
cd tests
cmake -S . -B build
cmake --build build
cd build
valgrind --leak-check=full -q ctest --output-on-failure
