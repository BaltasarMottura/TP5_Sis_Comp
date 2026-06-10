.PHONY: all reader driver clean serve

CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -O2
APP_DIR := app
DRIVER_DIR := driver
READER := $(APP_DIR)/app
READER_SRC := $(APP_DIR)/app.c

all: reader driver

reader:
	$(CC) $(CFLAGS) -o $(READER) $(READER_SRC)

driver:
	$(MAKE) -C $(DRIVER_DIR)

clean:
	$(MAKE) -C $(DRIVER_DIR) clean
	rm -f $(READER)

serve: reader
	python3 web/server.py --reader "$(CURDIR)/$(READER)"
