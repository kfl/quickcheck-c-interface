
all: ebin/bsearch.c
	erl -make

ebin/bsearch.c: src/binsearch.c
	cp $< $@
