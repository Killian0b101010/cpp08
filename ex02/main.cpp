/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiteixei <kiteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 19:59:42 by kiteixei          #+#    #+#             */
/*   Updated: 2025/12/30 01:42:21 by kiteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutanStack.hpp"
#include <iostream>
#include <stack>

int main() {
  std::cout << "===== BASIC STACK BEHAVIOR =====" << std::endl;

  MutanStack<int> mstack;
  mstack.push(10);
  mstack.push(20);
  mstack.push(30);

  std::cout << "Top: " << mstack.top() << std::endl;
  mstack.pop();
  std::cout << "Size after pop: " << mstack.size() << std::endl;

  std::cout << "\n===== ITERATOR (non-const) =====" << std::endl;

  MutanStack<int>::iterator it = mstack.begin();
  MutanStack<int>::iterator ite = mstack.end();

  for (; it != ite; ++it)
    std::cout << *it << std::endl;
 
  std::cout << "\n===== CONST ITERATOR =====" << std::endl;

  const MutanStack<int> const_stack = mstack;

  MutanStack<int>::const_iterator cit = const_stack.begin();
  MutanStack<int>::const_iterator cite = const_stack.end();

  for (; cit != cite; ++cit)
    std::cout << *cit << std::endl;

  std::cout << "\n===== MIX CONST / NON-CONST =====" << std::endl;

  MutanStack<int>::iterator it2 = mstack.begin();
  MutanStack<int>::const_iterator cit2 = mstack.begin();

  std::cout << "non-const iterator: " << *it2 << std::endl;
  std::cout << "const iterator: " << *cit2 << std::endl;

  *it2 = 42; // OK
  std::cout << "modified value (non-const): " << *it2 << std::endl;
  std::cout << "const still reads: " << *cit2 << std::endl;

  std::cout << "\n===== REVERSE ITERATOR =====" << std::endl;

  MutanStack<int>::reverse_iterator rit = mstack.rbegin();
  MutanStack<int>::reverse_iterator rite = mstack.rend();

  for (; rit != rite; ++rit)
    std::cout << *rit << std::endl;

  std::cout << "\n===== CONST REVERSE ITERATOR =====" << std::endl;


  MutanStack<int>::const_reverse_iterator crit = const_stack.rbegin();
  MutanStack<int>::const_reverse_iterator crite = const_stack.rend();

  for (; crit != crite; ++crit)
    std::cout << *crit << std::endl;

  std::cout << "\n===== STD::STACK COMPATIBILITY =====" << std::endl;

  std::stack<int> std_stack(mstack);
  std::cout << "std::stack top: " << std_stack.top() << std::endl;
  std::cout << "std::stack size: " << std_stack.size() << std::endl;

  std::cout << "\n===== EMPTY STACK ITERATION (EDGE CASE) =====" << std::endl;

  MutanStack<int> empty;
  if (empty.begin() == empty.end())
    std::cout << "Empty stack iterators are valid" << std::endl;

  std::cout << "\n===== ALL TESTS DONE =====" << std::endl;
  return 0;
}
