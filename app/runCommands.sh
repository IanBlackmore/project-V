#!/bin/bash
rm -rf build
mkdir build
cd build
cmake .. 
make
./apiTests
./MoneyFormatterTests
./proj_v