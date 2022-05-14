TARGET = server
CC = gcc

CFLAGS= -g -Wall 
INC = -I ../../inc

LDFLAGS= -lsqlite3
LIB = 

OBJS=  ./smain.o ../public/dictolprotocol.o  ../public/dictolpublic.o    \
./DAO/HistoryDao.o   ./DAO/UserDao.o   \
./Util/ServerSocket.o \
./SERVICE/HistoryService.o   ./SERVICE/UserService.o  ./SERVICE/WordService.o \
./Util/sqliteDriver.o \
./controller/ServerController.o


all:$(TARGET)

%.o:%.c
	$(CC) -c $(INC) $(CFLAGS) $< -o $@

$(TARGET):$(OBJS)
	$(CC) -o $@ $^  $(LDFLAGS) $(LIB)

clean:
	-rm ./$(OBJS) $(TARGET) -f
