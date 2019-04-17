#pragma once
#include "iostream"
#include "string"
#include "Node.h"

using namespace std;

class DoublyLinkedList
{
	private:
		Node *head;
		Node *tail;
	public:
		void appendNode(int, string, string, string, int, double);
		void const displayForward();
		void const displayBackward();
		void insertNode(int, string, string, string, int, double);
		void deleteNode(int);

		DoublyLinkedList();
		~DoublyLinkedList();
};

