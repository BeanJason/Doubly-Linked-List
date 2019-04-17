#pragma once

#include "iostream";
#include "string";

using namespace std;
class Node
{
	private:
		/*int visitId;
		string name;
		string type;
		string desc;
		int age;
		int weight;
		Node *head;
		Node *tail;
		Node *next;
		Node *prev;*/


	public:
		int visitId;
		string name;
		string type;
		string desc;
		int age;
		int weight;
		Node *next;
		Node *prev;
		/*void setVisitId(int);
		void setName(string);
		void setType(string);
		void setDesc(string);
		void setAge(int);
		void setWeight(int);*/
		Node();
		~Node();
};

