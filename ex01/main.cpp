/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiteixei <kiteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 20:22:01 by kiteixei          #+#    #+#             */
/*   Updated: 2025/12/25 04:19:19 by kiteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <exception>
#include <iostream>
// int main() {
//   try {
//
//     Span sp = Span(1123);
//     sp.addNumber(1011);
//     sp.addNumber(1001);
//     sp.addNumber(1022);
//     std::cout << "Shortest " << sp.shortestSpan() << std::endl;
//     std::cout << "Longest " << sp.longestSpan() << std::endl;
//   } catch (std::exception &s) {
//     std::cerr << s.what() << std::endl;
//   }
//   return 0;
// }

#include "Span.hpp"
#include <cstdlib>
#include <iostream>

int main() {
  std::cout << "===== TEST 1 : Cas simple =====" << std::endl;
  {
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan()
              << std::endl; // attendu: 2
    std::cout << "Longest span : " << sp.longestSpan()
              << std::endl; // attendu: 14
  }

  std::cout << "\n===== TEST 2 : Doublons =====" << std::endl;
  {
    Span sp(5);
    sp.addNumber(42);
    sp.addNumber(42);
    sp.addNumber(42);
    sp.addNumber(42);
    sp.addNumber(42);

    std::cout << "Shortest span: " << sp.shortestSpan()
              << std::endl; // attendu: 0
    std::cout << "Longest span : " << sp.longestSpan()
              << std::endl; // attendu: 0
  }

  std::cout << "\n===== TEST 3 : Deux valeurs =====" << std::endl;
  {
    Span sp(2);
    sp.addNumber(100);
    sp.addNumber(50);

    std::cout << "Shortest span: " << sp.shortestSpan()
              << std::endl; // attendu: 50
    std::cout << "Longest span : " << sp.longestSpan()
              << std::endl; // attendu: 50
  }

  std::cout << "\n===== TEST 4 : Pas assez de valeurs =====" << std::endl;
  {
    Span sp(1);
    sp.addNumber(10);

    try {
      sp.shortestSpan();
      std::cout << "ERROR: shortestSpan should throw" << std::endl;
    } catch (std::exception &e) {
      std::cout << "Exception shortestSpan OK" << std::endl;
    }

    try {
      sp.longestSpan();
      std::cout << "ERROR: longestSpan should throw" << std::endl;
    } catch (std::exception &e) {
      std::cout << "Exception longestSpan OK" << std::endl;
    }
  }

  std::cout << "\n===== TEST 5 : Dépassement de capacité =====" << std::endl;
  {
    Span sp(3);
    sp.addNumber(1);
    sp.addNumber(2);
    sp.addNumber(3);

    try {
      sp.addNumber(4);
      std::cout << "ERROR: addNumber should throw" << std::endl;
    } catch (std::exception &e) {
      std::cout << "Exception capacity OK" << std::endl;
    }
  }

  std::cout << "\n===== TEST 6 : 10 000 valeurs ordonnées =====" << std::endl;
  {
    Span sp(10000);
    for (int i = 0; i < 10000; i++)
      sp.addNumber(i * 2);

    std::cout << "Shortest span: " << sp.shortestSpan()
              << std::endl; // attendu: 2
    std::cout << "Longest span : " << sp.longestSpan()
              << std::endl; // attendu: 19998
  }

  std::cout << "\n===== TEST 7 : 10 000 valeurs aléatoires =====" << std::endl;
  {
    Span sp(10000);
    srand(42);

    for (int i = 0; i < 10000; i++)
      sp.addNumber(rand());

    int shortest = sp.shortestSpan();
    int longest = sp.longestSpan();

    std::cout << "Shortest span: " << shortest << std::endl; // >= 0
    std::cout << "Longest span : " << longest
              << std::endl; // valeur élevée, cohérente

    if (shortest < 0)
      std::cout << "ERROR: shortestSpan negative" << std::endl;
  }

  std::cout << "\n===== FIN DES TESTS =====" << std::endl;
  return 0;
}
