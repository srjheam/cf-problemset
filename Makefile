ifndef CONTEST
$(error CONTEST is not set)
endif

ifndef PROBLEM
$(error PROBLEM is not set)
endif

PROG = main
PROBLEMS_DIR = problems
TARGET_DIR = $(PROBLEMS_DIR)/$(PROBLEM)/$(CONTEST)$(PROBLEM)
TARGET = $(TARGET_DIR)/$(PROG)
SRC = $(TARGET_DIR)/$(CONTEST)$(PROBLEM).cpp
TESTS_DIR = $(TARGET_DIR)/tests
INPUTS_DIR = $(TESTS_DIR)/inputs
OUTPUTS_DIR = $(TESTS_DIR)/outputs
JUDGER = judger.sh

CC = g++
override CFLAGS += -std=c++17 -Wall -Wextra -Wconversion -pedantic -DONLINE_JUDGE

all : release

release : set-release build

debug : set-debug build

set-debug:
    override CFLAGS += -ggdb3 -fdiagnostics-color=always

set-release:
    override CFLAGS += -O2

build : $(SRC) $(TARGET)
	$(CC) -o $(TARGET) $(SRC) $(CFLAGS)

test : release
	@echo ""
	@sh $(JUDGER) -c $(CONTEST) -p $(PROBLEM)
