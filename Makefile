NAME=miniRT
CC=cc
FLAGS=-Wall -Wextra -Werror
INCLUDES=-I ./includes/
 
OBJS := tuples/tuple.o tuples/point.o tuples/vector.o tuples/scalar.o \
		tuples/magnitude.o tuples/normalize.o tuples/dot.o \
		tuples/cross.o tuples/color.o matrix/matrix.o matrix/determinant.o \
		matrix/submatrix.o matrix/minor.c matrix/cofactor.c \
		matrix/inverse.o
OBJS := $(addprefix sources/, $(OBJS))
LIBS := -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) -g $(FLAGS) $(INCLUDES) $< -c -o $@

tests: $(OBJS)
	@$(CC) $(INCLUDES) -g -I ./tests/ $(OBJS) ./tests/main.c $(LIBS) -o test.out
	@./test.out

.PHONY: tests
