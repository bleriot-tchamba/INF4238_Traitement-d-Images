all:main

main: Sources/main.c
	gcc Sources/main.c Sources/fonctions.c -o Executable/main -lm
