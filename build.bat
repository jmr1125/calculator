cmake -S. -Bbuild -DCMAKE_C_COMPILER=clang.exe -DCMAKE_CXX_COMPILER=clang++.exe -G"MinGW Makefiles"
cmake --build build
