# 04. Markov Chain Sentence Generator

## Dependencies On Windows

- [MinGW](https://www.mingw-w64.org/downloads/)
- [CMake](https://cmake.org/download/)
- [Make](http://gnuwin32.sourceforge.net/packages/make.htm)

## PATH Variables for Windows

- **MinGW:** `<path_to_mingw>/bin`
- **CMake:** `<path_to_cmake>/bin`
- **Make:** `<path_to_make>/bin`

## Dependencies On Linux

- Build Essentials
```bash
sudo apt install build-essential
```
- Cmake
```bash
sudo apt install cmake
```
- Make
```bash
sudo apt install make
```

## Building the project
- Open a terminal in the project folder
- Run the build script
##### Windows
```bash
build.bat
```

##### Linux
```bash
./build.sh
```

## Running the program
- You can run the program without building it if you want, no dependencies required
- Open a terminal in the project folder
- Go to the bin folder and run the executable
##### Windows
```bash
cd bin
Markov.exe
```

##### Linux
```bash
cd bin
./Markov
```

## Input file
- Inside the bin folder, there is a file called ```Words.txt```
- The program will read from this file and generate a sentence based on the words inside it
- You can edit it with whatever text you want, just make sure it has ASCII characters only