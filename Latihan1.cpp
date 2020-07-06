#include <iostream>
#define n 10

using namespace std;

// global variabel
int First, Last;
int S[n];

void buatKosong(){
	First = -1;
	Last = -1;
}

bool isKosong(){
	return (First < 0);
}

bool isPenuh(){
	return (Last == (n-1));
}

int getDepan(){
	return First;
}

int getBelakang(){
	return Last;
}

void tampilkanAntrian(){
	if (isKosong() == false)
	{
		cout<<"Isi Stack : ";
		for (int i = (n-1); i >= 0; i--)
		{
			cout<<S[i]<<" | ";
		}
		cout<<"\n";
	}else{
		cout<<"Antrian KOSONG | Depan = "<<getDepan()<<" | Belakang = "<<getBelakang()<<"\n";
	}
}

int tambahElemen(int x){
	if (isPenuh() == false)
	{
		if (isKosong() == true)
		{
			First += 1;
		}
		Last +=1;
		S[Last] = x;

		cout<<x<<" telah ditambahkan pada antrian | Depan = "<<getDepan()<<" | Belakang = "<<getBelakang()<<" \n";
	}else{
		cout<<"Antrian PENUH | Depan = "<<getDepan()<<"| Belakang = "<<getBelakang()<<"\n";
	}
	return getBelakang();
}

int hapusElemen(){
	int x = S[First];
	if (isKosong() == false)
	{
		if (getDepan() == getBelakang())	
		{
			S[First] = 0;
			buatKosong();
		}else{
			S[First] = 0; //Hapus elemen Pertema
			// Geser Elemen
			int posisi = First + 1;
			while(posisi <= Last){
				S[posisi - 1] = S[posisi];
				posisi++;
			}
			S[Last] = 0;
			Last -= 1;
		}

		cout<<x<<" telah dihapus dari Antrian | Depan = "<<getDepan();
		cout<<" | Belakang = "<<getBelakang()<<"\n";
	}else{
		cout<<"Antrian KOSONG | Depan = "<<getDepan()<<"| Belakang = "<<getBelakang()<<"\n";
	}

	return getBelakang();
}

int main(){
	int x;
	char Y;

	buatKosong();
	tampilkanAntrian();
	x = 0;

	// isi antrian sampai penuh
	while(isPenuh() == false){
		cout<<"Masukkan angka (0 - 99) : ";
		cin>>x;
		tambahElemen(x);
		tampilkanAntrian();
	}

	Y = 'Y';
	while(Y == 'Y'){
		cout<<"Hapus Elemen dari Antrian (Y/T) ? ";
		cin>>Y;
		if (Y == 'Y')
		{
			hapusElemen();
		}
		tampilkanAntrian();
	}
	return 0;
}