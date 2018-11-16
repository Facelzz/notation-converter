/**
*	Individual task on
*	Architecture of Computing Systems
**/

#include <iostream>
#include <math.h>
#include "converter.h"
#include "interface.h"

int main() {
	int firstNumber = -1, secondNumber = -1;
	int firstNumberSystem = 6, secondNumberSystem = 8;
	bool* firstBinary = new bool[12];
	bool* secondBinary = new bool[12];
	bool* sum = new bool[12];

	drawWelcome();

	for(int i = 1; ; i++) {

		std::cout<<"#"<<i<<":\n\t";
		std::cin>>firstNumber;
		std::cout<<"\t+\n\t";
		std::cin>>secondNumber;

		if(!firstNumber && !secondNumber)
		break;

		if(!isCorrect(firstNumber,firstNumberSystem) ||
		!isCorrect(secondNumber,secondNumberSystem))  {
			std::cout<<"One of entered numbers is wrong!\n";
			continue;
		}

		toBinary(firstNumber, firstNumberSystem, firstBinary);
		toBinary(secondNumber, secondNumberSystem, secondBinary);


		std::cout <<"\n  In decimal:\t"
		<<toDecimal(firstNumber,firstNumberSystem)
		<<" + "
		<<toDecimal(secondNumber,secondNumberSystem)
		<<" = "
		<<toDecimal(firstNumber,firstNumberSystem)
		+toDecimal(secondNumber,secondNumberSystem)
		<<"\n";

		std::cout<<"  In binary:\t";
		printBinary(firstBinary);
		std::cout<<" + ";
		printBinary(secondBinary);
		std::cout<<" = ";
		sum = sumBinary(firstBinary, secondBinary);
		printBinary(sum);
		std::cout<<"\n\n";
	}

	drawBye();

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

int toDecimal(bool* binaryNumber)	{
	int result = 0;
	for(int i = 11; i > 0; i--)
	result += binaryNumber[i]*pow(2,11-i);
	if(binaryNumber[0])
	result *= -1;
	return result;
}

void printBinary(bool* binaryNumber) {
	std::cout<<binaryNumber[0]<<".";
	for(int i = 1; i < 12; i++)
	std::cout<<binaryNumber[i];
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
			if(i == 0)
			std::cout<<	"\n   WARNING! Digit grid had overflowed! "
			"One of these numbers have wrong value.\n"
			"\tThe value will be used, but binary "
			"ANSWER WILL BE INCORRECT!\n";
			result[i] = number % 2;
			number /= 2;
			i--;
		}
	}	else
	std::cout<<"\n\tError! The number or number system are wrong!\n";
}

bool *sumBinary(bool* firstBinary, bool* secondBinary)	{
	bool* sum = new bool[12];
	bool _flag = 0; //перенос
	bool overflow = 0;
	for(int i = 11; i > 0; i--)	{
		if(firstBinary[i] && !secondBinary[i] || !firstBinary[i] && secondBinary[i])	{
			if(_flag)  {
				sum[i] = 0;
				_flag = 1;
			} else  {
				sum[i] = 1;
				_flag = 0;
			}
		}	else
		if(firstBinary[i] && secondBinary[i])	{
			if(_flag) {
				sum[i] = 1;
				_flag = 1;
			} else {
				sum[i] = 0;
				_flag = 1;
			}
		}	else
		if(!(firstBinary[i] && secondBinary[i])){
			if(_flag)
			sum[i] = 1;
			else
			sum[i] = 0;
			_flag = 0;
		}
	}
	if(toDecimal(firstBinary)+toDecimal(secondBinary) > 2047)
	std::cout<<" OVERFLOW! ";
	return sum;
}

void drawWelcome() {
	std::cout<< "\t\t\t ####################\n"
	"\t\t\t ###   WELCOME!   ###\n"
	"\t\t\t ####################\n";
	for(int i = 0; i < 10; i++)
	std::cout<<"=======";
	std::cout<< "\n\t\t\t     Let`s begin.\n"
	"\n\t\t       Enter two numbers thus:\n\n"
	"\t\t\t  (6-number-system)\n"
	"\t\t\t\t  +\n"
	"\t\t\t  (8-nubmer-system)\n"
	"\n     Then you`ll see a decimal and binary representation and get\n"
	"\t\t    the sum of them in the same way.\n"
	"\t\t         (Enter 0 + 0 to EXIT)\n";
	for(int i = 0; i < 10; i++)
	std::cout<<"=======";
	std::cout<<"\n\n";
}

void drawBye()  {
	std::cout<<"\n";
	for(int i = 0; i < 10; i++)
	std::cout<<"=======";
	std::cout<< "\n\n\t\t########################################\n"
	"\t\t###############   Bye!   ###############\n"
	"\t\t########################################\n\n";
}
