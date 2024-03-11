/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:05:10 by plang             #+#    #+#             */
/*   Updated: 2023/11/16 09:27:12 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (c >= 65 && c <= 90)
		return (8);
	if (c >= 97 && c <= 122)
		return (8);
	if (c >= 48 && c <= 57)
		return (8);
	else
		return (0);
}
