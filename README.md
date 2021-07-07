# Corewar

## Table of content
* [Introduction](https://www.github.com/NaadiQmmr/Corewar#Introduction)
* [How to run it](https://www.github.com/NaadiQmmr/Corewar#How%20to%20run%20it)
  * [How to run the asm part](https://www.github.com/NaadiQmmr/Corewar#How%20to%20run%20asm%20part)
  * [How to run the corewar part](https://wwW.github.com/NaadiQmmr/Corewar#How%20to%20run%20corewar%20part)
* [Going further](https://www.github.com/NaadiQmmr/Corewar#Going%20further)
* [Contributors](https://www.github.com/NaadiQmmr/Corewar#Contributors)

## Introduction
The corewar is a school project during the first year. It is my favorite project I think including all of my students years, and I bet a lot of students agree with me. It is fun by the way you approach the subject, by the way you exchange with the other teams at school and also by the way you made your architecture.

The purpose is to make programs fight against each other, write in the memory of each other, and see the final winner.

The project is divided into small sub projects :
- The `asm/` which is a language provided by our school that looks really close to Assembly. We have to take a file path in input, that will contains some ASM code instructions ; in output you'll receive the associated binary. As you understand, this part is to code a simple and tiny compiler.
- The `corewar/` which is a virtual machine that will take the binary files first compiles with the `asm/ ` part and interpret it by following a set of rules and constraints, like cycles of some functions.

This project is made in C language. You'll find C++ like code, on the corewar part.

## How to run it
If you run a `tree` command into the folder, you'll see three Makefiles : one at the root of the project, and the two others respectively in the `asm/` and `corewar` folder. Actually, the first one call the two other to produce their binaries ; you 'll then have to go to each corresponding folder to looking for their binaries.

```shell
$ make
```
### How to run asm part
If you have followed the previous step, you should have an `asm` binary. 

```shell
$ cd ./asm ; /asm filepath1 [filepath2] [...]
```
### How to run the corewar part
```shell
$ cd corewar/ ; ./corewar -h
USAGE
  ./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name] ...
DESCRIPTION
-dump nbr_cycle dumps the memory after the nbr_cycle execution (if the round isn't already over) with the following format: 32 bytes/line in hexadecimal (AOBCDEFE1DD3...)
-n prog_number sets the next program's number. By default, the first free number in parameter order
-a load_address sets the next program's loading address. When no address is specified, optimize the addresses so that the processes are as far away from eachother as possible. The adresses are MEM_size modulo.
```

## Going further
There is a tricky bug : as convention, the input files extension are `.s` and the output files are `.cor`: to replace the extension filename, the program will looks for the first `.` and will overwrite whatever is next by `.cor`. It is not smart because if we have the following inputs  `../superprogram.s` it will write a file with the filename `.cor`.

## Contributors
* [Adina C.](https://www.github.com/NaadiQmmr)
* [Bogdan G.](https://www.github.com/bogdzn)
* Guillaume D.
* Iaroslav S.
