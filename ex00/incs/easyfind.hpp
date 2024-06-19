/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:00:59 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/19 19:30:52 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Directive pour éviter les inclusions multiples d'un fichier d'en-tête */
#pragma once

/* Inclure les fichiers de la STL nécessaires */
#include <iterator>

/**
 * @brief Fonction easyfind recherche une valeur dans un conteneur
 */
template <typename T>
typename T::iterator easyfind(T &container, int value);

/* Inclure les fichiers .tpp nécessaires */
#include "../srcs/easyfind.tpp"

/* easyfind.hpp */

