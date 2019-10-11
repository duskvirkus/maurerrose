#!/bin/bash

cd proj/cmake

rm -r build

mkdir build
cd build

cmake ..
make -j10
