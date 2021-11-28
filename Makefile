all: notify-while-running

CFLAGS=$(shell pkg-config --cflags --libs libnotify) -Wall -O2

PREFIX=/usr/local/bin

install: notify-while-running
	install -D --target-directory="$(PREFIX)/bin" $^
