#include "./includes/libft.h"

char	*ft_strjoin_freemem(char **s1, char **s2)
{
	char *str;
	char *str1;

	if (s1 && s2)
	{
		str = (char *)malloc(sizeof(char)
			* (ft_strlen(*s1) + ft_strlen(*s2) + 1));
		if (str == NULL)
			return (NULL);
		str1 = str;
		str = ft_strcpy(str, (char *)*s1);
		str = ft_strcat(str, (char *)*s2);
		free(*s1);
		free(*s2);
		return (str);
	}
	return (0);
}
