BIN = ResHook.so
CFLAGS := -Wall -g

all: $(BIN)

%.so: %.o
	ld -shared -m elf_i386 -o $@ $^ -ldl

%.o: %.c
	$(CC) $(CFLAGS) -fPIC -DPIC -m32 -c -o $@ $^

clean:
	rm -f $(BIN)
