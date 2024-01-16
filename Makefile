# Compiler to use
CC = clang

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c11

# Build target executable
%: %.c
	$(CC) $(CFLAGS) -o $@ $^