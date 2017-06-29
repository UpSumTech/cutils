##########################################################################################
## variables and functions

THIS_MAKEFILE := $(lastword $(MAKEFILE_LIST))
THIS_DIR := $(shell 'pwd')
CC = gcc-5
INC = -Iinc

rfind = $(shell find '$(1)' -name '$(2)')

OUT = lib/readln.a
SRC_DIR := $(THIS_DIR)/src
OBJ_DIR := $(THIS_DIR)/obj
LIB_DIR := $(THIS_DIR)/lib

HEADER_FILES := $(call rfind, $(SRC_DIR), [^.]*.h)
SRC_FILES := $(call rfind, $(SRC_DIR), [^.]*.c)
OBJ_FILES := $(patsubst %.c, %.o, $(SRC_FILES))

##########################################################################################
## Top level targets
.DEFAULT_GOAL: $(OUT)
.PHONY: clean

$(OBJ_DIR)/%.o: $(SRC_FILES) $(HEADER_FILES)
    $(CC) -c $(INC) -o $@ $< $(CFLAGS)

$(OUT): $(OBJS)
    ar rvs $(OUT) $^

clean:
    rm -rf $(OBJ_DIR)/*.o $(OUT)
