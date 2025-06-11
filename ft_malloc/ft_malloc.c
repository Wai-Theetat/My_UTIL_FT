/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:06:01 by tdharmar          #+#    #+#             */
/*   Updated: 2025/06/11 21:06:01 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc_header.h"

void    *ft_malloc(size_t size)
{
    void	*new;

	new = malloc(size);
	if (new == NULL)
		return (NULL);
	if (append(g_head, new) == NULL)
		free(new);
		return (NULL);
	return (new);
}

void	traverse_to_free_list(void)
{
	t_node	*current;

	current = g_head;
	while (current != NULL)
	{
		free(current->data);
		current = current->next;
	}
}

void	free_list(void)
{
	t_node	*tmp;

	while (g_head != NULL)
	{
		tmp = g_head;
		g_head = g_head->next;
		free(tmp);
	}
}

void	free_all(void)
{
	traverse_to_free_list();
	free_list();
	free(g_head);
}

int	init_head(void)
{
	g_head = append(g_head, NULL);
	if (g_head == NULL)
	{
		free_all();
		return (0);
	}
	return (1);
}