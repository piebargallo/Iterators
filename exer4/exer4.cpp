/* Write a program that uses a range-based for loop and range::istream_view() to read integers from the standard input
   until a -1 is entered. Store the read integers in a vector, and use myCopy() algorithm from earlier in this chapter
   to verify that your vector contains the correct values. 
   
   Bonus exercise: Can you find a couple of ways to change the solution for exercise 17-4 to not use any loops?
   Hint: maybe one option could be to use the std::ranges::copy() algorithm to copy a range from a source to a target.
   It can be called with a range as first argument and an output iterator as the second argument. */

#include<ranges>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

template <typename InputIter, typename OutputIter>
void myCopy(InputIter begin, InputIter end, OutputIter target)
{
	for (auto iter{ begin }; iter != end; ++iter, ++target) {
		*target = *iter;
	}
}

int main()
{
	cout << "> ";

	// Option 1: using a range-based for loop.
	{
		vector<int> values;

		for (auto& value : ranges::istream_view<int>(cin)
			| views::take_while([](const auto& v) {return v != -1; })) {
			values.push_back(value);
		}

		myCopy(begin(values), end(values), ostream_iterator<int> { cout, " "});
	}

	cout << endl << "> ";

	// Option 2: no loop, but using a common view and a vector constructor.
	{
		auto r{ ranges::istream_view<int>(cin)
			| views::take_while([](const auto& v) {return v != -1; })
			| views::common };

		vector<int> values(r.begin(), r.end());

		myCopy(begin(values), end(values), ostream_iterator<int> { cout, " "});
	}

	cout << endl << "> ";

	// Option 3: no loop, but using std::ranges::copy() and a back_inserter.
	{
		vector<int> values;

		ranges::copy(ranges::istream_view<int>(cin)
			| views::take_while([](const auto& v) { return v != -1; }),
			back_inserter(values));

		myCopy(begin(values), end(values), ostream_iterator<int> { cout, " "});
	}
}
