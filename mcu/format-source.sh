#!/bin/bash
find Core/ -iname *.c -o -iname *.h | xargs clang-format -i --style="{BasedOnStyle: LLVM, ColumnLimit: 100, IndentWidth: 4}"
