#include <iostream>
#include <conio.h>
#include <string>

using namespace std;
int main()
{
	int deret[] = {15, 10, 13, 7, 22, 6, 17, 5, 7, 1};
	int n = 10;
	int i, j, temp, idMin;
	int min = 9999;

	for (int id = 0; id < n; ++id)
	{
		cout<<deret[id]<<" ";
	}
	cout<<endl;
	cout<<" Angka Terkecil = "<<(min)<<endl;
	for (int i = 0; i < n; ++i)
	{
		min = 9999; 
		cout<<" i = "<<i<<endl;
		for (int j = i; j < n; ++j)
		{
			cout<<"Lebih kecil daripada deret["<<j<<"] ("<<deret[j]<<") dibanding "<<min<<" ? ";
			if (deret[j] < min)
			{
				cout<<" Ya ; Rubah ";
				min = deret[j];
				idMin = j;
				cout<<"Angka Terkecil = deret ["<<idMin<<"] = "<<min<<endl;
			}else{
				cout<<" Tidak ; "<<endl;
			}
		}
		cout<<endl;
		cout<<"Tukar deret["<<i<<"] dengan Angka Terkecil pada deret ["<<idMin<<"]"<<endl;
		temp = deret[i];
		deret[i] = deret[idMin];
		deret[idMin] = temp;
		for (int id = 0; id < n; ++id)
		{
			cout<<deret[id]<<" ";
		}
		cout<<endl;
		cout<<endl;
	}
	for (int id = 0; id < n; ++id)
	{
		cout<<deret[id]<< " ";
	}
	cout<<endl;
	return 0;
}
