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

void printBinary(bool* binaryNumber) {
	std::cout<<binaryNumber[0]<<".";
	for(int i = 1; i < 12; i++)
		std::cout<<binaryNumber[i];
  std::cout<<std::endl;
}

void toBinary(int number, int numberSystem, bool* result)	{
  for(int i = 0; i < 12; i++, result[i] = 0);
  if(isCorrect(number, numberSystem))	{
		if(numberSystem != 10)
			number = toDecimal(number, numberSystem);
		if(number < 0)  {
			result[0] = 1;
      number *= -1;
    } else  {
        result[0] = 0;
      }
		int i = 11;
		while(number > 0)	{
			result[i] = number % 2;
			number /= 2;
			i--;
		}
	}	else
			std::cout<<"\n\tError! The number or number system are wrong!\n";
}
