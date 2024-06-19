/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:44:41 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/19 14:53:11 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion de la classe MutantStack */
#include "../incs/MutantStack.hpp"

/* Inclusion de la bibliothèque standard pour std::cout */
#include <iostream>

/* Inclusion de la bibliothèque standard pour std::vector */
#include <vector>

/* Inclusion de la bibliothèque standard pour std::sstream */
#include <sstream>

/* Inclusion de la bibliothèque standard pour std::cstring */
#include <cstring>

/* Inclusion de la bibliothèque standard pour std::list */
#include <list>

/* Definitions of ANSI color codes for console output */
#define GREY        "\033[0;30m"
#define RED         "\033[0;31m"
#define GREEN       "\033[0;32m"
#define YELLOW      "\033[0;33m"
#define BLUE        "\033[0;34m"
#define MAGENTA     "\033[0;35m"
#define CYAN        "\033[0;36m"
#define WHITE       "\033[0;37m"

#define BRIGHT_GREY    "\033[1;30m"
#define BRIGHT_RED     "\033[1;31m"
#define BRIGHT_GREEN   "\033[1;32m"
#define BRIGHT_YELLOW  "\033[1;33m"
#define BRIGHT_BLUE    "\033[1;34m"
#define BRIGHT_MAGENTA "\033[1;35m"
#define BRIGHT_CYAN    "\033[1;36m"
#define BRIGHT_WHITE   "\033[1;37m"

#define BLACK_BG       "\033[40m"
#define RED_BG         "\033[41m"
#define GREEN_BG       "\033[42m"
#define YELLOW_BG      "\033[43m"
#define BLUE_BG        "\033[44m"
#define MAGENTA_BG     "\033[45m"
#define CYAN_BG        "\033[46m"
#define WHITE_BG       "\033[47m"

#define BOLD           "\033[1m"
#define UNDERLINE      "\033[4m"
#define RESET          "\033[0m"

/* No Color */
#define NC             RESET

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
    if (expression) { std::cout << GREEN "[TEST PASSED]" << WHITE << BOLD << " " << message << NC << std::endl; } \
    else { std::cout << RED "[TEST FAILED]" << NC << " " << message << std::endl; }

/**
 * @brief Test initialization and destruction
 */
void testInitializationAndDestruction()
{
    std::cout << MAGENTA << "TEST INITIALIZATION AND DESTRUCTION" << NC << std::endl;
    MutantStack<int> stack;
    
    /* Imprimer le contenu de la pile */
    stack.printContainer(); 
    
    ASSERT_TEST(stack.empty(), "Newly created stack should be empty");
}

/**
 * @brief Test basic operations
 */
void testBasicOperations()
{
    std::cout << std::endl << MAGENTA << "TEST BASIC OPERATIONS" << NC << std::endl;
    MutantStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    /* Imprimer le contenu de la pile */
    stack.printContainer(); 
    
    ASSERT_TEST(stack.size() == 3, "Stack size should be 3 after pushing 3 elements");
    ASSERT_TEST(stack.top() == 3, "Top element should be 3");
    stack.pop();

    /* Imprimer le contenu de la pile */
    stack.printContainer(); 
    
    ASSERT_TEST(stack.size() == 2, "Stack size should be 2 after popping one element");
    ASSERT_TEST(stack.top() == 2, "Top element should be 2 after popping");
    ASSERT_TEST(!stack.empty(), "Stack should not be empty");
    stack.pop();
    stack.pop();

    /* Imprimer le contenu de la pile */
    stack.printContainer(); 
    
    ASSERT_TEST(stack.empty(), "Stack should be empty after popping all elements");
}

/**
 * @brief Test iterators
 */
void testIterators()
{
    std::cout << std::endl << MAGENTA << "TEST ITERATORS" << NC << std::endl;
    MutantStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
    /* Imprimer le contenu de la pile */
    stack.printContainer();    
    
    MutantStack<int>::iterator it = stack.begin();
    ASSERT_TEST(*it == 1, "Begin iterator should point to the first element");
    ++it;
    ASSERT_TEST(*it == 2, "Iterator increment should point to the second element");
    --it;
    ASSERT_TEST(*it == 1, "Iterator decrement should point back to the first element");
    it = stack.end();
    --it;
    ASSERT_TEST(*it == 3, "End iterator should point past the last element");
}

