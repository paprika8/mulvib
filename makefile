
ifdef MPI

FGCC:= mpif90
GCC:= mpicc
TARGET := mulvib_mpi.00.exe

SRC := $(wildcard source/*.src) $(wildcard source/mpi/*.src)
C := $(wildcard source/*.c) $(wildcard source/mpi/*.c)

else

FGCC:=gfortran
GCC:= gcc
TARGET := mulvib.00.exe

SRC := $(wildcard source/*.src) $(wildcard source/nompi/*.src)
C := $(wildcard source/*.c) $(wildcard source/nompi/*.c)

endif

F := $(SRC:.src=.f)

OBJ := $(F:.f=.fo) $(C:.c=.co)
OBJ := $(patsubst source/%,%,$(OBJ))
OBJ := $(addprefix object/,$(OBJ)) 



FLAGS := -O2 -fopenmp -fdefault-integer-8 
#CFLAGS := -g -c -DWINDOWS64 -DWINDOWSAZURE -m64 -fopenmp 
CFLAGS := -c -DLINUX64 -m64 -fopenmp 

INCLUDE := 
LIB := -fopenmp

#.SECONDARY: $(F) # for debug

.PHONY: all clean rebuild actvte

all: $(TARGET)

rebuild: clean all

clean:
	rm -rf ./object/
	rm -f ./$(TARGET)

$(TARGET): $(OBJ)
	$(FGCC) -o $(TARGET) $(OBJ) $(LIB)
	chmod +x ./$(TARGET)

%.f: %.src ./tools/actvte.exe
	MACHIN='*unx' SRCIN=$< CODEOUT=$@ ./tools/actvte.exe

object/%.co: source/%.c
	@mkdir -p $(dir $@)
	$(GCC) $(CFLAGS) $(INCLUDE) -c $< -o $@

object/%.fo: source/%.f
	@mkdir -p $(dir $@)
	$(FGCC) $(FLAGS) $(INCLUDE) -c $< -o $@

actvte: ./tools/actvte.exe

./tools/actvte.exe: ./tools/activate.c
	gcc -o ./tools/actvte.exe ./tools/activate.c 


#./scripts/mulvibmpi Imz_ccsdt_BTE_l0_23_a1