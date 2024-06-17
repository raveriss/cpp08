/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:44:41 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/17 19:54:40 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion de la classe Span */
#include "../incs/Span.hpp"

/* Inclusion de la bibliothèque standard pour std::cout */
#include <iostream>

/* Inclusion de la bibliothèque standard pour std::vector */
#include <vector>

/* Inclusion de la bibliothèque standard pour std::ostringstream */
#include <sstream>

/* Inclusion de la bibliothèque standard pour std::strcmp */
#include <cstring>

/* Definitions of ANSI color codes for console output */
#define GREY        "\033[0;30m"
#define RED         "\033[0;31m"
#define GREEN       "\033[0;32m"
#define YELLOW      "\033[0;33m"
#define BLUE        "\033[0;34m"
#define MAGENTA     "\033[0;35m"
#define CYAN        "\033[0;36m"
#define NC          "\033[0m"

/* Define return values */
#define ARG_ONE 2
#define NO_ARGUMENTS 1
#define RETURN_SUCCESS 0
#define FIRST_ARGUMENT 1
#define RETURN_FAILURE 1
#define TEST_ARG "tester"
#define STRING_COMPARE_SUCCESS 0

/* Macro for asserting test results and displaying appropriate messages */
#define ASSERT_TEST(expression, message) \
    if (expression) { std::cout << GREEN "[TEST PASSED]" << NC << " " << message << std::endl; } \
    else { std::cout << RED "[TEST FAILED]" << NC << " " << message << std::endl; }

/**
 * @brief Capture and compare output of a function
 */
void captureAndCompareOutput(void (*func)(), const std::string& expected, const std::string& message)
{
    std::ostringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
    
    func();
    
    std::cout.rdbuf(old);
    std::string output = buffer.str();
    ASSERT_TEST(output == expected, message);
}

/**
 * @brief Test constructor with valid capacity
 */
void testConstructorValidCapacity()
{
    
    Span sp(5);
    std::cout << sp.print() << std::endl;
    ASSERT_TEST(sp.size() == 0, "Span should be initialized with size 0");
    std::cout << sp.print() << std::endl;
    ASSERT_TEST(sp.capacity() == 5, "Span should have the correct capacity");
}

/**
 * @brief Test constructor with zero capacity
 */
void testConstructorZeroCapacity()
{
    try
    {
        Span sp(0);
        std::cout << sp.print() << std::endl;
        ASSERT_TEST(sp.capacity() == 0, "Span should be initialized with zero capacity");
    }
    catch(const std::exception& e)
    {
        ASSERT_TEST(false, e.what());
    }
}

/**
 * @brief Test adding numbers to Span up to its capacity
 */
void testAddNumberToMaxCapacity()
{
    Span sp(5);
    for (int i = 0; i < 5; ++i)
    {
        sp.addNumber(i);
    }
    std::cout << sp.print() << std::endl;
    ASSERT_TEST(sp.size() == 5, "Span should store numbers up to its capacity");
}

/**
 * @brief Test adding numbers beyond Span's capacity
 */
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
        std::cout << sp.print() << std::endl;
        ASSERT_TEST(true, "Exception thrown as expected");
    }
}

/**
 * @brief Test calculating shortest span on empty Span
 */
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
        std::cout << sp.print() << std::endl;
        ASSERT_TEST(true, "Exception thrown as expected");
    }
}

/**
 * @brief Test calculating shortest span with one element
 */
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
        std::cout << sp.print() << std::endl;
        ASSERT_TEST(true, "Exception thrown as expected");
    }
}

/**
 * @brief Test calculating shortest span with multiple elements
 */
void testShortestSpanMultipleElements()
{
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.print() << std::endl;
    ASSERT_TEST(sp.shortestSpan() == 2, "Shortest span should be 2");
}

/**
 * @brief Test calculating longest span on empty Span
 */
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
        std::cout << sp.print() << std::endl;
        ASSERT_TEST(true, "Exception thrown as expected");
    }
}

/**
 * @brief Test calculating longest span with one element
 */
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
        std::cout << sp.print() << std::endl;
        ASSERT_TEST(true, "Exception thrown as expected");
    }
}

/**
 * @brief Test calculating longest span with multiple elements
 */
void testLongestSpanMultipleElements()
{
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.print() << std::endl;
    ASSERT_TEST(sp.longestSpan() == 14, "Longest span should be 14");
}

/**
 * @brief Test adding range within Span's capacity
 */
void testAddRangeWithinCapacity()
{
    Span sp(10);
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> rangeVec(arr, arr + sizeof(arr) / sizeof(int));
    sp.addNumbers(rangeVec.begin(), rangeVec.end());
    std::cout << sp.print() << std::endl;
    ASSERT_TEST(sp.size() == 5, "Span should store numbers from range");
}

