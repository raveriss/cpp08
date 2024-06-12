#ifndef SPAN_TPP
#define SPAN_TPP

#include "../incs/Span.hpp"

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
    if (_data.size() + std::distance(begin, end) > _n)
        throw SpanException("Span will exceed capacity");
    _data.insert(_data.end(), begin, end);
}

#endif
