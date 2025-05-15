#include <iostream>
#include <string>
using namespace std;

// Struktur data buku
struct Buku {
    string judul;
    int harga;
    Buku* next;
};

// Pointer awal
Buku* head = nullptr;

// Fungsi untuk menambahkan buku di akhir
void tambahBuku(string judul, int harga) {
    Buku* baru = new Buku{judul, harga, nullptr};
    if (head == nullptr) {
        head = baru;
    } else {
        Buku* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "Buku berhasil ditambahkan!\n";
}

// Fungsi menampilkan seluruh data buku
void tampilkanBuku() {
    if (head == nullptr) {
        cout << "Data buku kosong.\n";
        return;
    }
    Buku* temp = head;
    cout << "=== Daftar Buku ===\n";
    while (temp != nullptr) {
        cout << "Judul: " << temp->judul << " | Harga: Rp" << temp->harga << endl;
        temp = temp->next;
    }
}

// Fungsi mencari buku berdasarkan judul (Sequential Search)
void cariBuku(string judul) {
    Buku* temp = head;
    while (temp != nullptr) {
        if (temp->judul == judul) {
            cout << "Buku ditemukan: " << temp->judul << " (Rp" << temp->harga << ")\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Buku tidak ditemukan.\n";
}

// Fungsi menyisipkan buku di posisi depan, tengah, atau belakang
void sisipBuku(string judul, int harga, string posisi) {
    Buku* baru = new Buku{judul, harga, nullptr};

    if (posisi == "depan") {
        baru->next = head;
        head = baru;
        cout << "Buku disisipkan di depan.\n";
    } else if (posisi == "belakang") {
        tambahBuku(judul, harga);
    } else if (posisi == "tengah") {
        if (head == nullptr || head->next == nullptr) {
            tambahBuku(judul, harga);
            return;
        }
        Buku* slow = head;
        Buku* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        baru->next = slow->next;
        slow->next = baru;
        cout << "Buku disisipkan di tengah!\n";
    } else {
        cout << "Posisi tidak valid. Gunakan: depan / tengah / belakang\n";
        delete baru;
    }
}

// Fungsi menghapus buku berdasarkan judul
void hapusBuku(string judul) {
    if (head == nullptr) {
        cout << "Data buku kosong.\n";
        return;
    }

    if (head->judul == judul) {
        Buku* hapus = head;
        head = head->next;
        delete hapus;
        cout << "Buku berhasil dihapus.\n";
        return;
    }

    Buku* temp = head;
    while (temp->next != nullptr && temp->next->judul != judul) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Buku tidak ditemukan.\n";
    } else {
        Buku* hapus = temp->next;
        temp->next = hapus->next;
        delete hapus;
        cout << "Buku berhasil dihapus.\n";
    }
}

// Menu utama
void menu() {
    int pilihan;
    do {
        cout << "\n=== Menu ===\n";
        cout << "1. Tambahkan Buku\n";
        cout << "2. Tampilkan Seluruh Data Buku\n";
        cout << "3. Cari Data Buku (Sequential Search)\n";
        cout << "4. Sisip Buku (Depan, Tengah, Belakang)\n";
        cout << "5. Hapus Buku\n";
        cout << "6. Keluar\n";
        cout << "Pilih Menu: ";
        cin >> pilihan;
        cin.ignore(); // menghindari error getline

        if (pilihan == 1) {
            string judul;
            int harga;
            cout << "Judul Buku: ";
            getline(cin, judul);
            cout << "Harga Buku: ";
            cin >> harga;
            cin.ignore();
            tambahBuku(judul, harga);
        } else if (pilihan == 2) {
            tampilkanBuku();
        } else if (pilihan == 3) {
            string judul;
            cout << "Masukkan judul yang dicari: ";
            getline(cin, judul);
            cariBuku(judul);
        } else if (pilihan == 4) {
            string judul, posisi;
            int harga;
            cout << "Judul Buku: ";
            getline(cin, judul);
            cout << "Harga Buku: ";
            cin >> harga;
            cin.ignore();
            cout << "Posisi (depan / tengah / belakang): ";
            getline(cin, posisi);
            sisipBuku(judul, harga, posisi);
        } else if (pilihan == 5) {
            string judul;
            cout << "Masukkan judul buku yang ingin dihapus: ";
            getline(cin, judul);
            hapusBuku(judul);
        } else if (pilihan == 6) {
            cout << "Program selesai. Terima kasih!\n";
        } else {
            cout << "Pilihan tidak valid. Coba lagi.\n";
        }

    } while (pilihan != 6);
}

int main() {
    menu();
    return 0;
}