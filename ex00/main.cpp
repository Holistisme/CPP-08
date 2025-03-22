#include "easyfind/easyfind.hpp"

/* ############################################################################################## */

#include "ColorFormatLib/ColorFormat.hpp"
#include "InputLib/Input.hpp"

/* ############################################################################################## */

#include <algorithm>
#include <ctime>
#include <iostream>
#include <list>
#include <vector>

/* ############################################################################################## */

int main( void ) {
	try {
		std::cout << "\nWelcome to the program ”" << ColorFormat::formatString("EasyFind™", "blue", "blink", "bold") << "“!" << std::endl;
		std::srand(static_cast<unsigned int>(std::time(NULL)));

		std::vector<int> vector;
		std::list<int>	 list;
		for (size_t index = 0 ; index < 10 ; index++) {
			vector.push_back(std::rand() % 42);
			list.push_back(std::rand()	 % 42);
		}
		
		while (true) {
			try {
				std::cout << std::endl;
				for (size_t index = 0 ; index < vector.size() ; index++) {
					std::list<int>::iterator listIndex = list.begin();
					std::advance(listIndex, index);
	
					std::cout << index << ": " << vector[index] << ", " << *listIndex << "." << std::endl;
				}
				
				Input userInput("\nYou can enter a " + ColorFormat::formatString("number", "yellow")
													 + " to replace it or ”"
													 + ColorFormat::formatString("EXIT", "red", "italic")
													 + "“ to quit!\n");
	
				if (userInput.stringFormat() == "EXIT")	break;

				int findInput	= userInput.integerFormat();
				int changeInput = Input("What to " + ColorFormat::formatString("replace", "green")
												   + " it with?").integerFormat();
				std::cout << std::endl;

				try { *easyfind(vector, findInput) = changeInput; }
				catch (std::exception &e) { std::cout << ColorFormat::formatString("I couldn't find anything in the vector!", "italic") << std::endl; }
				try { *easyfind(list, findInput) = changeInput;	  }
				catch (std::exception &e) { std::cout << ColorFormat::formatString("I couldn't find anything in the list!", "italic") << std::endl; }
			} catch (std::exception &e) { std::cerr << ColorFormat::formatString(e.what(), "red") << std::endl; }
		}
		std::cout << "\nThanks for using ”"		  << ColorFormat::formatString("EasyFind™", "blue", "blink", "bold")						<< "“!\n"	<< std::endl;
	} catch (const std::exception &e) { std::cerr << ColorFormat::formatString("The following error has been encountered: ", "red", "bold") << e.what() << std::endl; }
	return 0;
}