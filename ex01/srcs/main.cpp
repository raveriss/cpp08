/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:44:41 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/12 18:39:34 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Span.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>

#define GREY        "\033[0;30m"
#define RED         "\033[0;31m"
#define GREEN       "\033[0;32m"
#define YELLOW      "\033[0;33m"
#define BLUE        "\033[0;34m"
#define MAGENTA     "\033[0;35m"
#define CYAN        "\033[0;36m"
#define NC          "\033[0m"

#define ASSERT_TEST(expression, message) \
    if (expression) { std::cout << GREEN "[TEST PASSED]" << NC << " " << message << std::endl; } \
    else { std::cout << RED "[TEST FAILED]" << NC << " " << message << std::endl; }

void captureAndCompareOutput(void (*func)(), const std::string& expected, const std::string& message)
{
    std::ostringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
    
    func();
    
    std::cout.rdbuf(old);
    std::string output = buffer.str();
    ASSERT_TEST(output == expected, message);
}

void testConstructorValidCapacity()
{
    Span sp(5);
    ASSERT_TEST(sp.size() == 0, "Span should be initialized with size 0");
    ASSERT_TEST(sp.capacity() == 5, "Span should have the correct capacity");
}

void testConstructorZeroCapacity()
{
    try
    {
        Span sp(0);
        ASSERT_TEST(sp.capacity() == 0, "Span should be initialized with zero capacity");
    }
    catch(const std::exception& e)
    {
        ASSERT_TEST(false, e.what());
    }
}

void testAddNumberToMaxCapacity()
{
    Span sp(5);
    for (int i = 0; i < 5; ++i)
    {
        sp.addNumber(i);
    }
    ASSERT_TEST(sp.size() == 5, "Span should store numbers up to its capacity");
}

void testAddNumberBeyondCapacity()
{
    Span sp(5);
    for (int i = 0; i < 5; ++i)
    {
        sp.addNumber(i);
    }
    try
    {
        sp.addNumber(6);
        ASSERT_TEST(false, "Exception should be thrown when adding beyond capacity");
    }
    catch(const std::exception& e)
    {
        ASSERT_TEST(true, "Exception thrown as expected");
    }
}

void testShortestSpanEmpty()
{
    Span sp(5);
    try
    {
        sp.shortestSpan();
        ASSERT_TEST(false, "Exception should be thrown when calculating shortestSpan on empty Span");
    }
    catch(const std::exception& e)
    {
        ASSERT_TEST(true, "Exception thrown as expected");
    }
}

void testShortestSpanSingleElement()
{
    Span sp(5);
    sp.addNumber(1);
    try
    {
        sp.shortestSpan();
        ASSERT_TEST(false, "Exception should be thrown when calculating shortestSpan with one element");
    }
    catch(const std::exception& e)
    {
        ASSERT_TEST(true, "Exception thrown as expected");
    }
}

void testShortestSpanMultipleElements()
{
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    ASSERT_TEST(sp.shortestSpan() == 2, "Shortest span should be 2");
}

void testLongestSpanEmpty()
{
    Span sp(5);
    try
    {
        sp.longestSpan();
        ASSERT_TEST(false, "Exception should be thrown when calculating longestSpan on empty Span");
    }
    catch(const std::exception& e)
    {
        ASSERT_TEST(true, "Exception thrown as expected");
    }
}

void testLongestSpanSingleElement()
{
    Span sp(5);
    sp.addNumber(1);
    try
    {
        sp.longestSpan();
        ASSERT_TEST(false, "Exception should be thrown when calculating longestSpan with one element");
    }
    catch(const std::exception& e)
    {
        ASSERT_TEST(true, "Exception thrown as expected");
    }
}

void testLongestSpanMultipleElements()
{
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    ASSERT_TEST(sp.longestSpan() == 14, "Longest span should be 14");
}

void testAddRangeWithinCapacity()
{
    Span sp(10);
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> rangeVec(arr, arr + sizeof(arr) / sizeof(int));
    sp.addNumbers(rangeVec.begin(), rangeVec.end());
    ASSERT_TEST(sp.size() == 5, "Span should store numbers from range");
}

void testAddRangeBeyondCapacity()
{
    Span sp(5);
    int arr[] = {1, 2, 3, 4, 5, 6};
    std::vector<int> rangeVec(arr, arr + sizeof(arr) / sizeof(int));
    try
    {
        sp.addNumbers(rangeVec.begin(), rangeVec.end());
        ASSERT_TEST(false, "Exception should be thrown when adding range beyond capacity");
    }
    catch(const std::exception& e)
    {
        ASSERT_TEST(true, "Exception thrown as expected");
    }
}

