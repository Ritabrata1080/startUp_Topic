# CPP learnings

This is a repository to learn advanced c++ concepts and clear the basics of that language, understand multithreaded environments and other cool stuffs. Codeowner file is pushed as of now. More to come. 

## Generate the build files

The project uses cmake for building the binaries, ensure you have the latest cmake installed.
Follow the following steps for building and running the project

```sh
# Generate a build
cmake [-G <GENEREATOR>] -S . -B build <TARGET_OPTIONS>
```

The first parameter `[-G <GENERATOR>]` is optional, by default you should get 
- UNIX makefiles on MACOS/UNIX/LINUX
- MinGW makefiles on windows if installed, otherwise Visual Studio
However you can specify any of the options below to change the default generator to, substitute it in place of `<GENERATOR>`
- `XCode` (MACOS Only)
- `NMAKE Makefiles` (Windows Only)
- `Visual Studio` <VERSION> (Windows Only)
- `Unix Makefiles` (If not selected by default)
- `MinGW Makefiles`

The second parameter `<TARGET_OPTIONS>` can take the following values
- `-DBUILD_TARGET_ALL`
- `-DBUILD_TARGET_CACHE`
- `-DBUILD_TARGET_CPP_THREADS`
- `-DBUILD_TARGET_STL`
- `-DBUILD_TARGET_GENERICS`

BUILD_TARGET_ALL will build all of the targets, you can the other options, multiple at once to only build specific targets
For example
```sh
cmake -G "XCode" -S . -B build -DBUILD_TARGET_CPP_THREADS -DBUILD_TARGET_CACHE
```
is only going to build Cpp-Threads and Cache targets

## Build the project

If you selected any of "Unix Makefiles, MinGW Makefiles, NMAKE Makefiles".
you can directly run
```sh
cmake --build build
```

Otherwise the project files for the respecitve IDEs would be generated for you inside `build/`, open that in your IDE and build the project

## Run

If you select the default build or specify one which is any of "Unix Makefiles, MinGW Makefiles, NMAKE Makefiles"
You can run the executables that were generated inside `build/`
Otherwise they may be present inside `Debug`, `Release`, `x64`, `x86` folders
