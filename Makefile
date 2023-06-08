
EXE = fractol

EXELIB	=	libftfractol.a

LIB 	=	libft/libft.a

SRC = ft_fractol.c set_init.c color.c render.c events.c actions.c \
	  mandelbrot.c sort.c julia.c


OBJ = $(SRC:.c=.o)

CC	= gcc

CFLAGS = -Wall -Wextra -fsanitize=address -g3

MLX = -lmlx -framework OpenGL -framework AppKit -L ./mlx 

COMP = $(CC) $(CFLAGS) $(LIB) $(MLX) 

RM = rm -f

all : $(EXE)

$(EXE) : $(OBJ)
	$(MAKE) bonus -C ./libft
	$(COMP) $(OBJ) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	$(RM) $(OBJ)
	$(MAKE) fclean -C ./libft

fclean : clean
	$(RM) $(EXE)

re : fclean all

.PHONY : all clean fclean re
