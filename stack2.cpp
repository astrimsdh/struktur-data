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

int cariAngka(int cari){
	int id = 0;
	int posisi = -1;
	while(posisi < 0 && id < n){
		if (S[id] == cari)
		{
			posisi = id;
		}else{
			id++;
		}
	}

	return posisi;
}

void popStackNotTop(int posisi){
	//siapkan elemen lain untuk penyimpanan sementara
	int temp[n];
	int id = 0;
	while(getTop() > posisi){
		if (isKosong() == false)
		{
			// pindahkan elemen puncak sampai sebelum posisi ke stack Temp
			temp[id] = S[top];
			id++;
			cout<<S[top]<<" telah diambil dari stack S";

			S[top] = 0;
			top -= 1;
			cout<<"| Top = "<<getTop()<<" \n";
		}else{
			cout<<"Stack S KOSONG | Top = "<<getTop()<<" \n";
		}
	}

	// diambil elemen pada posisi
	if (getTop() == posisi)
	{
		popStack();
	}

	// push elemen kembali ke stack S
	id -= 1;
	while(id >= 0){
		pushStack(temp[id]);
		id--;
	}
}

int main(){
	int x;
	char pop;

	buatKosong();
	tampilkanStack();

	x = 0;

		while (isPenuh() == false)
		{
			cout<<"Masukkan angka (0 - 99) : ";
			cin>>x;
			pushStack(x);
		}
	tampilkanStack();
	// minta angka yang akan diambil 
	cout<<"Masukkan angka yang akan diambil dari Stack : ";
	cin>>x;
	int posisi = cariAngka(x);

	if (posisi >= 0)
	{
		//ditemukan pada stack 
		popStackNotTop(posisi);
	}else{
		cout<<x<<" bukan elemen Stack \n";
	}
	tampilkanStack();
	return 0;
}