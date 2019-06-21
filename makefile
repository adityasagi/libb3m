

CXX:=g++


FILES:=b3m.cpp gpio.cpp demo.cpp



SRC_DIR:=srcs

SRCS:= $(FILES:%.cpp=${SRC_DIR}/%.cpp)

OBJS:=$(FILES:%.cpp=%.o)

CFLAGS:= -I./libaqua/include -I./include/
CFLAGS+= -std=c++11

TARGET=b3m

############################################

all: ${TARGET}
	@echo "Target built"

${TARGET}: ${OBJS}
	${CXX} ${CFLAGS} -o $@ $^ 

%.o : %.cpp
	${CXX} ${CFLAGS} -c $<

clean:
	@rm -rf ${TARGET} ${OBJS}
