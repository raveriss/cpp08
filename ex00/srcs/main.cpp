/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:02:28 by raveriss          #+#    #+#             */
/*   Updated: 2024/06/19 16:29:15 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion de la bibliothèque standard pour std::cout */
#include <iostream>

/* Inclusion de la bibliothèque standard pour std::vector */
#include <vector>

/* Inclusion de la bibliothèque standard pour std::list */
#include <list>

/* Inclusion de la bibliothèque standard pour std::deque */
#include <deque>

/* Inclusion de la bibliothèque standard pour std::set */
#include <set>

/* Inclusion de la bibliothèque standard pour std::ostringstream */
#include <sstream>

/* Inclusion de la bibliothèque standard pour std::strcmp */
#include <cstring>

/* Inclusion de la bibliothèque standard pour limites numériques */
#include <limits>

/* Inclusion du fichier d'en-tête easyfind.hpp */
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

/* Define return values */
#define ARG_COUNT 2
#define NO_ARGUMENTS 1
#define RETURN_SUCCESS 0
#define FIRST_ARGUMENT 1
#define RETURN_FAILURE 1
#define TEST_ARG "tester"
#define STRING_COMPARE_SUCCESS 0

/*
    vector : C'est probablement le conteneur le plus utilisé.
Il représente une séquence d'éléments qui peuvent être accédés directement
par leur position (index). Les vectors permettent des insertions et
suppressions rapides à la fin, mais peuvent être coûteux pour des opérations
similaires au début ou au milieu.
    deque (double-ended queue) : Semblable au vector, mais optimisé pour des
insertions et suppressions rapides aux deux extrémités. Les performances pour
accéder à des éléments au milieu sont généralement moins bonnes que celles des
vectors.
    list : Une liste doublement chaînée permettant des insertions et
suppressions efficaces n'importe où dans la liste. Cependant, l'accès direct
par index est lent car il nécessite un parcours séquentiel depuis le début ou
la fin de la liste.
    forward_list : Une liste simplement chaînée, offrant des performances
légèrement meilleures que list pour certaines opérations, mais ne peut être
parcourue que dans un sens.
    array : Conteneur de taille fixe stockant une séquence d'éléments. 
Sa taille doit être connue à la compilation. Offre des performances d'accès
direct similaires à un tableau brut, mais avec les avantages de la STL.
string : Spécialisé pour stocker des séquences de caractères, offre de
nombreuses fonctions pour manipuler des chaînes de texte.
*/

/**
 * @brief Print the elements of a container
 */
template<typename T>
void printContainer(const T& container)
{
    /* Initialize an iterator to the beginning of the container */
	typename T::const_iterator it = container.begin();
    
    /* Print the opening bracket */
	std::cout << "[ ";

    /* Print all elements */
	while (it != container.end())
    {
        /* Print the element */
		std::cout << *it;
        
        /* Move the iterator to the next element */
		++it;

        /* Print a comma if the iterator is not pointing to the last element */
		if (it != container.end())
			std::cout << ", ";
	}

    /* Print the closing bracket */
	std::cout << " ]" << std::endl;
}

/**
 * @brief Print the first three and last three elements of a container
 */
template<typename T>
void printLargeContainer(const T& container)
{
    /* Initialize an iterator to the beginning of the container */
    typename T::const_iterator it = container.begin();

    /* Get the size of the container */
    size_t size = container.size();

    /* Initialize a counter */
    size_t i = 0;

    /* Print the opening bracket */
    std::cout << "[ ";

    /* Check if the size of the container is less than or equal to 6 */
    if (size <= 6)
    {
        /* Print all elements */
        for (; it != container.end(); ++it)
        {
            /* Print the element */
            std::cout << *it;
            
            /* Print a comma if the iterator is not pointing to the last element */
            if (it != --container.end())
                std::cout << ", ";
        }
    }
    else
    {
        /* Print first three elements */
        for (i = 0; i < 3 && it != container.end(); ++i, ++it)
        {
            /* Print the element */
            std::cout << *it << ", ";
        }

        /* Print ellipsis */
        std::cout << "..., ";

        /* Move the iterator to the last three elements */
        it = container.end();

        /* Move the iterator to the previous element */
        for (i = 0; i < 3; ++i)
        {
            /* Move the iterator to the previous element */
            --it;
        }

        /* Print last three elements */
        for (; it != container.end(); ++it)
        {
            /* Print the element */
            std::cout << *it;
            /* Print a comma if the iterator is not pointing to the last element */
            if (it != --container.end())
                std::cout << ", ";
        }
    }
    
    /* Print the closing bracket */
    std::cout << " ]" << std::endl;
}

