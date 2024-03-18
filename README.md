![Screenshot](header.png)

In general, it parses the `Lexer/txt/source.txt` and makes a lexical analysis of the source code written in the Stasyan language. The output of the program is `Lexer/txt/symbol_table.txt`, where all tokens can be found. Moreover, it produces some additional file `Lexer/log/log.txt` with debugging information and does error handling.

## What can it do?
The last version can identify:
* Arithmetical operators
* Type identifiers
* Object identifiers
* Digits
* Ints (unsigned) 
* Floats (unsigned) 
* Keywords (false, while, not, etc.) 
* Strings
* Comments v1 (/* text */)
* Comments v2 (--"text")
* EOF

## Dependencies
1. GNU Compiler Collection
2. Valgrind

## How to use it?
1. Git clone this repository using:
```bash 
cd $(working_repo)
git clone git@github.com:EtoAndruwa/Lexer.git 
```
2. Write the code of `source.txt` using some text editor (VS Code, Sublime, etc):
```bash
code ./Lexer/txt/source.txt
```
3. Run Makefile to compile & run the whole project:
```bash
make
```
4. The output will be in the folder `./Lexer/txt`
![Screenshot](output_exmpl.png)

## History of updates:
* 18.03.24 (Latest)
* 17.03.24
* 06.03.24
* 04.03.24