#include<string>
#include<iostream>
#include<time.h>
#include "OrderedList.h"
using namespace std;

int main() {
	srand(time(NULL));
	int size = 50;
	int choice;
	//cout << "Which test would you like to perform: 1 (OrderedList), 2 (OrderedListBack), 3 (OrderedListEmptySpace): ";
	//cin >> choice;
	OrderedListEmptySpace<int> list3;
	OrderedListBack<int> list2;
	OrderedList<int> list1;
	
	float avgOps1 = 0;
	float avgOps2 = 0;
	float avgOps3 = 0;

	for (int n = 0; n < 100; n++) {

		list1 = OrderedList<int>(size);
		list2 = OrderedListBack<int>(size);
		list3 = OrderedListEmptySpace<int>(size);

		int randomInts[50];
		string output = "";
		for (int i = 0; i < size; i++) {
			randomInts[i] = rand() % 100 + 1;
			list1.AddItem(&randomInts[i]);
			list2.AddItem(&randomInts[i]);
			list3.AddItem(&randomInts[i]);
			//cout << ".."<<to_string(randomInts[i])<<".." << list3.getListContents() << endl;

			output += to_string(randomInts[i]) + " ";
		}
		int index;
		string remove = "";
		for (int i = 0; i < 25; i++) {
			index = rand() % size;

			try {
				list1.RemoveItem(&randomInts[index]);
				list2.RemoveItem(&randomInts[index]);
				list3.RemoveItem(index);
				//cout << ".."<<to_string(randomInts[i])<<".." << list3.getListContents() << endl;
				remove += to_string(randomInts[i]) + " ";
			}
			catch (...) {
				i -= 1;
			}


		}
		int a, b, c, d, e;
		a = 1;
		b = 3;
		c = 2;
		d = 2;
		e = 4;
		/*list3.AddItem(&a);
		cout << list3.getListContents() << endl;
		list3.AddItem(&b);
		cout << list3.getListContents() << endl;
		list3.AddItem(&c);
		cout << list3.getListContents() << endl;
		list3.AddItem(&d);
		cout << list3.getListContents() << endl;
		list3.AddItem(&e);
		cout << list3.getListContents() << endl;
		cout << "Random inputs " << output << endl;
		cout << "Removed inputs " << remove << endl;
		cout << "List1 operations " << list1.getNumOps() << endl << list1.getListContents() << endl;
		cout << "List2 operations " << list2.getNumOps() << endl << list2.getListContents() << endl;
		cout << "List3 operations " << list3.getNumOps() << endl;
		cout << list3.getListContents() << endl;*/
		avgOps1 += list1.getNumOps();
		avgOps2 += list2.getNumOps();
		avgOps3 += list3.getNumOps();
	}
	cout << "l1: " << int(avgOps1/100) << "l2: " << int(avgOps2/100) << "l3: " << int(avgOps3/100) << endl;
	char z;
	cin >> z;
	
}