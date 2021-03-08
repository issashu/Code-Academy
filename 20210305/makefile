CC=gcc
FILE=test
LIB=head.c
LIB_OBJ=head.o

### unified cross-platform clean function
#checks for env var of win 
ifeq ($(OS),Windows_NT)
    RM=del /Q
    TARGET=test.exe
else
    RM=rm -f
    TARGET=test
endif

all:
	$(CC) $(FILE).c -o $(TARGET)

comp_lib:
	$(CC) -c -g $(LIB)

w_lib:
	$(CC) $(FILE).c -o $(TARGET) $(LIB_OBJ)

clean:
	$(RM) $(TARGET) $(LIB_OBJ)
