/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:02:56 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/14 02:35:11 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Directive pour éviter les inclusions multiples d'un fichier d'en-tête */
#pragma once

/* Definitions of ANSI color codes for console output */
#define GREY        "\033[0;30m"
#define RED         "\033[0;31m"
#define GREEN       "\033[0;32m"
#define YELLOW      "\033[0;33m"
#define BLUE        "\033[0;34m"
#define MAGENTA     "\033[0;35m"
#define CYAN        "\033[0;36m"
#define NC          "\033[0m"

/* Inclure les fichiers .hpp nécessaires */
#include "../incs/easyfind.hpp"

/* Inclure les fichiers de la STL nécessaires */
#include <algorithm>

/* Inclure les fichiers typeinfo pour la gestion des types */
#include <typeinfo>

/* Macro for asserting test results and displaying appropriate messages */
#define ASSERT_TEST(expression, message) \
	if (expression) { std::cout << GREEN "[TEST PASSED]" << NC << " " << message << std::endl; } \
	else { std::cout << RED "[TEST FAILED]" << NC << " " << message << std::endl; }

/**
 * @brief Fonction qui recherche une valeur dans un conteneur
 */
template <typename T>
typename T::iterator easyfind(T &container, int value) {
    /* Vérifier que le conteneur contient des int */
    if (typeid(typename T::value_type) != typeid(int)) {
        throw std::runtime_error("Le conteneur doit contenir des valeurs de type int.");
    }

    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("Value not found");
    }
    return it;
}

/* easyfind.tpp */
