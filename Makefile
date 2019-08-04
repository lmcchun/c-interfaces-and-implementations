test_files := $(patsubst test/%.c,bin/%,$(wildcard test/*.c))

test: $(test_files)

bin/%: test/%.c obj/%.o
	$(CC) -o bin/$* test/$*.c obj/$*.o -Isrc

obj/%.o: src/%.c
	$(CC) -o obj/$*.o src/$*.c -c

clean:
	-rm bin/* obj/*

.PHONY: test clean

.PRECIOUS: obj/%.o
