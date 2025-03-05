#include <iostream>
#include <string>

using namespace std;

const int MAX_BOOKS = 100; // maksimal jumlah buku

struct Book {
    string title;
    int year;
};

//  fungsi untuk menampilkan daftar buku
void displayBooks(Book books[], int count) {
    if (count == 0) {
        cout << "Daftar buku kosong.\n";
        return;
    }
    cout << "Daftar Buku:\n";
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << books[i].title << " (" << books[i].year << ")\n";
    }
}

// fungsi untuk mengurutkan dengan Bubblesort
void bubbleSort(Book books[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (books[j].year > books[j + 1].year) {
                swap(books[j], books[j + 1]);
            }
        }
    }
}

// Fungsi untuk mengurutkan dengan Quick Sort (ascending)
void quickSort(Book books[], int left, int right) {
    if (left >= right) return;
    
    int pivot = books[right].year;
    int i = left - 1;
    
    for (int j = left; j < right; j++) {
        if (books[j].year < pivot) {
            i++;
            swap(books[i], books[j]);
        }
    }
    swap(books[i + 1], books[right]);
    quickSort(books, left, i);
    quickSort(books, i + 2, right);
}

// fungsi Sequential Search
void sequentialSearch(Book books[], int count, int targetYear) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (books[i].year == targetYear) {
            cout << "Buku ditemukan: " << books[i].title << " (" << books[i].year << ")\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Buku dengan tahun " << targetYear << " tidak ditemukan.\n";
    }
}

// fungsi Binary Search 
void binarySearch(Book books[], int count, int targetYear) {
    int left = 0, right = count - 1;
    bool found = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (books[mid].year == targetYear) {
            cout << "Buku ditemukan: " << books[mid].title << " (" << books[mid].year << ")\n";
            found = true;
            break;
        } else if (books[mid].year < targetYear) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!found) {
        cout << "Buku dengan tahun " << targetYear << " tidak ditemukan.\n";
    }
}

// fungsi utama
int main() {
    Book books[MAX_BOOKS];
    int count = 0;
    int choice;

    do {
        cout << "\n=== Menu ===\n";
        cout << "1. Input Data Buku\n";
        cout << "2. Tampilkan Data Buku\n";
        cout << "3. Urutkan Buku dengan Bubble Sort\n";
        cout << "4. Urutkan Buku dengan Quick Sort\n";
        cout << "5. Cari Buku dengan Sequential Search\n";
        cout << "6. Cari Buku dengan Binary Search\n";
        cout << "7. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                if (count >= MAX_BOOKS) {
                    cout << "Kapasitas buku penuh!\n";
                    break;
                }
                cout << "Masukkan judul buku: ";
                getline(cin, books[count].title);
                cout << "Masukkan tahun terbit: ";
                cin >> books[count].year;
                cin.ignore();
                count++;
                break;
            }
            case 2:
                displayBooks(books, count);
                break;
            case 3:
                bubbleSort(books, count);
                cout << "Buku berhasil diurutkan dengan Bubble Sort.\n";
                break;
            case 4:
                quickSort(books, 0, count - 1);
                cout << "Buku berhasil diurutkan dengan Quick Sort.\n";
                break;
            case 5: {
                int targetYear;
                cout << "Masukkan tahun terbit yang dicari: ";
                cin >> targetYear;
                sequentialSearch(books, count, targetYear);
                break;
            }
            case 6: {
                int targetYear;
                cout << "Masukkan tahun terbit yang dicari: ";
                cin >> targetYear;
                binarySearch(books, count, targetYear);
                break;
            }
            case 7:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (choice != 7);

    return 0;
}