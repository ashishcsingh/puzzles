CC = g++
CFLAGS = -Wall -pthread -g -std=c++0x
LOG =
LDFLAGS = -g -pthread
SOURCES = arrays.cpp arrays_test.cpp graphs.cpp graphs_test.cpp dynamic.cpp\
			 linkedlist.cpp linkedlist_test.cpp logics.cpp logics_test.cpp\
 			 main.cpp strings.cpp strings_test.cpp log.cpp dynamic_test.cpp\
          threads_test.cpp threads.cpp hashmaps_test.cpp hashmaps.cpp\
			 bits.cpp bits_test.cpp

OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = program

all: $(EXECUTABLE)

$(EXECUTABLE):	$(OBJECTS)
			$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o:	%.cpp
			$(CC) -c $(CFLAGS) $(LOG) $< -o $@

clean:
			rm *.o $(EXECUTABLE)