/**
 * @brief Test the easyfind function with a present element
 */
void testEasyFindPresent()
{
    /* Declare a vector of size 10 */
	std::vector<int> vec(10);

    /* Fill the vector with elements from 0 to 9 */
	for (int i = 0; i < 10; ++i)
    {
        /* Add the element to the vector */
		vec[i] = i;
	}

    /* Print the elements of the vector */
	printContainer(vec);

    /* Try to find the element 5 in the vector */
	try
    {
        /* Search for the element 5 in the vector */
		std::vector<int>::iterator it = easyfind(vec, 5);

        /* Check if the iterator points is pointing to the correct element */
		ASSERT_TEST(*it == 5, "Found the element 5 in the vector");
	}
    
    /* Catch any exceptions */
    catch (std::exception &e)
    {
        /* If the element is not found, the test should fail */
		ASSERT_TEST(false, e.what());
	}
}

/**
 * @brief Test the easyfind function with an absent element
 */
void testEasyFindAbsent()
{
    /* Declare a vector of size 10 */
	std::vector<int> vec(10);

    /* Fill the vector with elements from 0 to 9 */
	for (int i = 0; i < 10; ++i)
    {
        /* Add the element to the vector */
		vec[i] = i;
	}

    /* Print the elements of the vector */
	printContainer(vec);

    /* Try to find the element 20 in the vector */
	try
    {
        /* Search for the element 20 in the vector */
		easyfind(vec, 20);

        /* If the element is found, the test should fail */
		ASSERT_TEST(false, "Element 20 should not be found in the vector");
	}

    /* Catch any exceptions */
    catch (std::exception &e)
    {
        /* If the element is not found, the test should pass */
		ASSERT_TEST(true, "Correctly threw exception when element 20 was not found");
	}
}

/**
 * @brief Test the easyfind function with a list
 */
void testEasyFindList()
{
    /* Declare a list of integers */
	std::list<int> lst;
    
    /* Fill the list with elements from 0 to 9 */
	for (int i = 0; i < 10; ++i)
    {
        /* Add the element to the list */
		lst.push_back(i);
	}

    /* Print the elements of the list */
	printContainer(lst);

    /* Try to find the element 3 in the list */
	try
    {
        /* Search for the element 3 in the list */
		std::list<int>::iterator it = easyfind(lst, 3);

        /* Check if the iterator points it pointing to the correct element */
		ASSERT_TEST(*it == 3, "Found the element 3 in the list");
	}

    /* Catch any exceptions */
    catch (std::exception &e)
    {
        /* If the element is not found, the test should fail */
		ASSERT_TEST(false, e.what());
	}

    /* Try to find the element 30 in the list */
	try
    {
        /* Search for the element 30 in the list */
		easyfind(lst, 30);

        /* If the element is found, the test should fail */
		ASSERT_TEST(false, "Element 30 should not be found in the list");
	}

    /* Catch any exceptions */
    catch (std::exception &e)
    {
        /* If the element is not found, the test should pass */
		ASSERT_TEST(true, "Correctly threw exception when element 30 was not found");
	}
}

/**
 * @brief Test the easyfind function with a deque
 */
