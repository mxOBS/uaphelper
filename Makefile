CC ?= gcc
CFLAGS += -std=c99
PREFIX ?= /usr
DESTDIR ?= /

all: uauhelper

uauhelper: uauhelper.c
	$(CC) $(CFLAGS) -o $@ $<

clean: uauhelper
	rm -fv uauhelper

install: uauhelper
	install -v -m 4755 -D uauhelper $(DESTDIR)/$(PREFIX)/bin/uauhelper
