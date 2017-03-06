#include<string>
#include<iostream>
#include "OrderedList.h"
using namespace std;

int main() {
	int size = 30;
	OrderedList<int> list1 = OrderedList<int>(size);
	OrderedListBack<int> list2 = OrderedListBack<int>(size);
	OrderedListEmptySpace<int> list3 = OrderedListEmptySpace<int>(size);
	cout << "List";
}