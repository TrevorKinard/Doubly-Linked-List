#include <iostream>
#include "Doubly_Linked_List.h"

void main()
{
	//User  number input
	int input = 0;
	//Create Linked List
	List<int> created = List<int>();

	while (input != 999)
	{
		//Clear screen
		system("cls");
		//Menu display
		std::cout << "1: Add node\n2: View Head node\n3: View Tail node\n";

		//Grab user's input
		std::cin >> input;
		//Switch through user's choice
		switch (input)
		{
		//Menu option 1
		case 1:
			std::cout << "Input a number!\n";
			std::cin >> input;
			//Create a new node and set its data
			created.createNode(input);
			std::cout << "Node Created!\n";
			break;
		//Menu option 2
		case 2: 
			//Display head of the linked list
			std::cout << created.getHead()->data << "\n";
			break;
		//Menu option 3
		case 3:
			//Display tail of the linked list
			std::cout << created.getTail()->data << "\n";
			break;
		}
		system("pause");
	}
}