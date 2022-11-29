NAME :=		cub3d
VPATH :=	ft_strtol:\
			parse:\
			tokenize:\
			utils:\
			validate_tokens
HEADERS :=	ft_strtol.h \
			parse.h \
			tokenize.h \
			utils.h \
			validate_tokens.h \
			structs.h
MAIN :=		obj/main.o
OBJECTS :=	obj/ft_strtol_utils.o \
			obj/ft_strtol.o \
			obj/ll_to_a_map.o \
			obj/parse.o \
			obj/file_to_str.o \
			obj/tokenize.o \
			obj/prints.o \
			obj/utils.o \
			obj/floodfill.o \
			obj/validate_map_elements.o \
			obj/validate_non_map_elements.o
LDFLAGS ?=
CFLAGS ?=	-Wall -Wextra -Werror
LIBFT :=	./libft
UTESTS :=	tests

all : libft $(NAME)

libft:
	make -C $(LIBFT)

$(NAME) : $(MAIN) $(OBJECTS)
	$(CC) -o $(NAME) $(MAIN) $(OBJECTS) $(LIBFT)/libft.a $(LDFLAGS)

obj/%.o : %.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $<

utests: all
	make -C $(UTESTS)

clean :
	make clean -C $(LIBFT)
	make clean -C $(UTESTS)
	rm -rf obj

fclean : clean
	make fclean -C $(LIBFT)
	make fclean -C $(UTESTS)
	rm -f $(NAME)
	rm -f run_tests

re : fclean all

.PHONY: all clean fclean re libft utests