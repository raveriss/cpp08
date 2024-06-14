/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:28:55 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/14 02:26:52 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Directive pour éviter les inclusions multiples d'un fichier d'en-tête */
#pragma once

/* Inclure les fichiers de la classe MutantStack */
#include "../incs/MutantStack.hpp"

/**
 * @brief Constructeur par défaut
 */
template <typename T>
MutantStack<T>::MutantStack()
: std::stack<T>()
{}

/**
 * @brief Constructeur de recopie
 */
template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other)
: std::stack<T>(other)
{}

/**
 * @brief Opérateur d’affectation
 */
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other)
{
    if (this != &other)
        std::stack<T>::operator=(other);
    return *this;
}

/**
 * @brief Destructeur
 */
template <typename T>
MutantStack<T>::~MutantStack()
{}

/**
 * @brief Constructeur par défaut
 */
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return std::stack<T>::c.end();
}

template <typename T>
void MutantStack<T>::pop()
{
    if (this->empty()) 
        throw std::runtime_error("Cannot pop from an empty stack");
    std::stack<T>::pop();
}

template <typename T>
T& MutantStack<T>::top()
{
    if (this->empty())
        throw std::runtime_error("Cannot access top of an empty stack");
    return std::stack<T>::top();
}


template <typename T>
const T& MutantStack<T>::top() const
{
    if (this->empty())
        throw std::runtime_error("Cannot access top of an empty stack");
    return std::stack<T>::top();
}

/* MutantStack.tpp */
