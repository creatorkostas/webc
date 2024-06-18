# webc

Write websites using the far superior (and actual programming language) C. 

<!--toc:start-->
- [webc](#webc)
  - [Usage](#usage)
    - [Build the library for Linux](#build-the-library-for-linux)
    - [Link the library to your project](#link-the-library-to-your-project)
  - [Examples](#examples)
  - [Documentation](#documentation)
  - [LICENSE](#license)
<!--toc:end-->



## Usage

### Build the library for Linux

```console
git clone https://github.com/KDesp73/webc
cd webc
make
```

### Link the library to your project

Add `-Lpath/to/library -lwebc` to your LDFLAGS

Make sure run `export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/lib/webc` before compiling


## Examples

See [Examples.md](./docs/Examples.md)

## Documentation

The documentation for this library is written in the header files

See [webc-core.h](./include/webc-core.h)

## LICENSE

[MIT](./LICENSE)
