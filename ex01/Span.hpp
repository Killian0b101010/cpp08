/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiteixei <kiteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 20:22:15 by kiteixei          #+#    #+#             */
/*   Updated: 2025/12/25 04:15:53 by kiteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SPAN_HPP
#define SPAN_HPP
#include <exception>
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
  int longestSpan();
  int shortestSpan();
  class IsInvalid : public std::exception {
    const char *what() const throw() { return ("Invalid list"); }
  };
  class MaxSize : public std::exception {
    const char *what() const throw() { return ("MaxSize"); }
  };
};
#endif
