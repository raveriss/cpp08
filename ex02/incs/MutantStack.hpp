/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:29:11 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/19 13:59:35 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Directive pour éviter les inclusions multiples d'un fichier d'en-tête */
#pragma once

/* Inclure les fichiers de conteneurs stack */
#include <stack>

/* Inclure les fichiers de conteneurs iterator */
#include <iterator>

/* Inclure les fichiers pour l'utilisation de cout */
#include <iostream>

/* Inclure les fichiers pour les limites des types */
#include <limits>


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

		/* Alias de type pour les itérateurs */
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        /* Retourne un itérateur au début du conteneur */
		iterator begin();

		/* Retourne un itérateur après la dernière valeur du conteneur */
		iterator end();

		/* Retourne un itérateur constant au début du conteneur */
		const_iterator begin() const;

		/* Retourne un itérateur au début du conteneur */
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

		/* Push with check */
		void push_with_check(long long value);
};

#include "../srcs/MutantStack.tpp"

/* MutantStack.tpp */
