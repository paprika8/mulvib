TARGET := 
SRC := $(wildcard ./source/*.src) 
OBJS := $(SRC:.src=.o)

EXE := mulvib
VERNO := 00

include settings_make/make_pcunix 

.PHONY: actvte all clear

link:
	@mkdir -p object
	@chdir object
	$(LDR)   -o ../$(EXE).$(VERNO)   $(LDOPTS)    \
				$(OBJS) \
				$(BLAS)   $(VECTOR)  $(QUICHE)  $(LIBRARIES)

actvte:
	gcc -g -Wextra ./tools/activate.c -o ./tools/actvte.exe 
	chmod +x ./tools/actvte.exe
	