#include <iostream>
#include "Array.h"

int main() 
{
	std::cout << "Hello World!\n";
	Array<int> newArray(10);
	
	std::cout << newArray.GetSize() << std::endl;
	newArray.Display();
	
	return 0;
}