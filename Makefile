NAME		= cub3D
CC			=	cc -g
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
LIBFTPATH	=	./libft
MLXPATH		=	./minilibx
LIBA		=	$(LIBFTPATH)/libft.a
LIBMLXA		=	$(MLXPATH)/libmlx.a
MLXFLAG		=	-framework OpenGL -framework AppKit

OBJDIR		=	.objFiles

SRC			=	main			\
				check			\
				exit			\
				map_init		\
				ray_init		\
				mlx_utils		\
				move			\
				ray_manager		\
				ray				\
				read_map		\
				utils			\
				utils2

OBJ			= $(addprefix $(OBJDIR)/, $(SRC:=.o))

GREEN = \x1b[32;01m
RED = \x1b[31;01m
BLUE = \033[34;1m
RESET = \x1b[0m

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFTPATH)
	@make -C $(MLXPATH)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBA) $(LIBMLXA) $(MLXFLAG)
	@printf "$(GREEN) Executable named cub3d created$(RESET)\n"


$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFTPATH)
	@make clean -C $(MLXPATH)
	@$(RM) $(OBJDIR) $(OBJ)
	@printf "$(BLUE) deleting object files$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFTPATH)
	@printf "$(RED) deleting executable cub3d$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re