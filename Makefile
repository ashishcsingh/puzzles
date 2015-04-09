CC = g++
CFLAGS = -Wall -g -std=c++0x
LDFLAGS = -g
SOURCES = arrays.cpp arrays_test.cpp graphs.cpp graphs_test.cpp dynamic.cpp\
			 linkedlist.cpp linkedlist_test.cpp logics.cpp logics_test.cpp\
 			 main.cpp strings.cpp strings_test.cpp 

OBJECTS = $(SOURCES:.cpp=.o)
	EXECUTABLE = program

$(EXECUTABLE):	$(OBJECTS)
			$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o:	%.cpp
			$(CC) -c $(CFLAGS) $< -o $@

clean:
			rm *.o $(EXECUTABLE)
