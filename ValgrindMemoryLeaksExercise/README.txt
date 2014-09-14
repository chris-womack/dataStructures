README FILE

PURPOSE: The files in this project are the solution for Assignment 2 that Ian wrote, with some memory bugs added. The purpose of this exercise is to run Valgrind on this code and find and fix the bugs. I have left everything alone in these files, except for the bugs I added, so Ian's comments about how to build this code and what the lines of code are doing should still be correct.

DISCLAIMER: All bugs that may or may not exist in my code are totally intentional and meant to be there for educational purposes. I swear.

DISCLAIMER: We do not expect that your submission for assignment 2 will look anything like this. This solution is a representation of what a fully modularized C++ program using classes 
might look like. It is meant to be a way for you to learn more about classes and see them in action in some working code.

READING TIPS:
I used a few different kinds of comments throughout these files:
// this is used after just a single line to provide a quick note of clarification
/// These are at the top of functions or confusing blocks of code and apply to the next few lines underneath

////These are where I put editorial notes that reveal part of my thought process or pose a question you should ask yourself while working through my code. These comments should be 
obvious because they break tabbing conventions and all start with NOTE:

Do not start with the Queue.cpp or Queue.h files, those are intentionally less commented than the others. Read the other files first. I recommend going in the following order:
Node.h
Node.cpp
Linked_List.h
Linked_List.cpp
Double_Linked_List.h
Double_Linked_List.cpp
Stack.h
Stack.cpp
Assignment2.cpp
Queue.h
Queue.cpp

This will let you start with the more heavily commented files and then get to the less commented ones later. As the code becomes less commented make sure you are still able to work 
through it and understand what it is doing! Pointer manipulation and classes are not the most inuitive things in the world so it is important to get a good understanding of both.

Throughout this file I used the "this" notation inside classes, for example:
"this->head" instead of just "head"
using this-> to reference an attribute is good practice because it ensures you are altering that specific object's copy of the variable, and not any other variable that might share 
that name. C++ allows global variable declarations (a variable declared outside any function that is accessible from any function) so you always have to be careful with scope, 
especially in the future when you might be working on a project with other programmers, as your variable names might not be unique.

BUILD INSTRUCTIONS:
I included the .exe with the source code files, so if you like you can just run that file and play with the program. If you are on a Linux system (such as the VM) you may need to give 
my pre-compiled .exe rights to execute. You can do this by opening a terminal, navigating to the directory the .exe is in, and typing in this command:

chmod +x Assignment2.exe

If you want to try building the code yourself you have to make sure *all* of the source code files are being compiled. In an IDE like codeblocks or xcode, this means including every file in one project before compiling. If you want to compile from the 
command line, you can do something like this:

g++ *.cpp

to tell the compiler to grab all .cpp files in the current directory and compile them together.

NOTE: This command will only work on OSX and Linux systems, as far as I know.
