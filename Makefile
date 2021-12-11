name = libftprintf.a
src =	ft_printf.c ft_put_d_bz.c ft_uns_hex_s.c
src_bonus = ft_printf_bonus.c ft_flg_bonus.c ft_sys_bonus.c ft_digit_bonus.c \
	ft_char_bonus.c ft_utoi_bonus.c ft_utox_bonus.c
obj = $(src:.c=.o)
obj_bonus = $(src_bonus:.c=.o)
rm = rm -f

$(name): $(obj)
	ar rc $(name) $(obj)

all: $(name)

%.o : %.c ft_printf.h
	gcc -Wall -Wextra -Werror -c  $<
%bonus.o : %bonus.c ft_printf_bonus.h
	gcc -Wall -Werror -Wextra -c $<

bonus: $(obj_bonus)
	ar rc $(name) $(obj_bonus)

clean:
	$(rm) $(obj) $(obj_bonus)

fclean: clean
	$(rm) $(name)

re: fclean $(name)

.PHONY: all clean re fclean bonus
