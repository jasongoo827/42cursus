#include <stdlib.h>
#include <stdio.h>
int t_strlen(char *str)
{
    int len;
    len = 0;
    while (*str != '\0')
    {
        len++ ;
        str++ ;
    }
    return (len);
}
char    *ft_strcat(char *dest, char *stc)
{
    int i;
    int j;
    i = 0;
    j = 0;
    while (dest[i] != '\0')
        i++ ;
    while (stc[j] != '\0')
        dest[i++] = stc[j++];
    dest[i] = '\0';
    return (dest);
}
int total_len(int size, char **strs, char *sep)
{
    int strs_len;
    int sep_len;
    int i;
    strs_len = 0;
    sep_len = t_strlen(sep);
    i = 0;
    if (size == 1)
        return (t_strlen(strs[0]) + 1);
    while (i < size - 1)
    {
        strs_len += t_strlen(strs[i]);
        strs_len += sep_len;
        i++ ;
    }
    strs_len = t_strlen(strs[i]);
    return (strs_len + 1);
}
char    *ft_strjoin(int size, char **strs, char *sep)
{
    int     total_length;
    int     i;
    char    *tmp;
    if (size == 0)
    {
        tmp = (char *) malloc (1);
        tmp[0] = 0;
        return (tmp);
    }
    total_length = total_len(size, strs, sep);
    tmp = (char *) malloc (sizeof(char) * total_length);
    if (!tmp)
        return (0);
    tmp[0] = '\0';
    i = 0;
    while (i < (size - 1))
    {
        tmp = ft_strcat(tmp, *(strs + i));
        tmp = ft_strcat(tmp, sep);
        i++ ;
    }
    tmp = ft_strcat(tmp, *(strs + i));
    return (tmp);
}

int main(void)
{
	// Exercise 03
	char *arr[9] = {"The", "Quick", "Brown", "Fox", "Jumps", "Over", "The", "Lazy", "Dog"};
	printf("%s\n", ft_strjoin(9, arr, ""));
	printf("%s\n", ft_strjoin(9, arr, " "));
	printf("%s\n", ft_strjoin(9, arr, "*"));
	printf("%s\n", ft_strjoin(9, arr, "!@#$%^&*()"));
	printf("%s\n", ft_strjoin(9, arr, "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"));
	printf("%s\n", ft_strjoin(5, arr, " "));
	printf("%s", ft_strjoin(0, arr, " "));
	return 0;
}