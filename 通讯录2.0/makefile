TARGET:=run
OBJS:=main.o func.o mystr.o funcAdd.o funcDelete.o funcFix.o funcSearch.o
CC:=gcc
CFLAGS:=-c -o
VPATH=./
$(TARGET):$(OBJS)
	$(CC) $(OBJS) -o $(TARGET)
%.o:%.c
	$(CC) $< $(CFLAGS) $@
clean:
	rm -rf *.o *.txt $(TARGET)
C_INLUCDE_PATH=./
export C_INCLUEDE_PATH