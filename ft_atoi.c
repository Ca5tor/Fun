/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltacos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 21:54:43 by ltacos            #+#    #+#             */
/*   Updated: 2021/08/10 22:06:20 by ltacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	F1(char *str, int m, int vsego_ciferok);
int	strLen(char *str);

int	ft_atoi(char *str)
{
	int		i;
	int		j;
	int		minus;
	char	ciferki[9999];

	minus = 0;
	i = 0;
	j = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ciferki[j] = str[i];
		i++;
		j++;
	}
	ciferki[j] = '\0';
	return (F1(ciferki, minus, strLen(ciferki)));
}

int	strLen(char *str)
{
	int	vsego_ciferok;

	vsego_ciferok = 0;
	while (str[vsego_ciferok])
		vsego_ciferok++;
	return (vsego_ciferok);
}

int	F1(char *str, int m, int vsego_ciferok)
{
	int	i;
	int	rezultatik;

	i = 0;
	rezultatik = 0;
	if (str[i] == '0' && vsego_ciferok == 1)
		return (0);
	while (i < vsego_ciferok)
	{   
		rezultatik += (str[i] - '0');
		if (vsego_ciferok > 1 && i < vsego_ciferok - 1)
			rezultatik *= 10;
		i++;
	}
	if (m % 2 != 0)
		rezultatik *= -1;
	return (rezultatik);
}
