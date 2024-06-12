/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:38:45 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/12 18:39:18 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>

class Span
{
private:
    unsigned int _n;
    std::vector<int> _data;

public:
    Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int number);
    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end);

    int shortestSpan() const;
    int longestSpan() const;

    unsigned int size() const;
    unsigned int capacity() const;

    class SpanException : public std::exception
    {
    private:
        const char* _msg;
    public:
        SpanException(const char* msg) : _msg(msg) {}
        virtual const char* what() const throw() { return _msg; }
    };
};

#include "../srcs/Span.tpp"

#endif