/**
 * @brief Test adding range beyond Span's capacity
 */
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
        std::cout << sp.print() << std::endl;
        ASSERT_TEST(true, "Exception thrown as expected");
    }
}

/**
 * @brief Test performance with 10000 numbers
 */
void testPerformance10000Numbers()
{
    Span sp(10000);
    for (int i = 0; i < 10000; ++i)
    {
        sp.addNumber(i);
    }
    std::cout << sp.printLargeContainer() << std::endl;

    ASSERT_TEST(sp.shortestSpan() == 1, "Shortest span with 10000 numbers should be 1");
    std::cout << sp.printLargeContainer() << std::endl;

    ASSERT_TEST(sp.longestSpan() == 9999, "Longest span with 10000 numbers should be 9999");
}

/**
 * @brief Test performance with 100000 numbers
 */
void testPerformance100000Numbers()
{
    Span sp(100000);
    for (int i = 0; i < 100000; ++i)
    {
        sp.addNumber(i);
    }
    std::cout << sp.printLargeContainer() << std::endl;
    ASSERT_TEST(sp.shortestSpan() == 1, "Shortest span with 100000 numbers should be 1");
    std::cout << sp.printLargeContainer() << std::endl;

    ASSERT_TEST(sp.longestSpan() == 99999, "Longest span with 100000 numbers should be 99999");
}

/**
 * @brief Test identical numbers
 */
void testIdenticalNumbers()
{
    Span sp(5);
    for (int i = 0; i < 5; ++i)
    {
        sp.addNumber(1);
    }
    std::cout << sp.print() << std::endl;
    ASSERT_TEST(sp.shortestSpan() == 0, "Shortest span with identical numbers should be 0");
    std::cout << sp.print() << std::endl;
    ASSERT_TEST(sp.longestSpan() == 0, "Longest span with identical numbers should be 0");
}

/**
 * @brief Test negative and positive numbers
 */
void testNegativeAndPositiveNumbers()
{
    Span sp(5);
    sp.addNumber(-10);
    sp.addNumber(10);
    sp.addNumber(-20);
    sp.addNumber(20);
    sp.addNumber(0);
    std::cout << sp.print() << std::endl;
    ASSERT_TEST(sp.shortestSpan() == 10, "Shortest span with negative and positive numbers should be 10");
    std::cout << sp.print() << std::endl;
    ASSERT_TEST(sp.longestSpan() == 40, "Longest span with negative and positive numbers should be 40");
}

/**
 * @brief Test copy constructor
 */
void testCopyConstructor()
{
    Span sp1(5);
    sp1.addNumber(1);
    sp1.addNumber(2);
    sp1.addNumber(3);

    Span sp2(sp1);
    std::cout << sp1.print() << std::endl;
    std::cout << sp2.print() << std::endl;
    ASSERT_TEST(sp1.size() == sp2.size(), "Copied Span should have the same size");
    ASSERT_TEST(sp1.shortestSpan() == sp2.shortestSpan(), "Copied Span should have the same shortest span");
    ASSERT_TEST(sp1.longestSpan() == sp2.longestSpan(), "Copied Span should have the same longest span");
}

/**
 * @brief Test assignment operator
 */
void testAssignmentOperator()
{
    Span sp1(5);
    sp1.addNumber(1);
    sp1.addNumber(2);
    sp1.addNumber(3);

    Span sp2(10);
    sp2 = sp1;
    std::cout << sp1.print() << std::endl;
    std::cout << sp2.print() << std::endl;
    ASSERT_TEST(sp1.size() == sp2.size(), "Assigned Span should have the same size");
    ASSERT_TEST(sp1.shortestSpan() == sp2.shortestSpan(), "Assigned Span should have the same shortest span");
    ASSERT_TEST(sp1.longestSpan() == sp2.longestSpan(), "Assigned Span should have the same longest span");
}

/**
 * @brief Test clear and reuse
 */
void testClearAndReuse()
{
    Span sp(5);
    sp.addNumber(1);
    sp.addNumber(2);
    sp.addNumber(3);
    sp.addNumber(4);
    sp.addNumber(5);
    std::cout << sp.print() << std::endl;
    std::cout << std::endl;

    std::cout << "Clearing Span..." << std::endl;
    
    /* Appel de la méthode clear pour vider le Span */
    sp.clear();
    std::cout << sp.print() << std::endl;
    ASSERT_TEST(sp.size() == 0, "Span should be empty after clear");
    std::cout << std::endl;

    std::cout << "Re-using Span..." << std::endl;
    sp.addNumber(4);
    sp.addNumber(5);
    std::cout << sp.print() << std::endl;
    ASSERT_TEST(sp.size() == 2, "Span should have 2 elements after reuse");
    ASSERT_TEST(sp.shortestSpan() == 1, "Shortest span should be 1 after reuse");
    ASSERT_TEST(sp.longestSpan() == 1, "Longest span should be 1 after reuse");
}

