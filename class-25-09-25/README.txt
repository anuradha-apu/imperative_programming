class-file-list.c is an example file that contains a headed list whose head is statically defined.  It is as-is from class.
It has been cleaned out, split into 3 and eliminated in the build (Makefile)
It is here only for documentation purposes.

One more change in the build is that the list variable hd, is no longer a static variable but a pointer and the first cell is also dynamically allocated. This is a choice, I kept everything as uniformly pointers so I am not confused.

This file(class-file-list.c) is here only because you have seen it! It is eliminated and broken up into
   listlib.c: This is the main list functionality
   listlib.h: This is the header and contains all macros and declaration
   main.c: This is the wrapper and driver o check the list library

