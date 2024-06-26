/* Building further on the solution for exercise 17-2, add an implementation for operator<< for the person class.
   
   Next, create a pipeline to extract the person of each pair from the vector of pairs, and only keep the first four
   persons. Use the myCopy() algorithm introduced earlier in this chapter to print the names of those four persons
   to the standard output; one name per line.
   
   Finally, create a pipeline but one that additionally projects all filtered Persons to their last name. Again use
   myCopy() to print those last names to the standard output. */

#include <ranges>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class Person
{
public:
	Person(string first, string last)
		: m_firstName{ move(first) }, m_lastName{ move(last) } { }

	const string& getFirstName() const { return m_firstName; }
	const string& getLastName() const { return m_lastName; }
private:
	string m_firstName;
	string m_lastName;
};

ostream& operator<<(ostream& os, const Person& person)
{
	os << person.getFirstName() << " " << person.getLastName();
	return os;
}

template <typename InputIter, typename OutputIter>
void myCopy(InputIter begin, InputIter end, OutputIter target)
{
	for (auto iter{ begin }; iter != end; ++iter, ++target) {
		*target = *iter;
	}
}

int main()
{
	vector persons{
		pair{ Person{ "Izzie", "Fellows" }, 11 },
		pair{ Person{ "Eshaan", "Cooper" }, 15 },
		pair{ Person{ "Rick", "Crouch" }, 48 },
		pair{ Person{ "Faye", "Pittman" }, 35 },
		pair{ Person{ "Jude", "Bone" }, 69 },
		pair{ Person{ "Ella-Louise", "Byers" }, 60 },
		pair{ Person{ "Jad", "Lott" }, 75 },
		pair{ Person{ "Teddie", "Love" }, 24 },
		pair{ Person{ "Niko", "Silva" }, 16 },
		pair{ Person{ "Bryan", "Melendez" }, 42 },
	};

	{
		auto fourPersons{ views::common( // Convert the resulting range to a common range.
			persons
			| views::keys   // Only interested in the first element of each pair, the keys.
			| views::take(4)) };
		myCopy(begin(fourPersons), end(fourPersons), ostream_iterator<Person> { cout, "\n" });
	}

	cout << endl;

	{
		auto fourPersons{ views::common( // Convert the resulting range to a common range.
			persons
			| views::keys   // Only interested in the first element of each pair, the keys.
			| views::take(4)
			| views::transform([](const auto& person) { return person.getLastName(); })) };
		myCopy(begin(fourPersons), end(fourPersons), ostream_iterator<string> { cout, "\n" });
	}
}
