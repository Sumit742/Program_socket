# Automatically get the source file (assumes only 1 .c file)
SRC := $(wildcard *.c)

# Extract the name without extension
EXE := $(basename $(SRC))

# Default target
all: $(EXE)

# Rule to build executable
$(EXE): $(SRC)
	gcc $(SRC) -o $(EXE)

# Clean generated files
clean:
	rm -f $(EXE)
# Automatically find all C files
SRC := $(wildcard *.c)

# Generate executable names (basename without .c)
EXE := $(patsubst %.c,%,$(SRC))

# Default target: build all executables
all: $(EXE)

# Rule to build any single executable
%: %.c
	gcc $< -o $@

# Run a particular executable
# Usage: make run tcp_client
run:
	@if [ "$(word 2,$(MAKECMDGOALS))" = "" ]; then \
		echo "Error: Specify executable to run, e.g., make run tcp_client"; \
	else \
		prog=$(word 2,$(MAKECMDGOALS)); \
		if [ -f "$$prog" ]; then \
			echo "Running $$prog..."; \
			./$$prog; \
		else \
			echo "Executable $$prog not found. Build it first!"; \
		fi \
	fi

# Run all executables
run_all:
	@for prog in $(EXE); do \
		echo "Running $$prog..."; \
		./$$prog; \
		echo; \
	done

# Clean all executables
clean:
	rm -f $(EXE)

