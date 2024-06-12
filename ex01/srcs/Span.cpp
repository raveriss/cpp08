/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:33:33 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/13 00:12:33 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Span.hpp"
#include <sstream>

/**
 * @brief Constructor
 */
Span::Span(unsigned int n) :
_n(n)
{}

/**
 * @brief Copy constructor
 */
Span::Span(const Span &other) :
_n(other._n), _data(other._data)
{}

/**
 * @brief Assignment operator
 */
Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _n = other._n;
        _data = other._data;
    }
    return *this;
}

/**
 * @brief Destructor
 */
Span::~Span()
{}

/**
 * @brief Add a number to the Span object
 */
void Span::addNumber(int number)
{
    if (_data.size() >= _n)
    {
        throw SpanException("Span is full");
    }
    _data.push_back(number);
}

/**
 * @brief Find the shortest span between the elements in the Span object
 */
int Span::shortestSpan() const
{
    if (_data.size() < 2)
    {
        throw SpanException("Not enough elements to find a span");
    }
    std::vector<int> sorted = _data;
    std::sort(sorted.begin(), sorted.end());
    int shortest = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; ++i)
    {
        int span = sorted[i + 1] - sorted[i];
        if (span < shortest)
        {
            shortest = span;
        }
    }
    return shortest;
}

/**
 * @brief Find the longest span between the elements in the Span object
 */
int Span::longestSpan() const
{
    if (_data.size() < 2)
    {
        throw SpanException("Not enough elements to find a span");
    }
    int min = *std::min_element(_data.begin(), _data.end());
    int max = *std::max_element(_data.begin(), _data.end());
    return max - min;
}

/**
 * @brief Get the size of the Span object
 */
unsigned int Span::size() const
{
    return _data.size();
}

/**
 * @brief Get the capacity of the Span object
 */
unsigned int Span::capacity() const
{
    return _n;
}

/**
 * @brief Print the data in the Span object
 */
std::string Span::print() const
{
    std::ostringstream oss;
    oss << "[ ";
    for (size_t i = 0; i < _data.size(); ++i)
    {
        oss << _data[i];
        if (i < _data.size() - 1)
            oss << ", ";
    }
    oss << " ]";
    return oss.str();
}

/**
 * @brief Print the first 3 and last 3 elements of the Span object
 */
std::string Span::printLargeContainer() const
{
    std::ostringstream oss;
    size_t size = _data.size();
    oss << "[ ";

    if (size <= 6)
    {
        for (size_t i = 0; i < size; ++i)
        {
            oss << _data[i];
            if (i < size - 1)
                oss << ", ";
        }
    }
    else
    {
        for (size_t i = 0; i < 3; ++i)
        {
            oss << _data[i] << ", ";
        }

        oss << "..., ";

        for (size_t i = size - 3; i < size; ++i)
        {
            oss << _data[i];
            if (i < size - 1)
                oss << ", ";
        }
    }
    
    oss << " ]";
    return oss.str();
}

void Span::clear()
{
    _data.clear(); // Vider le vecteur des données
}
