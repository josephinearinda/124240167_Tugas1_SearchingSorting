#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Buku {
    string judul;
    int tahun_terbit;
};

void tampilkan_buku(Buku daftar_bk[], int jml_bk) {
    if (jml_bk == 0) {
        cout << "Daftar buku kosong" << endl;
        return;
    }

    cout << "-------------------------------------------------" << endl;    
    cout << "|                 Daftar Buku                   |" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "| Judul                          | Tahun Terbit |" << endl;
    cout << "-------------------------------------------------" << endl;

    for (int i = 0; i < jml_bk; i++) {
        cout << "| " << left << setw(30) << daftar_bk[i].judul << " | " << setw(12) << daftar_bk[i].tahun_terbit << " |" << endl;
    }

    cout << "-------------------------------------------------" << endl;
    cout << endl;
}


void bubblesort(Buku daftar_bk[], int jml_bk) {
    for (int i = 0; i < jml_bk - 1; i++) {
        for (int j = 0; j < jml_bk - i - 1; j++) {
            if (daftar_bk[j].tahun_terbit > daftar_bk[j + 1].tahun_terbit) {
                swap(daftar_bk[j], daftar_bk[j + 1]);
            }
        }
    }
}

int partition(Buku daftar_bk[], int low, int high) {
    int pivot = daftar_bk[high].tahun_terbit;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (daftar_bk[j].tahun_terbit < pivot) {
            i++;
            swap(daftar_bk[i], daftar_bk[j]);
        }
    }
    swap(daftar_bk[i + 1], daftar_bk[high]);
    return i + 1;
}

void quicksort(Buku daftar_bk[], int low, int high) {
    if (low < high) {
        int pi = partition(daftar_bk, low, high);
        quicksort(daftar_bk, low, pi - 1);
        quicksort(daftar_bk, pi + 1, high);
    }
}

void sequentialsearch(Buku daftar_bk[], int jml_bk, int tahun, Buku hasil[], int& jml_hasil) {
    jml_hasil = 0;
    for (int i = 0; i < jml_bk; i++) {
        if (daftar_bk[i].tahun_terbit == tahun) {
            hasil[jml_hasil] = daftar_bk[i];
            jml_hasil++;
        }
    }
}

void binarysearch(Buku daftar_bk[], int jml_bk, int tahun, Buku hasil[], int& jml_hasil) {
    jml_hasil = 0;
    int low = 0, high = jml_bk - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (daftar_bk[mid].tahun_terbit == tahun) {
            int i = mid;
            while (i >= 0 && daftar_bk[i].tahun_terbit == tahun) {
                hasil[jml_hasil] = daftar_bk[i];
                jml_hasil++;
                i--;
            }
            i = mid + 1;
            while (i < jml_bk && daftar_bk[i].tahun_terbit == tahun) {
                hasil[jml_hasil] = daftar_bk[i];
                jml_hasil++;
                i++;
            }
            return;
        } else if (daftar_bk[mid].tahun_terbit < tahun) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
}

int main() {
    const int MAX_BUKU = 100;
    Buku daftar_bk[MAX_BUKU];
    int jml_bk = 0;
    int pilihan;

    do {
        cout << "\n================ MENU ================\n";
        cout << "1. Input Data Buku\n";
        cout << "2. Tampilkan Daftar Buku\n";
        cout << "3. Urutkan Buku dengan Bubble Sort\n";
        cout << "4. Urutkan Buku dengan Quick Sort\n";
        cout << "5. Cari Buku dengan Sequential Search\n";
        cout << "6. Cari Buku dengan Binary Search\n";
        cout << "7. Keluar\n";
        cout << "======================================\n";
        cout << "Pilihan Anda : ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            int jml_input;
            cout << "Berapa buku yang mau diinput: ";
            cin >> jml_input;
            cin.ignore();

            if (jml_bk + jml_input > MAX_BUKU) {
                cout << "BUKU MELEBIHI BATAS!" << endl;
            } else {
                for (int i = 0; i < jml_input; i++) {
                    cout << "Judul " << jml_bk + 1 << ": ";
                    getline(cin, daftar_bk[jml_bk].judul);
                    cout << "Tahun terbit " << jml_bk + 1 << ": ";
                    cin >> daftar_bk[jml_bk].tahun_terbit;
                    cin.ignore();
                    jml_bk++;
                }
            }
        } else if (pilihan == 2) {
            tampilkan_buku(daftar_bk, jml_bk);
        } else if (pilihan == 3) {
            Buku sebelum_bubble[MAX_BUKU];
            for (int i = 0; i < jml_bk; i++) {
                sebelum_bubble[i] = daftar_bk[i];
            }
            bubblesort(daftar_bk, jml_bk);
            cout << "Sebelum bubble sort:\n";
            tampilkan_buku(sebelum_bubble, jml_bk);
            cout << "Sesudah bubble sort:\n";
            tampilkan_buku(daftar_bk, jml_bk);
        } else if (pilihan == 4) {
            Buku sebelum_quick[MAX_BUKU];
            for (int i = 0; i < jml_bk; i++) {
                sebelum_quick[i] = daftar_bk[i];
            }
            quicksort(daftar_bk, 0, jml_bk - 1);
            cout << "Sebelum quick sort:\n";
            tampilkan_buku(sebelum_quick, jml_bk);
            cout << "Sesudah quick sort:\n";
            tampilkan_buku(daftar_bk, jml_bk);
        } else if (pilihan == 5) {
            int tahun;
            cout << "Tahun terbit : ";
            cin >> tahun;
            cin.ignore();
            Buku hasil[MAX_BUKU];
            int jml_hasil;
            sequentialsearch(daftar_bk, jml_bk, tahun, hasil, jml_hasil);
            if (jml_hasil > 0) {
                cout << "Buku ditemukan : " << endl;
                for (int i = 0; i < jml_hasil; i++) {
                    cout << hasil[i].judul << " (" << hasil[i].tahun_terbit << ")" << endl;
                }
            } else {
                cout << "BUKU TIDAK TERSEDIA!" << endl;
            }
        } else if (pilihan == 6) {
            int tahun;
            cout << "Tahun terbit :";
            cin >> tahun;
            cin.ignore();
            bubblesort(daftar_bk, jml_bk);
            Buku hasil[MAX_BUKU];
            int jml_hasil;
            binarysearch(daftar_bk, jml_bk, tahun, hasil, jml_hasil);
            if (jml_hasil > 0) {
                cout << "Buku ditemukan : " << endl;
                for (int i = 0; i < jml_hasil; i++) {
                    cout << hasil[i].judul << " (" << hasil[i].tahun_terbit << ")" << endl;
                }
            } else {
                cout << "BUKU TIDAK TERSEDIA!" << endl;
            }
        }
    } while (pilihan != 7);

    return 0;
}