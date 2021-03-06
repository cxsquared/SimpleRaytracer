CC = g++
CFLAGS = -c -g -Wall
LDFLAGS =
SRC_PATH = ./src
INC = -I ./inc
FILES = main.cpp vect.cpp ray.cpp camera.cpp color.cpp pointLight.cpp sphere.cpp plane.cpp
SOURCES = $(FILES:%.cpp=$(SRC_PATH)/%.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = ./bin/raytracer

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(INC) $< -o $@

clean:
	rm $(OBJECTS)
