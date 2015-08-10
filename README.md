# VDebugger
C/C++ Debugger

Hi, it's my first time using github to share my project.
This is a C/C++ Debugger aiming to create visualizations of data sturucture(like linkedlist, stack, queue and trees)
during debugging.

So far, it's only capable of some simple debugging functions, like single-stepping and break point.

Explanations on each source files:

mainwindow.h & mainwindow.cpp : GUI of the Debugger

vdbg.h & vdbg.cpp : Everything about debugging is contained in this two file, it's a class for debugging, you can use it to debug an 
executable, make break points, single step, and look at value of local/global variables of Debuggee, etc.

DebugThread.h & DebugThread.cpp : It's a thread class inherited from QThread, the mainwindow will start a new thread for debugging
so that it won't interfere with the GUI thread.
