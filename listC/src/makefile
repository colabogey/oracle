#!/usr/bin/make -f

PROJECT_NAME = oracle
ifeq (, $(PROJECT_BASE))
PROJECTS_BASE := ${HOME}/projects
PROJECT_BASE := ${PROJECTS_BASE}/${PROJECT_NAME}
endif

include $(PROJECT_BASE)/toplevelC.mk

CFLAGS = $(CFLAGSTOUSE) \
	-Wall -Wno-unknown-pragmas -Wno-sign-compare \
	-Wwrite-strings -Wno-unused \
	$(INCDIRS) $(DEFS)

LDFLAGS = 
LIBFLAGS = -lgtest -lgmock -L$(PROJECT_BIN_DIR)

SRC_DIR     = ./
BUILD_DIR   = ./build
BIN_DIR     = ./bin
INC_DIR		= ../include

$(shell mkdir -p $(PROJECT_BIN_DIR))
$(shell mkdir -p $(BIN_DIR))
$(shell mkdir -p $(BUILD_DIR))

include includes.mk

SRCS    = $(wildcard $(SRC_DIR)/*.c)
OBJS    = $(addprefix $(BUILD_DIR)/, $(notdir $(SRCS:.c=.o)))
IDEPS    = $(wildcard $(INC_DIR)/*.h)
MYLIBNAME	= liblistc.a

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(IDEPS)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

.PHONY: all
all: $(BIN_DIR)/$(MYLIBNAME)

$(BIN_DIR)/$(MYLIBNAME):	$(OBJS)
	ar cr $(BIN_DIR)/$(MYLIBNAME) $(OBJS)
	chmod a+x $(BIN_DIR)/$(MYLIBNAME)
	cp $(BIN_DIR)/$(MYLIBNAME) $(PROJECT_BIN_DIR)/$(MYLIBNAME)
	cp $(INC_DIR)/* $(LISTC_INTERFACE_DIR)

.PHONY: coverage
coverage:
	echo "nothing to be done for coverage"

.PHONY: tests
tests:
	echo "nothing to be done for tests"

.PHONY: testclean
testclean:
	echo "nothing to be done for testclean"

.PHONY: clean
clean:
	rm -f $(BUILD_DIR)/* $(BIN_DIR)/*

.PHONY: format
format:
	clang-format -i -style=file $(SRCS)
	clang-format -i -style="{IndentWidth: 4}" $(SRCS)
	clang-format -i -style=file $(IDEPS)
	clang-format -i -style="{IndentWidth: 4}" $(IDEPS)

