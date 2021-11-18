#include <iostream>
#include <fstream>
#include "gates.h"
#include <sstream>
#include <string>

/*
		Clay Sanford, ECE321L, 11/17/2021
		Uses SLL of class gate to simulate a circuit. Gate has several attributes, namely index, type, amount of inputs, array of inputs, output, and the pointer to the next gate,
		as it is a single linked list of gates.
		The gates.cpp and gates.h files have also been modified; These files now have the n-bit or and and calculations take one array whos first element is the size of the array. This is because
		when you call a function with an array as a parameter you can't actually see the size of the array. Makes you long for python, tbh.
		

*/

class gate {							//Gate class
private:								//Variables should be private
	int i;								//Integer that is the index of the gate	
	char type;							//Character that is the type of the gate
	int inputCount;						//Integer that is how many inputs the gate has
	int* inputs;						//The pointer to list of inputs
	int output;							//The output of the gate
	gate* nextGate;						//Pointer to the next gate
public:
	gate() {							//Generic constructor -> not used
		i = NULL;
		type = 'I';
		inputCount = 0;
		inputs = nullptr;
		output = NULL;
		nextGate = nullptr;
	}

	gate(int index) {							//input constructor - only used for inputs
		i = index;
		type = 'I';
		inputCount = 0;
		inputs = nullptr;
		output = NULL;
		nextGate = nullptr;
	}

	gate(int index, int input) {				//Output constructor - only used for outputs
		i = index;
		type = 'Q';
		inputCount = 1;
		inputs = new int[1];
		inputs[0] = input;
		output = NULL;
		nextGate = nullptr;

	}

	gate(int index, char gateType, int inCount, int inputIndexes[]) {	//Overloaded constructor -> used for all other gates
		i = index;
		type = gateType;
		inputCount = inCount;
		inputs = new int[inputCount];									//This is just a poor man's vector to be honest
		for (int i = 0; i < inputCount; i++) {
			inputs[i] = inputIndexes[i];
		}
		output = NULL;
		nextGate = nullptr;
	}

	void setNext(gate* next) {			//Modifier for setting next gate
		nextGate = next;
	}

	gate* getNext() {					//Accessor for getting next gate
		return nextGate;
	}

	int getOutput() {					//Access for getting gate output
		return output;
	}

	void getInputs(gate* head) {
		gate* temp = head;		//Makes a temporary gate pointer so that we do not modify the head node.
		if ((type != 'I')) {	//If not an input, get the outputs of the selected gates and return the 
			for (int i = 0; i < inputCount; i++) {				//For every input
				for (int j = 1; j < inputs[i]; j++) {			//Crawl through all gates to index
					temp = temp->getNext();						//Set node to next node
				}
				//std::cout << "Gate " << this->i << " input " << i << " is " << temp->getOutput() << std::endl;	//DEBUG
				inputs[i] = temp->getOutput();					//Get the output of the indexed gate
				temp = head;									//Set temp back to head for next gate
			}
		}
		else {								//If it's an input
			std::cout << "What is the value for input " << i << ": ";	//Request the value of the input
			std::cin >> output;				//recieve input
		}
	}

	void Pulse() {						//Clock pulse
		int* temp = new int[inputCount + 1];
		switch (type) {
		case 'A':						//If our gate is an AND:
			temp[0] = inputCount;					//First element is amount of elements
			//std::cout << "AND DEBUG " << inputCount << " inputs "; //DEBUG
			/* for (int i = 0; i < inputCount; i++) {
				std::cout << inputs[i] << " ";
			}
			std::cout << std::endl; */						//DEBUG
			for (int i = 1; i <= inputCount; i++) {	//All other elements are from the inputs
				//std::cout << inputs[i - 1] << " is and " << this->i << " elem " << i << std::endl;
				temp[i] = inputs[i - 1];			//Append the list of inputs to the array
			}
			output = AND_N(temp);					//Output is the AND of the inputs
			break;
		
		case 'O':						//IF our gate is an OR:
			temp[0] = inputCount;					//First element is amount of elements
			for (int i = 1; i <= inputCount; i++) {	//All other elements are from the inputs
				temp[i] = inputs[i - 1];			//Append the list of inputs to the array
			}
			output = OR_N(temp);					//Output is the OR of the inputs
			break;

		case 'N':						//IF our gate is a NOT:
			output = NOT(inputs[0]);				//Our output is the NOT of our input.
			break;

		case 'X':						//IF our gate is an XOR:
			//std::cout << "XOR called, inputs: " << inputs[0] << " " << inputs[1] << std::endl;	//DEBUG
			output = XOR(inputs[0], inputs[1]);		//Our output is the XOR of our inputs
			break;

		case 'Q':						//If our gate is an output, we just need the value of the input
			output = inputs[0];			//Set the output to the value of the input
			std::cout << "Output of output " << i << " is " << output << std::endl;
			break;
		case 'I':						//Inputs don't need any output
		default:
			break;
		}
		delete[] temp;
		//std::cout << "Gate " << i << " type " << type << " output set to " << output << std::endl; //DEBUG
	}
};

