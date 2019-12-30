#!/usr/bin/env bash

pwd = "$(pwd)"
base = "$(realpath $0)"

cd "$base"
rm -rf build &&                                 \
    mkdir build &&                              \
    cd build &&                                 \
    conan install .. --profile=clang &&         \
    cd .. &&                                    \
    cmake -DCMAKE_CXX_COMPILER=/usr/bin/clang++ \
          -DCMAKE_C_COMPILER=/usr/bin/clang     \
          -DCMAKE_EXPORT_COMPILE_COMMANDS=1     \
          -B build -S .  &&                     \
    cmake --build build

cd "$pwd"
