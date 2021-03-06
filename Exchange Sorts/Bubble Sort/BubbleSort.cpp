// Application created on 03.07.2018
// Program written entirely by Przemyslaw Poluszczyk
// For the purposes of self-developing and learning.
// Feel free to use it if you need it.
// Why object? to make it a little bit more complex.

#include "stdafx.h"  // only for Visual C++.
#include <fstream> // Read/Write from file.
#include <iostream> // Console stream.
#include <conio.h>  // i like _getch()

using namespace std;
// Main class of our BubbleSort
class BubbleSort
{

private:

	fstream File; // name of our File.
	int Size; // Size of an Array
	int *_Array; // Array ( should be long long for big data )
public:
	BubbleSort(); // default Constructor.
	~BubbleSort(); // Class Destructor
	void BubbleCompile(); // MAIN thing in this code, here is the BubbleSort itself.
	void PrintOnScreen(); // Shows the results on Console
	void SetArray(); // Sets the Array Size / Indexes
	void Run(); // All functions put together so the main is clear
	void ReadFile(); // Reads data from file.
};

int main()

{
	BubbleSort Test;
	
	Test.Run();
	_getch();
	return 0;
}

BubbleSort::BubbleSort()
{
}

BubbleSort::~BubbleSort()
{
	delete[] _Array;
}

void BubbleSort::BubbleCompile()
{
	for (int j = 0; j<Size; j++)
	{
		for (int i = 0; i<Size - 1; i++)
		{
			int buffor = 0;
			if (_Array[i]>_Array[i + 1])
			{
				buffor = _Array[i];
				_Array[i] = _Array[i + 1];
				_Array[i + 1] = buffor;
			}
		}
	}
}

void BubbleSort::PrintOnScreen()
{
	for (int i = 0; i<Size; i++)
	{
		cout << " " << _Array[i];
	}
}

void BubbleSort::SetArray()
{
	int Step1;
	cout << "Hello,Would you like to type down the numbers or update Array from file?\n1.Array\t2.File" << endl;
	cin >> Step1;
	if (Step1 == 1)
	{
		cout << "Insert size of the array" << endl;
		cin >> Size;
		_Array = new int[Size];
		for (int i = 0; i<Size; i++)
			cin >> _Array[i];
		BubbleCompile();
	}
	else if(Step1== 2)
	{
		ReadFile();
	}
	else cout << "Wrong number choosen, what did u expect ? " << endl;
}

void BubbleSort::Run()
{
	SetArray();
	PrintOnScreen();
}

void BubbleSort::ReadFile()
{
	int step1;
	cout << "Which type of file would you like to use?\n1.Small\t2.Medium\t3.Big" << endl;
	cin >> step1;
	if (step1 == 1)
	{
		File.open("small.txt");
		//if(File.is_open()) cout<<"File is now opened "<<endl;
		File >> Size;
		_Array = new int[Size];
		for (int i = 0; i<Size; i++)
		{
			File >> _Array[i];
		}
		File.close();
		BubbleCompile();
	}
	else if (step1 == 2)
	{
		File.open("medium.txt");
		//if(File.is_open()) cout<<"File is now opened "<<endl;
		File >> Size;
		_Array = new int[Size];
		for (int i = 0; i<Size; i++)
		{
			File >> _Array[i];
		}
		File.close();
		BubbleCompile();
	}
	else if (step1 == 3)
	{
		File.open("big.txt");
		//if(File.is_open()) cout<<"File is now opened "<<endl;
		File >> Size;
		_Array = new int[Size];
		for (int i = 0; i<Size; i++)
		{
			File >> _Array[i];
		}
		File.close();
		BubbleCompile();
	}
	else cout << "Wrong number choosen, what did u expect?" << endl;
}