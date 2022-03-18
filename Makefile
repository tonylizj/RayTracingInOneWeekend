CXX=g++ 
CXXFLAGS=-std=c++17 -Wall -Wextra -O -g -MMD # use -MMD to generate dependencies
SOURCES=$(wildcard *.cpp)   # list of all .cc files in the current directory
OBJECTS=${SOURCES:.cpp=.o}  # .o files depend upon .cc files with same names
DEPENDS=${OBJECTS:.o=.d}   # .d file is list of dependencies for corresponding .cc file
EXEC=a.out

IMAGE=image.ppm

# First target in the makefile is the default target.
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXEC)
#	strip ${EXEC}

run:
	./$(EXEC) > $(IMAGE)

%.o: %.cpp 
	$(CXX) -c -o $@ $< $(CXXFLAGS) 

-include ${DEPENDS}

.PHONY: clean
clean:
	rm  -f $(OBJECTS) $(DEPENDS) $(EXEC)

fullclean:
	rm  -f $(OBJECTS) $(DEPENDS) $(EXEC) $(IMAGE)
