/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiteixei <kiteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 20:22:10 by kiteixei          #+#    #+#             */
/*   Updated: 2025/12/25 04:18:18 by kiteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

Span::Span() {}

Span::Span(unsigned int i) : _i(i) {}

Span::Span(const Span &other) {
  _vect = other._vect;
  _i = other._i;
}

Span &Span::operator=(const Span &cpy) {

  if (this != &cpy) {
    _vect = cpy._vect;
    _i = cpy._i;
  }
  return (*this);
}

Span::~Span() {}

void Span::addNumber(int n) {
  if (_vect.size() > _i)
    throw MaxSize();
  _vect.push_back(n);
}

int Span::longestSpan() {

  std::vector<int> tmp = _vect;
  int max = tmp[0];
  int min = tmp[0];

  if (tmp.size() < 2)
    throw IsInvalid();

  for (size_t i = 1; i < tmp.size(); ++i) {
    if (tmp[i] > max)
      max = tmp[i];
    if (tmp[i] < min)
      min = tmp[i];
  }
  return (max - min);
}

int Span::shortestSpan() {

  if (_vect.size() < 2)
    throw IsInvalid();
  std::vector<int> tmp = _vect;
  std::sort(tmp.begin(), tmp.end());
  int shortest = tmp[1] - tmp[0];
  for (size_t i = 1; i < tmp.size() - 1; ++i) {
    int diff = tmp[i + 1] - tmp[i];
    if (diff < shortest)
      shortest = diff;
  }
  return (shortest);
}