void testEasyFindDeque()
{
    /* Declare a deque of integers */
	std::deque<int> deq;

    /* Fill the deque with elements from 0 to 9 */
	for (int i = 0; i < 10; ++i)
    {
        /* Add the element to the deque */
		deq.push_back(i);
	}

    /* Print the elements of the deque */
	printContainer(deq);

    /* Try to find the element 7 in the deque */
	try
    {
        /* Search for the element 7 in the deque */
		std::deque<int>::iterator it = easyfind(deq, 7);

        /* Check if the iterator points to the correct element */
		ASSERT_TEST(*it == 7, "Found the element 7 in the deque");
	}

    /* Catch any exceptions */
    catch (std::exception &e)
    {
        /* If the element is not found, the test should fail */
		ASSERT_TEST(false, e.what());
	}

    /* Search for the element 70 in the deque */
	try
    {
        /* Search for the element 70 in the deque */
		easyfind(deq, 70);

        /* If the element is found, the test should fail */
		ASSERT_TEST(false, "Element 70 should not be found in the deque");
	}
    
    /* Catch any exceptions */
    catch (std::exception &e)
    {
        /* If the element is not found, the test should pass */
		ASSERT_TEST(true, "Correctly threw exception when element 70 was not found");
	}
}

/**
 * @brief Test the easyfind function with a set
 */
void testEasyFindSet()
{
    /* Declare a set of integers */
	std::set<int> st;

    /* Fill the set with elements from 0 to 9 */
	for (int i = 0; i < 10; ++i)
    {
        /* Add the element to the set */
		st.insert(i);
	}

    /* Print the elements of the set */
	printContainer(st);

    /* Try to find the element 4 in the set */
	try
    {
        /* Search for the element 4 in the set */
		std::set<int>::iterator it = easyfind(st, 4);
        
        /* Check if the iterator points to the correct element */
		ASSERT_TEST(*it == 4, "Found the element 4 in the set");
	}

    /* Catch any exceptions */
    catch (std::exception &e)
    {
        /* If the element is not found, the test should fail */
		ASSERT_TEST(false, e.what());
	}

    /* Try to find the element 40 in the set */
	try
    {
        /* Search for the element 40 in the set */
		easyfind(st, 40);

        /* If the element is found, the test should fail */
		ASSERT_TEST(false, "Element 40 should not be found in the set");
	}

    /* Catch any exceptions */
    catch (std::exception &e)
    {
        /* If the element is not found, the test should pass */
		ASSERT_TEST(true, "Correctly threw exception when element 40 was not found");
	}
}

/**
 * @brief Test the easyfind function with an empty container
 */
void testEasyFindEmpty()
{
    /* Initialize an vector */
	std::vector<int> vec;

    /* Print the elements of the empty vector */
	printContainer(vec);

    /* Try to find the element 1 in the empty vector */
	try
    {
        /* Search for the element 1 in the empty vector */
		easyfind(vec, 1);

        /* If the element is found, the test should fail */
		ASSERT_TEST(false, "Should not find any element in an empty vector");
	}

    /* Catch any exceptions */
    catch (std::exception &e)
    {
        /* If the element is not found, the test should pass */
		ASSERT_TEST(true, "Correctly threw exception when searching in an empty vector");
	}
}

/**
 * @brief Test the easyfind function with a large container
 */
void testEasyFindLargeContainer()
{
    /* Initialize a vector with 1 million elements */
	std::vector<int> vec(1000000);
    
    /* Fill the vector with elements from 0 to 999999 */
	for (int i = 0; i < 1000000; ++i)
    {
        /* Add the element to the vector */
		vec[i] = i;
	}

    /* Print the first three and last three elements of the vector */
	printLargeContainer(vec);

    /* Try to find the element 999999 in the large vector */
	try
    {
        /* Search for the element 999999 in the large vector */
		std::vector<int>::iterator it = easyfind(vec, 999999);
        
        /* Check if the iterator points to the correct element */
		ASSERT_TEST(*it == 999999, "Found the element 999999 in the large vector");
	}

    /* Catch any exceptions */
    catch (std::exception &e)
    {
        /* If the element is not found, the test should fail */
		ASSERT_TEST(false, e.what());
	}
}

/**
 * @brief Test the easyfind function with negative and zero elements
 */
