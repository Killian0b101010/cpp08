/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiteixei <kiteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:00:32 by kiteixei          #+#    #+#             */
/*   Updated: 2025/12/25 03:04:10 by kiteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>
#include <exception>

class Notfound : public std::exception {
public:
  const char *what() const throw() { return ("Not found"); }
};

template <typename T> typename T::iterator easyfind(T &c, int find) {
  typename T::iterator it;
  it = std::find(c.begin(), c.end(), find);
  if (it == c.end())
    throw Notfound();
  return (it);
}

#endif
