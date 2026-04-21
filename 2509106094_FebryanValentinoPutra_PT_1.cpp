#include <iostream>
#include <string>

using namespace std;

struct Buku {
    int idBuku;
    string namaBuku;
};

int linearSearch(Buku* daftar, int ukuran, string* target) {
    for (int i = 0; i < ukuran; i++) {
        if ((daftar + i)->namaBuku == *target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(Buku* daftar, int ukuran, int* targetID) {
    int awal = 0;
    int akhir = ukuran - 1;
    
    while (awal <= akhir) {
        int tengah = awal + (akhir - awal) / 2;
        
        if ((daftar + tengah)->idBuku == *targetID) {
            return tengah;
        }
        
        if ((daftar + tengah)->idBuku < *targetID) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }
    return -1;
}

void tampilkanData(Buku* daftar, int ukuran) {
    cout << "\n=== Daftar Barang Inventaris ===\n";
    for (int i = 0; i < ukuran; i++) {
        cout << "ID: " << daftar[i].idBuku << " | Nama: " << daftar[i].namaBuku << endl;
    }
    cout << "---------------------------------\n";
}

int main() {
    Buku inventaris[] = {
       {101, "Buku_Sejarah"},
       {105, "Buku_Cerpen"},
       {110, "Buku_Anak"},
       {120, "Buku_Novel"},
       {150, "Buku_Sains"}
    };
    int jumlahBuku = sizeof(inventaris) / sizeof(inventaris[0]);
    int pilihan;
    
    do {
        tampilkanData(inventaris, jumlahBuku);
        cout << "Menu Searching:\n";
        cout << "1. Cari berdasarkan Nama (Linear Search)\n";
        cout << "2. Cari berdasarkan ID (Binary Search)\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            string cariNama;
            cout << "Masukkan nama buku yang dicari: ";
            cin >> cariNama;
            
            int hasil = linearSearch(inventaris, jumlahBuku, &cariNama);
            if (hasil != -1) {
                cout << "Buku ditemukan! ID: " << inventaris[hasil].idBuku << endl;
            } else {
                cout << "Buku tidak ditemukan.\n";
            }
        } 
        else if (pilihan == 2) {
            int cariID;
            cout << "Masukkan ID buku yang dicari: ";
            cin >> cariID;
            
            int hasil = binarySearch(inventaris, jumlahBuku, &cariID);
            if (hasil != -1) {
                cout << "Buku ditemukan! Nama: " << inventaris[hasil].namaBuku << endl;
            } else {
                cout << "ID tidak ditemukan.\n";
            }
        }
        cout << endl;
    } while (pilihan != 3);

    return 0;
}