/**
 * @brief Test performance with a large number of elements
 */
void testPerformance()
{
    std::cout << std::endl << MAGENTA << "TEST PERFORMANCE" << NC << std::endl;
    MutantStack<int> stack;
    for (int i = 0; i < 1000000; ++i)
    {
        stack.push(i);
    }

    /* Imprimer le contenu de la pile */
    stack.printLargeContainer();
    
    ASSERT_TEST(stack.size() == 1000000, "Stack size should be 1000000 after pushing 1000000 elements");
    for (int i = 0; i < 1000000; ++i)
    {
        stack.pop();
    }

    /* Imprimer le contenu de la pile */
    stack.printContainer();     
    
    ASSERT_TEST(stack.empty(), "Stack should be empty after popping all elements");
}

/**
 * @brief Test robustness with different data types
 */
void testRobustness()
{
    std::cout << std::endl << MAGENTA << "TEST ROBUSTNESS" << NC << std::endl;
    MutantStack<double> doubleStack;
    doubleStack.push(1.1);
    doubleStack.push(2.2);
    doubleStack.push(3.3);

    /* Imprimer le contenu de la pile */
    doubleStack.printContainer();  
    
    ASSERT_TEST(doubleStack.size() == 3, "Double stack size should be 3");

    MutantStack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");

    /* Imprimer le contenu de la pile */
    stringStack.printContainer();  
    
    ASSERT_TEST(stringStack.top() == "World", "Top element should be 'World'");
}

/**
 * @brief Test comparison with other containers
 */
void testComparison()
{
    std::cout << std::endl << MAGENTA << "TEST COMPARISON" << NC << std::endl;
    MutantStack<int> stack;
    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 0; i < 1000; ++i)
    {
        stack.push(i);
        vec.push_back(i);
        deq.push_back(i);
    }

    /* Imprimer le contenu de la pile */
    stack.printLargeContainer(); 

    ASSERT_TEST(stack.size() == vec.size(), "Stack size should match vector size");
    ASSERT_TEST(stack.size() == deq.size(), "Stack size should match deque size");
}

/**
 * @brief Test integration with other data structures
 */
void testIntegration()
{
    std::cout << std::endl << MAGENTA << "TEST INTEGRATION" << NC << std::endl;
    
    /* Example use case: Copying elements between MutantStack and std::vector */

    /* Create a MutantStack and push some elements */
    MutantStack<int> mstack;
    for (int i = 0; i < 10; ++i)
    {
        mstack.push(i);
    }

    /* Copy elements from MutantStack to std::vector */
    std::vector<int> vec(mstack.begin(), mstack.end());

    /* Imprimer le contenu de la pile */
    mstack.printContainer();  
    
    ASSERT_TEST(vec.size() == 10, "Vector size should be 10 after copying from MutantStack");
    for (int i = 0; i < 10; ++i)
    {
        ASSERT_TEST(vec[i] == i, "Vector elements should match the elements pushed to MutantStack");
    }

    /* Modify the std::vector */
    for (int i = 0; i < 10; ++i)
    {
        vec[i] = i * 2;
    }

    /* Clear the MutantStack and copy modified elements back from std::vector */
    while (!mstack.empty())
    {
        mstack.pop();
    }
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        mstack.push(*it);
    }

    /* Verify the elements in MutantStack match the modified std::vector */
    int expected_value = 18;
    bool allTestsPassed = true;
    while (!mstack.empty())
    {
        if (mstack.top() != expected_value)
            allTestsPassed = false;
        mstack.pop();
        expected_value -= 2;
    }

    /* Imprimer le contenu de la pile */
    mstack.printContainer();      
    
    ASSERT_TEST(allTestsPassed, "MutantStack elements should match modified vector elements after copying back");
}

/**
 * @brief Test resilience
 */