void testPerformance10000Numbers()
{
    Span sp(10000);
    for (int i = 0; i < 10000; ++i)
    {
        sp.addNumber(i);
    }
    ASSERT_TEST(sp.shortestSpan() == 1, "Shortest span with 10000 numbers should be 1");
    ASSERT_TEST(sp.longestSpan() == 9999, "Longest span with 10000 numbers should be 9999");
}

void testPerformance100000Numbers()
{
    Span sp(100000);
    for (int i = 0; i < 100000; ++i)
    {
        sp.addNumber(i);
    }
    ASSERT_TEST(sp.shortestSpan() == 1, "Shortest span with 100000 numbers should be 1");
    ASSERT_TEST(sp.longestSpan() == 99999, "Longest span with 100000 numbers should be 99999");
}

void testIdenticalNumbers()
{
    Span sp(5);
    for (int i = 0; i < 5; ++i)
    {
        sp.addNumber(1);
    }
    ASSERT_TEST(sp.shortestSpan() == 0, "Shortest span with identical numbers should be 0");
    ASSERT_TEST(sp.longestSpan() == 0, "Longest span with identical numbers should be 0");
}

void testNegativeAndPositiveNumbers()
{
    Span sp(5);
    sp.addNumber(-10);
    sp.addNumber(10);
    sp.addNumber(-20);
    sp.addNumber(20);
    sp.addNumber(0);
    ASSERT_TEST(sp.shortestSpan() == 10, "Shortest span with negative and positive numbers should be 10");
    ASSERT_TEST(sp.longestSpan() == 40, "Longest span with negative and positive numbers should be 40");
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << NC << std ::endl;
        std::cout << CYAN << "/*                                 MANDATORY                                  */" << NC << std ::endl;
        std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << NC << std ::endl;

        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    else if (argc == 2 && strcmp(argv[1], "tester") == 0)
    {
        std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << NC << std ::endl;
        std::cout << CYAN << "/*                                 OPTIONNEL                                  */" << NC << std ::endl;
        std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << NC << std ::endl;

        std::cout << MAGENTA << "TEST CONSTRUCTOR VALID CAPACITY" << NC << std::endl;
        testConstructorValidCapacity();

        std::cout  << std::endl << MAGENTA << "TEST CONSTRUCTOR ZERO CAPACITY" << NC << std::endl;
        testConstructorZeroCapacity();

        std::cout  << std::endl << MAGENTA << "TEST ADD NUMBER TO MAX CAPACITY" << NC << std::endl;
        testAddNumberToMaxCapacity();

        std::cout  << std::endl << MAGENTA << "TEST ADD NUMBER BEYOND CAPACITY" << NC << std::endl;
        testAddNumberBeyondCapacity();

        std::cout  << std::endl << MAGENTA << "TEST SHORTEST SPAN EMPTY" << NC << std::endl;
        testShortestSpanEmpty();

        std::cout << std::endl << MAGENTA << "TEST SHORTEST SPAN SINGLE ELEMENT" << NC << std::endl;
        testShortestSpanSingleElement();

        std::cout << std::endl << MAGENTA << "TEST SHORTEST SPAN MULTIPLE ELEMENTS" << NC << std::endl;
        testShortestSpanMultipleElements();

        std::cout << std::endl << MAGENTA << "TEST LONGEST SPAN EMPTY" << NC << std::endl;
        testLongestSpanEmpty();

        std::cout << std::endl << MAGENTA << "TEST LONGEST SPAN SINGLE ELEMENT" << NC << std::endl;
        testLongestSpanSingleElement();

        std::cout << std::endl << MAGENTA << "TEST LONGEST SPAN MULTIPLE ELEMENTS" << NC << std::endl;
        testLongestSpanMultipleElements();

        std::cout << std::endl << MAGENTA << "TEST ADD RANGE WITHIN CAPACITY" << NC << std::endl;
        testAddRangeWithinCapacity();

        std::cout << std::endl << MAGENTA << "TEST ADD RANGE BEYOND CAPACITY" << NC << std::endl;
        testAddRangeBeyondCapacity();

        std::cout << std::endl << MAGENTA << "TEST PERFORMANCE 10000 NUMBERS" << NC << std::endl;
        testPerformance10000Numbers();

        std::cout << std::endl << MAGENTA << "TEST PERFORMANCE 100000 NUMBERS" << NC << std::endl;
        testPerformance100000Numbers();

        std::cout << std::endl << MAGENTA << "TEST IDENTICAL NUMBERS" << NC << std::endl;
        testIdenticalNumbers();

        std::cout << std::endl << MAGENTA << "TEST NEGATIVE AND POSITIVE NUMBERS" << NC << std::endl;
        testNegativeAndPositiveNumbers();
    }
    else
    {
        std::cout << RED << "Usage: ./span or ./span tester" << NC << std::endl;
        return 1;
    }
    
    return 0;
}

/* main.cpp */
