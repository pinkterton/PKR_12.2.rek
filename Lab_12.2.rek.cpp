#include <iostream>

using namespace std;

typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem;
	tmp->info = value;
	tmp->link = NULL;
	if (last != NULL)
		last->link = tmp;
	last = tmp;
	if (first == NULL)
		first = tmp;
}
Info dequeue(Elem*& first, Elem*& last)
{
	Elem* tmp = first->link;
	Info value = first->info;
	delete first;
	first = tmp;
	if (first == NULL)
		last = NULL;
	return value;
}
bool check_pair_elements(Elem* L)
{
	if (L == NULL)
		return false;

	if (L->link == NULL)
		return false;
	
	if (L->info == L->link->info)
		return true;

	return check_pair_elements(L->link);
}

int main()
{
	Elem* first = NULL,
		* last = NULL;

	const int VALUE = 6;

	cout << "Length list: " << VALUE << endl;
	for (int i = 1; i <= VALUE; i++)
	{
		int n;
		cout << "Enter values: "; cin >> n;
		enqueue(first, last, n);
	}

	cout << endl;
	if (check_pair_elements(first))
		cout << "Pair founded" << endl;
	else
		cout << "Pair not founded" << endl;


	cout << endl;
	while (first != NULL)
		cout << dequeue(first, last) << " ";
	cout << endl;

	return 0;
}