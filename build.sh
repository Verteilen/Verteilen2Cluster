#/bin/bash
echo Start Building...
cmake -DCMAKE_BUILD_TYPE=Debug -G Ninja -S . -B ./cmake-build-debug
cmake --build ./cmake-build-debug --target Vertelien2Cluster -j 14
