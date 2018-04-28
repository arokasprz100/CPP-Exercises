CCX = g++
CXXFLAGS = -g -Wall -std=c++11

DEP_FLAGS = -MMD -MP

SRC = $(wildcard *.C)
OBJ = $(SRC:.C=.o)
DEP = $(SRC:.C=.d)

CXXFLAGS+=$(DEP_FLAGS)

TARG = regexp

all: $(TARG)

$(TARG): $(OBJ)
	$(CCX) $^$(LFLAGS) -o $@

.PHONY: clean

clean:
	rm $(OBJ) $(TARG) $(DEP)

class:
	read -p "Enter Class Name:" name; \
	touch $$name.C; \
	printf "#include \""$$name.h"\"\n" > $$name.C; \
	touch $$name.h; \
	printf "#ifndef "$$name"_h\n#define "$$name"_h\n\nclass "$$name"{\npublic:\n\nprivate:\n\n};\n\n\n\n#endif" > $$name.h

-include $(DEP)
