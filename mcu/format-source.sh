#!/bin/bash
find Core/ -iname *.c -o -iname *.h | xargs clang-format -i --style="{BasedOnStyle: LLVM, ColumnLimit: 120, IndentWidth: 4}"
