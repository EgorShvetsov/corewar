/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_worker_lldi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:05:33 by limry             #+#    #+#             */
/*   Updated: 2020/07/02 16:05:33 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_server.h"

t_car		*op_lldi(t_car *car, t_worker *wk, int ar_3t_3l[6])
{
	int		offset_flag[2];
	int		v[3];

	offset_flag[0] = 1 + 1;
	offset_flag[1] = 1;
	v[0] = vm_op_get_val(wk, car, ar_3t_3l, offset_flag);
	offset_flag[0] += ar_3t_3l[3];
	v[0] = vm_op_get_val(wk, car, ar_3t_3l + 1, offset_flag);
	offset_flag[0] += ar_3t_3l[4];
	v[2] = vm_op_byte_to_32int(wk->map,
		car->position + offset_flag[0], ar_3t_3l[5]);
	car->reg[v[2] - 1] = vm_op_byte_to_32int(wk->map,
	car->position + (v[0] + v[1]), REG_SIZE);
	car->carry = car->reg[v[2] - 1] ? 0 : 1;
	if (wk->flag_log & LOG_OP || wk->gameid > 0)
		vm_op_log(car, v, ar_3t_3l, wk);
	return (car);
}
