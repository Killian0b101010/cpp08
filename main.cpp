/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiteixei <kiteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:05:28 by kiteixei          #+#    #+#             */
/*   Updated: 2025/12/24 20:16:03 by kiteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <exception>
#include <iostream>
#include <vector>
int main(void) {
  std::vector<int> v;
  v.push_back(15);
  v.push_back(20);
  try {
    std::cout << *easyfind(v, 20);
  } catch (std::exception &s) {
    std::cerr << s.what() << "\n";
  }
  return (0);
}
