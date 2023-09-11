#include <iterator>
#include <vector>
#include <format>
#include <iostream>

template<typename Iter>
auto myFind(Iter begin, Iter end, const typename std::iterator_traits<Iter>::value_type& value)
{
	for (auto iter{ begin }; iter != end; ++iter) {
		if (*iter == value) {
			return iter;
		}
	}
	return end;
}

int main()
{
	std::vector values{ 11, 22, 33, 44 };

	auto result{ myFind(cbegin(values), cend(values), 22) };
	if (result != cend(values)) {
		std::cout << std::format("Found value at position {}", distance(cbegin(values), result));
	}

	return 0;
}