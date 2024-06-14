/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:38:45 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/14 02:37:59 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Directive pour éviter les inclusions multiples d'un fichier d'en-tête */
#pragma once

/* Inclure les fichiers de conteneurs vector */
#include <vector>

/* Inclure les fichiers de conteneurs algorithm */
#include <algorithm>

/* Inclure les fichiers exception */
#include <exception>

/* Inclure les fichiers string */
#include <string>

/**
 * @brief Span class
 */
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
        
        std::string print() const;

        /* Ajout de la méthode */
        std::string printLargeContainer() const;

        /* Ajout de la méthode clear */
        void clear();


        class SpanException : public std::exception
        {
            private:
                const char* _msg;
            public:
                SpanException(const char* msg) : _msg(msg) {}
                virtual const char* what() const throw() { return _msg; }
        };
};

/* Inclure les fichiers .tpp nécessaires */
#include "../srcs/Span.tpp"
