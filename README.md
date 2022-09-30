# RogEng

A 2d engine designed to for simplicity.

## Installation and building

Simply clone the directory, and do the usual CMake stuff:

```
mkdir build
cd build
cmake ..
make && sudo make install
```

If you're only looking to build and not install RogEng, skip `sudo make install` and just run `make`. The "lib" and "include" directories will be created inside of the build folder.

For building, RogEng requires the latest version of [SFML](https://github.com/SFML/SFML). If you're on linux, you can probably use your package manager for this.

