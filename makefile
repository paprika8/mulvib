SRC := $(wildcard source/*.src)

F := $(SRC:.src=.f)
C := $(wildcard source/*.c)

OBJ := $(F:.f=.fo) $(C:.c=.co)
OBJ := $(patsubst source/%,%,$(OBJ))
OBJ := $(addprefix object/,$(OBJ)) 

TARGET := mulvib.00.exe

FLAGS := -O2 -fdefault-integer-8 -fopenmp
CFLAGS := -c -DWINDOWS64 -DWINDOWSAZURE -m64 -fopenmp
#CFLAGS := -c -DLINUX64 -m64

INCLUDE := 
LIB := -fopenmp

#.SECONDARY: $(F) # for debug

.PHONY: all clean rebuild

all: $(TARGET)

rebuild: clean all

clean:
	rm -rf ./object/
	rm -f ./$(TARGET)

$(TARGET): $(OBJ)
	gfortran -o $(TARGET) $(OBJ) $(LIB)
	chmod +x ./$(TARGET)

%.f: %.src
	MACHIN='*unx' SRCIN=$< CODEOUT=$@ ./tools/actvte.exe

object/%.co: source/%.c
	@mkdir -p $(dir $@)
	gcc $(CFLAGS) $(INCLUDE) -c $< -o $@

object/%.fo: source/%.f
	@mkdir -p $(dir $@)
	gfortran $(FLAGS) $(INCLUDE) -c $< -o $@
