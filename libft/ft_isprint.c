/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 23:53:10 by lrandria          #+#    #+#             */
/*   Updated: 2021/05/17 00:52:36 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int 	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}