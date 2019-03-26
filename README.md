<p align="center" style="font-size:200%"><img src="https://drive.google.com/uc?export=download&confirm=no_antivirus&id=1ULdyRKnaAoDfw-VbxXqWtyN8HWK187Bg" height="50%" width="50%"></p>
<p align="center"><a href="https://travis-ci.org/luparev22/chessviz"><img src="https://travis-ci.org/luparev22/chessviz.svg?branch=master"></a></p>

# About chessviz

#### The program for visualization of chess notations.

# Install

```
$ git clone "https://github.com/luparev22/chessviz.git"
$ cd chessviz
$ make
```

# How to use

#### The program accepts a file containing a string of chess notation as input.
#### Grammar:
```
СписокХодов = {ЗаписьХода ПереводСтроки}
ЗаписьХода = НомерХода. Ход Ход
Ход = [ТипФигуры] Поле ТипХода Поле [ТипФигуры | 'e.p.' | '+' | '#']
    | Рокировка
ТипФигуры = 'K' | 'Q' | 'R' | 'B' | 'N'
Поле = /[a-h][1-8]/
ТипХода = '-' | 'x'
Рокировка = '0-0-0' | '0-0'
```

#### Example:

```
1. e2-e4 e7-e5
2. Bf1-c4 Nb8-c6
3. Qd1-h5 Ng8-f6
4. Qh5xf7#
```

#### In order for the program to use the text file you created, you need to register the following:
```
$ bin/main example.txt
```
#### where example.txt is a file containing chess notations. Instead of example.txt any name of the file containing chess notations is possible.

#### At the output, the program creates a .html file by opening which you will see the rendered chess notation that you provided to the program.

# Folder hierarchy
Filename  | File content
----------------|----------------------
bin|Directory containing the executable file obtained as a result of installing the program.
build|Directory containing build artifacts (.o and .d files).
src|Directory containing source files.
src/board.cpp|The implementation of the functions of checking the input data, the implementation of the course.
src/board_print_html.cpp|Board output functions in html format.
src/main.cpp|Entry point to the program.
src/board.h|Function declarations and type definitions.
src/board_print_html.h|Function declarations and type definitions.
Makefile|File containing instructions for building the program.
.clang-format|The file contains instructions for the design of the code.
.gitignore|A file containing git file ignore instructions.
.travis.yml|A file containing instructions for automatic builds using travis-ci.
