/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 11:32:37 by psmolich          #+#    #+#             */
/*   Updated: 2026/09/12 14:55:01 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Goal: Use C++ manner

If no arguments are provided: print "* LOUD AND UNBEARABLE FEEDBACK NOISE *" on standard output

for every argument provided print it on standard output in upper case
write new line character at the end of the output

important article: https://www.digitalocean.com/community/tutorials/string-uppercase-lowercase-c-plus-plus
The most idiomatic and powerful method is to use the std::transform algorithm from the <algorithm> header. -> prohibited

to acces manual: man 3cpp toupper
why static_cast: https://en.cppreference.com/cpp/string/byte/toupper

I decided to keep this exercise focused on what I think it is actually trying to teach: handling program arguments, strings,
and converting characters to uppercase.
Since this is an early exercise, I intentionally did not implement Unicode/UTF-8 character handling.
The solution uses std::toupper() on individual bytes/characters and therefore does not perform Unicode case conversion.
*/

#include <iostream>
#include <string> 
#include <cctype>

std::string toUpper(std::string s)
{
    for (std::string::size_type i = 0; i < s.length(); i++)
        s[i] = std::toupper(static_cast<unsigned char>(s[i]));

    return(s);
}

 int main(int ac, char **av)
 {
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    
    for (int i = 1; i < ac; i++)
        std::cout << toUpper(av[i]);
    std::cout << std::endl;
    
    return (0);
 }