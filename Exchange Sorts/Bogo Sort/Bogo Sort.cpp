// Bogo Sort.cpp : Defines the entry point for the console application.
//Application created on 08.07.2018
// Program written entirely by Przemyslaw Poluszczyk
// For the purposes of self-developing and learning.
// Feel free to use it if you need it.
// Why object oriented programming? to make it a little bit more complex.

#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <ctime>

using namespace std;

class BogoSort
{
private:
	long long ASize;
	long long *Array;
	long long counter;
public:
	void CheckOrder();
	void RandomizeArray();
	void PrintResults();
	void SetArray();
	void RunProgram();
	bool GoodOrder();
	~BogoSort();
};

int main()
{
	BogoSort Test;
	Test.RunProgram();
	_getch();
	return 0;
}

void BogoSort::CheckOrder()
{
	counter = 0;
	while (!GoodOrder())
	{
		RandomizeArray();
		counter++;
	}
}

void BogoSort::RandomizeArray()
{
	srand(time(NULL));
	for (int i = 0; i<ASize; i++)
	{
		swap(Array[i], Array[rand() % ASize]);
	}
}
void BogoSort::PrintResults()
{
	for (int i = 0; i<ASize; i++)
	{
		cout << Array[i] << " ";
	}
}

void BogoSort::SetArray()
{
	cout << "insert size of the array" << endl;
	cin >> ASize;
	Array = new long long[ASize];
	//ASize/sizeof Array[0];
	cout << "add numbers to an Array" << endl;
	for (int i = 0; i < ASize; i++)
	{
		cin >> Array[i];
	}
}

void BogoSort::RunProgram()
{
	SetArray();
	CheckOrder();
	cout << "Array has been sorted" << endl;
	PrintResults();
	cout << " Array had to be shuffled " << counter << " time\s";
}
bool BogoSort::GoodOrder()

{
	int temp = ASize;
	bool goodOrder = true;
	while (--temp > 0) {
		if (Array[temp - 1] > Array[temp]) goodOrder = false;
	}
	return goodOrder;
}
BogoSort::~BogoSort()
{
delete [] Array;
}
