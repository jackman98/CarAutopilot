rm -r build
mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=~/Downloads/hackaton/TOOLCHAIN/pi.cmake ..
make
