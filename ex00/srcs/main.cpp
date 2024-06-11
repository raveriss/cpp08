#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <sstream>
#include <cstring>
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

/**
 * @brief Print the first three and last three elements of a container
 */
template<typename T>
void printLargeContainer(const T& container)
{
    typename T::const_iterator it = container.begin();
    typename T::const_iterator end = container.end();
    size_t size = container.size();
    size_t i = 0;

    std::cout << "[ ";

    // Print first three elements
    for (i = 0; i < 3 && it != end; ++i, ++it)
    {
        std::cout << *it << ", ";
    }

    // Print ellipsis if there are more than 6 elements
    if (size > 6)
    {
        std::cout << "..., ";
        std::advance(it, size - 6); // Move iterator to the 4th element from the end
    }

    // Print last three elements
    for (; it != end; ++it)
    {
        std::cout << *it;
        if (it != --end)
            std::cout << ", ";
    }

    std::cout << " ]" << std::endl;
}

/**
 * @brief Print the elements of a container
 */
template<typename T>
void printContainer(const T& container)
{
	typename T::const_iterator it = container.begin();
	std::cout << "[ ";
	while (it != container.end())
    {
		std::cout << *it;
		++it;
		if (it != container.end())
			std::cout << ", ";
	}
	std::cout << " ]" << std::endl;
}

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
 * @brief Test the easyfind function with a present element
 */
void testEasyFindPresent()
{
	std::vector<int> vec(10);
	for (int i = 0; i < 10; ++i)
    {
		vec[i] = i;
	}

	printContainer(vec);

	try
    {
		std::vector<int>::iterator it = easyfind(vec, 5);
		ASSERT_TEST(*it == 5, "Found the element 5 in the vector");
	}
    catch (std::exception &e)
    {
		ASSERT_TEST(false, e.what());
	}
}

/**
 * @brief Test the easyfind function with an absent element
 */
void testEasyFindAbsent()
{
	std::vector<int> vec(10);
	for (int i = 0; i < 10; ++i)
    {
		vec[i] = i;
	}

	printContainer(vec);

	try
    {
		easyfind(vec, 20);
		ASSERT_TEST(false, "Element 20 should not be found in the vector");
	}
    catch (std::exception &e)
    {
		ASSERT_TEST(true, "Correctly threw exception when element 20 was not found");
	}
}

/**
 * @brief Test the easyfind function with a list
 */
void testEasyFindList()
{
	std::list<int> lst;
	for (int i = 0; i < 10; ++i)
    {
		lst.push_back(i);
	}

	printContainer(lst);

	try
    {
		std::list<int>::iterator it = easyfind(lst, 3);
		ASSERT_TEST(*it == 3, "Found the element 3 in the list");
	}
    catch (std::exception &e)
    {
		ASSERT_TEST(false, e.what());
	}

	try
    {
		easyfind(lst, 30);
		ASSERT_TEST(false, "Element 30 should not be found in the list");
	}
    catch (std::exception &e)
    {
		ASSERT_TEST(true, "Correctly threw exception when element 30 was not found");
	}
}

/**
 * @brief Test the easyfind function with a deque
 */
void testEasyFindDeque()
{
	std::deque<int> deq;
	for (int i = 0; i < 10; ++i)
    {
		deq.push_back(i);
	}

	printContainer(deq);

	try
    {
		std::deque<int>::iterator it = easyfind(deq, 7);
		ASSERT_TEST(*it == 7, "Found the element 7 in the deque");
	}
    catch (std::exception &e)
    {
		ASSERT_TEST(false, e.what());
	}

	try
    {
		easyfind(deq, 70);
		ASSERT_TEST(false, "Element 70 should not be found in the deque");
	}
    catch (std::exception &e)
    {
		ASSERT_TEST(true, "Correctly threw exception when element 70 was not found");
	}
}

/**
 * @brief Test the easyfind function with a set
 */
void testEasyFindSet()
{
	std::set<int> st;
	for (int i = 0; i < 10; ++i)
    {
		st.insert(i);
	}

	printContainer(st);

	try
    {
		std::set<int>::iterator it = easyfind(st, 4);
		ASSERT_TEST(*it == 4, "Found the element 4 in the set");
	}
    catch (std::exception &e)
    {
		ASSERT_TEST(false, e.what());
	}

	try
    {
		easyfind(st, 40);
		ASSERT_TEST(false, "Element 40 should not be found in the set");
	}
    catch (std::exception &e)
    {
		ASSERT_TEST(true, "Correctly threw exception when element 40 was not found");
	}
}

/**
 * @brief Test the easyfind function with an empty container
 */
void testEasyFindEmpty()
{
	std::vector<int> vec;

	printContainer(vec);

	try
    {
		easyfind(vec, 1);
		ASSERT_TEST(false, "Should not find any element in an empty vector");
	}
    catch (std::exception &e)
    {
		ASSERT_TEST(true, "Correctly threw exception when searching in an empty vector");
	}
}

/**
 * @brief Print the first three and last three elements of a container
 */
