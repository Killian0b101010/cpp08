/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiteixei <kiteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 20:22:01 by kiteixei          #+#    #+#             */
/*   Updated: 2025/12/27 20:13:07 by kiteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <exception>
#include <iostream>
#include <sys/types.h>
#include <ctime>
#include <cstdlib>
int main() {
  srand(time (NULL));
  try {

    Span test(10000);
    test.addNumber(11);
    test.addNumber(21);
    std::vector<int> t;
    for (int i = 0; i < 3; i++)
        t.push_back(std::rand());

    test.addNumber(t.begin(), t.end());
    std::cout << test << std::endl;
    // test.addNumber(12);
    // try {
    // test.addNumber(12);
    // }
    // catch(...){}
    std::cout << "Shortest " << test.shortestSpan() << std::endl;
    std::cout << "Longest " << test.longestSpan() << std::endl;
  } catch (std::exception &s) {
    std::cerr << s.what() << std::endl;
  }
  return 0;
}




