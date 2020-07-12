#include <iostream>
#include <string>
#define n 10
using namespace std;

int Top, Top2;
std::string histori[n];
std::string moveon[n];
std::string kata;

void buatKosong(int obj){
	if (obj == 0)
	{
		Top = -1;
	}else if(obj == 1){
		Top2 = -1;
	}
}

bool isKosong(int obj){
	if (obj == 0)
	{
		if (Top < 0 )
		{
			return true;
		}else{
			return false;
		}
	}else if (obj == 1){
		if (Top2 < 0 )
		{	
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}


bool isPenuh(int obj){
	if (obj == 0)
	{
		if (Top == (n-1))
		{
			return true;
		}else{
			return false;
		}
	}else if (obj == 1){
		if (Top2 == (n-1))
		{
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}

int getTop(int obj){
	if (obj == 0 )
	{
		return Top;
	}else{
		return Top2;
	}
}

void tampilkanStack(){
	if (isKosong(0) == false)
	{
		cout<<"\nRiwayat Jelajah : ";
		for (int i = getTop(0); i >= 0; i--)
		{
			cout<<histori[i]<<" | ";
		}
		cout<<"\n\n";
	}else{
		cout<<"\nRiwayat KOSONG\n";
	}
}

int jumlahItem(int obj){
	if (obj == 0)
	{
		return getTop(0)+1;
	}else{
		return getTop(1)+1;	
	}
}

int jelajahBaru(){
	if (isPenuh(0) == false)
	{
		Top += 1;
		histori[Top] = kata;

		cout<<"\n\n";
		cout<<"Membuka jelajah : "<<kata<<"\n";
		cout<<"Jumlah Riwayat = "<<jumlahItem(0)<<"\n";
	}else{
		cout<<"\n\nRiwayat Penuh\n";
		cout<<"Jumlah Riwayat = "<<jumlahItem(0)<<"\n";
		cout<<"Kapasitas = "<<n<<"\n\n";
	}
	return getTop(0);
}

int forwardBaru(){
	if (isPenuh(1) == false)
	{
		Top2 += 1;
		moveon[Top2] = kata;
	}else{
		cout<<"\n\nForward PENUH\n";
		cout<<"Jumlah Riwayat = "<<jumlahItem(1)<<"\n";
		cout<<"Kapasitas = "<<n<<"\n\n";
	}
	return getTop(1);
}

int jelajahKembali(){
	if (isKosong(0) == false)
	{
		kata = histori[Top];
		forwardBaru();

		histori[Top] = "";
		Top -= 1;

		cout<<"Kembali jelajah "<<kata<<"\n";
		cout<<"Jumlah Riwayat = "<<jumlahItem(0)<<"\n";
	}else{
		cout<<"\n\nRiwayat KOSONG\n";
		cout<<"Kapasitas = "<<n<<"\n\n";
	}
	return getTop(0);
}

int jelajahForward(){
	if (isKosong(1) == false)
	{
		kata = moveon[Top2];
		jelajahBaru();

		moveon[Top2] = "";
		Top2 -= 1;
	}else{
		cout<<"\n\nForward KOSONG\n";
		cout<<"Kapasitas = "<<n<<"\n\n";
	}
	return getTop(1);
}

int main(){
	char Y, menu;

	buatKosong(0);
	buatKosong(1);
	tampilkanStack();

	Y = 'Y';
	while(Y == 'Y'){
		cout<<"\n\n====================================\n";
		cout<<"Pilihan Menu : \n";
		cout<<"<N = New> Jelajah Baru \n";
		cout<<"<B = Back> Kembali ke Halaman Sebelemunya \n";
		cout<<"<F = Forward> Maju ke Halaman Sebelumnya \n";
		cout<<"======================================\n";
		cout<<"Pilihan <N/B/F> : ";
		cin>>menu;

		if (menu == 'N' || menu == 'n')
		{
			cout<<"Masukkan URL = ";
			cin>>kata;

			jelajahBaru();
			tampilkanStack();
		}else if(menu == 'B' || menu == 'b')
		{
			jelajahKembali();
			tampilkanStack();
		}else if (menu == 'F' || menu == 'f')
		{
			jelajahForward();
			tampilkanStack();
		}else{
			cout<<"Menu tidak VALID!!! \n";
		}
		cout<<"\n===================================\n";
		cout<<"Proses Lagi ? (Y/T) : ";
		cin>>Y;
	}
	return 0;
}