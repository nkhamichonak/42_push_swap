/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:43:57 by nkhamich          #+#    #+#             */
/*   Updated: 2024/12/04 11:11:58 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"

void	execute_silent(t_stack **a, t_stack **b, char *command);
bool	is_valid_instruct(char *command);
void	free_and_exit_checker(t_stack **a, t_list **instructions);
bool	is_empty(char *argv);

#endif
