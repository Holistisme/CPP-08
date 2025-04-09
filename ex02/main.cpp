#include "MutantStack/MutantStack.hpp"

/* ############################################################################################## */

#include "ColorFormatLib/ColorFormat.hpp"
#include "InputLib/Input.hpp"

/* ############################################################################################## */

#include <iostream>
#include <list>
#include <stack>

/* ############################################################################################## */

#define le <=
#define eq ==

/* ############################################################################################## */

static inline void begin(const MutantStack<int> &container);
static inline void begin(const std::list<int> &container);
static inline void empty(MutantStack<int> &container);
static inline void empty(std::list<int> &container);
static inline void end(const MutantStack<int> &container);
static inline void end(const std::list<int> &container);
static inline void rbegin(const MutantStack<int> &container);
static inline void rbegin(const std::list<int> &container);
static inline void rend(const MutantStack<int> &container);
static inline void rend(const std::list<int> &container);
static inline void pop(MutantStack<int> &container);
static inline void pop(std::list<int> &container);
static inline void push(MutantStack<int> &container, const int value);
static inline void push(std::list<int> &container, const int value);
static inline void size(MutantStack<int> &container);
static inline void size(std::list<int> &container);
static inline void top(MutantStack<int> &container);
static inline void top(std::list<int> &container);

/* ############################################################################################## */

#include <iostream>
#include <list>
#include <stack>

int main() {
	try {
		std::cout << "\nWelcome to the program ”" << ColorFormat::formatString("Mutation™", "red", "blink", "bold") << "“!" << std::endl;
	
		MutantStack<int> mutant;
		std::list<int>	 list;
	
		std::cout << "_______________________________________________________________________________\n" << std::endl;
		std::cout << "You can execute following indexes:\n"
										 << ColorFormat::formatString("\n0 - EXIT", "red", "italic")	 << ": to end the program"
										 << ColorFormat::formatString("\n1 - BEGIN", "blue", "italic")	 << ": to list containers from the beginning."
										 << ColorFormat::formatString("\n2 - EMPTY", "green", "italic")	 << ": to check if containers are empty."
										 << ColorFormat::formatString("\n3 - END", "yellow", "italic")	 << ": to list the containers from the end."
										 << ColorFormat::formatString("\n4 - RBEGIN", "cyan", "italic")	 << ": to list containers from the reverse beginning."
										 << ColorFormat::formatString("\n5 - REND", "magenta", "italic") << ": to list containers from the reverse end."
										 << ColorFormat::formatString("\n6 - POP", "red", "italic")		 << ": to remove the element on top of the stacks."
										 << ColorFormat::formatString("\n7 - SIZE", "blue", "italic")	 << ": to get the size of the stacks."
										 << ColorFormat::formatString("\n8 - TOP", "green", "italic")	 << ": to get the element on top of the stacks."
										 << ColorFormat::formatString("\n9 - PUSH", "yellow", "italic")	 << ": to add a number to the stacks." << std::endl;
		std::cout << "_______________________________________________________________________________"	 << std::endl;

		bool running = true;
		while (running) {
			std::cout << std::endl;
			try {
				switch (Input().integerFormat()) {
					case 0:	running = false;
							break;
					case 1:	begin(mutant), begin(list);
							break;
					case 2:	empty(mutant), empty(list);
							break;
					case 3:	end(mutant), end(list);
							break;
					case 4:	rbegin(mutant), rbegin(list);
							break;
					case 5:	rend(mutant), rend(list);
							break;
					case 6:	pop(mutant), pop(list);
							break;
					case 7:	size(mutant), size(list);
							break;
					case 8:	top(mutant), top(list);
							break;
					case 9:	const int value = Input("\nValue to add:").integerFormat();
							push(mutant, value), push(list, value);
							break;
				}
			} catch (const std::exception &e) { std::cerr << ColorFormat::formatString("Please use realistic values: ", "red", "bold") << e.what() << std::endl; }
		}
	} catch (const std::exception &e) { std::cerr << ColorFormat::formatString("The following error has been encountered: ", "red", "bold") << e.what() << std::endl; }
	std::cout << "\nThanks for using ”"			  << ColorFormat::formatString("Mutation™", "red", "blink", "bold")							<< "“!\n"	<< std::endl;
	return 0;
}

/* ############################################################################################## */

static inline void begin(const MutantStack<int> &container) {
	std::ostringstream stream;
	stream << "\nThe MutantStack contains: ";

	if (not container.empty()) {
		for (MutantStack<int>::const_iterator iterator = container.begin(); iterator neq container.end(); iterator++) {
			stream << *iterator;
			iterator + 1 neq container.end() ? stream << ", "
											 : stream << ".";
		}
	} else stream << "none."; 
	std::cout << stream.str() << std::endl;
}

static inline void begin(const std::list<int> &container) {
	std::ostringstream stream;
	stream << "The List contains: ";

	if (not container.empty()) {
		for (std::list<int>::const_iterator iterator = container.begin(); iterator neq container.end(); iterator++) {
			stream << *iterator;
	
			std::list<int>::const_iterator next = iterator;
			++next;
	
			next neq container.end() ? stream << ", "
									 : stream << ".";
		}
	} else stream << "none."; 
	std::cout << stream.str() << std::endl;
}

