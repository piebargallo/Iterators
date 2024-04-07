/* Write a program that lazily construts the sequence of elements 10-100, squares each number, removes all numbers 
   dividable by five, and transforms the remaining values to strings using std::to_string(). */

#include <ranges>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	auto result{ views::iota(10, 100)
		| views::transform([](const auto& v) { return v * v; })
		| views::filter([](const auto& v) { return v % 5 != 0; })
		| views::transform([](const auto& v) { return to_string(v); }) };

	for (const auto& v : result) {
		cout << v << " ";
	}
	cout << endl;
}
