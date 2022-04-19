// Redo Undo Functionality Using Doubly Linked List

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	string action;
	Node* next;
	Node* prev;

	Node(string action){
		this->action = action;
		this->next = NULL;
		this->prev = NULL;
	}
};


/* Function to insert action into UndoList */
Node* Write(string action,Node* head){

	Node* newNode = new Node(action);
	if (head == NULL)
	{
		head = newNode;
		return head;
	}else if (head->next == NULL)
	{
		head->next = newNode;
		newNode->prev = head;
		return head;
	}else{
		Node* temp = head;
		while(temp->next!=NULL){
			temp = temp->next;
		}

		temp->next = newNode;
		newNode->prev = temp;
		return head;
	}

	return head;
}


void Read(Node* head){
	Node* temp = head;
	cout << "Text Editor String : ";
	while(temp!= NULL){
		cout << temp->action[6];
		temp = temp->next;
	}
	cout << endl;
}

Node* Undo(Node* Redo,Node* Undo){

	/* Traversing through the Undo List */
	Node* temp = Undo;
	while(temp->next != NULL)
		temp = temp->next;
	
	/* Clear previous node next field */
	if (temp->prev != NULL)
	{
		temp->prev->next = NULL; // Important Part of Program
	}

	if (Redo == NULL)
	{
		Redo = temp;
		temp->next = NULL;
		temp->prev = NULL;
		return Redo;
	}
	else if (Redo->next == NULL)
	{
		Redo->next = temp;
		temp->prev = Redo;
		Redo = Redo->next;
		return Redo;
	}
	return Redo;
}

Node* Redo(Node* Redo,Node* Undo){

	if(Redo == NULL){
		cout << "Can't perform redo operation" << endl;
		return Redo;
	}

	Node* Undotemp = Undo;
	Node* Redotemp = Redo;
	if (Redo->prev !=NULL)
	{
		Redo = Redo->prev;
		Redo->next = NULL;
	}
	else{
		Redo = NULL;
	}

	if (Undotemp == NULL)
	{
		Undotemp = Redotemp;
	}
	else if (Undotemp->next == NULL)
	{
		Undotemp->next = Redotemp;
		Redotemp->prev = Undotemp;
	}
	else
	{
		while(Undotemp->next!=NULL){
			Undotemp = Undotemp->next;
		}

		Undotemp->next = Redotemp;
		Redotemp->prev = Undotemp;

	}

	return Redo;
	
}

int main()
{
	Node* UndoHead = NULL;
	Node* RedoHead = NULL;
	while(true){

	int choice;
	cout << "\nChoose From the following : " << endl;
	cout << "1.Write" << endl;
	cout << "2.Read" << endl;
	cout << "3.Undo" << endl;
	cout << "4.Redo" << endl;
	cout << "5.Exit" << endl;
	cout << "Enter Your choice : ";

	cin >> choice;

	switch(choice){
		case 1:{
			char c;
			cout << "Enter Your character : ";
			cin >> c;
			string b = "Write ";
			string act = b+c;
			cout << act << endl;
			UndoHead = Write(act,UndoHead);
		}
		break;
		case 2:{
			Read(UndoHead);
		}
		break;
		case 3:{
			RedoHead = Undo(RedoHead,UndoHead);
		}
		break;
		case 4:{
			RedoHead = Redo(RedoHead,UndoHead);
		}
		break;
		case 5:{
			exit(0);
		}
		default:{
			cout << "Invalid Choice" << endl;
		}
	}

	}

	
	return 0;
}