#include <vector>
#include <iostream>

template<typename Iter>
void myPrint(Iter begin, Iter end)
{
	for (auto iter{ begin }; iter != end; ++iter) {
		std::cout << *iter << " ";
	}
}

int main()
{
	std::vector values{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (auto iter{ cbegin(values) }; iter != cend(values); ++iter) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;

	myPrint(cbegin(values), cend(values));
	std::cout << std::endl;

	return 0;
}