
DIRS = src

.PHONY: all
.PHONY: clean

all:
	for d in ${DIR}; do ${MAKE} -C $$d; done

clean:
	for d in ${DIRS}; do ${MAKE} -C $$d clean; done
