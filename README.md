# RogEng

A 2d engine designed to for simplicity.

## Installation and building

Simply clone the directory, and do the usual CMake stuff:

```
mkdir build
cd build
cmake .. -DCMAKE_CXX_COMPILER=clang++
make && sudo make install
```

If you're only looking to build and not install RogEng, skip `sudo make install` and just run `make`. The "lib" and "include" directories will be created inside of the build folder.

For building, RogEng requires the latest version of [SFML](https://github.com/SFML/SFML) and [FMT](fmtlib/lib). If you're on linux, you can probably use your package manager for this.

It is HEAVILY reccomended to use [LLVM](https://github.com/llvm/llvm-project)'s clang to compile. If you choose not to, you can exclude `-DCMAKE_CXX_COMPILER=clang++` from the build commands.
