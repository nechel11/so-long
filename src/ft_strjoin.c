/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zafar <nbyrd@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:52:35 by zafar             #+#    #+#             */
/*   Updated: 2022/01/18 11:50:26 by zafar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		dlina;
	int		j;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	dlina = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	res = (char *)malloc(sizeof(char) * dlina + 1);
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}	
