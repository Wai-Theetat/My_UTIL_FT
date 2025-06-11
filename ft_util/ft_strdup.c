/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:22:39 by tdharmar          #+#    #+#             */
/*   Updated: 2025/06/01 13:32:05 by tdharmar         ###   ########.fr       */
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

char	*ft_strcpy(char *src, char *des)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		des[i] = src[i];
		i++;
	}
	des[i] = '\0';
	return (des);
}

char	*ft_strdup(char *src)
{
	int		size;
	char	*dest;

	size = ft_strlen(src);
	dest = (char *)malloc(size + 1);
	if (dest == NULL)
		return (NULL);
	ft_strcpy(src, dest);
	return (dest);
}

/*#include <stdio.h>
int	main(void)
{
	char	*src;
	char	*dup;

	src = "THIS IS SOURCE TXT FOR DUP";
	dup = NULL;

	printf("Before : %s\n", dup);
	dup = ft_strdup(src);
	printf("After  : %s\n", dup);
	free(dup);
}*/
