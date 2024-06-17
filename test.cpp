#include <vector>
#include <iterator>

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::vector<int>::iterator it = v.begin();
    std::vector<int>::iterator ite = v.end();

    for (; it != ite; ++it)
    {
        std::cout << *it;
        if (it != --v.end())
            std::cout << ", ";
    }
    std::cout << std::endl;

    return 0;
}