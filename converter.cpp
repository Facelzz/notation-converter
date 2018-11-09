/**
*	Individual task on
*	Architecture of Computing Systems
**/

#include <iostream>
#include "converter.h"

int main() {
	
	return 0;
}

bool isCorrect(int numberSystem, int number)		{
	do {
		if((number % 10) > numberSystem)
			return false;
		else number /= 10;
	} while(number > 0);
	return true;
}
