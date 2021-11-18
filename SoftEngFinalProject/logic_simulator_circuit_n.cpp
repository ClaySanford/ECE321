#include "gates.h"
#include <iostream>	
#include <stdlib.h>
/*
	Clay Sanford, ECE321L. Logic_Simulator_circuit_n module.
	
*/

void randFill(int a[], int len) { //Fill a passed array with random 0s or 1s.
	for (int i = 0; i < len; i++) {
		a[i] = rand() % 2; 
	}

}
/*
int main() {

	int* a = nullptr;	//Use null pointers for the two inputs; this allows for me to dynamically allocate arrays of whatever length I need whenever.
	int* b = nullptr;	//Must remember to delete to avoid memory leaks.
	a = new int[8];		//The first circuit, circuit 1, uses 8-bit arrays. 
	b = new int[8];		//Because of this, I have only allocated 8-bits for the inputs.
	char imp = '0';		//Character for decider
	int man;			//Integer for manual input
	std::cout << "For Circuit 1 (8b): Random input or manual input? (r for random, m for manual): ";
	std::cin >> imp;	//Recieve character decider
	switch (imp) {
	case ('r'):
	case ('R'):
		randFill(a, 8);
		randFill(b, 8);
		break;
	case ('m'):
	case ('M'):
		for (int i = 0; i < 8; i++) {
			std::cout << "Input a[" << i << "]: ";
			std::cin >> man;
			a[i] = man;
		}
		for (int i = 0; i < 8; i++) {
			std::cout << "Input b[" << i << "]: ";
			std::cin >> man;
			b[i] = man;
		}
		break;
	default:
		std::cout << "Unknown input. Generating randomly." << std::endl;
		randFill(a, 8);
		randFill(b, 8);
		break;
	}
	std::cout << "Input a is: ";
	for (int i = 0; i < 8; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl << "Input b is: ";
	for (int i = 0; i < 8; i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;
	// Because of the way circuit 1 breaks up a and b, I need to make smaller arrays.
	int a1[4] = { a[0], a[1], a[2], a[3] };
	int a2[4] = { a[4], a[5], a[6], a[7] };
	int b1[4] = { b[0], b[1], b[2], b[3] };
	int b2[4] = { b[4], b[5], b[6], b[7] };
	

	int C1 = NOT(XNOR(AND_N(a1, b1), OR_N(a2, b2)));	//Gets output of Circuit 1
	std::cout << "Output of circuit 1 is: " << C1 << std::endl;	//Prints output
	delete[] a;			//Delete a after use
	a = nullptr;		//Reset to null
	delete[] b;			//Delete b after use
	b = nullptr;		//Reset to null

	a = new int[16];
	b = new int[16];

	std::cout << "For Circuit 2 (16b): Random input or manual input? (r for random, m for manual): ";
	std::cin >> imp;	//Recieve character decider
	switch (imp) {
	case ('r'):
	case ('R'):
		randFill(a, 16);
		randFill(b, 16);
		break;
	case ('m'):
	case ('M'):
		for (int i = 0; i < 16; i++) {
			std::cout << "Input 16[" << i << "]: ";
			std::cin >> man;
			a[i] = man;
		}
		for (int i = 0; i < 16; i++) {
			std::cout << "Input b[" << i << "]: ";
			std::cin >> man;
			b[i] = man;
		}
		break;
	default:
		std::cout << "Unknown input. Generating randomly." << std::endl;
		randFill(a, 16);
		randFill(b, 16);
		break;
	}
	std::cout << "Input a is: ";
	for (int i = 0; i < 16; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl << "Input b is: ";
	for (int i = 0; i < 16; i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;

	int a21[4] = { a[0], a[1], a[2], a[3] };
	int a22[4] = { a[4], a[5], a[6], a[7] };
	int a3[4] = { a[8], a[9], a[10], a[11] };
	int a4[4] = { a[12], a[13], a[14], a[15] };
	int b21[4] = { b[0], b[1], b[2], b[3] };
	int b22[4] = { b[4], b[5], b[6], b[7] };
	int b3[4] = { b[8], b[9], b[10], b[11] };
	int b4[4] = { b[12], b[13], b[14], b[15] };

	int C2 = OR(OR(AND_N(a4, b21), OR_N(a3, b22)), AND(OR_N(a22, b3), AND_N(a21, b4)));

	std::cout << "Output of circuit 2 is: " << C2 << std::endl;

	delete[] a;	//Memory cleanup
	delete[] b;

}*/