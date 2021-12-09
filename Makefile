name = printf
src =	ft_printf_bonus.c ft_flg_bonus.c ft_sys_bonus.c ft_digit_bonus.c main.c
obj = $(src:.c=.o)
rm = rm -f

$(name): $(obj)
	gcc -Wall -Wextra -Werror $(obj) -o $(name)

all: $(name)

%.o : %.c ft_printf_bonus.h
	gcc -Wall -Wextra -Werror -c $<

clean:
	$(rm) $(obj)

fclean: clean
	$(rm) $(name)

re: fclean $(name)

.PHONY: all clean re fclean
