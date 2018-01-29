#include "./includes/libft.h"

char	*ft_addletter(char *string, char letter)
{
	char	*str;
	char	*str_copy;

	str_copy = string;
	str = (char *)malloc(sizeof(char) + 1);
	str[0] = letter;
	str[1] = '\0';
	string = ft_strjoin(str_copy, str);
	free(str_copy);
	free(str);
	return (string);
}