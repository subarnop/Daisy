CFLAGS = -lm -std=c99
OUTPUT = daisy

all: $(OUTPUT)

$(OUTPUT) :
	gcc -o $@ main.c function.c $(CFLAGS)

clean:
	rm -v $(OUTPUT)

