#ifndef _Linked_List_
#define _Linked_List_

//Doubly Linked List class which uses a template to allow the List to be used with any datatype
template <class DataType>
class List
{
private:
	//Node Structure
	struct Node
	{
		DataType data;
		Node* prevNode;
		Node* nextNode;
	};
public:
	List()
	{
		//Set the last node in the linked list
		tail = nullptr;
		//Set the first node in the linked list
		head = nullptr;
	}

	//Create next node in list that points to its previous node
	void createNode(DataType iData)
	{
		//Set start and end Node if it has no connecting node
		if (head == nullptr && tail == nullptr)
		{
			head = new Node{ iData, nullptr, nullptr };
			tail = head;
		}
		//Create the new node after the tail node and set it as the tail.
		tail->nextNode = new Node{ iData, tail, nullptr };
		//Set the new tail node;
		tail = tail->nextNode;
	}
	//Insert Node inside desired location of list
	void insert(unsigned int iter, DataType iData)
	{
		unsigned int n = 0;
		Node* current = head;
		while (true)
		{
			if (iter == n)
			{
				Node* prev = current.prevNode;
				current.prevNode = new Node{ iData, front, prev};
				prev.nextnode = current.prevnode;
				return;
			}
			current = current.nextNode;
			++n;
		}
	}
	//Remove Node at desired position
	void remove(unsigned int iter)
	{
		if (head != nullptr)
		{
			unsigned int n = 0;
			Node* current = head;
			while (current != nullptr)
			{
				if (iter == n)
				{
					current->prevNode->nextNode = current->nextNode;
					current->nextNode->prevNode = current->prevNode;
					if (current == head)
					{
						head = current->nextNode;
					}
					if (current == tail)
					{
						tail = current->prevNode;
					}
					delete current;
					return;
				}
				node = node->nextNode;
				++n;
			}
		}
		return;
	}
	void remove(Node* iNode)
	{
		Node* current = head;
		while (current != nullptr)
		{
			if (iNode == current)
			{
				current->prevNode->nextNode = current->nextNode;
				current->nextNode->prevNode = current->prevNode;
				if (current == head)
				{
					head = current->nextNode;
				}
				if (current == tail)
				{
					tail = current->prevNode;
				}
				delete current;
				return;
			}
			node = node->nextNode;
		}
		return;
	}
	//Find first node in the list that has the desired data
	Node* find(DataType iData)
	{
		Node* current = head;
		while (true)
		{
			if (current == nullptr) return nullptr;
			if (iData == current->data) return current;
			current = current->nextNode;
		}
	}
	//Return minimum valued node
	void min();
	//Return maximum valued node
	void max();

	//Set the variables to the passed argument: setters
	void setHead(Node* iHead)
	{
		head = iHead;
	}
	void setTail(Node* iTail)
	{
		tail = iTail;
	}
	void setData(DataType iData)
	{
		data = iData;
	}

	//return the variables from the class: getters
	Node* getHead()
	{
		return head;
	}
	Node* getTail()
	{
		return tail;
	}
	DataType getData()
	{
		return data;
	}

private:
	//Class variables
	Node* head;
	Node* tail;
};
#endif