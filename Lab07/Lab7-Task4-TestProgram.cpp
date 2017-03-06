#include<string>
#include<iostream>
#include<time.h>
#include "OrderedList.h"
using namespace std;

int main() {
	srand(time(NULL));
	int size = 30;
	int choice;
	//cout << "Which test would you like to perform: 1 (OrderedList), 2 (OrderedListBack), 3 (OrderedListEmptySpace): ";
	//cin >> choice;
	OrderedListEmptySpace<int> list3;
	OrderedListBack<int> list2;
	OrderedList<int> list1;
	
	list1 = OrderedList<int>(size);
	list2 = OrderedListBack<int>(size);
	list3 = OrderedListEmptySpace<int>(size);

	int randomInts[30];
	string output = "";
	/*for (int i = 0; i < 30; i++) {
		randomInts[i] = rand() % 100 + 1;
		list1.AddItem(&randomInts[i]);
		//list2.AddItem(&randomInts[i]);
		//list3.AddItem(&randomInts[i]);
		cout << "List2 " << list2.getListContents() << endl;

		output += to_string(randomInts[i]) + " ";
	}*/
	int a, b, c, d, e;
	a = 1;
	b = 3;
	c = 2;
	d = 2;
	e = 4;
	list2.AddItem(&a);
	list2.AddItem(&b);
	list2.AddItem(&c);
	list2.AddItem(&d);
	list2.AddItem(&e);
	cout << "Random inputs " << output << endl;
	cout << "List1 " << list1.getListContents() << endl;
	cout << "List2 " << list2.getListContents() << endl;
	cout << "List3 " << list3.getListContents() << endl;
	
	char z;
	cin >> z;
	
}