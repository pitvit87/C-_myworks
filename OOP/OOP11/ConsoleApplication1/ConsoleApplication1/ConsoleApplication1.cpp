#include <iostream>
#include <fstream>
using namespace std;

void SaveDoubleArreyToFile(const char* filename, double* A, int size)
{
	ofstream outFile(filename, ios::binary);

	if (!outFile)
	{
		cerr << "Error opening file." << endl;
		return;
	}

	outFile.write((char*)&size, sizeof(size));

	for (int i = 0; i < size; i++)
		outFile.write((char*)&A[i], sizeof(double));

	outFile.close();

}

void LoadDoubleArrayFromFile(const char* filename, double** A, int* size)
{
	ifstream inFile(filename, ios::binary);

	if (!inFile.is_open())
	{
		cerr << "Error input file." << endl;
		return;
	}

	inFile.read((char*)size, sizeof(int));

	try
	{
		*A = new double[*size];
	}
	catch (bad_alloc e)
	{
		cout << e.what() << endl;
		return;
	} 

	for (int i = 0; i < *size; i++)
	{
		inFile.read((char*)&(*A)[i], sizeof(double));
	}

	inFile.close();

}

int main()
{
	double AD[] = { 1.1, 2.2, 3.3, 4.4, 5.5 , 6.6 };

	SaveDoubleArreyToFile("array.bin", AD, 6);
	
	double* AD2 = nullptr;
	int size2;

	LoadDoubleArrayFromFile("array.bin", &AD2, &size2);

	for (int i = 0; i < size2; i++)
		cout << AD2[i] << " ";
	cout << endl;

}