void testResilience()
{
    std::cout << MAGENTA << std::endl << "TEST RESILIENCE" << NC << std::endl;
    bool allTestsPassed = true;

    for (int i = 0; i < 1000; ++i)
    {
        MutantStack<int> stack;
        for (int j = 0; j < 100; ++j)
        {
            stack.push(j);
        }
        if (stack.size() != 100)
        {
            allTestsPassed = false;
        }

        for (int j = 99; j >= 0; --j)
        {
            if (stack.top() != j)
                allTestsPassed = false;
            stack.pop();
        }
        if (!stack.empty())
            allTestsPassed = false;
    }

    ASSERT_TEST(allTestsPassed, "Test resilience completed successfully.");
}

/**
 * @brief Test backup and restore
 */
void testBackupAndRestore()
{
    std::cout << std::endl << MAGENTA << "TEST BACKUP AND RESTORE" << NC << std::endl;
    MutantStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::vector<int> backup;
    for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); ++it)
    {
        backup.push_back(*it);
    }

    MutantStack<int> restoredStack;
    for (size_t i = 0; i < backup.size(); ++i)
    {
        restoredStack.push(backup[i]);
    }

    /* Imprimer le contenu de la pile */
    stack.printContainer();  

    ASSERT_TEST(stack.size() == restoredStack.size(), "Restored stack should have the same size as the original stack");
    ASSERT_TEST(stack.top() == restoredStack.top(), "Restored stack should have the same top element as the original stack");
}

/**
 * @brief Test exception handling
 */
void testExceptionHandling()
{
    std::cout << std::endl << MAGENTA << "TEST EXCEPTION HANDLING" << NC << std::endl;
    MutantStack<int> stack;

    /* Imprimer le contenu de la pile */
    stack.printContainer(); 

    try
    {
        stack.pop();
        /* Si nous arrivons ici, l'exception n'a pas été lancée, ce qui est une erreur */
        ASSERT_TEST(0, "Exception should be thrown when popping from an empty stack");
    } catch (const std::exception& e)
    {
        /* L'exception a été lancée comme prévu */
        std::string message = "Exception thrown as expected: ";
        message += e.what();
        ASSERT_TEST(1, message.c_str());
    }

    try
    {
        stack.top();
        /* Si nous arrivons ici, l'exception n'a pas été lancée, ce qui est une erreur */
        ASSERT_TEST(0, "Exception should be thrown when accessing top of an empty stack");
    }
    catch (const std::exception& e)
    {
        /* L'exception a été lancée comme prévu */
        std::string message = "Exception thrown as expected: ";
        message += e.what();
        ASSERT_TEST(1, message.c_str());
    }
}

/**
 * @brief Test intensive usage
 */
void testIntensiveUsage()
{
    std::cout << std::endl << MAGENTA << "TEST INTENSIVE USAGE" << NC << std::endl;
    MutantStack<int> stack;

    std::cout << BRIGHT_CYAN << "Pushing 1000000 elements..." << NC << std::endl;
    for (int i = 0; i < 1000000; ++i)
    {
        stack.push(i);
    }

    /* Imprimer le contenu de la pile */
    stack.printLargeContainer();
    
    std::cout << BRIGHT_CYAN << "\nPopping 1000000 elements..." << NC << std::endl;
    for (int i = 0; i < 1000000; ++i)
    {
        stack.pop();
    }

    /* Imprimer le contenu de la pile */
    stack.printLargeContainer();
    
    ASSERT_TEST(stack.empty(), "Stack should be empty after intensive usage");
}

/**
 * @brief Test performance balance
 */
void testPerformanceBalance()
{
    std::cout << std::endl << MAGENTA << "TEST PERFORMANCE BALANCE" << NC << std::endl;
    MutantStack<int> stack;
    std::cout << BRIGHT_CYAN << "Pushing 1000 elements..." << NC << std::endl;
    for (int i = 0; i < 1000; ++i)
    {
        stack.push(i);
    }

    /* Imprimer le contenu de la pile */
    stack.printLargeContainer();
    
    ASSERT_TEST(stack.size() == 1000, "Stack size should be 1000 after pushing 1000 elements");

    std::cout << BRIGHT_CYAN << "\nPopping 500 elements..." << NC << std::endl;
    for (int i = 0; i < 500; ++i)
    {
        stack.pop();
    }

    /* Imprimer le contenu de la pile */
    stack.printLargeContainer();
    
    ASSERT_TEST(stack.size() == 500, "Stack size should be 500 after popping 500 elements");

    std::cout << BRIGHT_CYAN << "\nPushing another 500 elements..." << NC << std::endl;
    for (int i = 0; i < 500; ++i)
    {
        stack.push(i);
    }

    /* Imprimer le contenu de la pile */
    stack.printLargeContainer();
    
    ASSERT_TEST(stack.size() == 1000, "Stack size should be 1000 after pushing another 500 elements");
}


