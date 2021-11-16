/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:48:27 by jokang            #+#    #+#             */
/*   Updated: 2021/11/16 16:48:28 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_isdigit(int c)
{
	if (c < 0 || c > 255)
	{
		return (0);
	}	
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
