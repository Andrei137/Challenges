@echo off
setlocal

cmake.exe -G "MinGW Makefiles" -B build
cd build
make

endlocal