int findLen(std::string itemList) {
	int count = 0;						//Counting int starts at 0
	std::string temporary;				//Temp string
	std::stringstream stream;			//Stream object
	stream << itemList;					//Stream object is the list of numbers
	while (!stream.eof()) {				//While we haven't reached the end of the string
		stream >> temporary;			//Get the next element
		count++;						//Increment the count
	}
	return count;						//Return the number of elements in the string.
}

int main() {
	std::ifstream circuit;				//Create an input stream for the file
	circuit.open("circuit.txt");		//Open the circuit file
	int gates;							//Integer for the number of gates
	circuit >> gates;					//Get the number of gates from the firsts line, leaves \n character.
	circuit.get();						//Gets the whitespace so that I can properly use getline
	std::string information;			//A string for the information of the gates
	gate* head;							//A gate pointer for the head of the linked list
	gate* temp;							//A gate pointer to modify the list without losing the head
	std::getline(circuit, information);	//Get the first line into information
	head = new gate(1);					//Head will always be an input; Because of this, we hardcode it to be an input1
	temp = head;						//Temp starts out as the head node
	int index;							//Variable for pulling out the index
	char type;							//Variable for pulling out the type
	int count;							//Integer for the amount of inputs
	int* inList;						//Pointer for array of 
	std::string tempStr;				//Temporary string for parsing through the stringstream
	std::stringstream ss;				//Stringstream element for parsing through the lines of text to extract inputs
	for (int i = 1; i < gates; i++) {	//For every gate in the file, except the first
		std::getline(circuit, information);									//Get the string for the file
		index = std::stoi(information.substr(0, information.find(':')));	//Gets the string to int of the index (takes the substring from the start to the ':'
		//std::cout << index << " ";										//Debug print
		type = information.substr(information.find(':') + 2)[0];			//Gets the gate type character by taking the 0th element 2 spaces after the ':'
		//std::cout << type << std::endl;									//Debug print
		switch(type){
		case 'I':
			temp->setNext(new gate(index));											//Add the next gate as an input
			break;
		case 'Q':
			//Q only has one input, so we only need one input
			count = std::stoi(information.substr(information.find(type) + 2));		//Set count to the input
			temp->setNext(new gate(index, count));									//Add next gate as an output
			break;
		case 'N':
			//Not also only has one input
			count = 1;																//Set count to 1
			inList = new int[1];													//new array of integers for inputs
			inList[0] = (std::stoi(information.substr(information.find(type) + 2)));//Set the array of integers to the input
			temp->setNext(new gate(index, type, count, inList));					//Declare a new gate
			delete[] inList;														//Clean up array
			break;
		case 'X':
			//XOR has 2 inputs. The prompt is wrong, you can't XOR one item (well you can but the truth table is just that item). You can actually XOR more than two items; this is how adders work.
			count = 2;																//Set count to 2
			inList = new int[2];													//inList is an array of 2 inputs
			ss << information.substr(information.find(type) + 2);					//Ss is the stringstream of everyhting after the type
			//std::cout << information.substr(information.find(type) + 2) << std::endl;	//DEBUG
			//std::cout << "Creating new XOR. Inputs: ";								//DEBUG
			for (int j = 0; j < 2; j++){											//For every element in the array of inputs 
				ss >> tempStr;														//Store the string of the index into temp
				//std::cout << tempStr << " ";											//DEBUG
				inList[j] = std::stoi(tempStr);										//Save the int(input) to the array
				//std::cout << inList[j] << " ";										//DEBUG
			}
			//std::cout << std::endl;
			temp->setNext(new gate(index, type, count, inList));					//Declare a new gate
			delete[] inList;														//Clean up array
			break;
		case 'A':
		case 'O':																	//We declare and and or gates in the same way
			//And and Or can have as many inputs as the user feels.
			//std::cout << information.substr(information.find(type) + 2) << std::endl;		//DEBUG
			count = findLen(information.substr(information.find(type) + 2));		//Use length function to get number of inputs
			inList = new int[count];												//Declare array with number of inputs
			ss << information.substr(information.find(type) + 2);					//Stream is partial string
			//std::cout << "And/OR substr: ";											//DEBUG
			for (int j = 0; j < count; j++) {										//For every element
				ss >> tempStr;														//Put the string of the input into tempstring
				//std::cout << tempStr << " ";											//DEBUG
				inList[j] = stoi(tempStr);											//Store the int input into the array
			}
			temp->setNext(new gate(index, type, count, inList));					//The next gate is dynamically declared
			delete[] inList;														//Clean up memory
			break;
		default:																	//THIS CASE SHOULD NOT BE REACHED
			std::cout << "Critical Error" << std::endl;								//THE ONLY POSSIBILITY IS USER ERROR
			break;																	//DO NOT GET HERE
		}
		ss.clear();
		temp = temp->getNext();												//Crawl through gates
	}
	//After circuit read:
	temp = head;								//Reset the temp node to the head node
	for (int i = 0; i < gates; i++) {			//For every gate
			temp->getInputs(head);				//switch the values from index numbers to 0 or 1 for the inputs
			temp->Pulse();						//Clock pulse of this specific gate; updates output to be 0 or 1 based on the inputs and type of 
			temp = temp->getNext();				//Cycle through gates
	}
}