TARGET_EXEC ?= program

BUILD_DIR ?= ./out
SRC_DIRS ?= ./src

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP -std=c++17
#$(pkg-config --cflags --libs sdl2)
#-Wall
LDFLAGS ?= -lm -std=c++17
CFLAGS = -Wall
#CXXFLAGS = -Wall -Wextra -Werror
CXXFLAGS = -Wall -std=c++17
CC = g++
CXX = g++

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
	./$(BUILD_DIR)/$(TARGET_EXEC)

# assembly
$(BUILD_DIR)/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	#$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean run auto parser $(BUILD_DIR)/$(TARGET_EXEC)

parser:
	#$(MKDIR_P) $(BUILD_DIR)/$(SRC_DIRS)/
	#cd $(SRC_DIRS); bison -d -y mdl.y; flex -I mdl.l; g++ $(CXXFLAGS) -c lex.yy.c y.tab.c; mv *.o ../$(BUILD_DIR)/$(SRC_DIRS)
	cd $(SRC_DIRS); bison -d -y mdl.y; flex -I mdl.l

clean:
	-$(RM) -r $(BUILD_DIR)
	-$(RM) -r .vscode
	#-$(RM) -r $(SRC_DIRS)/y.tab.c $(SRC_DIRS)/y.tab.h $(SRC_DIRS)/lex.yy.c $(SRC_DIRS)/lex.yy.o $(SRC_DIRS)/y.tab.o $(SRC_DIRS)/position.hh $(SRC_DIRS)/location.hh

cleanParser:
	-$(RM) -r $(SRC_DIRS)/y.tab.c $(SRC_DIRS)/y.tab.h $(SRC_DIRS)/lex.yy.c $(SRC_DIRS)/lex.yy.o $(SRC_DIRS)/y.tab.o $(SRC_DIRS)/position.hh $(SRC_DIRS)/location.hh

run:
	./$(BUILD_DIR)/$(TARGET_EXEC)

auto: $(BUILD_DIR)/$(TARGET_EXEC)
	./$(BUILD_DIR)/$(TARGET_EXEC)
#convert image.ppm image.png

memcheck:
	valgrind --leak-check=yes ./$(BUILD_DIR)/$(TARGET_EXEC)

memcheck_full:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(BUILD_DIR)/$(TARGET_EXEC)

bear: clean
	make -B

view:
	convert image.ppm image.png

-include $(DEPS)

MKDIR_P ?= mkdir -p
