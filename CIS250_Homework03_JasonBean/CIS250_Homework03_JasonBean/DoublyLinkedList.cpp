#include "pch.h"
#include "DoublyLinkedList.h"
#include "Node.h"
#include "iomanip"

DoublyLinkedList::DoublyLinkedList()
{
}


DoublyLinkedList::~DoublyLinkedList()
{
}

void DoublyLinkedList::appendNode(int id, string Pname, string Ptype, string description, int Page, double Pweight)
{
	Node *node;
	Node *curNode;


	if (!head)
	{
		node = new Node();
		node->visitId = id;
		node->name = Pname;
		node->type = Ptype;
		node->desc = description;
		node->age = Page;
		node->weight = Pweight;
		node->next = nullptr;
		node->prev = nullptr;
		head = node;
		tail = node;

		
	}
	else {
		node = new Node();
		node->visitId = id;
		node->name = Pname;
		node->type = Ptype;
		node->desc = description;
		node->age = Page;
		node->weight = Pweight;
		node->next = nullptr;
		node->prev = tail;
		tail->next = node;
		tail = node;
	}

	
}

void const DoublyLinkedList::displayForward()
{
	
	cout << "Displaying Doubly Linked List Forward" << endl;
	cout << "=====================================" << endl;
	Node *curNode;
	curNode = head;
	
	int setW = 30;

	cout << left << setw(setW) << "VisitID" << left << setw(setW) << "Name" << left << setw(setW) << "Type" << left << setw(setW) << "Description";
	cout << "=============================================================================================================" << endl;
	while (curNode != nullptr)
	{
		cout << left << setw(setW) << curNode->visitId << left << setw(setW) << curNode->name << left << setw(setW) << curNode->type << left << setw(setW) << curNode->desc;
		
		curNode = curNode->next;
	}
}

void const DoublyLinkedList::displayBackward()
{
	cout << "Displaying Doubly Linked List Backward" << endl;
	cout << "======================================" << endl;
	Node *curNode;
	curNode = tail;

	int setW = 30;

	cout << left << setw(setW) << "VisitID" << left << setw(setW) << "Name" << left << setw(setW) << "Type" << left << setw(setW) << "Description" << endl;
	cout << "=============================================================================================================" << endl;

	//Loop to cycle through all of the nodes
	while (curNode != nullptr)
	{
		cout << left << setw(setW) << curNode->visitId << left << setw(setW) << curNode->name << left << setw(setW) << curNode->type << left << setw(setW) << curNode->desc;
		
		curNode = curNode->prev;
	}

}

void DoublyLinkedList::insertNode(int id, string Pname, string Ptype, string description, int Page, double Pweight)
{
	Node *node;
	Node *curNode;
	Node *prevNode = nullptr;

	node = new Node();
	node->visitId = id;
	node->name = Pname;
	node->type = Ptype;
	node->desc = description;
	node->age = Page;
	node->weight = Pweight;

	if (!head)
	{
		head = node;
		node->next = nullptr;
	}

	else
	{
		curNode = head;

		while (curNode != nullptr && curNode->visitId < id)
		{
			prevNode = curNode;

			curNode = curNode->next;
		}

		if (prevNode == nullptr)
		{
			head = node;
			node->next = curNode;
			curNode->prev = head;
		}
		else
		{
			prevNode->next = node;
			node->next = curNode;
			node->prev = prevNode;
			curNode->prev = node;
		}
	}

}

void DoublyLinkedList::deleteNode(int id)
{
	Node *curNode;
	Node *node;
	Node *prevNode = nullptr;

	if (!head)
	{
		return;
	}

	if (head->visitId == id)
	{
		curNode = head->next;
		delete head;
		head = curNode;
	}

	else
	{
		curNode = head;

		while (curNode != nullptr && curNode->visitId != id)
		{
			prevNode = curNode;
			curNode = curNode->next;
		}

		if (curNode)
		{
			node = curNode->next;
			prevNode->next = node;
			
			node->prev = prevNode;


			delete curNode;
		}
	}
}
