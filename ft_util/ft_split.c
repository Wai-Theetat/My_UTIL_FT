/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:32:06 by tdharmar          #+#    #+#             */
/*   Updated: 2025/06/11 21:25:56 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_is_sep(char *sep, char c)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_word(char *str, char *sep)
{
	int	i;
	int	word_cnt;

	i = 0;
	word_cnt = 0;
	if (str == NULL || sep == NULL)
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_is_sep(sep, str[i]))
			i++;
		if (str[i] != '\0')
			word_cnt++;
		while (str[i] != '\0' && !ft_is_sep(sep, str[i]))
			i++;
	}
	return (word_cnt);
}

char	*ft_do_split(char *str, char *charset, int index)
{
	char	*res;
	int		i;
	int		len;

	i = index;
	len = 0;
	while (str[i] != '\0' && !ft_is_sep(charset, str[i]))
	{
		i++;
		len++;
	}
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = str[index + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		j;
	int		word_cnt;

	i = 0;
	word_cnt = ft_count_word(str, charset);
	res = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < word_cnt)
	{
		while (str[j] != '\0' && ft_is_sep(charset, str[j]))
			j++;
		res[i] = ft_do_split(str, charset, j);
		j += ft_strlen(res[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

