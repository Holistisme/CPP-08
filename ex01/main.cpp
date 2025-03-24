#include "Span/Span.hpp"

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

static void multipleAdding(Span &span, const int firstNumber, const int secondNumber);

/* ############################################################################################## */

int main( void ) {
	try {
		std::cout << "\nWelcome to the program ”" << ColorFormat::formatString("TheSpan™", "yellow", "blink", "bold") << "“!\n" << std::endl;

		Span span(Input("What " + ColorFormat::formatString("size", "green") + " to define for the class vector?").integerFormat());

		while (true) {
			try {
				std::cout << "_______________________________________________________________________________\n" << std::endl;
				std::cout << "You can execute ”" << ColorFormat::formatString("ADD", "blue", "italic")	 	 	 << "“ for adding integers in the vectors, ”"
												 << ColorFormat::formatString("SHORT", "green", "italic")		 << "“ for getting\nthe shortest span, ”"
												 << ColorFormat::formatString("LONG", "yellow", "italic")		 << "“ for getting the longest span or ”"
												 << ColorFormat::formatString("EXIT", "red", "italic")			 << "“ to quit!" << std::endl;
				std::cout << "_______________________________________________________________________________\n" << std::endl;

				span.displayVector();
	
				Input userInput("Instruction to execute:");
	
				if (userInput.stringFormat() == "ADD") {
					int	firstNumber = Input("What number should be added to the vector?").integerFormat();
	
					Input additionalNumber("If you want to add a range to another number, this is the place. " + ColorFormat::formatString("Otherwise, leave empty", "italic") + ".");
					not additionalNumber.stringFormat().empty() ? multipleAdding(span, firstNumber, additionalNumber.integerFormat())
																: span.addNumber(firstNumber);
				}
				else if (userInput.stringFormat() == "SHORT") {
					std::cout << span.shortestSpan() << std::endl;
				}
				else if (userInput.stringFormat() == "LONG") {
					std::cout << span.longestSpan() << std::endl;
				}
				else if (userInput.stringFormat() == "EXIT") break;
				else	std::cout << ColorFormat::formatString("Unclear instructions!", "red", "bold") << std::endl;
			} catch (const std::exception &e) { std::cerr << ColorFormat::formatString("The following warning has been encountered: ", "red", "italic") << e.what() << std::endl; }
		}
	} catch (const std::exception &e) { std::cerr << ColorFormat::formatString("The following error has been encountered: ", "red", "bold") << e.what() << std::endl; }
	std::cout << "\nThanks for using ”"			  << ColorFormat::formatString("TheSpan™", "yellow", "blink", "bold")						<< "“!\n"	<< std::endl;
	return 0;
}

static void multipleAdding(Span &span, const int firstNumber, const int secondNumber) {
	std::vector<int> range;
	int				 value = firstNumber;

	while (value neq secondNumber) {
		range.push_back(value);
		firstNumber lt secondNumber ? ++value
									: --value;
	}

	range.push_back(secondNumber);
	span.addNumber(range.begin(), range.end());
}