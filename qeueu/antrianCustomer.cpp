#include <iostream>
#define n 10
using namespace std;

int First, Last;
int antrian[n];

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
		cout<<"On Process : "<<antrian[getDepan()]<<"\n";
		cout<<"Selanjutnya : ";
		for (int i = getBelakang(); i >= (getDepan()+1); i--)
		{
			cout<<antrian[i]<<" | ";
		}

		cout<<"\n";
	}else{
		cout<<"Antrian KOSONG\n";
	}
}

int selisihAntrian(){
	int awal = antrian[getDepan()];
	int akhir = antrian[getBelakang()];

	return akhir - awal;
}

int tamuDatang(){
	if (isPenuh() == false)
	{
		int x = antrian[getBelakang()] + 1;

		if (isKosong() == true)
		{
			First += 1;
		}
		Last += 1;
		antrian[Last] = x;

		cout<<"\n\nNo Antrian : "<<x<<"\n";
		cout<<"On Process : "<<antrian[getDepan()]<<"\n";
		cout<<"Anda dilayani setelah "<<selisihAntrian()<<" berikutnya\n\n";
	}else{
		cout<<"\n\nAntrian PENUH | Kapasitas = "<<n;
		cout<<"On Process : "<<antrian[getDepan()]<<"\n\n";
	}
	return getBelakang();
}
int tamuSelesai(){
	int x = antrian[First];
	if (isKosong() == false)
	{
		if (getDepan() == getBelakang())
		{
			// tersisa satu elemen di antrian
			antrian[First] = 0;
			buatKosong();
		}else{
			antrian[First] = 0; //hapus elemen pertama
			// Geser elemen
			int posisi = First + 1;
			while(posisi <= getBelakang()){
				antrian[posisi - 1] = antrian[posisi];
				posisi++;
			}
			antrian[Last] = 0;
			Last -= 1;
		}

		cout<<"\n\nNext Process : "<<antrian[getDepan()]<<"\n";
		cout<<"Sisa Tamu : "<<selisihAntrian()<<"\n\n";
	}else{
		cout<<"\n\nAntrian KOSONG \n";
	}
	return getBelakang();
}

int main(){
	char Y, menu;
	buatKosong();
	tampilkanAntrian();

	Y = 'Y';
	while(Y == 'Y'){
		cout<<"\n\n============================\n";
		cout<<"Pilihan Menu : \n";
		cout<<"<N = New> Tamu Baru \n";
		cout<<"<F = Finish> Tamu Selesai \n";
		cout<<"============================\n";
		cout<<"Pilihan <N/F> : ";
		cin>>menu;
		if (menu == 'N')
		{
			tamuDatang();
			tampilkanAntrian();
		}else if(menu == 'F'){
			tamuSelesai();
			tampilkanAntrian();
		}else{
			cout<<"Menu tidak VALID!!!\n";
		}

		cout<<"\n============================\n";
		cout<<"Proses Lagi ? <Y/T> : ";
		cin>>Y;
	}
	return 0;
}