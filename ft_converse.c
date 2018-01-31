#include "ft_printf.h"

char	*ft_converse(t_printf *params, ...)
{
	if (params->converse == '%')
		ft_converse_per(params,);
	if (params->converse == 's' || params->converse == 'S')
		ft_converse_string();
	if (params->converse == 'i' || params->converse == 'd' || params->converse == 'u' 
		|| params->converse == 'D' || || params->converse == 'U')
		ft_converse_numb();
	if (params->converse == 'o' || params->converse == 'O')
		ft_converse_oct();
	if (params->converse == 'x' || params->converse == 'X' || params->converse == 'p')
		ft_converse_hex();
	if (params->converse == 'c' || params->converse == 'C')
		ft_converse_char();
}