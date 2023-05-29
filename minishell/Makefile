CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./libft  -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include -g3 -fsanitize=address
LDLIBS = -lft -lreadline
SRC_DIR = ./srcs
OBJ_DIR = ./objs
SOURCES = $(shell find $(SRC_DIR) -type f -name '*.c')
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))
EXECUTABLE = minishell

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(EXECUTABLE)
