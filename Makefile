# Compiler
CC = clang

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-result -Wno-unused-value -Wno-unused-label -Wno-unused-const-variable -Wno-unused-macros -Wno-unused-function -Wno-unused-variable -Wno-unused-parameter -Wno-unused-but-set-parameter -Wno-unused-but-set-variable -Wno-unused-result -Wno-unused-value -Wno-unused-label -Wno-unused-const-variable -Wno-unused-macros

# Clang-format
CLANG_FORMAT = clang-format
CLANG_FORMAT_FLAGS = -i

# Targets
TARGET = main

all: $(TARGET)

main: main.c
	$(CC) $(CFLAGS) -o main main.c
	./main

out: main.c
	$(CC) $(CFLAGS) -DSHOULD_PRINT_ARRAY=1 -o main main.c
	./main > out.txt

format:
	$(CLANG_FORMAT) $(CLANG_FORMAT_FLAGS) *.c *.h

clean:
	rm -f $(TARGET) *.txt *.csv *.png

.PHONY: all out format clean
