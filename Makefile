
all: ebin/bsearch.c
	erl -make

ebin/bsearch.c: src/bsearch.c
	cp $< $@
