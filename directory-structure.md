# Directory Layout

## tf main directory

I am trying to follow the standard I am most use to seeing. 
1. The top directory is the name of the application.
1. All source files are under the `src` directory.
1. The top level `CMakelists.txt` is in the `src` directory.
1. The application is in the `app` directory. It contains a `CMakeLists.txt` 
and `src` and `include` directories as needed.
1. Each library is in it's own directory. Each library directory contains a `CMakeLists.txt` file and it `src` and `include` directories.
```bash
    tf
    └── src
        ├── CMakeLists.txt
        ├── app
        │   ├── CMakeLists.txt
        │   └── src
        ├── test
        ├── TfTools
        │   ├── CMakeLists.txt
        │   ├── include
        │   │   └── TfTools
        │   └── src
        └── TfUtils
            ├── CMakeLists.txt
            ├── include
            │   └── TfUtils
            └── src
```
