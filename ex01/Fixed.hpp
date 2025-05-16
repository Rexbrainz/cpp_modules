/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:45:00 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/15 13:56:14 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
#define	FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

struct	Fixed
{
	Fixed(void);
	Fixed(const int);
	Fixed(const float);
	Fixed(const Fixed&);
	~Fixed();
	Fixed&	operator=(const Fixed&);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
  private:
	int					fpnValue;
	static const int	fBits;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& rightOperand);

#endif
