NAME=miniRT
CC=cc
FLAGS=-Wall -Wextra -Werror
INCLUDES=-I ./includes/ -I lib/minilibx -Ilib/libft
 
OBJS := tuples/tuple.o tuples/point.o tuples/vector.o tuples/scalar.o \
		tuples/magnitude.o tuples/normalize.o tuples/dot.o \
		tuples/cross.o tuples/color.o matrix/matrix.o matrix/determinant.o \
		matrix/submatrix.o matrix/minor.o matrix/cofactor.o \
		matrix/inverse.o transform/translate.o transform/scale.o transform/rotate.o \
		transform/skew.o ray/ray.o objects/sphere.o ray/intersections.o \
		ray/hit.o ray/transform.o objects/transform.o tuples/normal_at.o \
		tuples/reflect.o light.o material.o
OBJS := $(addprefix sources/, $(OBJS))
LIBS := -lm -Llib/libft -lft -Llib/minilibx -lmlx_Linux -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS) sources/main.c
	make -C lib/minilibx
	make -C lib/libft
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS) sources/main.c $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) -g $(FLAGS) $(INCLUDES) $< -c -o $@

tests: $(OBJS)
	@$(CC) $(INCLUDES) -g -I ./tests/ $(OBJS) ./tests/main.c $(LIBS) -o test.out
	@./test.out

clean:
	rm -rf $(OBJS)

.PHONY: tests
