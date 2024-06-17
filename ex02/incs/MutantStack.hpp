/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:29:11 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/17 11:17:14 by raveriss         ###   ########.fr       */
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
class MutantStack : public std::stack<T>
{
    public:
        /* Constructeur par défaut */
        MutantStack();

        /* Constructeur de recopie */
        MutantStack(const MutantStack<T>& other);

        /* Opérateur d’affectation */
        MutantStack<T>& operator=(const MutantStack<T>& other);

        /* Destructeur */
        virtual ~MutantStack();

        /* Définition des itérateurs */
        typedef typename std::stack<T>::container_type::iterator iterator;

        /* Définition des itérateurs const */
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        iterator begin();

        /* Définition de la méthode end */
        iterator end();

        /* Définition de la méthode begin */
        const_iterator begin() const;

        /* Définition de la méthode end */
        const_iterator end() const;

        /* Méthode pop qui lance une exception si la pile est vide */
        void pop();

        /* Méthode top qui lance une exception si la pile est vide */
        T& top();
        const T& top() const;
        
        /* Print the Container */
        void printContainer() const;

        /* Print the Large Container */
        void printLargeContainer() const;
};

#include "../srcs/MutantStack.tpp"

/* MutantStack.tpp */
