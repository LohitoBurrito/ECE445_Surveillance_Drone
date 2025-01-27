# Define variables for paths inside the container (default paths)
BOOST_DIR = /usr/include/boost
LIBCURL_DIR = /usr/include
JSON_CPP_DIR = /usr/include
NLOHMANN_JSON_DIR = /usr/include/nlohmann

# Define the compiler and flags
CXX = g++
CXXFLAGS = -I$(BOOST_DIR) -I$(LIBCURL_DIR) -I$(JSON_CPP_DIR) -I$(NLOHMANN_JSON_DIR)
LDFLAGS = -L$(LIBCURL_DIR) -lcurl -pthread

# Define the source files (adjusted if they are in a subdirectory like src/)
SRC = src/main.cpp src/commandControl.cpp

# Define the output executable
OUT = websocket

# Default target
all: $(OUT)

# Rule for compiling and linking the executable
$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDFLAGS) -o $(OUT)

# Clean target to remove the executable
clean:
	rm -f $(OUT)
