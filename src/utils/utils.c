/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:01:20 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/12 22:35:32 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	decimalToHexadecimal(int decimalNum)
{
	int		i;
	int		remainder;
	char	hexNum[100];

	i = 0;
	while (decimalNum != 0)
	{
		remainder = decimalNum % 16;
		if (remainder < 10)
		{
			hexNum[i] = remainder + 48;
		}
		else
		{
			hexNum[i] = remainder + 55;
		}
		i++;
		printf("\n1");
		decimalNum /= 16;
	}
	printf("Hexadecimal number: ");
	i = 0;
	while (hexNum[i])
		printf("%c", hexNum[i++]);
}
