TARGET = client
CC = gcc

CFLAGS= -g -Wall 
INC = -I ../../inc


OBJS= ./cmain.o ./util/ClientSocket.o ../public/dictolprotocol.o ../public/dictolpublic.o \
	  ./view/view.o \
	  ./controller/controller.o

all:$(TARGET)

%.o:%.c
	$(CC) -c $(INC) $(CFLAGS) $< -o $@

$(TARGET):$(OBJS)
	$(CC) -o $@ $^ 

clean:
	-rm ./$(OBJS) $(TARGET) -f
