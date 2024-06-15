C_FLAGS = "-Wall"

quine-clock: main.c
	${CC} -o $@ ${C_FLAGS} $<