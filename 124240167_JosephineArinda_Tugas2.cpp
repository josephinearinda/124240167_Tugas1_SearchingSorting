#include <iostream>
#include <iomanip> 
#include <string>
using namespace std;

struct Buku {
    string judul;
    int harga;
    Buku* prev;
    Buku* next;
};

Buku* head = nullptr;
Buku* tail = nullptr;

void tambahBuku(string judul, int harga, bool depan = false) {
    Buku* bukuBaru = new Buku{judul, harga, nullptr, nullptr};
    if (!head) {
        head = tail = bukuBaru;
    } else if (depan) {
        bukuBaru->next = head;
        head->prev = bukuBaru;
        head = bukuBaru;
    } else {
        tail->next = bukuBaru;
        bukuBaru->prev = tail;
        tail = bukuBaru;
    }
    cout << "Buku \"" << judul << "\" berhasil ditambahkan!\n";
}

void tampilkanBuku() {
    if (!head) {
        cout << "DATA BUKU TIDAK ADA! TAMBAHKAN BUKU DULU!\n";
        return;
    }
    cout << "                DATA BUKU              \n";
    cout << "=======================================\n";
    cout << "| " << left << setw(20) << "Judul"
         << "| " << right << setw(10) << "Harga" << "    |\n";
    cout << "=======================================\n";
    Buku* temp = head;
    while (temp) { 
        cout << "| " << left << setw(20) << temp->judul 
             << "| " << right << setw(10) << temp->harga << "    |\n";
        temp = temp-> next; 
    }
    cout << "=======================================\n";
}

void cariBuku(string judul) {
    Buku* temp = head;
    while (temp) { 
        if (temp->judul == judul) {
            cout << "BUKU DITEMMUKAN!\n";
            cout << "Judul : " << temp->judul << "\n";
            cout << "Harga : Rp " << temp->harga << "\n";
            return;
        }
        temp = temp-> next; 
    }
    cout << "Buku \"" << judul << "\" tidak ditemukan!\n";
}

void hapusBuku(string judul) {
    Buku* temp = head;
    while (temp) { 
        if (temp->judul == judul) {
            if (temp == head) head = temp->next;
            if (temp == tail) tail = temp->prev;
            if (temp->prev) temp->prev->next = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
            delete temp;
            cout << "Buku \"" << judul << "\" berhasil dihapus!\n";
            return;
        }
        temp = temp-> next;
    }
    cout << "Buku \"" << judul << "\" tidak ditemukan!\n";
}

void sisipBuku(string judul, int harga, int posisi, string setelahJudul = "") {
    if (posisi == 1) { 
        tambahBuku(judul, harga, true);
    } else if (posisi == 2) { 
        Buku* temp = head;
        while (temp) { 
            if (temp-> judul == setelahJudul) {
                Buku* bukuBaru = new Buku{judul, harga, temp, temp->next};
                if (temp->next) temp->next->prev = bukuBaru;
                temp->next = bukuBaru;
                if (temp == tail) tail = bukuBaru;
                cout << "Buku \"" << judul << "\" berhasil disisipkan setelah \"" << setelahJudul << "\".\n";
                return;
            }
            temp = temp-> next; 
        }
        cout << "Buku \"" << setelahJudul << "\" tidak ditemukan!\n";
    } else if (posisi == 3) { 
        tambahBuku(judul, harga, false);
    } else {
        cout << "PILIH SISIP YANG BENAR!\n";
    }
}

int main() {
    int pilihan;
    do {
        cout << "---------------------------------------\n";
        cout << "|            SELAMAT DATANG           |";
        cout << "\n|     TOKO BUKU LINGKARAN LITERASI    |\n";
        cout << "=======================================";
        cout << "\n|                 MENU                |\n";
        cout << "=======================================\n";
        cout << "1. Tambahkan Buku\n";
        cout << "2. Tampilkan Seluruh Data Buku\n";
        cout << "3. Cari Buku (judul)\n";
        cout << "4. Sisip Buku \n";
        cout << "5. Hapus Buku (judul)\n";
        cout << "6. Keluar\n";
        cout << "\nPilih Menu: ";
        cin >> pilihan;
        cin.ignore();
        if (pilihan == 1) {
            string judul;
            int harga;
            cout << "Masukkan judul buku : ";
            getline(cin, judul);
            cout << "Masukkan harga buku : ";
            cin >> harga;
            tambahBuku(judul, harga, false);
        } else if (pilihan == 2) {
            tampilkanBuku();
        } else if (pilihan == 3) {
            string judul;
            cout << "Masukkan judul buku yang dicari : ";
            getline(cin, judul);
            cariBuku(judul);
        } else if (pilihan == 4) {
            string judul, setelahJudul;
            int harga;
            int posisi;
            cout << "Masukkan judul buku : ";
            getline(cin, judul);
            cout << "Masukkan harga buku : ";
            cin >> harga;
            cin.ignore();
            cout << "Pilih posisi sisipan (angka) :\n";
            cout << "1. depan\n2. tengah\n3. belakang\n";
            cout << "Pilih : ";
            cin >> posisi;
            cin.ignore();
            if (posisi == 2) { 
                cout << "Buku akan disisipkan setelah judul : ";
                getline(cin, setelahJudul);
            }
            sisipBuku(judul, harga, posisi, setelahJudul);
        } else if (pilihan == 5) {
            string judul;
            cout << "Judul buku yang mau dihapus : ";
            getline(cin, judul);
            hapusBuku(judul);
        } else if (pilihan != 6) {
            cout << "PILIHAN GA VALID!\n";
        }
    } while (pilihan != 6);
    cout << "TERIMA KASIH TELAH MENGGUNAKAN PROGRAM! SEMOGA MEMBANTU!\n";
    return 0;
}