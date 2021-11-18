#include <iostream>
#include <fstream>
#include "gates.h"
#include <sstream>
#include <string>

/*
		Clay Sanford, ECE321L, 11/10/2021
		I think I've made a mistake; this program already handles multiple inputs -> why would I hardcode 2 inputs?
		Essentially, I made a class of a gate; the gate has an index value, a type (as a character), two inputs (when initialzed they are indexes of gates, after the
		getInput function they are either 1 or 0), an output (1 or 0), and a pointer to the next gate, so the gates themselves function as a linked list.
		If you want to change the circuit topology, change the circuit.txt file.

*/


class gate {
	public:							//I could use mutators and accessors, but I do not want to type mutators and accessors. I will be directly editing most things. Sorry.
		int i;						//Index integer
		char type;					//Type character
		int inputA, inputB;			//Ints for input a and b (Starts as a value from 1-n, ends as 0 or 1)
		int output;					//Int for output (0 or 1)
		gate* nextGate;				//Pointer to next gate (treated as linked list)
		
		void setNext(gate* next) {	//A function for some reason, because I didn't want to type this->nextgate = new. Probably more efficient to delete this but alas.
			nextGate = next;		//Does exactly what you'd think.
			return;
		}
		
		void getInput(gate* head) {	//Function sets inputA and inputB to the outputs of the selected gates
			gate* temp = head;		//Makes a temporary gate pointer so that we do not modify the head node.
			if ((type != 'I')) {	//If not an input, get the outputs of the selected gates and return the 
				int j;				//counting integer
				for (j = 1; j < inputA; j++) { //Start from one because we don't count from 0
					temp = temp->nextGate;		//Follow the chain through all the gates
				}
				inputA = temp->output;			//Upon reaching the specified gate, the specific input is the output of that gate.
				temp = head;					//Reset temp node to beginning. Alternatively, I could just use the head for the next loop but who cares
				for (j = 1; j < inputB; j++) {	//Still start from 1
					temp = temp->nextGate;		//Same following chain
				}
				inputB = temp->output;			//Input B is the output of the previous 
			}
			else {								//If it's an input
				std::cout << "What is the value for input " << i << ": ";	//Request the value of the input
				std::cin >> output;				//recieve input
			}
		}

		void Pulse() {							//Clock pulse function; finds the output of a circuit
			switch(type) {						//Switch case to select the specific gate
				case('N'):						//Not gates
					output = NOT(inputA);		
					break;
				case('A'):						//And gates
					output = AND(inputA, inputB);
					break;
				case('O'):						//Or gates
					output = OR(inputA, inputB);
					break;
				case('X'):						//Xor gates
					output = XOR(inputA, inputB);
					break;
				case('Q'):						//Circuit output (Program can also handle multiple outputs)
					output = inputA;
					std::cout << "The value of output " << i << " is " << output << std::endl;
				case('I'):						//Inputs don't have an output that needs to be calculated, this is handled in the get input section.
				default:
					break;
			}
			
		}
};


/*
int main(){
	std::ifstream circuit;
	circuit.open("circuit.txt");
	int gates;						//Integer for the number of gates
	circuit >> gates;				//Get the number of gates from the firsts line, leaves \n character.
	std::string information;
	gate* head;						//Head node; pointer constantly points towards the FIRST gate
	gate* temp;						//Temporary node simply used to modify the chain while maintaining the head. 
	head = new gate;				//Make head node point to a gate
	circuit >> information;			//Get the first chunk of the next line (because the index can be more than 1 character, I need the entire chunk)
	information.pop_back();			//Remove the :
	head->i = stoi(information);	//The index is string to integer of the first number
	std::getline(circuit, information); //Get the rest of the line
	head->type = information.at(1);		//Type is the first character. Because the first char is really a " " due ot the way getline and >> function, we have to use the second position.
	head->inputA = information.at(3) - '0';	//- '0' is a fancy way to turn a 1-character number into an integer.
	head->inputB = information.at(5) - '0';	//^^
	temp = head;
	for (int i = 1; i < gates; i++) {		//For loop to get all gates. Does the exact same process as above but for the temp, and then has temp loop through itself to form the linked list.
		temp->setNext(new gate);			//The next gate is a new gate
		temp = temp->nextGate;				//Move so that temp is now pointing to the new gate
		circuit >> information;				//Get in the first chunk that contains the index
		information.pop_back();				//Remove the :
		temp->i = stoi(information);		//String to integer and then save as index
		std::getline(circuit, information);	//Get rest of line
		temp->type = information.at(1);		//Get type
		temp->inputA = information.at(3) - '0';	//Get in a
		temp->inputB = information.at(5) - '0';	//Get in b
	}
	temp = head;							//Return temp to head for the looping part of next section
	for (int i = 0; i < gates; i++) {		//For loop to get the inputs and subsequently outputs of all gates
		temp->getInput(head);				//switch the values from index numbers to 0 or 1 for the inputs
		temp->Pulse();						//Clock pulse of this specific gate; updates output to be 0 or 1 based on the inputs and type of gate
		temp = temp->nextGate;				//Move to next gate to continue process
	}
}
*/