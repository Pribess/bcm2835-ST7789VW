CC = gcc

CFLAGS = -Wall
LDFLAGS = -lbcm2835

TARGET = st7789vw

INCLUDEDIR = ./src
SOURCES = $(wildcard *.c */*.c */*/*.c)
OBJECTS = $(SOURCES:.c=.o)


$(TARGET) : $(OBJECTS)
	$(CC) $(notdir $^) $(LDFLAGS) -o $@

%.o : %.c
	$(CC) -I$(INCLUDEDIR) -c $(CFLAGS) $< -o $(notdir $@)


.PHONY: all clean

all : $(TARGET)

clean:
	rm -f $(TARGET) *.o
