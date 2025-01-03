#ifndef FT_PRINTF
#define FT_PRINTF

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

typedef struct s_format
{
    bool 			blank;
    bool 			hash;
    bool 			pad;
    bool 			leftAdjust;
    bool 			plus;
    int 			width;
    bool 			precision;
	int 			precision_width;
	char 			specifier;
	int				width_spaces;
	int				width_zeros;
	int				precsion_zeros;

	int 			ndi;
	unsigned int	nu;
	char*			str;
	char			c;
	void* 			p;
	bool			invalid;
	int				printed;
} t_format;

void	*ft_memset(void* s, int c, size_t n);
char*	ft_strdup(const char* s);
int		ft_strlen(char* s);
void	ft_putchar(char c);
int		nbr_length(long n, int sign);
int		ft_putnbr(int n);
int		ft_atoi(char* s);
void	parse_width(char* f, t_format* l);
void	parse_precision(char* f, t_format* l);
void	parse_specifier(char* f, t_format* l);
void	set_width_precision(t_format* l, bool sign, int arg_length, int hash);

void	apply_width_padding(t_format * l);
void	print_p_w(t_format * l, bool sign, bool plus_flag, bool blank_flag);
void	dynamic_zero_padding(bool valid_zero_padding, t_format* l, bool plus_flag, bool blank_flag);
bool	check_flag(char c, t_format* options);
void	parse_format(char* f, t_format* l);
void	init_format_list(t_format* list);
int		process_id(va_list ap, t_format* options);
void	dispatch(t_format* l, va_list ap);
int		ft_printf(const char * format, ...);

int		process_u(va_list ap, t_format* l);
int		ft_putnbr_u(unsigned int n);
void	zero_padding_u(t_format* l);
int		process_u(va_list ap, t_format* l);
void	print_p_w_u(t_format * l);

void	process_x(t_format* l, va_list ap);
void	zero_padding_x(t_format* l, char* hex);
void	print_p_w_x(t_format * l, char* hex);
char*	convert_hex(unsigned int n, char x);

void	process_p(t_format* l, va_list ap);
void	zero_padding_p(t_format* l, bool plus_flag, bool blank_flag, char* add);
void	print_p_w_p(t_format * l, bool plus_flag, bool blank_flag, char* add);

void	process_c(t_format* l, va_list ap);

void	process_s(t_format* l, va_list ap);
void	print_s(t_format* l, char* s);
int		strlength(char* s);
void	ft_putstr(char* s);


bool	is_invalid_at_f(char f);
bool	is_invalid_at_w(char* f);
bool	is_invalid_at_p(char* f);


#endif