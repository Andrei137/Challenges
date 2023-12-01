rm -rf build
mkdir bin
cmake -B build -S src -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=../bin
cd build; 
make;