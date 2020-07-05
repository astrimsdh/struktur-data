#include <iostream>
#define n 10

using namespace std;
int top;
int S[n];

void buatKosong(){
	top = -1;
}

bool isKosong(){
	if (top < 0 )	
	{
		return true;
	}else{
		return false;
	}
}

bool isPenuh(){
	if (top >= n-1)
	{
		return true;	
	}else{
		return false;
	}
}

int getTop(){
	return top;
}

int pushStack(int x) {
	if (isPenuh() == false)
	{
		top += 1;
		S[top] = x;
		cout<<x<<" telah ditambahkan pada Stack | Top = "<<getTop()<<" \n";
	}else{
		cout<<x<<"Stack PENUH | top = "<<getTop()<<" \n";
	}

	return getTop();
}


int popStack() {
	if (isKosong() == false)
	{
		int x = S[top];
		S[top] = 0;
		top -= 1;
		cout<<x<<" telah diambil dari Stack | Top = "<<getTop()<<" \n";
	}else{
		cout<<"Stack KOSONG | Top = "<<getTop()<<" \n";
	}
	return getTop();
}

void tampilkanStack(){
	if (isKosong() == false)
	{
		cout<<"Isi Stack : ";
		for (int i = n-1 ; i >= 0; i--)
		{
			cout<<S[i]<<" | ";
		}
		cout<<" \n";
	}else{
		cout<<"Stack KOSONG | Top = "<<getTop()<<" \n";
	}
}


int main(){
	int x;
	char pop;

	buatKosong();
	tampilkanStack();

	x = 0;

	while(x < 100) {
		cout<<"Masukkan angka (0 - 99)";
		cin>>x;

		if (isPenuh() == false)
		{
			pushStack(x);
		}else{
			popStack();
			pushStack(x);
		}
	}

	tampilkanStack();
	return 0;
}
