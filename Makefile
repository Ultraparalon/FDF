# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/28 16:58:58 by iseletsk          #+#    #+#              #
#    Updated: 2018/04/23 11:01:48 by vkaidans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_DIR :=		./sources/
OBJ_DIR :=		./objects/
INC_DIR :=		./includes/
LIB_DIR :=		./libraries/

SRC :=		main.c ft_draw_line.c ft_wizard.c ft_read_file.c ft_parser.c \
			ft_error.c ft_rainbow.c input.c ft_create_map.c ft_depth.c \
			ft_vector.c input_friendly.c

OBJ =		$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT =			$(LIBFT_DIR)libft.a
LIBFT_DIR :=	$(LIB_DIR)libft/
LIBFT_INC :=	$(LIBFT_DIR)includes/
LIBFT_FLAGS :=	-lft -L $(LIBFT_DIR)

CC_FLAGS :=		-Wall -Wextra -Werror

LINK_FLAGS :=	$(LIBFT_FLAGS)

HEADER_FLAGS :=	-I $(INC_DIR) -I $(LIBFT_INC)

CC :=		gcc

.SILENT:

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CC_FLAGS)  $(OBJ) $(LINK_FLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created fdf"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Cleaned fdf"

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	make fclean -C $(LIBFT_DIR)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fully cleaned fdf"

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re
