#include "gates.h"
#include <iostream>

int NOT(int a) {
	return !a;
}
int AND(int a, int b) {
	return (a && b);
}
int NAND(int a, int b) {
	return !(a && b);
}
int OR(int a, int b) {
	return (a || b);
}
int NOR(int a, int b) {
	return !(a || b);
}
int XOR(int a, int b) {
	return (a ^ b);
}
int XNOR(int a, int b) {
	return !(a ^ b);
}
int AND_N(int a[]) {			//Changed the function - now uses one array, and the first element is the number of bits the AND is.
	//std::cout << "And recieved, " << a[0] << " elements" << std::endl; DEBUG
	for (int i = 1; i <= a[0]; i++) {	//For every element
		if (a[i] == 0) {					//If any are 0 return 0
			return 0;					//
		}
		//std::cout << "AND ELEM " << i << " VAL " << a[i] << std::endl; DEBUG
	}
	return 1;							//If all are true return 1
}

int OR_N(int a[]) {	//Changed the function - now uses one array, and the first element is the number of bits the OR is.
	for (int i = 1; i <= a[0]; i++) {	//For every element in the array
		//std::cout << "OR ELEM " << i << " VAL " << a[i] << std::endl; DEBUG
		if (a[i] != 0) {						//If any element is true
			return 1;					//Return one 
		}
	}
	return 0;							//If all 0, return 0.
}