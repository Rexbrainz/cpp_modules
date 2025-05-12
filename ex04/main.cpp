/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:19:54 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/12 13:57:52 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

void	process_file(std::istream& in, std::ostream& out,
	   		std::string s1, std::string s2)
{
	std::string				line;
	std::string::size_type	pos;

	while(std::getline(in, line))
	{
		pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.size());
			line.insert(pos, s2);
			pos += s2.size();
		}
		out << line << std::endl;
	}
}

int	main(int argc, char **argv)
{
	std::ifstream	in;
	std::ofstream	out;
	std::string		file;

	if (argc != 4)
	{
		std::cout << "\033[31mError: Wrong input\033[0m";
		std::cout << std::endl;
		return (0);
	}
	file = argv[1];
	in.open(file);
	out.open(file + ".replace", std::ofstream::app);
	process_file(in, out, argv[2], argv[3]);
	in.close();
	out.close();
	return (0);
}
