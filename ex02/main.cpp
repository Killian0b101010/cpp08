/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiteixei <kiteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 19:59:42 by kiteixei          #+#    #+#             */
/*   Updated: 2026/02/14 18:23:53 by kiteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <list>
#include "MutantStack.hpp"

void ft_main_42() {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);
}

void test_basic_stack()
{
    std::cout << "basic test" << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << "top: " << mstack.top() << "\n";

    mstack.pop();

    std::cout << "size after pop: " << mstack.size() << "\n\n";
}

void test_iteration()
{
    std::cout << "iteration test" << std::endl;

    MutantStack<int> mstack;

    for (int i = 1; i <= 5; i++)
        mstack.push(i * 10);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    while (it != ite)
    {
        std::cout << *it << "\n";
        ++it;
    }
    std::cout << "\n";
}

void test_copy_constructor()
{
    std::cout << "copy constructor\n";

    MutantStack<int> original;
    original.push(1);
    original.push(2);
    original.push(3);

    MutantStack<int> copy(original);

    while (!copy.empty())
    {
        std::cout << copy.top() << "\n";
        copy.pop();
    }
    std::cout << "\n";
}

void test_assignment_operator()
{
    std::cout << "surcharge operateur =" << std::endl;

    MutantStack<int> a;
    a.push(100);
    a.push(200);

    MutantStack<int> b;
    b = a;

    while (!b.empty())
    {
        std::cout << b.top() << "\n";
        b.pop();
    }
    std::cout << "\n";
}

void test_vs_list()
{
    std::cout << "test vs list" << std::endl;

    MutantStack<int> mstack;
    std::list<int> list;

    for (int i = 0; i < 5; i++)
    {
        mstack.push(i);
        list.push_back(i);
    }
    // std::stack<int>::container_type::iterator it;
    MutantStack<int>::iterator it = mstack.begin();
    std::list<int>::iterator lit = list.begin();

    while (it != mstack.end() && lit != list.end())
    {
        std::cout << "MutantStack: " << *it
                  << " | List: " << *lit << "\n";
        ++it;
        ++lit;
    }

    std::cout << "\n";
}

void test_const_iterators()
{
    std::cout << "const iterators\n";

    MutantStack<int> tmp;
    for (int i = 1; i <= 5; ++i)
        tmp.push(i);

    const MutantStack<int> mstack(tmp);

    std::cout << "const iteration:\n";
    MutantStack<int>::const_iterator it = mstack.begin();
    MutantStack<int>::const_iterator ite = mstack.end();

    while (it != ite)
    {
        std::cout << *it << "\n";
        ++it;
    }

    std::cout << "\nreverse const iteration:\n";
    MutantStack<int>::const_reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::const_reverse_iterator rite = mstack.rend();

    while (rit != rite)
    {
        std::cout << *rit << "\n";
        ++rit;
    }

    std::cout << "\n";
}

int main()
{
    ft_main_42();
    test_basic_stack();
    test_iteration();
    test_copy_constructor();
    test_assignment_operator();
    test_vs_list();
    test_const_iterators();
    return 0;
}


