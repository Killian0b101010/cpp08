/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiteixei <kiteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:05:28 by kiteixei          #+#    #+#             */
/*   Updated: 2026/02/14 15:20:26 by kiteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"


void test_vector_success()
{
    std::cout << "vector succes \n";

    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    try
    {
        std::vector<int>::iterator it = easyfind(v, 20);
        std::cout << "found: " << *it << "\n";
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    std::cout << "\n";
}

void test_vector_fail()
{
    std::cout << "fail\n";

    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    try
    {
        easyfind(v, 42);
        std::cout << "Should not print\n";
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << "\n";
    }

    std::cout << "\n";
}

void test_list()
{
    std::cout << "list test\n";

    std::list<int> l;
    l.push_back(5);
    l.push_back(15);
    l.push_back(25);

    try
    {
        std::list<int>::iterator it = easyfind(l, 15);
        std::cout << "found : " << *it << "\n";
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    std::cout << "\n";
}

void test_deque()
{
    std::cout << "deque test \n";

    std::deque<int> d;
    d.push_back(100);
    d.push_back(200);

    try
    {
        std::deque<int>::iterator it = easyfind(d, 200);
        std::cout << "found : " << *it << "\n";
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    std::cout << "\n";
}

int main()
{
    test_vector_success();
    test_vector_fail();
    test_list();
    test_deque();
    return 0;
}

