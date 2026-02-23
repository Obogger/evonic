#!/usr/bin/env bash

set -e  # stop on error

cmake -S . -B build
cmake --build build
./build/bin/Evonic