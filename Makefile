NAME := cub3d
HEADERS :=	file_to_str.h \
			ft_strtol.h \
			ll_to_a_map.h \
			parse_floor_ceiling.h \
			structs.h \
			tokenize.h \
			utils.h \
			validate_map.h
MAIN :=		obj/main.o
OBJECTS :=	obj/file_to_str.o \
			obj/floodfill.o \
			obj/free_breezy.o \
			obj/ft_strtol.o \
			obj/ft_strtol_utils.o \
			obj/ll_to_a_map.o \
			obj/parse_floor_ceiling.o \
			obj/tokenize.o \
			obj/utils.o \
			obj/validate_input.o \
			obj/validate_map.o \
			obj/validate_non_map_elements.o
LDFLAGS ?=
CFLAGS ?=	-Wall -Wextra -Werror
LIBFT :=	./libft
UTESTS := tests

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