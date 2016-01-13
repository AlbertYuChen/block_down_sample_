CC=g++
CFLAGS=-lpthread -lrt
SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=downsample
INCLUDES = -I ./zi_lib/external/include -I ./zi_lib/

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@
.cpp.o:
	$(CC) $< $(INCLUDES) $(CFLAGS) -c -o $@

.PHONY: clean
clean:
	rm *.o $(EXECUTABLE) 