
# Memwatch is Your Friend!!

Good programs deallocate all the memory that they allocate.  You write good programs.

Allocating and deallocate memory
```
  <type> *pointer = malloc(<number of bytes to allocate>)
  free(<pointer to dynamically allocated memory>)
```

Memwatch can help detect memory leaks and alike.  Here's how to set it up!

 - Create symbolic links in your directory to `memwatch.c` and `memwatch.h` .
```
    cd <some play directory>
    ln -s /home/class_projects/memwatch-2.71/memwatch.c memwatch.c
    ln -s /home/class_projects/memwatch-2.71/memwatch.h memwatch.h
```
The file system chases links; thus it is like having the files in that
directory, buy you don't end up with copies of the file all over the place.

 - Add `#include "memwatch.h"` to your code.

 - Add `-DMEMWATCH -DMW_STDIO` in your `Makefile` to all lines that invoke `gcc`.

A better approach is to add a makefile variable for this.
The `-D` acts like a `#define` and declares a variable.   The effect in this case is that memwatch's code is compiled in with your code.

 - Add `memwatch.o` to the link rule in your `Makefile`.
 
 - Compile and run your code. 

Memwatch will generate the file `memwatch.log` (try `less memwatch.log`).
If *unfreed bytes* totals 0, you are golden.  Otherwise, the file will tell you the lines where you allocated memory that didn't get freed.
