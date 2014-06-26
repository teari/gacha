TARGET = gacha
CC = gcc
OBJS = main.o gacha.o card.o
INCLUDE = -I../include

.PHONY: all
.PHONY: clean

all:${TARGET}
	rm -f ${OBJS}
${TARGET}:${OBJS}
	${CC} -Wall -O2 -o ${TARGET} ${OBJS}
${OBJS}: %.o: %.c
	${CC} ${INCLUDE} -Wall -O2 -c $< -o $@

clean:
	rm -f ${TARGET} ${OBJS}
