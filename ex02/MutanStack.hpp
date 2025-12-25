/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutanStack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiteixei <kiteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:00:04 by kiteixei          #+#    #+#             */
/*   Updated: 2025/12/25 23:25:34 by kiteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTAN_STACK_HPP
#define MUTAN_STACK_HPP
#include <stack>

template <typename T> class MutanStack : public std::stack<T> {
public:
  MutanStack();
  ~MutanStack();
  MutanStack &operator=(const MutanStack &cpy);
  typedef typename std::stack<T>::container_type container_type;
  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef typename std::stack<T>::container_type::const_iterator const_iterator;
  typedef
      typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
  typedef typename std::stack<T>::container_type::const_reverse_iterator
      const_reverse_iterator;

  iterator begin();
  iterator end();

  const_iterator begin() const;
  const_iterator end() const;

  reverse_iterator rbegin();
  reverse_iterator rend();

  const_reverse_iterator rbegin() const;
  const_reverse_iterator rend() const;
};



template <typename T>
MutanStack<T>::MutanStack()
{

}

template <typename T> MutanStack<T>::~MutanStack()
{

}


template <typename T> typename MutanStack<T>::iterator MutanStack<T>::begin() {
  return (std::stack<T>::c.begin());
}

template <typename T>
MutanStack<T> &MutanStack<T>::operator=(const MutanStack &cpy)
{
    if (this != &cpy)
        std::stack<T>::operator=(cpy);
    return *this;
}

template <typename T> typename MutanStack<T>::iterator MutanStack<T>::end() {
  return (std::stack<T>::c.end());
}

template <typename T>
typename MutanStack<T>::const_iterator MutanStack<T>::begin() const {
  return (std::stack<T>::c.begin());
}

template <typename T>
typename MutanStack<T>::const_iterator MutanStack<T>::end() const {
  return (std::stack<T>::c.end());
}

template <typename T>
typename MutanStack<T>::reverse_iterator MutanStack<T>::rbegin() {
  return (std::stack<T>::c.rbegin());
}
template <typename T>
typename MutanStack<T>::reverse_iterator MutanStack<T>::rend() {
  return (std::stack<T>::c.rend());
}
template <typename T>
typename MutanStack<T>::const_reverse_iterator MutanStack<T>::rbegin() const {
  return (std::stack<T>::c.rbegin());
}
template <typename T>
typename MutanStack<T>::const_reverse_iterator MutanStack<T>::rend() const {
  return (std::stack<T>::c.rend());
}

#endif
