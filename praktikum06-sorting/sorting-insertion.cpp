#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
	int deret[] = {15, 10, 13, 7, 22, 6, 17, 5, 7, 1};
	int n = 10;
	int i, j;
	int kunci;

	cout<<"Deret tak berurut = ";
	for (int id = 0; id < n; ++id)
	{
		cout<<deret[id]<<" ";	
	}
	cout<<endl<<endl;

	for (int i = 1; i < n; i++)
	{
		cout<<"i = "<<i<<endl;
		j = i;
		kunci = deret[i];
		cout<<"Kunci = deret["<<i<<"] = "<<kunci<<endl;

		while( j > 0 && (deret[j - 1] > kunci))
		{
			cout<<"deret["<<j<<"] ("<<deret[j-1]<<") > "<<kunci;
			cout<<"; insert "<<deret[j-1]<<" pada posisi "<<j<<endl;
			deret[j] = deret[j-1];

			for (int id = 0; id < n; ++id)
			{
				cout<<deret[id]<<" ";
			}
			cout<<endl;
			j--;
		}
		deret[j] = kunci;
		cout<<"insert x ("<<kunci<<") pada posisi "<<j<<endl;

		for (int id = 0; id < n; ++id)
		{
			cout<<deret[id]<<" ";
		}
		cout<<endl<<endl;
	}
	cout<<"Deret Berurut = ";
	for (int id = 0; id < n; ++id)
	{
		cout<<deret[id]<<" ";
	}
	cout<<endl;


	return 0;
}
