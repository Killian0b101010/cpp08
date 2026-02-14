/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiteixei <kiteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 20:22:15 by kiteixei          #+#    #+#             */
/*   Updated: 2026/02/14 18:11:23 by kiteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <cstddef>
#include <exception>
#include <iterator>
#include <vector>
class Span {

private:
  std::vector<int> _vect;
  size_t _i;

public:
  Span();
  Span(const Span &other);
  Span(unsigned int i);
  Span &operator=(const Span &cpy);
  ~Span();
  void addNumber(int n);
  int getVec(int);

  template <typename iterator> void addNumber(iterator begin, iterator end) {
    if (std::distance(begin, end) + _vect.size() > _i)
      throw MaxSize();
    _vect.insert(_vect.end(), begin, end);
  }

  int longestSpan();
  int shortestSpan();
  int getSize();
  void ft_main_42(void);
  class NotEnoughtNumbers : public std::exception {
    const char *what() const throw() { return ("NotEnoughtNumbers"); }
  };
  class MaxSize : public std::exception {
    const char *what() const throw() { return ("Size to small"); }
  };
};
std::ostream &operator<<(std::ostream &s, Span &span);
#endif
