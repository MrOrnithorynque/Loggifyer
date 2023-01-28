CC		=	g++
CFLAGS	=	-I./includes -std=c++20 -Wall -pedantic -Werror

SRCS 	=	srcs/Logger.cpp
OBJS	=	$(SRCS:.cpp=.o)

HDRS	=	includes/PTP/Loggifyer/Logger.hpp

LIB_NAME=	libLoggifyer

all: libLoggifyer.a

cmake-build:
	mkdir -p build
	cd build && cmake .. && cmake --build .

# Build libLoggifyer.a library
libLoggifyer.a: srcs/Logger.cpp includes/PTP/Loggifyer/Logger.hpp
	$(CC) $(CFLAGS) -c ${SRCS} -o ${OBJS}
	ar rcs ${LIB_NAME}.a ${OBJS}

# Build testLoggifyer executable
testLoggifyer: tests/testMain.cpp ${LIB_NAME}.a
	$(CC) $(CFLAGS) -L. -lLoggifyer tests/testMain.cpp -o testLoggifyer


clean:
	rm -f *.o libLoggifyer.a testLoggifyer
	cd build && make clean

fclean: clean
	rm -rf build

.PHONY: clean all cmake-build libLoggifyer.a testLoggifyer
