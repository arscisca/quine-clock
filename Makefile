C_FLAGS = -std=c89 -include stdio.h -include unistd.h -include time.h

quine-clock: main.c
	gcc -o $@ ${C_FLAGS} $<