@echo off
setlocal

mkdir bin
cd src
wsl make build
move Fizzbuzz ../bin

endlocal