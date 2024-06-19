/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:02:56 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/19 19:30:59 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Directive pour éviter les inclusions multiples d'un fichier d'en-tête */
#pragma once

/**
 * @brief Fonction qui retourne un itérateur sur la première occurrence de la valeur recherchée
 */
#include <algorithm>
#include <typeinfo>
#include <stdexcept>
#include <limits>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    /* Vérifier que le conteneur contient des int */
    if (typeid(typename T::value_type) != typeid(int))
        throw std::runtime_error("Le conteneur doit contenir des valeurs de type int.");

    /* Vérifier si la valeur est dans les limites d'un int */
    if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        throw std::overflow_error("Value exceeds the limits of int");

    int intValue = static_cast<int>(value);
    typename T::iterator it = std::find(container.begin(), container.end(), intValue);
    if (it == container.end())
        throw std::runtime_error("Value not found");
    return it;
}

/* easyfind.tpp */
