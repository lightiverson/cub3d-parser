NAME :=				../unit_tests
TEST_OBJECTS :=		obj/get_map_col_size.o \
					obj/get_map_size.o \
					obj/has_three_map_elements_min.o \
					obj/test_get_start_pos.o \
					obj/ll_to_a_map.o \
					obj/test_tokenizer.o \
					obj/test_has_single_start_position.o \
					obj/test_is_dot_cube_file.o \
					obj/test_is_sorted.o
CUB3D_OBJECTS :=	../obj/file_to_str.o \
					../obj/floodfill.o \
					../obj/free_breezy.o \
					../obj/ll_to_a_map.o \
					../obj/tokenize.o \
					../obj/utils.o \
					../obj/validate_input.o \
					../obj/validate_map.o
LIBFT :=			../libft
LDFLAGS ?=
CFLAGS ?=

all : $(NAME)

$(NAME) : $(TEST_OBJECTS) $(CUB3D_OBJECTS)
	$(CC) -o $(NAME) $(TEST_OBJECTS) -lcriterion $(CUB3D_OBJECTS) -L$(LIBFT) -l:libft.a $(LDFLAGS)

obj/%.o : %.c $(header)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

clean : 
	rm -rf obj

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re