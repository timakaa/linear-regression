CXX := g++
CXXFLAGS := -std=c++23 -Wall -Wextra

# Default target just prints help
run:
	@echo "Usage: make run FILE=path/to/file.cpp"

# Run target compiles and runs the given FILE
run:
	@if [ -z "$(f)" ]; then \
		echo "Error: You must specify FILE=path/to/file.cpp"; \
		exit 1; \
	fi
	$(CXX) $(CXXFLAGS) -o /tmp/runprog $(f) && /tmp/runprog
	@rm -f /tmp/runprog
