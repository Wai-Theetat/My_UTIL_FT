/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_header.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:04:49 by tdharmar          #+#    #+#             */
/*   Updated: 2025/06/11 21:04:49 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_HEADER_H
# define FT_MALLOC_HEADER_H

# include <stdlib.h>

static t_node	*g_head = NULL;

typedef struct s_node
{
    void *data;
    struct s_node *next;
}   t_node;


//Linked List
struct s_node	*create_node(void *new_data);
struct s_node *ft_append_node(struct s_node *head, void *new_data);

//Malloc and Free

int     init_head(void);                //Initial Malloc
void    *ft_malloc(size_t size);
void	traverse_to_free_list(void);    //Free Data
void	free_list(void);                //Free Linked-List


#endif