#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
	int deret[] = {15, 10, 13, 7, 22, 6, 17, 5, 7, 1};
	int n = 10;
	int i, j, temp;
	int tukar = 0;

	cout<<"Deret tak berurut = ";
	for (int id = 0; id < n; ++id)
	{
		cout<<deret[id]<<" ";	
	}
	cout<<endl<<endl;

	for (int i = 0; i < n; ++i)
	{
		cout<<" i = "<<i<<endl;
		for (int j = 0; j < n; ++j)
		{
			cout<<"deret["<<j<<"] > deret["<<(j+1)<<"] ? ";
			if (deret[j] > deret[j+1])
			{
				cout<<"Tukarkan ";
				temp = deret[j];
				deret[j] = deret[j+1];
				deret[j+1] = temp;

			}
			cout<<endl;
			for (int id = 0; id < n; ++id)
			{
				cout<<deret[id]<<" ";
			}
			cout<<endl;
		}
	}
	cout<<endl<<"Deret terurut = ";
	for (int id = 0; id < n; ++id)
	{
		cout<<deret[id]<<" ";
	}
	cout<<endl;

	return 0;
}
