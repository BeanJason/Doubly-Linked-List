// CIS250_Homework03_JasonBean.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Jason Bean
//3-21-19
//Homework03

#include "pch.h"
#include <iostream>
#include "string"
#include "fstream"
#include "Node.h"
#include "DoublyLinkedList.h"

using namespace std;

void readFile(DoublyLinkedList&);

int main()
{
	DoublyLinkedList list;
	

	readFile(list);
	cout << "=====================================" << endl;
	cout << "Before Insert Into Doubly Linked List" << endl;
	cout << "=====================================" << endl;
	cout << endl;
	
	list.displayForward();
	cout << endl;
	list.displayBackward();
	cout << endl;
	list.insertNode(4, "Becky", "Dog", "Missing tail", 5, 25);

	cout << "=====================================" << endl;
	cout << "After Insert Into Doubly Linked List" << endl;
	cout << "=====================================" << endl;

	cout << endl;
	list.displayForward();
	cout << endl;
	list.displayBackward();
	cout << endl;

	list.deleteNode(2);

	cout << "=====================================" << endl;
	cout << "After Delete From Doubly Linked List" << endl;
	cout << "=====================================" << endl;

	cout << endl;
	list.displayForward();
	cout << endl;
	list.displayBackward();

	system("pause");
	return 0;
}

void readFile(DoublyLinkedList &doubleList)
{
	//Node node;
	//DoublyLinkedList doubleList;
	ifstream inputfile;
	string lineOfText;
	string fileName = "Pets.txt";
	int commaPos;
	string delim = ",";

	int visitId;
	string name;
	string type;
	string desc;
	int age;
	int weight;

	inputfile.open(fileName);
	
	if (inputfile)
	{
		
		while (getline(inputfile, lineOfText))
		{
			commaPos = lineOfText.find(delim);

			visitId = stoi(lineOfText.substr(0, commaPos));
			

			lineOfText = lineOfText.substr(commaPos + 1);
			commaPos = lineOfText.find(delim);

			name = (lineOfText.substr(0, commaPos));
			
			lineOfText = lineOfText.substr(commaPos + 1);
			commaPos = lineOfText.find(delim);

			type = (lineOfText.substr(0, commaPos));
			
			lineOfText = lineOfText.substr(commaPos + 1);
			commaPos = lineOfText.find(delim);

			desc = (lineOfText.substr(0, commaPos));
	
			lineOfText = lineOfText.substr(commaPos + 1);
			commaPos = lineOfText.find(delim);

			age = stoi(lineOfText.substr(0, commaPos));
			
			lineOfText = lineOfText.substr(commaPos + 1);
			commaPos = lineOfText.find(delim);

			weight = stod(lineOfText.substr(0, commaPos));
			//node.setWeight(weight);
			lineOfText = lineOfText.substr(commaPos + 1);
			commaPos = lineOfText.find(delim);

			doubleList.appendNode(visitId, name, type, desc, age, weight);
		}
	}
	else
	{
		cout << "File didn't open wtf" << endl;
	}
}
