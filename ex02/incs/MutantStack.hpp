/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:29:11 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/13 19:39:47 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    // Constructeur par défaut
    MutantStack();

    // Constructeur de recopie
    MutantStack(const MutantStack<T>& other);

    // Opérateur d’affectation
    MutantStack<T>& operator=(const MutantStack<T>& other);

    // Destructeur
    virtual ~MutantStack();

    // Définition des itérateurs
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    void pop();

};

#include "../srcs/MutantStack.tpp"

/* MutantStack.tpp */
