/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:18:21 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/13 07:54:15 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HARL_HPP
#define	HARL_HPP

#include <iostream>
#include <string>

struct Harl
{
	using	 PMF = void (Harl::*)(void);
	void	complain(std::string level);
 private:
	 void	debug(void);
	 void	info(void);
	 void	warning(void);
	 void	error(void);
};

#endif
