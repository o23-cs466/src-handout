# Some C Examples

In this directory you will find some examples that I used in CS366.   In general I'm a big fan of writing lots of small examples to test out new features and new code constructs. 

define.c --  illustrates gcc's `-Dxx `   [ `make dt` ]
 
static_size.c -- motivates need for dynamic memory allocation [ `gcc static_size.c -DMAX_N=2000 ; a.out ` ]   
Try with ever larger values of `N`.
 
pointers-n-arrays.c -- recall the array index equation?  enjoy `3[a]` :) [ `make pa` ]

pointer-n-const.c  -- illustrates const pointers and pointees [ `make pc] ]

malloc-play.c -- malloc, structs, and common errors.  plus! the use of `gdb` [ `make mp' ]

memwatch.md-- basic memwatch explanation
memwatch-play.c -- illustrates three common allocation errors.   [ `make mw` ]
