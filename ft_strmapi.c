#include "libft.h"

static char	*ft_strmem(const char *s)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(s);
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	copy[len] = '\0';
	return (copy);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*result;

	if (!(result = ft_strmem(s)))
		return (NULL);
	i = 0;
	while (*s)
		*result++ = (*f)(i++, *s++);
	return result;
}
