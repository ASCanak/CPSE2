#include "../headers/stl.hpp"

int main(){
	auto bible = stl("King Jame's bible.txt");
	
	bible.printCharCount();
	bible.printLineCount();
	bible.printLetterCount();
	bible.convertToLower();
	bible.individualLetterCount();
    bible.printIndividualLetterCount(1);
    bible.printIndividualLetterCount(2);
	bible.printTenMostCommonWords();

	std::cout << "Terminating application\n";
	return 0;
}