/**
 * @brief Test pushing a number greater than max int value
 */ 
void testPushWithCheck()
{
    std::cout << std::endl << MAGENTA << "TEST PUSH WITH CHECK" << NC << std::endl;
    
    MutantStack<int> stack;

    try
    {
        stack.push_with_check(static_cast<long long>(std::numeric_limits<int>::max()) + 1);
        ASSERT_TEST(false, "Exception should be thrown when pushing a number greater than max int value");
    }
    catch(const std::overflow_error& e)
    {
        std::cout << CYAN << "Caught exception: " << e.what() << NC << std::endl;
        ASSERT_TEST(true, "Exception thrown as expected");
    }
    catch(const std::exception& e)
    {
        std::cout << "Caught unexpected exception: " << e.what() << std::endl;
        ASSERT_TEST(false, "Unexpected exception type");
    }
}

/**
 * @brief Run all tests
 */
void runTests()
{
    testInitializationAndDestruction();
    testBasicOperations();
    testIterators();
    testPerformance();
    testRobustness();
    testComparison();
    testIntegration();
    testResilience();
    testBackupAndRestore();
    testExceptionHandling();
    testIntensiveUsage();
    testPerformanceBalance();
    testPushWithCheck();
}

void printList(const std::list<int>& lst)
{
    std::cout << "[ ";
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
    {
        if (it != lst.begin())
        {
            std::cout << ", ";
        }
        std::cout << *it;
    }
    std::cout << " ]" << std::endl;
}

/**
 * @brief Main function
 */
int main(int argc, char *argv[])
{
    if (argc == NO_ARGUMENTS)
    {
		std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << NC << std::endl;
		std::cout << CYAN << "/*                                 MANDATORY                                  */" << NC << std::endl;
		std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << NC << std::endl;

        /* Code pour les tests de base (équivalent au mode "MANDATORY") */
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);

        /*  Devrait afficher 17 */
        std::cout << mstack.top() << std::endl;
        mstack.pop();

        /* Devrait afficher 1 */
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        std::stack<int> s(mstack);

        std::cout << MAGENTA << std::endl << "TEST AVEC STD::LIST USAGE" << NC << std::endl << std::endl;
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(17);

        /*  Devrait afficher 17 */
        std::cout << lst.back() << std::endl;
        lst.pop_back();
        
        /* Devrait afficher 5 */
        std::cout << lst.size() << std::endl;
        
        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        lst.push_back(0);
        
        std::list<int>::iterator itlst = lst.begin();
        std::list<int>::iterator itelst = lst.end();
        ++itlst;
        --itlst;
        while (itlst != itelst)
        {
            std::cout << *itlst << std::endl;
            ++itlst;
        }
        
        std::list<int> lst2(lst);

        std::cout << std::endl << "Liste:" << std::endl;
        printList(lst2);
    }
    else if (argc == ARG_ONE && strcmp(argv[FIRST_ARGUMENT], TEST_ARG) == STRING_COMPARE_SUCCESS)
    {
        /* Code pour les tests détaillés (équivalent au mode "OPTIONNEL") */
        std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << NC << std::endl;
        std::cout << CYAN << "/*                                 OPTIONNEL                                  */" << NC << std::endl;
        std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << NC << std::endl;

        runTests();
    }
    else
    {
        std::cout << RED << "Usage: ./mutantstack or ./mutantstack tester" << NC << std::endl;
        return RETURN_FAILURE;
    }
    
    return RETURN_SUCCESS;
}

/* main.cpp */
