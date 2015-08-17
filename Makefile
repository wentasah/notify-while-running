all: notify-while-running

CFLAGS=$(shell pkg-config --cflags --libs libnotify) -Wall -O2
