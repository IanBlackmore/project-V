#!/bin/bash
rm -rf build
mkdir build
cd build
cmake .. 
make
./apiTests
./proj_v