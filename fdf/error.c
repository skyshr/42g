/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:11:35 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/29 22:11:35 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	error(int error_num)
{
	if (error_num == 1)
		write(1, "Give one argument.\n", 19);
	else if (error_num == 2)
		write(1, "Cannot open file.\n", 18);
	else if (error_num == 3)
		write(1, "Fdf memory allocation error.\n", 29);
	else if (error_num == 4)
		write(1, "Map memory allocation error.\n", 29);
	else if (error_num == 5)
		write(1, "Img memory allocation error.\n", 29);
	else if (error_num == 6)
		write(1, "Cam memory allocation error.\n", 29);
	else if (error_num == 7)
		write(1, "Line memory allocation error.\n", 29);
	exit(error_num);
}