/**
 * @brief Main function
 */
int main(int argc, char *argv[])
{
    if (argc == NO_ARGUMENTS)
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
    else if (argc == ARG_ONE && strcmp(argv[FIRST_ARGUMENT], TEST_ARG) == STRING_COMPARE_SUCCESS)
    {
        std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << NC << std ::endl;
        std::cout << CYAN << "/*                                 OPTIONNEL                                  */" << NC << std ::endl;
        std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << NC << std ::endl;

        /* Test copy constructor */
        std::cout << MAGENTA << "TEST COPY CONSTRUCTOR" << NC << std::endl;
        testCopyConstructor();

        /* Test assignment operator */
        std::cout << std::endl << MAGENTA << "TEST ASSIGNMENT OPERATOR" << NC << std::endl;
        testAssignmentOperator();

        /* Test constructor with valid capacity */
        std::cout << std::endl << MAGENTA << "TEST CONSTRUCTOR VALID CAPACITY" << NC << std::endl;
        testConstructorValidCapacity();

        /* Test constructor with zero capacity */
        std::cout  << std::endl << MAGENTA << "TEST CONSTRUCTOR ZERO CAPACITY" << NC << std::endl;
        testConstructorZeroCapacity();

        /* Test add number to max capacity */
        std::cout  << std::endl << MAGENTA << "TEST ADD NUMBER TO MAX CAPACITY" << NC << std::endl;
        testAddNumberToMaxCapacity();

        /* Test add number beyond capacity */
        std::cout  << std::endl << MAGENTA << "TEST ADD NUMBER BEYOND CAPACITY" << NC << std::endl;
        testAddNumberBeyondCapacity();

        /* Test shortest span empty */
        std::cout  << std::endl << MAGENTA << "TEST SHORTEST SPAN EMPTY" << NC << std::endl;
        testShortestSpanEmpty();

        /* Test shortest span single element */
        std::cout << std::endl << MAGENTA << "TEST SHORTEST SPAN SINGLE ELEMENT" << NC << std::endl;
        testShortestSpanSingleElement();

        /* Test shortest span multiple elements */
        std::cout << std::endl << MAGENTA << "TEST SHORTEST SPAN MULTIPLE ELEMENTS" << NC << std::endl;
        testShortestSpanMultipleElements();

        /* Test longest span empty */
        std::cout << std::endl << MAGENTA << "TEST LONGEST SPAN EMPTY" << NC << std::endl;
        testLongestSpanEmpty();

        /* Test longest span single element */
        std::cout << std::endl << MAGENTA << "TEST LONGEST SPAN SINGLE ELEMENT" << NC << std::endl;
        testLongestSpanSingleElement();

        /* Test longest span multiple elements */
        std::cout << std::endl << MAGENTA << "TEST LONGEST SPAN MULTIPLE ELEMENTS" << NC << std::endl;
        testLongestSpanMultipleElements();

        /* Test add range within capacity */
        std::cout << std::endl << MAGENTA << "TEST ADD RANGE WITHIN CAPACITY" << NC << std::endl;
        testAddRangeWithinCapacity();

        /* Test add range beyond capacity */
        std::cout << std::endl << MAGENTA << "TEST ADD RANGE BEYOND CAPACITY" << NC << std::endl;
        testAddRangeBeyondCapacity();

        /* Test performance 10000 numbers */
        std::cout << std::endl << MAGENTA << "TEST PERFORMANCE 10000 NUMBERS" << NC << std::endl;
        testPerformance10000Numbers();

        /* Test performance 100000 numbers */
        std::cout << std::endl << MAGENTA << "TEST PERFORMANCE 100000 NUMBERS" << NC << std::endl;
        testPerformance100000Numbers();

        /* Test identical numbers */
        std::cout << std::endl << MAGENTA << "TEST IDENTICAL NUMBERS" << NC << std::endl;
        testIdenticalNumbers();

        /* Test negative and positive numbers */
        std::cout << std::endl << MAGENTA << "TEST NEGATIVE AND POSITIVE NUMBERS" << NC << std::endl;
        testNegativeAndPositiveNumbers();

        /* Test clear and reuse */
        std::cout << std::endl << MAGENTA << "TEST CLEAR AND RE-USE" << NC << std::endl;
        testClearAndReuse();
    }
    else
    {
        std::cout << RED << "Usage: ./span or ./span tester" << NC << std::endl;
        return RETURN_FAILURE;
    }
    
    return RETURN_SUCCESS;
}

/* main.cpp */
