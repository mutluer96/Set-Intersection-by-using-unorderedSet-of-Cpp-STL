#include <iostream>
#include <unordered_set>
#include<Windows.h>

using namespace std;

int main()
{
	int *list1, *list2;
	vector<int> intersect;
	int cap1, cap2, temp;
	cout << "What is the num of elements in list 1?\t";
	cin >> cap1;
	list1 = new int[cap1];
	cout << endl;
	for (int i = 0; i < cap1; i++)
	{
		cout << "Please insert an integer for list1: ";
		cin >> temp;
		list1[i] = temp;
	}

	cout << "\nWhat is the num of elements in list 2?\t";
	cin >> cap2;
	list2 = new int[cap2];
	cout << endl;

	for (int i = 0; i < cap2; i++)
	{
		cout << "Please insert an integer for list2: ";
		cin >> temp;
		list2[i] = temp;
	}

	unordered_set<int> setnum; //In background there is hash table and find operation takes just constant step

	int small_index;
	bool is_Cap1; 
	if (cap1 < cap2)
	{
		small_index = cap1;
		is_Cap1 = true;
	}
	else
	{
		small_index = cap2;
		is_Cap1 = false;
	}

	if (is_Cap1 == true) 
	{
		for (int j = 0; j < cap2; j++)
		{
			setnum.insert(list2[j]);
		}
		for (int i = 0; i < small_index; i++)
		{
			if (setnum.find(list1[i]) != setnum.end())
			{
				intersect.push_back(list1[i]);
			}
		}
	}
	else
	{
		for (int j = 0; j < cap1; j++)
		{
			setnum.insert(list1[j]);
		}
		for (int i = 0; i < small_index; i++)
		{
			if (setnum.find(list2[i]) != setnum.end())
			{
				intersect.push_back(list2[i]);
			}
		}
	}
	
	vector<int>::iterator it_res;//as a shortening of resultant iterator
	cout <<endl<<"intersection of them:\n";
	for (it_res = intersect.begin(); it_res != intersect.end(); it_res++)
	{
		cout << *it_res << " ";
	}
	cout << endl;

	system("Pause");
	return 0;
}