/* ############################################################################################## */

static inline void empty(MutantStack<int> &container) {
	container.empty() ? std::cout << "\nMutantStack is empty."	   << std::endl
					  : std::cout << "\nMutantStack is not empty." << std::endl;
}

static inline void empty(std::list<int> &container) {
	container.empty() ? std::cout << "List is empty."	   << std::endl
					  : std::cout << "List is not empty." << std::endl;
}

/* ############################################################################################## */

static inline void end(const MutantStack<int> &container) {
	std::ostringstream stream;
	stream << "\nThe MutantStack contains: ";

	if (not container.empty()) {
		MutantStack<int>::const_iterator iterator = container.end() - 1;
		do {
            stream << *iterator;
			iterator eq container.begin() ? stream << "."
										  : stream << ", ";
		} while (iterator-- neq container.begin());
	} else stream << "none."; 
	std::cout << stream.str() << std::endl;
}

static inline void end(const std::list<int> &container) {
	std::ostringstream stream;
	stream << "The List contains: ";

	if (not container.empty()) {
		std::list<int>::const_iterator iterator = container.end();
		do {
            stream << *(--iterator);
			iterator eq container.begin() ? stream << "."
										  : stream << ", ";
		} while (iterator neq container.begin());
	} else stream << "none."; 
	std::cout << stream.str() << std::endl;
}

/* ############################################################################################## */

static inline void rbegin(const MutantStack<int> &container) {
	std::ostringstream stream;
	stream << "\nThe MutantStack contains: ";

	if (not container.empty()) {
		for (MutantStack<int>::const_reverse_iterator iterator = container.rbegin(); iterator neq container.rend(); iterator++) {
			stream << *iterator;
			iterator + 1 neq container.rend() ? stream << ", "
											  : stream << ".";
		}
	} else stream << "none."; 
	std::cout << stream.str() << std::endl;
}

static inline void rbegin(const std::list<int> &container) {
	std::ostringstream stream;
	stream << "The List contains: ";

	if (not container.empty()) {
		for (std::list<int>::const_reverse_iterator iterator = container.rbegin(); iterator neq container.rend(); iterator++) {
			stream << *iterator;
	
			std::list<int>::const_reverse_iterator next = iterator;
			++next;
	
			next neq container.rend() ? stream << ", "
									  : stream << ".";
		}
	} else stream << "none."; 
	std::cout << stream.str() << std::endl;
}

/* ############################################################################################## */

static inline void rend(const MutantStack<int> &container) {
	std::ostringstream stream;
	stream << "\nThe MutantStack contains: ";

	if (not container.empty()) {
		MutantStack<int>::const_reverse_iterator iterator = container.rend() - 1;
		do {
            stream << *iterator;
			iterator eq container.rbegin() ? stream << "."
										   : stream << ", ";
		} while (iterator-- neq container.rbegin());
	} else stream << "none."; 
	std::cout << stream.str() << std::endl;
}

static inline void rend(const std::list<int> &container) {
	std::ostringstream stream;
	stream << "The List contains: ";

	if (not container.empty()) {
		std::list<int>::const_reverse_iterator iterator = container.rend();
		do {
            stream << *(--iterator);
			iterator eq container.rbegin() ? stream << "."
										   : stream << ", ";
		} while (iterator neq container.rbegin());
	} else stream << "none."; 
	std::cout << stream.str() << std::endl;
}

/* ############################################################################################## */

static inline void pop(MutantStack<int> &container) {
	if (not container.empty())	{
		std::cout << ColorFormat::formatString("\nPOP! (in the MutantStack)", "italic") << std::endl;
		container.pop();
	}
	else	std::cout << ColorFormat::formatString("\nCan't pop the MutantStack void!", "red") << std::endl;
}

static inline void pop(std::list<int> &container) {
	if (not container.empty()) {
		container.pop_back();
		std::cout << ColorFormat::formatString("POP! (in the List)", "italic") << std::endl;
	}
	else	std::cout << ColorFormat::formatString("Can't pop the List void!", "red") << std::endl;
}

/* ############################################################################################## */

static inline void push(MutantStack<int> &container, const int value) {
	container.push(value);
}

static inline void push(std::list<int> &container, const int value) {
	container.push_back(value);
}

/* ############################################################################################## */

static inline void size(MutantStack<int> &container) {
	std::cout << "\nMutantStack size is: " << container.size() << "." << std::endl;
}

static inline void size(std::list<int> &container) {
	std::cout << "List size is: " << container.size() << "." << std::endl;
}

/* ############################################################################################## */

static inline void top(MutantStack<int> &container) {
	not container.empty() ? std::cout << "\nMutantStack top is " << container.top() << "." << std::endl
						  : std::cout << "\nMutantStack " + ColorFormat::formatString("has not", "red") << " top." << std::endl;
}

static inline void top(std::list<int> &container) {
	not container.empty() ? std::cout << "List top is " << container.back() << "." << std::endl
						  : std::cout << "List " + ColorFormat::formatString("has not", "red") << " top." << std::endl;
}