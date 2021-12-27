name = libftprintf.a
src =	src_base/ft_printf.c src_base/ft_put_d_bz.c src_base/ft_uns_hex_s.c
src_bonus = src_bonus/ft_printf_bonus.c src_bonus/ft_flg_bonus.c src_bonus/ft_syslen_bonus.c src_bonus/ft_digit_bonus.c \
	src_bonus/ft_char_bonus.c src_bonus/ft_utoi_bonus.c src_bonus/ft_utox_bonus.c src_bonus/ft_void_bonus.c src_bonus/ft_string_bonus.c \
	src_bonus/ft_systrans_bonus.c src_bonus/ft_sysdup_bonus.c src_bonus/ft_sysnb_bonus.c src_bonus/ft_syslen_bonus.c
obj = $(src:.c=.o)
obj_bonus = $(src_bonus:.c=.o)
rm = rm -f

$(name): $(obj)
	ar rcs $(name) $?

all: $(name)

%.o : %.c ft_printf.h
	gcc -Wall -Wextra -Werror -c $< -o $@
%bonus.o : %bonus.c ft_printf_bonus.h
	gcc -Wall -Werror -Wextra -c $< -o $@

bonus: clean fclean
	@make obj="$(obj_bonus)" all

clean:
	$(rm) $(obj) $(obj_bonus)

fclean: clean
	$(rm) $(name)

re: fclean all

.PHONY: all clean re fclean bonus
