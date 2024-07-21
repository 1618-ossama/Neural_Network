CC = gcc
CFLAGS = -Wall -Wextra -O2
DBGFLAGS = -g

SRC_FILES = main.c
EXEC_NAME = exe

all: $(EXEC_NAME)

$(EXEC_NAME): $(SRC_FILES)
	$(CC) $(CFLAGS) -o $(EXEC_NAME) $(SRC_FILES)

debug: $(EXEC_NAME)_debug

$(EXEC_NAME)_debug: $(SRC_FILES)
	$(CC) $(CFLAGS) $(DBGFLAGS) -o $(EXEC_NAME)_debug $(SRC_FILES)

clean:
	rm -f $(EXEC_NAME) $(EXEC_NAME)_debug

run: 
	./$(EXEC_NAME)

debug-run: 
	gdb ./$(EXEC_NAME)_debug
