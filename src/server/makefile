TARGET = server
CC = gcc

CFLAGS= -g -Wall 
INC = -I ../../inc


OBJS= ./ServerSocket.o ./smain.o ../public/dictolprotocol.o  ../public/dictolpublic.o

all:$(TARGET)

%.o:%.c
	$(CC) -c $(INC) $(CFLAGS) $< -o $@

$(TARGET):$(OBJS)
	$(CC) -o $@ $^ 

clean:
	-rm ./$(OBJS) $(TARGET) -f
