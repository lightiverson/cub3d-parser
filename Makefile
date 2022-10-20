NAME := cub3d
HEADERS :=	file_to_str.h \
			tokenize.h
MAIN :=		obj/main.o
OBJECTS :=	obj/file_to_str.o \
			obj/tokenize.o
LDFLAGS ?=
CFLAGS ?=	-Wall -Wextra -Werror
LIBFT :=	./libft

all : libft $(NAME)

libft:
	make -C $(LIBFT)

$(NAME) : $(MAIN) $(OBJECTS)
	$(CC) -o $(NAME) $(MAIN) $(OBJECTS) -L$(LIBFT) -l:libft.a $(LDFLAGS)

obj/%.o : %.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $<

clean :
	make clean -C $(LIBFT)
	rm -rf obj

fclean : clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re libft