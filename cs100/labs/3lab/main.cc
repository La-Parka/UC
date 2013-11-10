#include <iostream>
using namespace std;

class List
{
	public:
		struct Node
                {
                         Node* next;
                         int data;
                };


	private:

		Node* head;
		Node* tail;

	public:

		List();
		void insert(int d);
		void remove(unsigned i);
		Node* find(int d);
		unsigned size();
		void print();
		int sum();
};

List::List()
{
	head = NULL;
	tail = NULL;
}
void List::insert(int d)
{
	//if (size() >= 255)
	//{
	//	cout << "Error: List is too big." << endl;
	//	return;
	//}

	Node* newNode = new Node ();
	newNode->data = d;
	newNode->next = NULL;

	if (head == NULL)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		if (head->data >= d)
		{
			newNode->next = head;
			head = newNode;
		}
		//Addeed case if next is null
		else
		{
			Node* itLast = head;
			//Needed a case when you get to end of list and didnt add 
			for (Node* it = head->next; itLast != NULL; itLast = itLast->next)
			{
				if (it)
				{
					if (it->data >= d)
					{
						itLast->next = newNode;
						newNode->next = it;
						break;
					}
				}
				else if ( itLast == tail )
				{
					tail -> next = newNode;
					newNode -> next = NULL;
					tail=newNode;	
				}
				if (it)
					it = it -> next;
			}		

		}
	}

}

void List::remove(unsigned index)
{
	Node* itLast = head;
	if (index == 0)
	{
		head = itLast->next;
		delete itLast;
		return;
	}
	Node* it = head->next;
	for (unsigned i = 0; i <= index; i++)
	{
		if (i == index)
		{
			itLast->next = it->next;
			
			if (it == tail)
			{
				tail = itLast;
			}

			delete it;
		}
		else
		{
			it = it->next;
		}

		itLast = itLast->next;
	}
}

List::Node* List::find(int d)
{
	Node* notfound;

	for (Node* it = head; it != NULL; it = it->next)
	{
		if (it->data == d)
			return it;
	}

	return notfound;
}

unsigned List::size()
{
	unsigned i = 0;
	for (Node* it = head; it != NULL; it = it->next)
	{
		i++;
	}

	return i+1;
}

void List::print()
{
	for (Node* it = head; it != NULL; it = it->next)
	{
		cout << it->data << ' ';
	}
	cout << endl;
}

int List::sum()
{
	int sum;

	for (Node* it = head; it != NULL; it = it->next)
	{
		sum += it->data;
	}

	return sum;
}

int main()
{
	List list;

	int num;
	cout << "Enter an integer (enter a negative one to stop inserting): ";
	cin >> num;

	unsigned size = 0;

	while (num >= 0)
	{
		list.insert(num);
		cout << num << " was inserted into the list!" << endl;

		cout << "Enter an integer (enter a negative one to stop inserting): ";
		cin >> num;
	}

	cout << "List contents: " << endl
	     << "\t";
	list.print();

	unsigned index;
	cout << "Delete the element at index: ";
	cin >> index;

	list.remove(index);

        cout << "List contents: " << endl
             << "\t";
        list.print();

	unsigned n;
	cout << "Search for a number: ";
	cin >> n;

	List::Node* found = list.find(n);
	if (n != NULL)
		cout << "Found " << found->data << endl;
	else
		cout << "Could not find " << n << endl;

	cout << "Sum of all list elements: " << list.sum() << endl;

	return 0;
}












