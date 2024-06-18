/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 00:01:03 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/18 17:42:14 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Directive pour éviter les inclusions multiples d'un fichier d'en-tête */
#pragma once

/* Inclure les fichiers Span.hpp */
#include "../incs/Span.hpp"

/* Include pour les limites des types */
#include <limits>

/* Inclusion pour les exceptions standard */
#include <stdexcept>

/**
 * @brief Add numbers to the Span object
 */
template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
    if (_data.size() + std::distance(begin, end) > _n) {
        throw SpanException("Span will exceed capacity");
    }

    for (Iterator it = begin; it != end; ++it) {
        if (*it > std::numeric_limits<int>::max() || *it < std::numeric_limits<int>::min()) {
            throw SpanException("Number is out of int range");
        }
    }

    _data.insert(_data.end(), begin, end);
}


