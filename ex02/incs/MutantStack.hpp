/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:29:11 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/14 02:40:27 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Directive pour éviter les inclusions multiples d'un fichier d'en-tête */
#pragma once

/* Inclure les fichiers de conteneurs stack */
#include <stack>

/* Inclure les fichiers de conteneurs iterator */
#include <iterator>

/* Inclure les fichiers pour l'utilisation de cout */
#include <ostream>

/* Inclure les fichiers pour l'utilisation de cout */
#include <iostream>

/**
 * @brief MutantStack class
 */
template <typename T>
class MutantStack : public std::stack<T> {
public:
    /* Constructeur par défaut */
    MutantStack();

    /* Constructeur de recopie */
    MutantStack(const MutantStack<T>& other);

    /* Opérateur d’affectation */
    MutantStack<T>& operator=(const MutantStack<T>& other);

    /* Destructeur */
    virtual ~MutantStack();

    /**
     * @brief Print the Container
     */
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

    /**
     * @brief Print the Large Container
     */
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

    /* Définition des itérateurs const */
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    /* Méthode pop qui lance une exception si la pile est vide */
    void pop();

    /* Méthode top qui lance une exception si la pile est vide */
    T& top();
    const T& top() const;


};

#include "../srcs/MutantStack.tpp"

/* MutantStack.tpp */
