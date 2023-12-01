# 46. Counts occurrences of characters in a Given String

## Dependencies On Windows

- [MinGW](https://www.mingw-w64.org/downloads/)

## PATH Variables for Windows

- **MinGW:** `<path_to_mingw>/bin`

## Dependencies On Linux

- Build Essentials
```bash
sudo apt install build-essential
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
Occurrences.exe
```

##### Linux
```bash
cd bin
./Occurrences
```

## Input file

- Inside the bin folder, there is a file called ```String.txt```
- It contains a string in Unicode format
- You can edit it and run the program to see the results

## Output file
- The output file will be saved in the bin folder, with the name ```Occurrences.txt```
- There, you will find the occurrences of each character in the string, with Unicode support