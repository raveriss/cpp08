/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:33:33 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/18 19:13:55 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion pour la classe Span */
#include "../incs/Span.hpp"

/* Inclusion pour les flux de sortie */
#include <sstream>

/* Inclusion pour les exceptions standard */
#include <stdexcept>

/**
 * @brief Constructor
 */
Span::Span(unsigned int n)
: _n(n)
{}

/**
 * @brief Copy constructor
 */
Span::Span(const Span &other)
: _n(other._n), _data(other._data)
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
void Span::addNumber(long long number)
{
    if (_data.size() >= _n)
        throw SpanException("Span is full");
    if (number > std::numeric_limits<int>::max() || number < std::numeric_limits<int>::min())
        throw SpanException("Number is out of int range");
    _data.push_back(number);
}

/**
 * @brief Find the shortest span between the elements in the Span object
 */
long long Span::shortestSpan() const
{
    if (_data.size() < 2)
        throw SpanException("Not enough elements to find a span");
    std::vector<int> sorted = _data;
    std::sort(sorted.begin(), sorted.end());
    long long shortest = static_cast<long long>(sorted[1]) - static_cast<long long>(sorted[0]);
    for (size_t i = 1; i < sorted.size() - 1; ++i)
    {
        long long span = static_cast<long long>(sorted[i + 1]) - static_cast<long long>(sorted[i]);
        if (span < shortest)
            shortest = span;
    }
    return shortest;
}

/**
 * @brief Find the longest span between the elements in the Span object
 */
long long Span::longestSpan() const
{
    if (_data.size() < 2)
        throw SpanException("Not enough elements to find a span");
    int min = *std::min_element(_data.begin(), _data.end());
    int max = *std::max_element(_data.begin(), _data.end());
    return static_cast<long long>(max) - static_cast<long long>(min);
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

/**
 * @brief clear the Span object
 */
void Span::clear()
{
    /* Vider le vecteur des données */
    _data.clear();
}

/**
 * @brief Construct a new Span:: Span Exception:: Span Exception object
 * @param msg 
 */
Span::SpanException::SpanException(const char* msg)
: _msg(msg)
{}

/**
 * @brief Returns a C-style string describing the exception.
 * @return const char* A C-style string describing the exception.
 */
const char* Span::SpanException::what() const throw()
{
    return _msg;
}
