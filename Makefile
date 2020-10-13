NAME = ft_ls

COMP = gcc

FLAG = -Wall -Werror -Wextra

LIBINCLUDES = -I ./libft

SRC = 	ft_flag.c \
		ft_util.c \
		ft_not_printf.c \
		ft_not_printf_util_0.c \
		ft_not_printf_util_1.c \
		ft_error.c \
		ft_dir.c \
		ft_dir_sort.c \
		ft_dir_aux.c \
		ft_file.c \
		ft_file_aux.c \
		ft_file_sort.c \
		ft_file_data.c \
		ft_file_namehand.c \
		ft_memoryfree.c \
		main.c

OBJ = $(SRC:.c=.o)

INCLUDE = -I ./libft/ -I ./inc/

LIB = ./libft/libft.a
LIB_DIR = ./libft
LIB_RULE = $(addsuffix .lib, $(LIB_DIR))

all: $(LIB_RULE) $(NAME)

%.lib:
	@ make -sC $(LIB_DIR)

$(NAME) : $(LIB) $(OBJ)
	@ $(COMP) $(FLAG) -o $(NAME) $(OBJ) $(LIB)
	@ echo "\033[37;1;42m ft_ls done \033[0m"

%.o : ./src/%.c
	@ $(COMP) $(FLAG) -I ./libft/ -I ./inc/ -o $@ -c $<
	@ echo "\033[33m $< \033[0m"

$(LIB) :
	@ make -sC ./libft/

clean:
	@ rm -rf $(OBJ)
	@ make clean -C ./libft/

fclean: clean
	@ rm -rf $(NAME)
	@ make fclean -C ./libft/

re: fclean all

.PHONY: all clean fclean re
