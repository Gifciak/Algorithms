// Coctail Shaker Sort.cpp : Defines the entry point for the console application.

//Application created on 05.07.2018
// Program written entirely by Przemyslaw Poluszczyk
// For the purposes of self-developing and learning.
// Feel free to use it if you need it.
// Why object? to make it a little bit more complex.

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <fstream>

using namespace std;

class CoctailShakerSort
{
private:
	long long ASize; // size of our Array
	long long *Array; // the array itself
	bool PosSwap; // position swap, needed for the sorting
	fstream File; // File operations
	int option; // by hand or by file?
public:
	CoctailShakerSort();
	~CoctailShakerSort();
	void CoctailCompute();
	void SetArrayByHand();
	void PrintResults();
	void GetSize();
	void RunProgram();
};

int main()
{
	CoctailShakerSort Test;
	Test.RunProgram();
	_getch();
	return 0;
}

// the most complex constructor ever.
CoctailShakerSort::CoctailShakerSort()
{
	option = 0;
}
// ???
CoctailShakerSort::~CoctailShakerSort()
{
	delete[] Array;
}
// main part of our app
void CoctailShakerSort::CoctailCompute()
{
	int bottom = 0;
	int top = ASize - 1;
	//int buffor;
	PosSwap = true;
	while (PosSwap)
	{
		PosSwap = false;

		for (int i = bottom; i<top; i++)
		{
			if (Array[i]>Array[i + 1])
			{
				swap(Array[i], Array[i + 1]);
				/*buffor = Array[i];
				Array[i] = Array[i + 1];
				Array[i + 1] = buffor;*/
				PosSwap = true;
			}
		}
		top--;
		
		for (int i = top; i>bottom; i--)
		{
			if (Array[i] < Array[i - 1])
			{
				swap(Array[i], Array[i - 1]);
				/*	buffor = Array[j];
					Array[j] = Array[j - 1];
					Array[j - 1] = buffor;*/
				PosSwap = true;
			}
			}
		bottom++;
	}
}

void CoctailShakerSort::SetArrayByHand()
{
	Array = new long long[ASize];
	for (int i = 0; i<ASize; i++)
	{
		cin >> Array[i];
	}
}
//works fine, nothing to say about that method.
void CoctailShakerSort::PrintResults()
{
	for (int i = 0; i<ASize; i++)
	{
		cout << Array[i] << " ";
	}
}

void CoctailShakerSort::GetSize()
{
	if (option == 1)
	{
		cout << "Insert by hand size of array, and then numbers" << endl;
		cin >> ASize;
		SetArrayByHand();
	}
	else if (option == 2)
	{
		File.open("example.txt");
		if (File.good())cout << "File loaded" << endl;
		File >> ASize;
		Array = new long long[ASize];
		for (int i = 0; i<ASize; i++)
		{
			File >> Array[i];
		}
		File.close();
	}
}

void CoctailShakerSort::RunProgram()

{
	cout << "manually created Array 1)\tFrom the file 2)" << endl;
	cin >> option;
	GetSize();
	//PrintResults();
	CoctailCompute();
	PrintResults();
}