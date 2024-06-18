/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:38:45 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/18 17:21:46 by raveriss         ###   ########.fr       */
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
        /* Size max of the container */
        unsigned int _n;

        /* Data container */
        std::vector<int> _data;

    public:
        /* Constructeurs par paramétrique */
        Span(unsigned int n);

        /* Constructeur par copie */
        Span(const Span &other);

        /* Surcharge de l'opérateur = */
        Span &operator=(const Span &other);

        /* Destructeur */
        ~Span();

        /* Add numbers to the Span object */
        void addNumber(long long number);

        
        /* Add numbers to the Span object */
        template <typename Iterator>
        void addNumbers(Iterator begin, Iterator end);

        /* Shortest span */
        long long shortestSpan() const;

        /* Longest span */
        long long longestSpan() const;

        /* Ajout de la méthode size */
        unsigned int size() const;

        /* Ajout de la méthode capacity */
        unsigned int capacity() const;
        
        /* Ajout de la méthode print */
        std::string print() const;

        /* Ajout de la méthode printLargeContainer */
        std::string printLargeContainer() const;

        /* Ajout de la méthode clear */
        void clear();

        /* Exception pour la classe Span */
        class SpanException : public std::exception
        {
            private:
                /* Message d'erreur */
                const char* _msg;
            public:
                /* Constructeur avec message */
                SpanException(const char* msg);

                /* Renvoie le message d'erreur */
                virtual const char* what() const throw();
        };
};

/* Inclure les fichiers .tpp nécessaires */
#include "../srcs/Span.tpp"
