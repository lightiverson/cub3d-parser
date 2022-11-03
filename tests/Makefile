NAME :=				../unit_tests
TEST_OBJECTS :=		obj/test_get_start_pos.o \
					obj/test_tokenizer.o \
					obj/test_has_multiple_start_positions.o \
					obj/test_has_start_position.o \
					obj/test_is_dot_cube_file.o \
					obj/test_is_sorted.o
CUB3D_OBJECTS :=	../obj/file_to_str.o \
					../obj/ll_to_two_d_array.o \
					../obj/tokenize.o \
					../obj/utils.o \
					../obj/validate_input.o \
					../obj/validate_map.o
LIBFT :=			../libft

all : $(NAME)

$(NAME) : $(TEST_OBJECTS) $(CUB3D_OBJECTS)
	$(CC) -o $(NAME) $(TEST_OBJECTS) -lcriterion $(CUB3D_OBJECTS) -L$(LIBFT) -l:libft.a $(LDFLAGS)

obj/%.o : %.c $(header)
	@mkdir -p $(dir $@)
	$(CC) -c -o $@ $<

clean : 
	rm -rf obj

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re