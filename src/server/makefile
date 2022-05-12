TARGET = server
CC = gcc

CFLAGS= -g -Wall 
INC = -I ../../inc

LDFLAGS= -lsqlite3
LIB = 

OBJS= ./ServerSocket.o ./smain.o ../public/dictolprotocol.o  ../public/dictolpublic.o    \
./DAO/HistoryDao.o   ./DAO/UserDao.o   \
./SERVICE/HistoryService.o   ./SERVICE/UserService.o  \
./Util/sqliteDriver.o

all:$(TARGET)

%.o:%.c
	$(CC) -c $(INC) $(CFLAGS) $< -o $@

$(TARGET):$(OBJS)
	$(CC) -o $@ $^  $(LDFLAGS) $(LIB)

clean:
	-rm ./$(OBJS) $(TARGET) -f
