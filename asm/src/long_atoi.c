/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 13:40:48 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/27 13:41:46 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					value(int *p, const char *str)
{
	int s;

	while ((str[*p] == ' ' || str[*p] == '\t' || str[*p] == '\n' \
				|| str[*p] == '\f' || str[*p] == '\r' || str[*p] == '\v') \
			&& str[*p] != '\0')
		*p = *p + 1;
	s = 1;
	if (str[*p] == '+' || str[*p] == '-')
	{
		if (str[*p] == '-')
			s = -1;
		*p = *p + 1;
	}
	return (s);
}

long long			long_atoi(const char *str)
{
	int			i;
	long long	n;
	int			sign;

	i = 0;
	sign = value(&i, str);
	n = 0;
	while (str[i] == '0')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * sign);
}
