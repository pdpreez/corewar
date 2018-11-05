/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 18:00:45 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/27 13:45:50 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		swap_bits(int *num)
{
	int		b0;
	int		b1;
	int		b2;
	int		b3;

	b0 = (*num & 0x000000ff) << 24;
	b1 = (*num & 0x0000ff00) << 8;
	b2 = (*num & 0x00ff0000) >> 8;
	b3 = (*num & 0xff000000) >> 24;
	*num = b0 | b1 | b2 | b3;
}

void		convert_header(t_header *header, int fd)
{
	swap_bits((int *)&(header->magic));
	swap_bits((int *)&(header->prog_size));
	write(fd, (header), sizeof(t_header));
}
