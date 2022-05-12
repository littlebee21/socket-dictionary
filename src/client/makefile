TARGET = client
CC = gcc

CFLAGS= -g -Wall 
INC = -I ../../inc


OBJS= ./cmain.o ./ClientSocket.o ../public/dictolprotocol.o ../public/dictolpublic.o

all:$(TARGET)

%.o:%.c
	$(CC) -c $(INC) $(CFLAGS) $< -o $@

$(TARGET):$(OBJS)
	$(CC) -o $@ $^ 

clean:
	-rm ./$(OBJS) $(TARGET) -f
