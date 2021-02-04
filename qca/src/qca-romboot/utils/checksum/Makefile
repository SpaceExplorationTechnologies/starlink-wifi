
TARGET = ../bin/checksum	# for Linux environment
#TARGET = ../bin/checksum.exe	# for CygWin environment

all: $(TARGET)

$(TARGET): checksum.c
	gcc -o $(TARGET) $^

clean:
	-rm -f $(TARGET)
