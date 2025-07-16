/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:45:00 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/15 10:48:04 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
#define	FIXED_HPP

#include <iostream>
#include <string>

struct	Fixed
{
	Fixed(void);
	Fixed(const Fixed&);
	Fixed&	operator=(const Fixed&);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
  private:
	int					fpnValue;
	static const int	fBits;
};

#endif
