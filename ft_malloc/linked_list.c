/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:53:20 by tdharmar          #+#    #+#             */
/*   Updated: 2025/06/11 20:53:20 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc_header.h"

struct s_node	*create_node(void *new_data)
{
	struct s_node	*new_node;

	new_node = malloc(sizeof(struct s_node));
	if (new_node == NULL)
		return (NULL);
	new_node->data = new_data;
	new_node->next = NULL;
	return (new_node);
}

struct s_node *ft_append_node(struct s_node *head, void *new_data)
{
    struct s_node *new_node;
    struct s_node *last_node;

    last_node = head;
    new_node = ft_create_node(new_data);
    if (new_node == NULL)
        return (NULL);
    if (head == NULL)
    return (new_node);
    while (last_node->next != NULL)
    {
        last_node = last_node->next;
    }
    last_node->next = new_node;
    return (head);
}
