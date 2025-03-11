CC := gcc
AR := ar
CFLAGS ?= -Wall
CSOURCES := $(wildcard src/qxx/*.c)
CINCLUDE := include/
TARGET := libmmath.a

#
# all
#
$(TARGET): $(CSOURCES)
	$(CC) -c $(CSOURCES) $(CFLAGS) -I $(CINCLUDE)
	$(AR) rcs $(TARGET) *.o
	@rm -rf *.o


#
# clean
#
clean:
	@rm -rf *.out
	@rm -rf *.exe
	@rm -rf *.o
	@rm -rf *.a
	@rm -rf $(TARGET)
