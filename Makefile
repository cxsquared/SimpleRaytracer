CC = g++
CFLAGS = -c -Wall
LDFLAGS =
SRC_PATH = ./src
INC = -I ./inc
FILES = main.cpp vect.cpp ray.cpp camera.cpp color.cpp light.cpp
SOURCES = $(FILES:%.cpp=$(SRC_PATH)/%.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = raytracer

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(INC) $< -o $@

clean:
	rm $(OBJECTS)