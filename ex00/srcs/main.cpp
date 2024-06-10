/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:05:04 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/10 18:05:23 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <sstream>
#include <cstring>
#include "../incs/easyfind.hpp"

/* Definitions of ANSI color codes for console output */
#define GREY        "\033[0;30m"
#define RED         "\033[0;31m"
#define GREEN       "\033[0;32m"
#define YELLOW      "\033[0;33m"
#define BLUE        "\033[0;34m"
#define MAGENTA     "\033[0;35m"
#define CYAN        "\033[0;36m"
#define NC          "\033[0m"

/* Macro for asserting test results and displaying appropriate messages */
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

void testEasyFindPresent()
{
    std::vector<int> vec(10);
    for (int i = 0; i < 10; ++i) {
        vec[i] = i;
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 5);
        ASSERT_TEST(*it == 5, "Found the element 5 in the vector");
    } catch (std::exception &e) {
        ASSERT_TEST(false, e.what());
    }
}

void testEasyFindAbsent()
{
    std::vector<int> vec(10);
    for (int i = 0; i < 10; ++i) {
        vec[i] = i;
    }

    try {
        /* std::vector<int>::iterator it = */ easyfind(vec, 20);
        ASSERT_TEST(false, "Element 20 should not be found in the vector");
    } catch (std::exception &e) {
        ASSERT_TEST(true, "Correctly threw exception when element 20 was not found");
    }
}

void testEasyFindList()
{
    std::list<int> lst;
    for (int i = 0; i < 10; ++i) {
        lst.push_back(i);
    }

    try {
        std::list<int>::iterator it = easyfind(lst, 3);
        ASSERT_TEST(*it == 3, "Found the element 3 in the list");
    } catch (std::exception &e) {
        ASSERT_TEST(false, e.what());
    }

    try {
        /* std::list<int>::iterator it = */ easyfind(lst, 30);
        ASSERT_TEST(false, "Element 30 should not be found in the list");
    } catch (std::exception &e) {
        ASSERT_TEST(true, "Correctly threw exception when element 30 was not found");
    }
}

void testEasyFindDeque()
{
    std::deque<int> deq;
    for (int i = 0; i < 10; ++i) {
        deq.push_back(i);
    }

    try {
        std::deque<int>::iterator it = easyfind(deq, 7);
        ASSERT_TEST(*it == 7, "Found the element 7 in the deque");
    } catch (std::exception &e) {
        ASSERT_TEST(false, e.what());
    }

    try {
        /* std::deque<int>::iterator it = */ easyfind(deq, 70);
        ASSERT_TEST(false, "Element 70 should not be found in the deque");
    } catch (std::exception &e) {
        ASSERT_TEST(true, "Correctly threw exception when element 70 was not found");
    }
}

void testEasyFindSet()
{
    std::set<int> st;
    for (int i = 0; i < 10; ++i) {
        st.insert(i);
    }

    try {
        std::set<int>::iterator it = easyfind(st, 4);
        ASSERT_TEST(*it == 4, "Found the element 4 in the set");
    } catch (std::exception &e) {
        ASSERT_TEST(false, e.what());
    }

    try {
        /* std::set<int>::iterator it = */ easyfind(st, 40);
        ASSERT_TEST(false, "Element 40 should not be found in the set");
    } catch (std::exception &e) {
        ASSERT_TEST(true, "Correctly threw exception when element 40 was not found");
    }
}

void testEasyFindEmpty()
{
    std::vector<int> vec;

    try {
        /* std::vector<int>::iterator it = */ easyfind(vec, 1);
        ASSERT_TEST(false, "Should not find any element in an empty vector");
    } catch (std::exception &e) {
        ASSERT_TEST(true, "Correctly threw exception when searching in an empty vector");
    }
}

void testEasyFindLargeContainer()
{
    std::vector<int> vec(1000000);
    for (int i = 0; i < 1000000; ++i) {
        vec[i] = i;
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 999999);
        ASSERT_TEST(*it == 999999, "Found the element 999999 in the large vector");
    } catch (std::exception &e) {
        ASSERT_TEST(false, e.what());
    }
}

void testEasyFindNegativeAndZero()
{
    int arr[] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

    try {
        std::vector<int>::iterator it = easyfind(vec, -3);
        ASSERT_TEST(*it == -3, "Found the element -3 in the vector");
    } catch (std::exception &e) {
        ASSERT_TEST(false, e.what());
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 0);
        ASSERT_TEST(*it == 0, "Found the element 0 in the vector");
    } catch (std::exception &e) {
        ASSERT_TEST(false, e.what());
    }
}

void testEasyFindMultipleOccurrences()
{
    int arr[] = {1, 2, 3, 2, 1};
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

    try {
        std::vector<int>::iterator it = easyfind(vec, 2);
        ASSERT_TEST(it == vec.begin() + 1, "Found the first occurrence of element 2 in the vector");
    } catch (std::exception &e) {
        ASSERT_TEST(false, e.what());
    }
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << NC << std ::endl;
        std::cout << CYAN << "/*                                 MANDATORY                                  */" << NC << std ::endl;
        std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << NC << std ::endl;

        std::vector<int> vec;
        for (int i = 0; i < 10; ++i) {
            vec.push_back(i);
        }

        try {
            std::vector<int>::iterator it = easyfind(vec, 5);
            std::cout << "Found: " << *it << std::endl;
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            std::vector<int>::iterator it = easyfind(vec, 20);
            std::cout << "Found: " << *it << std::endl;
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    else if (argc == 2 && strcmp(argv[1], "tester") == 0)
    {
        std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << NC << std ::endl;
        std::cout << CYAN << "/*                                 OPTIONNEL                                  */" << NC << std ::endl;
        std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << NC << std ::endl;

        std::cout << MAGENTA << "TEST EASY FIND PRESENT" << NC << std::endl;
        testEasyFindPresent();
        
        std::cout << std::endl << MAGENTA << "TEST EASY FIND ABSENT" << NC << std::endl;
        testEasyFindAbsent();

        std::cout << std::endl << MAGENTA << "TEST EASY FIND WITH LIST" << NC << std::endl;
        testEasyFindList();

        std::cout << std::endl << MAGENTA << "TEST EASY FIND WITH DEQUE" << NC << std::endl;
        testEasyFindDeque();

        std::cout << std::endl << MAGENTA << "TEST EASY FIND WITH SET" << NC << std::endl;
        testEasyFindSet();

        std::cout << std::endl << MAGENTA << "TEST EASY FIND WITH EMPTY CONTAINER" << NC << std::endl;
        testEasyFindEmpty();

        std::cout << std::endl << MAGENTA << "TEST EASY FIND WITH LARGE CONTAINER" << NC << std::endl;
        testEasyFindLargeContainer();

        std::cout << std::endl << MAGENTA << "TEST EASY FIND WITH NEGATIVE AND ZERO" << NC << std::endl;
        testEasyFindNegativeAndZero();

        std::cout << std::endl << MAGENTA << "TEST EASY FIND WITH MULTIPLE OCCURRENCES" << NC << std::endl;
        testEasyFindMultipleOccurrences();
    }
    else
    {
        std::cout << RED << "Usage: ./easyfind or ./easyfind tester" << NC << std::endl;
        return 1;
    }

    return 0;
}
