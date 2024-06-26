/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 00:39:36 by jokang            #+#    #+#             */
/*   Updated: 2022/05/30 16:07:12 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define BUFFER_SIZE (30)

t_queue	*set_queue_list(t_queue **queue, int fd)
{
	t_queue	**p;
	int		is_exist;

	p = queue;
	is_exist = FALSE;
	while (*p != FT_NULL)
	{
		if ((*p)->fd == fd)
		{
			is_exist = TRUE;
			break ;
		}
		p = &(*p)->next;
	}
	if (!is_exist)
	{
		*p = (t_queue *)malloc(sizeof(t_queue));
		(*p)->buffer_pa = ((char *)malloc(sizeof(char) * BUFFER_SIZE));
		(*p)->is_eof = FALSE;
		(*p)->num_count = 0;
		(*p)->last_count = 0;
		(*p)->fd = fd;
		(*p)->next = FT_NULL;
	}
	return (*p);
}

int	try_enqueue_fd(t_queue *queue_pa, int fd)
{
	int	ret;

	ret = read(fd, queue_pa->buffer_pa, BUFFER_SIZE);
	if (ret < 0)
		return (FALSE);
	if (ret == 0)
	{
		queue_pa->is_eof = TRUE;
		queue_pa->num_count = 0;
		return (FALSE);
	}
	if (ret < BUFFER_SIZE)
	{
		queue_pa->num_count = ret;
		queue_pa->last_count = ret;
		queue_pa->is_eof = TRUE;
	}
	else
		queue_pa->num_count = BUFFER_SIZE;
	return (TRUE);
}

int	dequeue_by_next_line(t_queue *queue_pa, t_table *head)
{
	char	*buffer;
	char	*string;

	while (head->next != FT_NULL)
		head = head->next;
	string = head->string_pa + head->capacity;
	buffer = queue_pa->buffer_pa;
	if (queue_pa->is_eof == TRUE)
		buffer += (queue_pa->last_count - queue_pa->num_count);
	else
		buffer += (BUFFER_SIZE - queue_pa->num_count);
	while (queue_pa->num_count != 0 && head->capacity != e_size)
	{
		*string++ = *buffer++;
		queue_pa->num_count--;
		head->capacity++;
		if (*(string - 1) == '\n' \
				|| (queue_pa->is_eof && queue_pa->num_count == 0))
		{
			return (TRUE);
		}
	}
	return (FALSE);
}

void	free_t_struct(t_queue **queue, t_table **lst, int fd)
{
	t_queue	*tmp;
	t_table	*p;

	while (queue != FT_NULL && *queue != FT_NULL)
	{
		if ((*queue)->fd == fd)
		{	
			tmp = *queue;
			*queue = (*queue)->next;
			free(tmp->buffer_pa);
			free(tmp);
			break ;
		}
		queue = &(*queue)->next;
	}
	while (lst != FT_NULL && *lst != FT_NULL)
	{
		free((*lst)->string_pa);
		p = (*lst)->next;
		free(*lst);
		*lst = p;
	}
}

char	*get_next_line(int fd)
{
	static t_queue	*queue_list = FT_NULL;
	t_queue			*queue_pa;
	t_table			*head;
	char			*result;

	queue_pa = set_queue_list(&queue_list, fd);
	if (queue_pa->num_count == 0 && !try_enqueue_fd(queue_pa, fd))
	{
		free_t_struct(&queue_list, FT_NULL, fd);
		return (FT_NULL);
	}
	head = build_table_malloc();
	while (dequeue_by_next_line(queue_pa, head) == FALSE)
	{
		if (queue_pa->num_count == 0)
			if (try_enqueue_fd(queue_pa, fd) == FALSE)
				break ;
		if (is_table_capacity_full(head) == TRUE)
			add_back_table_malloc(&head);
	}
	result = ft_strdup_table_malloc(head);
	free_t_struct(FT_NULL, &head, fd);
	if (queue_pa->is_eof && queue_pa->num_count == 0)
		free_t_struct(&queue_list, FT_NULL, fd);
	return (result);
}
