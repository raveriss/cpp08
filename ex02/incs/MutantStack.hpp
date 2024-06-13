/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:29:11 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/14 00:06:57 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iterator>
#include <ostream>
#include <iostream>

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

    void printContainer() const {
        typename MutantStack<T>::container_type::const_iterator it = this->c.begin();
        std::cout << "[ ";
        if (it != this->c.end()) {
            std::cout << *it;
            ++it;
        }
        for (; it != this->c.end(); ++it) {
            std::cout << ", " << *it;
        }
        std::cout << " ]" << std::endl;
    }

    void printLargeContainer() const
    {
        const_iterator it = this->c.begin();
        size_t size = this->c.size();
        size_t i = 0;

        std::cout << "[ ";

        if (size <= 6)
        {
            for (; it != this->c.end(); ++it)
            {
                std::cout << *it;
                if (it != --this->c.end())
                    std::cout << ", ";
            }
        }
        else
        {
            for (i = 0; i < 3 && it != this->c.end(); ++i, ++it)
            {
                std::cout << *it << ", ";
            }

            std::cout << "..., ";

            it = this->c.end();
            for (i = 0; i < 3; ++i)
            {
                --it;
            }

            for (; it != this->c.end(); ++it)
            {
                std::cout << *it;
                if (it != --this->c.end())
                    std::cout << ", ";
            }
        }

        std::cout << " ]" << std::endl;
    }

    /* Définition des itérateurs */
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    void pop();

    // Méthode top qui lance une exception si la pile est vide
    T& top();
    const T& top() const;


};

#include "../srcs/MutantStack.tpp"

/* MutantStack.tpp */