void testEasyFindNegativeAndZero() 
{
    /* Initialize an array with negative and zero elements */
	int arr[] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};

    /* Initialize a vector with the array */
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

    /* Print the elements of the vector */
	printContainer(vec);

    /* Try to find the element -3 in the vector */
	try
    {
        /* Search for the element -3 in the vector */
		std::vector<int>::iterator it = easyfind(vec, -3);

        /* Check if the iterator points to the correct element */
		ASSERT_TEST(*it == -3, "Found the element -3 in the vector");
	}
    
    /* Catch any exceptions */
    catch (std::exception &e)
    {
        /* If the element is not found, the test should fail */
		ASSERT_TEST(false, e.what());
	}

    /* Try to find the element 0 in the vector */
	try
    {
        /* Search for the element 0 in the vector */
		std::vector<int>::iterator it = easyfind(vec, 0);

        /* Check if the iterator points to the correct element */
		ASSERT_TEST(*it == 0, "Found the element 0 in the vector");
	}

    /* Catch any exceptions */
    catch (std::exception &e)
    {
        /* If the element is not found, the test should fail */
		ASSERT_TEST(false, e.what());
	}
}

/**
 * @brief Test the easyfind function with multiple occurrences of an element
 */
void testEasyFindMultipleOccurrences()
{
    /* Initialize an array with multiple occurrences of the element 2 */
    int arr[] = {1, 2, 3, 2, 1};

    /* Initialize a vector with the array */
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

    /* Print the elements of the vector */
    printContainer(vec);

    /* Try to find the element 2 in the vector */
    try
    {
        /* Search for the element 2 in the vector */
        std::vector<int>::iterator it = easyfind(vec, 2);

        /* Get the index of the element */
        size_t index = std::distance(vec.begin(), it);

        /* std::find returns an iterator to the first occurrence of the element in the range [first, last) */
        std::vector<int>::iterator expectedIt = std::find(vec.begin(), vec.end(), 2);

        /* Get the index of the first occurrence of the element */
        size_t expectedIndex = std::distance(vec.begin(), expectedIt);
        
        /* Create a string stream to store the message */
        std::ostringstream oss;

        /* Append the message to the string stream */
        oss << "Found the first occurrence of element 2 at index[" << index << "] in the vector";

        /* Check if the iterator points to the correct element and the correct index */
        ASSERT_TEST(*it == 2 && index == expectedIndex, oss.str());
    }

    /* Catch any exceptions */
    catch (std::exception &e)
    {
        /* If the element is not found, the test should fail */
        ASSERT_TEST(false, e.what());
    }
}

/**
 * @brief Test adding a number greater than the maximum int value
 */
void testAddNumberBeyondIntMax()
{
    std::vector<int> vec;
    vec.push_back(1);  // Ajouter un élément pour tester le find

    /* Print the elements of the vector */
    printContainer(vec);

    try
    {
        easyfind(vec, static_cast<long long>(std::numeric_limits<int>::max()) + 1);
        ASSERT_TEST(false, "Exception should be thrown when adding a number greater than max int value");
    }
    catch(const std::overflow_error& e)
    {
        std::cout << CYAN << "Caught exception: " << e.what() << NC << std::endl;
        ASSERT_TEST(true, "Exception thrown as expected");
    }
    catch(const std::exception& e)
    {
        std::cout << CYAN << "Caught unexpected exception: " << e.what() << NC << std::endl;
        ASSERT_TEST(false, "Unexpected exception type");
    }
}

/**
 * @brief Main function
 */
