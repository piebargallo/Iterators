#include <vector>
#include <iterator>
#include <iostream>

template <typename IteratorType>
void iteratorTraitsTest(IteratorType it)
{
	typename std::iterator_traits<IteratorType>::value_type temp;
	temp = *it;
	//auto temp{ *it };
	std::cout << temp << std::endl;
}

int main()
{
	std::vector v{ 5 };
	iteratorTraitsTest(cbegin(v));

	return 0;
}
