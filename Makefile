# a simple makefile for the source examples in this directory

C_OPTS = (-g -Wall)

first:
	@echo "first rule is the default, but all you get is this"

hello: hello.c
	gcc $(C_Opts) hello.c -o hello
