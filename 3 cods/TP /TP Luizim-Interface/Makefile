CC = gcc
CFLAGS = -g -Wall  
GTKFLAGS = `pkg-config --cflags gtk+-3.0`
GTKFLAGS2 = `pkg-config --libs gtk+-3.0`
OBJS = gui.o entrada.o
TARGET = main
all: $(TARGET)

main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(GTKFLAGS) -o tp3 main.c $(GTKFLAGS2)
gui.o: GUI/gui.c GUI/gui.h entrada.h
	$(CC) $(CFLAGS) $(GTKFLAGS) -c GUI/gui.c $(GTKFLAGS)
entrada.o: entrada.c entrada.h GUI/gui.h
	$(CC) $(CFLAGS) $(GTKFLAGS) -c entrada.c $(GTKFLAGS)
clean:
	rm -rf $(OBJS) tp3
