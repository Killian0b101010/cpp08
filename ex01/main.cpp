/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiteixei <kiteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 20:22:01 by kiteixei          #+#    #+#             */
/*   Updated: 2026/02/14 18:11:57 by kiteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <list>
#include <sys/types.h>

void ft_main_42(void) {
  std::cout << "Main 42" << std::endl;
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
}

void ft_main_add_number() {
  std::cout << "Main add number" << std::endl;
  std::srand(time(NULL));
  Span sp = Span(100000);
  sp.addNumber(14);
  sp.addNumber(13);
  std::vector<int> vec;
  for (int i = 0; i < 10000; i++)
    vec.push_back(std::rand());
  sp.addNumber(vec.begin(), vec.end());
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
  std::cout << sp << std::endl;
}

void ft_list_vector() 
{
  Span sp(100);
  std::list<int> myList;
  myList.push_back(10);
  myList.push_back(20);
  myList.push_back(30);
  std::vector<int> myVector;
  myVector.push_back(1);
  myVector.push_back(2);
  sp.addNumber(myList.begin(), myList.end());
  sp.addNumber(myVector.begin(), myVector.end());
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
}

void ft_deque_vector() 
{
  Span sp(100);
  std::deque<int> myDeQue;
  myDeQue.push_back(10);
  myDeQue.push_back(20);
  myDeQue.push_back(30);
  std::vector<int> myVector;
  myVector.push_back(1);
  myVector.push_back(2);
  sp.addNumber(myDeQue.begin(), myDeQue.end());
  sp.addNumber(myVector.begin(), myVector.end());
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
  std::cout << sp;
}
int main() {
  try {
    ft_main_42();
    ft_main_add_number();
    ft_list_vector();
    ft_deque_vector();

  } catch (std::exception &s) {
    std::cerr << s.what() << std::endl;
  }
}
