#include <iostream>
#define n 10

using namespace std;

int main(){
	int S[n];
	int top, x;
	char pop;

	top = -1;
	x = 0;
	while(x < 100)
	{
		cout<<"Masukkan angka (0 - 99) : ";
		cin>>x;
		if (top >= n-1){
			cout<<x<<" tidak ditambahkan ke Stack | Top = "<<top<<" \n\n";
			cout<<"Pop elemen top untuk memasukkan data (Y/T) ? ";
			cin>>pop;

			if (pop == 'Y')
			{
				S[top] = 0;
				top -= 1;

				cout<<x<<" Stack Belum penuh | Top = "<<top<<" \n";
			}else{
				cout<<x<<" tidak ditambahkan ke Stack | Top = "<<top<<" \n";
			}
		}else{
			if (top < 0 )
			{
				cout<<"Stack Kosong \n";
			}
			top++;
			S[top] = x;

			cout<<x<<" ditambahkan ke Stack | Top = "<<top<<" \n";
		}
	}
	cout<<"Isi Stack : ";
	for (int i= n-1; i >= 0; i--){
		cout<<S[i]<<" | ";
	}
	cout<<" \n";
	return 0;
}