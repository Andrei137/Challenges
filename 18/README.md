# 18. Image to ASCII Art

## Dependencies On Windows

- [MinGW](https://www.mingw-w64.org/downloads/)
- [CMake](https://cmake.org/download/)
- [Make](http://gnuwin32.sourceforge.net/packages/make.htm)
- [OpenCV](https://opencv.org/releases/)
- [OpenCV MinGW Build](https://github.com/huihut/OpenCV-MinGW-Build) (extract it in `<path_to_opencv>/build`)

## PATH Variables for Windows

- **MinGW:** `<path_to_mingw>/bin`
- **CMake:** `<path_to_cmake>/bin`
- **Make:** `<path_to_make>/bin`
- **OpenCV (bin):** `<path_to_opencv>/build/x64/mingw/bin`
- **OpenCV (lib):** `<path_to_opencv>/build/x64/mingw/lib`

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
- OpenCV
```bash
sudo apt install libopencv-dev
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
- You can run the program without building it if you want, but you need to keep the dll files in the bin folder
- Open a terminal in the project folder
- Go to the bin folder and run the executable
##### Windows
- You can drag and drop an image on the executable to use it as input
- Alternatively, you can run the program from the command line
```bash
cd bin
Ascii.exe <path_to_image>
```

##### Linux
```bash
cd bin
./Ascii <path_to_image>
```

## Output file
- The output file will be saved in the bin folder, with the name ```Ascii.txt```
- There, you will find the ASCII art of the image you selected
- Note that the image will be resized to reasonable values
