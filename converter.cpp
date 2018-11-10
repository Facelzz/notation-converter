/**
*	Individual task on
*	Architecture of Computing Systems
**/

#include <iostream>
#include <math.h>
#include "converter.h"

int main() {
	
	return 0;
}

bool isCorrect(int number, int numberSystem)	{
	do {
		if((number % 10) >= numberSystem)
			return false;
		else number /= 10;
	} while(number > 0);
	return true;
}

int toDecimal(int number, int numberSystem)	{
	int result = 0;
	for(int i = 0; number > 0; i++)	{
		result += (number % 10) * pow(numberSystem,i);
		number /= 10;
	}
	return result;
}
