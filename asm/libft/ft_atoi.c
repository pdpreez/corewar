/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 07:14:41 by swilson           #+#    #+#             */
/*   Updated: 2018/06/01 11:52:43 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	if ((c == ' ') || (c == '\n') || (c == '\v') ||\
			(c == '\t') || (c == '\r') || (c == '\f'))
	{
		return (1);
	}
	return (0);
}

int			ft_atoi(const char *str)
{
	int		i;
	long	ret;
	int		sign;

	i = 0;
	ret = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		ret = ret * 10 + (str[i++] - '0');
		if ((ret < 0) && (sign == 1))
			return (-1);
		else if ((ret < 0) && (sign == -1))
			return (0);
	}
	return (ret * sign);
}
