#include "../incs/Span.hpp"

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &other) : _n(other._n), _data(other._data) {}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _n = other._n;
        _data = other._data;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (_data.size() >= _n)
    {
        throw SpanException("Span is full");
    }
    _data.push_back(number);
}

int Span::shortestSpan() const
{
    if (_data.size() < 2)
    {
        throw SpanException("Not enough elements to find a span");
    }
    std::vector<int> sorted = _data;
    std::sort(sorted.begin(), sorted.end());
    int shortest = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; ++i)
    {
        int span = sorted[i + 1] - sorted[i];
        if (span < shortest)
        {
            shortest = span;
        }
    }
    return shortest;
}

int Span::longestSpan() const
{
    if (_data.size() < 2)
    {
        throw SpanException("Not enough elements to find a span");
    }
    int min = *std::min_element(_data.begin(), _data.end());
    int max = *std::max_element(_data.begin(), _data.end());
    return max - min;
}

unsigned int Span::size() const
{
    return _data.size();
}

unsigned int Span::capacity() const
{
    return _n;
}
