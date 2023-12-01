@echo off
setlocal

mkdir bin
cd src
g++ Main.cpp -o Occurrences -O2
move Occurrences.exe ../bin

endlocal