/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:21:42 by knovytsk          #+#    #+#             */
/*   Updated: 2018/02/24 13:42:58 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define RED_TEXT "\033[31;1m"
# define GREEN_TEXT "\033[32;1m"
# define YELLOW_TEXT "\033[33;1m"
# define BLUE_TEXT "\033[34;1m"
# define MAGNETA_TEXT "\033[35;1m"
# define CYAN_TEXT "\033[36;1m"
# define WHITE_TEXT "\033[37;1m"
# define EOC "\033[0m"

# define ABS(Value) (((Value) < 0) ? -(Value) : (Value))

typedef struct			s_fmt
{
	char				flags[5];
	int					width;
	int					precision;
	char				modifier;
	char				conversion;
}						t_fmt;

typedef struct			s_dbl
{
	unsigned long long	fr_part;
	unsigned long long	i_part;
	int					fr_size;
	int					zero_fr;
	int					i_size;
	int					exp;
	int					exp_size;
	int					dec_point;
	char				exp_sign;
	long double			num;
}						t_dbl;

typedef struct			s_time
{
	double				year;
	double				month;
	double				day;
	double				hour;
	double				min;
}						t_time;

typedef struct			s_out
{
	int					space;
	int					left_justify;
	int					minus_sign;
	int					plus_sign;
	int					prefix;
	int					apostr;
	int					zero_pad;
	int					pointer;
	int					precision;
	int					flags;
	int					value_len;
	int					out_len;
	char				*value;
	void				*arg;
	t_fmt				f;
	t_dbl				d;
	t_time				time;
}						t_out;

typedef void			(*t_flags)(t_out *out);
typedef void			(*t_analizer)(t_out *out, va_list arg, t_flags *flags);
int						ft_printf(const char *format, ...);
int						write_format(t_out *out, const char *format,
									va_list ar, int j);
int						output_length(const char *f, va_list ar, t_out *out);
void					output_analize(t_out *out, va_list ar);
t_out					p_initialise(void);
void					reset_values(t_out *out);
char					*f_int_base(long long int n, int base);
char					*f_unsigned_int(unsigned long long int n,
											int base);
int						check_float_values(t_out *out, long double arg,
											char conv);
char					*for_f_conv(t_out *out, long double num);
char					*for_e_conv(t_out *out, long double num);
char					*for_g_conv(t_out *out, long double num);
char					*for_a_conv(t_out *out, long double num);
void					get_exponent(t_out *out, long double num);
void					get_exponent_for_a(t_out *out, long double num);
void					separate_num(t_out *out, long double num);
void					separate_num_for_a(t_out *out, long double num);
void					i_part_size(t_out *out, unsigned long i_p, int base);
void					f_part_size(t_out *out, unsigned long f_p, int base);
void					g_size(t_out *out);
void					a_size(t_out *out);
void					check_dec_point(t_out *out, long double num, char conv);
void					exp_size(t_out *out, int exp, char conv);
void					round_fract_for_a(t_out *out);
int						round_parts_for_g(t_out *out);
size_t					ft_strlen(const char *s);
int						ft_atoi(const char *str);
void					ft_bzero(void *s, size_t n);
char					*ft_strdup(const char *s1);
int						ft_strcmp(const char *s1, const char *s2);
void					ft_strdel(char **as);
int						fmt_conversion(char f);
int						fmt_size_modifier(char f);
int						fmt_precision(char f);
int						fmt_field_width(char f);
int						fmt_flags(char f);
void					signed_conversions(t_out *out, va_list ar,
											t_flags *flags);
void					unsigned_conversions(t_out *out, va_list ar,
											t_flags *flags);
void					persentage(t_out *out, va_list ar, t_flags *flags);
void					pointer_conversions(t_out *out, va_list ar,
											t_flags *flags);
void					no_conversion(t_out *out, va_list ar, t_flags *flags);
void					char_conversions(t_out *out, va_list ar,
											t_flags *flags);
void					wchar_conversions(t_out *out, va_list ar,
											t_flags *flags);
void					f_conversion(t_out *out, va_list ar, t_flags *flags);
void					e_conversion(t_out *out, va_list ar, t_flags *flags);
void					g_conversion(t_out *out, va_list ar, t_flags *flags);
void					a_conversion(t_out *out, va_list ar, t_flags *flags);
void					int_ptr_conversion(t_out *out, va_list ar,
											t_flags *flags);
void					time_conversion(t_out *out, va_list ar, t_flags *flags);
void					non_print_conversion(t_out *out, va_list ar,
											t_flags *flags);
void					zero_padding(t_out *out);
void					sign_production(t_out *out);
void					apostr_production(t_out *out);
void					apostr_f_production(t_out *out);
void					space_production(t_out *out);
void					alternative_output(t_out *out);
void					manage_width(t_out *out, int length);
void					manage_min_precision(t_out *out);
void					manage_max_precision(t_out *out);
void					capital_hex(char *s);
void					put_marks(t_out *out, int i, char conv);
void					manage_operations(t_out *out, t_flags *flags);
void					manage_unsigned_modifier(t_out *out, int base);
void					manage_decimal_modidfier(t_out *out, int base);
int						get_value_len(t_out *out);
void					get_wide_char(t_out *out);
#endif
