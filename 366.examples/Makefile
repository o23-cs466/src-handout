
# in the make file either use the full path 
#   MW_DIR = /home/class_projects/memwatch-2.71/
#   MW = -I$(MW_DIR) $(MW_DIR)/memwatch.c
# or symbolic links
#   ln -s /home/class_projects/memwatch-2.71/memwatch.h memwatch.h 
#   ln -s /home/class_projects/memwatch-2.71/memwatch.c memwatch.c 

CC = gcc
CFLAGS = $(MW) -Wall -g


default: memwatch-play

# the need to play with memwatch lead to 
# the need to play with '#define'


# test compilers -D option
.PHONY: dt
dt: 
	$(CC) $(CFLAGS) -o define-test define.c -DB=20
	@-./define-test
	$(CC) $(CFLAGS) -o define-test define.c -DB=42
	@-./define-test


# run just the preprocessor
.PHONY: run-cpp
run-cpp:
	$(CC) -E define.c -DB=20


.PHONY: pa
pa:
	$(CC) $(CFLAGS) pointers-n-arrays.c -o pa
	@-./pa

.PHONY: pc
pc:
	$(CC) $(CFLAGS) pointer-n-const.c -o pc
	@-./pc

.PHONY: mp
mp:
	$(CC) $(CFLAGS) malloc-play.c -o mp
	@-./mp
	@echo "try gdb mp"


memwatch-play: memwatch-play.o memwatch.o
	$(CC) $(CFLAGS) -o memwatch-play memwatch-play.o memwatch.o

memwatch-play.o: memwatch-play.c memwatch.h
	$(CC) $(CFLAGS) -c memwatch-play.c -DMEMWATCH -DMW_STDIO

memwatch.o: memwatch.c memwatch.h
	$(CC) $(CFLAGS) -c memwatch.c -DMEMWATCH -DMW_STDIO

memwatch.h:
	ln -s ~binkley/public_html/366/src/memwatch-2.71/memwatch.h

memwatch.c:
	ln -s ~binkley/public_html/366/src/memwatch-2.71/memwatch.c


.PHONY: mw
mw: memwatch-play
	@-/bin/rm memwatch.log
	-./memwatch-play
	less memwatch.log

.PHONY: clean
clean: 
	/bin/rm mp a.out memwatch-play memwatch-play.o memwatch.log memwatch.o src.ps xd pa pc mw define-test


.PHONY: src
src:
	more define.c static_size.c pointers-n-arrays.c pointer-n-const.c malloc-play.c memwatch-play.c string-main.c > all.c

