/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:28:55 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/13 17:33:21 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../incs/MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other) {
    if (this != &other) {
        std::stack<T>::operator=(other);
    }
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
    return std::stack<T>::c.end();
}


/* MutantStack.tpp */
