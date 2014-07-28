Daisy - Simple Arithmetic and Logical Interpreter
===============================================

Daisy is a simple arithmetic and logical Interpreter. It is developed using the very simple methods of developing an Interpreter. It helps to solve simple arithmetic expressions and also implement logical conditions so as to implement very priliminary idea of programming 
Daisy started as a fun project and loved to be a open source in 2014.

Daisy just consists of a c program run in a gcc compiler.
Daisy has been developed using certain arithmetic key words which can be directly implemented from a text file or can be taken as input during run time.

It is written in C.
The initial prototype runs on Linux. There is no Mac or Windows version yet.

Requirements :white_check_mark:
-------------------------------
:pushpin: gcc version 4.8.2 

Compilation :arrow_forward:
---------------------------
Once you have setup the dependencies, download the source:
```
$ cd ~/Downloads
$ git clone https://github.com/Subarno/Daisy
```

Create and move into the build directory:
```
$ cd Daisy
```

Compile and run for 'Runtime Input Method' 
```
$ gcc -std=c99 main.c function.c
$ ./a.out

```

Compile for 'Input Using a Text File'
```
$ gedit run.txt
$ ./a.out run.txt
```

Functional Words used and their functions:white_check_mark:
------------
```
add   --> Addition
sub   --> Substraction 
mul   --> Multiplication
div   --> Division
iff   --> Logical operater
more  --> Comparison Operator
less  --> Comparison Operator
equal --> Comparison Operator
quit  --> Quit or End Program
```
> Happy To Code ... Happy To Live :octocat:
