#include "gates.h"
#include <iostream>
/*
	Clay Sanford, ECE321L. Logic_Simulator module, takes a request for a type of gate, and then the input(s) for that gate, outputs the 
	value and truth table for that input and gate respectively.
*/
/*
int main() {
	char sel = 'a';
	int a, b;
	do{
		std::cout << "Which gate would you like to simulate?" << std::endl;
		std::cout << "(0 for NOT, 1 for AND, 2 for NAND, 3 for OR, 4 for NOR, 5 for XOR, 6 for XNOR): ";
		std::cin >> sel;
		switch (sel) {
		case('0'): //NOT
			std::cout << "NOT gate selected. What is the value of a: ";
			std::cin >> a;
			std::cout << "NOT " << a << " is " << NOT(a) << std::endl;
			std::cout << "NOT truthtable:" << std::endl;
			std::cout << "______" << std::endl;
			std::cout << "0 | " << NOT(0) << std::endl;
			std::cout << "1 | " << NOT(1) << std::endl;
			break;
		case('1'): //AND
			std::cout << "AND gate selected. What is the value of a: ";
			std::cin >> a;
			std::cout << "What is the value of b: ";
			std::cin >> b;
			std::cout << a << " AND " << b << " is " << AND(a, b) << std::endl;
			std::cout << "AND truthtable:" << std::endl;
			std::cout << "________" << std::endl;
			std::cout << "0  0 | " << AND(0, 0) << std::endl;
			std::cout << "0  1 | " << AND(0, 1) << std::endl;
			std::cout << "1  0 | " << AND(1, 0) << std::endl;
			std::cout << "1  1 | " << AND(1, 1) << std::endl;
			break;
		case('2'): //NAND
			std::cout << "NAND gate selected. What is the value of a: ";
			std::cin >> a;
			std::cout << "What is the value of b: ";
			std::cin >> b;
			std::cout << a << " AND " << b << " is " << NAND(a, b) << std::endl;
			std::cout << "NAND truthtable:" << std::endl;
			std::cout << "________" << std::endl;
			std::cout << "0  0 | " << NAND(0, 0) << std::endl;
			std::cout << "0  1 | " << NAND(0, 1) << std::endl;
			std::cout << "1  0 | " << NAND(1, 0) << std::endl;
			std::cout << "1  1 | " << NAND(1, 1) << std::endl;
			break;
		case('3'): //OR
			std::cout << "OR gate selected. What is the value of a: ";
			std::cin >> a;
			std::cout << "What is the value of b: ";
			std::cin >> b;
			std::cout << a << " OR " << b << " is " << OR(a, b) << std::endl;
			std::cout << "NAND truthtable:" << std::endl;
			std::cout << "________" << std::endl;
			std::cout << "0  0 | " << OR(0, 0) << std::endl;
			std::cout << "0  1 | " << OR(0, 1) << std::endl;
			std::cout << "1  0 | " << OR(1, 0) << std::endl;
			std::cout << "1  1 | " << OR(1, 1) << std::endl;
			break;
		case('4'): //NOR
			std::cout << "NOR gate selected. What is the value of a: ";
			std::cin >> a;
			std::cout << "What is the value of b: ";
			std::cin >> b;
			std::cout << a << " NOR " << b << " is " << NOR(a, b) << std::endl;
			std::cout << "NAND truthtable:" << std::endl;
			std::cout << "________" << std::endl;
			std::cout << "0  0 | " << NOR(0, 0) << std::endl;
			std::cout << "0  1 | " << NOR(0, 1) << std::endl;
			std::cout << "1  0 | " << NOR(1, 0) << std::endl;
			std::cout << "1  1 | " << NOR(1, 1) << std::endl;
			break;
		case('5'): //XOR
			std::cout << "XOR gate selected. What is the value of a: ";
			std::cin >> a;
			std::cout << "What is the value of b: ";
			std::cin >> b;
			std::cout << a << " XOR " << b << " is " << XOR(a, b) << std::endl;
			std::cout << "NAND truthtable:" << std::endl;
			std::cout << "________" << std::endl;
			std::cout << "0  0 | " << XOR(0, 0) << std::endl;
			std::cout << "0  1 | " << XOR(0, 1) << std::endl;
			std::cout << "1  0 | " << XOR(1, 0) << std::endl;
			std::cout << "1  1 | " << XOR(1, 1) << std::endl;
			break;
		case('6'): //XNOR
			std::cout << "XNOR gate selected. What is the value of a: ";
			std::cin >> a;
			std::cout << "What is the value of b: ";
			std::cin >> b;
			std::cout << a << " XNOR " << b << " is " << XNOR(a, b) << std::endl;
			std::cout << "NAND truthtable:" << std::endl;
			std::cout << "________" << std::endl;
			std::cout << "0  0 | " << XNOR(0, 0) << std::endl;
			std::cout << "0  1 | " << XNOR(0, 1) << std::endl;
			std::cout << "1  0 | " << XNOR(1, 0) << std::endl;
			std::cout << "1  1 | " << XNOR(1, 1) << std::endl;
			break;
		case('q'):
		case('Q'):
			std::cout << "Goodbye!" << std::endl;
			break;
		default:
			std::cout << "Input not understood. Sorry!" << std::endl;
			break;
		}
	} while ((sel != 'q') && (sel != 'Q'));
}*/