int main(int argc, char *argv[])
{
    /* Check if the program is run without any arguments */
	if (argc == NO_ARGUMENTS)
	{
        /* Print the title of the test mandatory */
		std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << NC << std::endl;
		std::cout << CYAN << "/*                                 MANDATORY                                  */" << NC << std::endl;
		std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << NC << std::endl;

        /* Declare a vector of integers */
		std::vector<int> vec;
        
        /* Fill the vector with elements from 0 to 9 */
		for (int i = 0; i < 10; ++i)
        {
            /* Add the element to the vector */
			vec.push_back(i);
		}

        /* Try to find the element 5 in the vector */
		try
        {
            /* Search for the element 5 in the vector */
			std::vector<int>::iterator it = easyfind(vec, 5);
            
            /* Print the found element */
			std::cout << "Found: " << *it << std::endl;
		}

        /* Catch any exceptions */
        catch (std::exception &e)
        {
            /* Print the exception message */
			std::cerr << e.what() << std::endl;
		}

        /* Try to find the element 20 in the vector */
		try
        {
            /* Search for the element 20 in the vector */
			std::vector<int>::iterator it = easyfind(vec, 20);
            
            /* Print the found element */
			std::cout << "Found: " << *it << std::endl;
		}

        /* Catch any exceptions */
        catch (std::exception &e)
        {
            /* Print the exception message */
			std::cerr << e.what() << std::endl;
		}
	}

    /* Check if the program is run with the argument "tester" */
	else if (argc == ARG_COUNT && strcmp(argv[FIRST_ARGUMENT], TEST_ARG) == STRING_COMPARE_SUCCESS)
	{
        /* Print the title of the test optional */
		std::cout << CYAN << "\n/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << NC << std::endl;
		std::cout << CYAN << "/*                                 OPTIONNEL                                  */" << NC << std::endl;
		std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << NC << std::endl;

        /* Print the title of the test easyfind present */
		std::cout << MAGENTA << "TEST EASYFIND PRESENT" << NC << std::endl;

        /* Test the easyfind function with a present element */
		testEasyFindPresent();

        /* Print the title of the test easyfind absent */
		std::cout << std::endl << MAGENTA << "TEST EASYFIND ABSENT" << NC << std::endl;

        /* Test the easyfind function with an absent element */
		testEasyFindAbsent();

        /* Print the title of the test easyfind with list */
		std::cout << std::endl << MAGENTA << "TEST EASYFIND WITH LIST" << NC << std::endl;

        /* Test the easyfind function with a list */
		testEasyFindList();

        /* Print the title of the test easyfind with deque */
		std::cout << std::endl << MAGENTA << "TEST EASYFIND WITH DEQUE" << NC << std::endl;

        /* Test the easyfind function with a deque */
		testEasyFindDeque();

        /* Print the title of the test easyfind with set */
		std::cout << std::endl << MAGENTA << "TEST EASYFIND WITH SET" << NC << std::endl;

        /* Test the easyfind function with a set */
		testEasyFindSet();

        /* Print the title of the test easyfind with empty container */
		std::cout << std::endl << MAGENTA << "TEST EASYFIND WITH EMPTY CONTAINER" << NC << std::endl;

        /* Test the easyfind function with an empty container */
		testEasyFindEmpty();

        /* Print the title of the test easyfind with large container */
		std::cout << std::endl << MAGENTA << "TEST EASYFIND WITH LARGE CONTAINER" << NC << std::endl;

        /* Test the easyfind function with a large container */
		testEasyFindLargeContainer();

        /* print the title of the test easyfind with negative and zero */
		std::cout << std::endl << MAGENTA << "TEST EASYFIND WITH NEGATIVE AND ZERO" << NC << std::endl;

        /* Test the easyfind function with negative and zero elements */
		testEasyFindNegativeAndZero();

        /* Print the title of the test easyfind with multiple occurrences */
		std::cout << std::endl << MAGENTA << "TEST EASYFIND WITH MULTIPLE OCCURRENCES" << NC << std::endl;

        /* Test the easyfind function with multiple occurrences of an element */
		testEasyFindMultipleOccurrences();

        std::cout << std::endl << MAGENTA << "TEST ADD NUMBER BEYOND INT MAX" << NC << std::endl;
        /* Test adding a number greater than the maximum int value */
        testAddNumberBeyondIntMax();
	}
	else
	{
        /* Print the usage of the program */
		std::cout << RED << "Usage: ./easyfind or ./easyfind tester" << NC << std::endl;

        /* Return 1 if the program did not run successfully */
		return RETURN_FAILURE;
	}

    /* Return 0 if the program ran successfully */
	return RETURN_SUCCESS;
}

/* main.cpp */