template<typename T>
void printFifoContainer(const T& container)
{
    typename T::const_iterator it = container.begin();
    size_t size = container.size();
    size_t i = 0;

    std::cout << "[ ";

    if (size <= 6)
    {
        // Print all elements if container size is 6 or less
        for (; it != container.end(); ++it)
        {
            std::cout << *it;
            if (it != --container.end())
                std::cout << ", ";
        }
    }
    else
    {
        // Print first three elements
        for (i = 0; i < 3 && it != container.end(); ++i, ++it)
        {
            std::cout << *it << ", ";
        }
        // Print ellipsis
        std::cout << "..., ";
        // Print last three elements
        it = container.end();
        for (i = 0; i < 3; ++i)
        {
            --it;
        }
        for (; it != container.end(); ++it)
        {
            std::cout << *it;
            if (it != --container.end())
                std::cout << ", ";
        }
    }

    std::cout << " ]" << std::endl;
}

/**
 * @brief Test the easyfind function with a large container
 */
void testEasyFindLargeContainer()
{
	std::vector<int> vec(1000000);
	for (int i = 0; i < 1000000; ++i)
    {
		vec[i] = i;
	}

	printFifoContainer(vec);

	try
    {
		std::vector<int>::iterator it = easyfind(vec, 999999);
		ASSERT_TEST(*it == 999999, "Found the element 999999 in the large vector");
	}
    catch (std::exception &e)
    {
		ASSERT_TEST(false, e.what());
	}
}

/**
 * @brief Test the easyfind function with negative and zero elements
 */
void testEasyFindNegativeAndZero() 
{
	int arr[] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

	printContainer(vec);

	try
    {
		std::vector<int>::iterator it = easyfind(vec, -3);
		ASSERT_TEST(*it == -3, "Found the element -3 in the vector");
	}
    catch (std::exception &e)
    {
		ASSERT_TEST(false, e.what());
	}

	try
    {
		std::vector<int>::iterator it = easyfind(vec, 0);
		ASSERT_TEST(*it == 0, "Found the element 0 in the vector");
	}
    catch (std::exception &e)
    {
		ASSERT_TEST(false, e.what());
	}
}

/**
 * @brief Test the easyfind function with multiple occurrences of an element
 */
void testEasyFindMultipleOccurrences()
{
    int arr[] = {1, 2, 3, 2, 1};
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

    printContainer(vec);

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 2);
        size_t index = std::distance(vec.begin(), it);

        // Find the expected index of the first occurrence of the element 2
        std::vector<int>::iterator expectedIt = std::find(vec.begin(), vec.end(), 2);
        size_t expectedIndex = std::distance(vec.begin(), expectedIt);
        
        std::ostringstream oss;
        oss << "Found the first occurrence of element 2 at index[" << index << "] in the vector";

        // Check if the iterator points to the correct element and the correct index
        ASSERT_TEST(*it == 2 && index == expectedIndex, oss.str());
    }
    catch (std::exception &e)
    {
        ASSERT_TEST(false, e.what());
    }
}

/**
 * @brief Main function
 */
int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << NC << std::endl;
		std::cout << CYAN << "/*                                 MANDATORY                                  */" << NC << std::endl;
		std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << NC << std::endl;

		std::vector<int> vec;
		for (int i = 0; i < 10; ++i)
        {
			vec.push_back(i);
		}

		try
        {
			std::vector<int>::iterator it = easyfind(vec, 5);
			std::cout << "Found: " << *it << std::endl;
		}
        catch (std::exception &e)
        {
			std::cerr << e.what() << std::endl;
		}

		try
        {
			std::vector<int>::iterator it = easyfind(vec, 20);
			std::cout << "Found: " << *it << std::endl;
		}
        catch (std::exception &e)
        {
			std::cerr << e.what() << std::endl;
		}
	}
	else if (argc == 2 && strcmp(argv[1], "tester") == 0)
	{
		std::cout << CYAN << "\n/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << NC << std::endl;
		std::cout << CYAN << "/*                                 OPTIONNEL                                  */" << NC << std::endl;
		std::cout << CYAN << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << NC << std::endl;

		std::cout << MAGENTA << "TEST EASYFIND PRESENT" << NC << std::endl;
		testEasyFindPresent();

		std::cout << std::endl << MAGENTA << "TEST EASYFIND ABSENT" << NC << std::endl;
		testEasyFindAbsent();

		std::cout << std::endl << MAGENTA << "TEST EASYFIND WITH LIST" << NC << std::endl;
		testEasyFindList();

		std::cout << std::endl << MAGENTA << "TEST EASYFIND WITH DEQUE" << NC << std::endl;
		testEasyFindDeque();

		std::cout << std::endl << MAGENTA << "TEST EASYFIND WITH SET" << NC << std::endl;
		testEasyFindSet();

		std::cout << std::endl << MAGENTA << "TEST EASYFIND WITH EMPTY CONTAINER" << NC << std::endl;
		testEasyFindEmpty();

		std::cout << std::endl << MAGENTA << "TEST EASYFIND WITH LARGE CONTAINER" << NC << std::endl;
		testEasyFindLargeContainer();

		std::cout << std::endl << MAGENTA << "TEST EASYFIND WITH NEGATIVE AND ZERO" << NC << std::endl;
		testEasyFindNegativeAndZero();

		std::cout << std::endl << MAGENTA << "TEST EASYFIND WITH MULTIPLE OCCURRENCES" << NC << std::endl;
		testEasyFindMultipleOccurrences();
	}
	else
	{
		std::cout << RED << "Usage: ./easyfind or ./easyfind tester" << NC << std::endl;
		return 1;
	}

	return 0;
}

/* main.cpp */
