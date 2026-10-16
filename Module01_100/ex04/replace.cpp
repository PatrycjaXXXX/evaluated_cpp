/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 06:04:13 by psmolich          #+#    #+#             */
/*   Updated: 2026/10/16 14:28:26 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

//https://cplusplus.com/reference/string/string/npos/

void	replace(std::string& line,
				const std::string& s1, const std::string& s2)
{
	size_t	pos = 0;

	if (line.empty() || s1.empty())
		return;
	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos += s2.length();
	}
	return;
}