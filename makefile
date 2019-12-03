CC  := gcc
OBJ := src/main.c src/interpreter.c src/utils.c

override CFLAGS += -g -O3 -lm

language:=	one-char

all: $(language)

$(language): $(OBJ)
	$(CC) $(OBJ) -o $(language) $(CFLAGS)

clean:
	rm -f $(OBJ)