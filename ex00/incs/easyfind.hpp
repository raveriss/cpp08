/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:00:59 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/10 18:11:38 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <iterator>

template <typename T>
typename T::iterator easyfind(T &container, int value);

#include "../srcs/easyfind.tpp"

/* easyfind.tpp */

