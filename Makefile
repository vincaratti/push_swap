NAME		=	push_swap	
CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror -I $(INCLUDE)
SRCDIR		=	./src/
OBJDIR		=	./obj/
INCLUDE		=	./include/

SRC		=	ps_atoi.c	\
			ps_split.c	\
			movements_1.c 	\
			tools.c		\
			parser.c	\
			push_swap.c
					
OBJ		=	${addprefix $(OBJDIR), $(SRC:%.c=%.o)}


# ===== #


all:			$(NAME)

$(NAME):		$(OBJDIR) $(OBJ)
				@make -C libft/
				$(CC) $(CFLAGS) $(OBJ) -L libft -lft -o $(NAME)

clean:
				rm -rf $(OBJDIR)
				@make -C libft/ clean

fclean:			
				rm -rf $(NAME) $(OBJDIR)
				@make -C libft/ fclean

re:				fclean all

$(OBJDIR)%.o:	$(SRCDIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
				@mkdir -p $(OBJDIR)

.PHONY:			re clean fclean objs all
