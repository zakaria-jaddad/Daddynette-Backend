package main

var Days = map[string][]string{
	"C00": {
		"ft_putchar.c",
		"ft_print_alphabet.c",
		"ft_print_reverse_alphabet.c",
		"ft_print_numbers.c",
		"ft_is_negative.c",
		"ft_print_comb.c",
		"ft_print_comb2.c",
		"ft_putnbr.c",
		"ft_print_combn.c",
	},
	"C01": {
		"ft_ft.c",
		"ft_ultimate_ft.c",
		"ft_swap.c",
		"ft_div_mod.c",
		"ft_ultimate_div_mod.c",
		"ft_putstr.c",
		"ft_strlen.c",
		"ft_rev_int_tab.c",
		"ft_sort_int_tab.c",
	},
	"C02": {
		"ft_strcpy.c",
		"ft_strncpy.c",
		"ft_str_is_alpha.c",
		"ft_str_is_numeric.c",
		"ft_str_is_lowercase.c",
		"ft_str_is_uppercase.c",
		"ft_str_is_printable.c",
		"ft_strupcase.c",
		"ft_strlowcase.c",
		"ft_strcapitalize.c",
		"ft_strlcpy.c",
		"ft_putstr_non_printable.c",
		"ft_print_memory.c",
	},
	"C03": {
		"ft_strcmp.c",
		"ft_strncmp.c",
		"ft_strcat.c",
		"ft_strncat.c",
		"ft_strstr.c",
		"ft_strlcat.c",
	},
	"C04": {
		"ft_strlen.c",
		"ft_putstr.c",
		"ft_putnbr.c",
		"ft_atoi.c",
		"ft_putnber_base.c",
		"ft_atoibase.c",
	},
	"C05": {
		"ft_iterative_factorial.c",
		"ft_recursive_factorial.c",
		"ft_iterative_power.c",
		"ft_recursive_power.c",
		"ft_fibonacci.c",
		"ft_sqrt.c",
		"ft_is_prime.c",
		"ft_find_next_prime.c",
		"ft_the_ten_queens_puzzle.c",
	},
	"C06": {
		"ft_print_program_name.c",
		"ft_print_params.c",
		"ft_rev_params.c",
		"ft_sort_params.c",
	},
	"C07": {
		"ft_strdup.c",
		"ft_range.c",
		"ft_ultimate_range.c",
		"ft_strjoin.c",
		"ft_convert_base.c",
		"ft_split.c",
	},
	"C08": {
		"ft.h",
		"ft_boolean.h",
		"ft_abs.h",
		"ft_point.h",
		"ft_strv_to_tab.c",
		"ft_show_tab.c",
	},
	"C09": {"libft", "Makefile", "ft_split.c"},
}

func GetDaysMap() map[string][]string {
	return Days
}

func GetDayExercises(dayname string) []string {
	return Days[dayname]
}
