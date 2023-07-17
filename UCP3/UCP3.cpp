#include <iostream>
#include <string>

using namespace std;

const int MAX_MAHASISWA = 100;
int NIM[MAX_MAHASISWA];
string nama[MAX_MAHASISWA];
string jurusan[MAX_MAHASISWA];
int tahunMasuk[MAX_MAHASISWA];
int jumlahMahasiswa = 0;

void tambahMahasiswa() {
    if (jumlahMahasiswa < MAX_MAHASISWA) {
        cout << "========== TAMBAH MAHASISWA ==========" << endl;
        cout << "NIM: ";
        cin >> NIM[jumlahMahasiswa];
        cin.ignore();
        cout << "Nama: ";
        getline(cin, nama[jumlahMahasiswa]);
        cout << "Jurusan: ";
        getline(cin, jurusan[jumlahMahasiswa]);
        cout << "Tahun Masuk: ";
        cin >> tahunMasuk[jumlahMahasiswa];
        cin.ignore();
        jumlahMahasiswa++;
        cout << "Mahasiswa berhasil ditambahkan!" << endl;
    }
    else {
        cout << "Kapasitas maksimum mahasiswa telah tercapai." << endl;
    }
}

void tampilkanSemuaMahasiswa() { //array
    cout << "========== DAFTAR MAHASISWA ==========" << endl;
    for (int i = 0; i < jumlahMahasiswa; i++) { //// Looping dengan i dimulai dari 0 hingga n-1
        cout << "NIM    : " << NIM[i] << endl;
        cout << "Nama   : " << nama[i] << endl;
        cout << "Jurusan: " << jurusan[i] << endl;
        cout << "Tahun  : " << tahunMasuk[i] << endl;
        cout << endl;
    }
}

void AlgoritmaMencariMahasiswaByNIM() { //linearsearch yang menggunakan bool
    int nimCari;
    bool ditemukan = false;

    cout << "========== CARI MAHASISWA BERDASARKAN NIM ==========" << endl;
    cout << "Masukkan NIM yang ingin dicari: ";
    cin >> nimCari;

    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (NIM[i] == nimCari) {
            cout << "Mahasiswa ditemukan!" << endl;
            cout << "NIM    : " << NIM[i] << endl;
            cout << "Nama   : " << nama[i] << endl;
            cout << "Jurusan: " << jurusan[i] << endl;
            cout << "Tahun  : " << tahunMasuk[i] << endl;
            cout << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Mahasiswa dengan NIM " << nimCari << " tidak ditemukan." << endl;
    }
}

void AlgoritmaSortByTahunMasuk() { //bubblesortarray, karena ada memakai temp
    cout << "========== DAFTAR MAHASISWA BERDASARKAN TAHUN MASUK ==========" << endl;

    int tempNIM, tempTahunMasuk;
    string tempNama, tempJurusan;

    for (int i = 0; i < jumlahMahasiswa; i++) {
        for (int j = i + 1; j < jumlahMahasiswa; j++) {
            if (tahunMasuk[i] > tahunMasuk[j]) {
                tempNIM = NIM[i];
                tempTahunMasuk = tahunMasuk[i];
                tempNama = nama[i];
                tempJurusan = jurusan[i];

                NIM[i] = NIM[j];
                tahunMasuk[i] = tahunMasuk[j];
                nama[i] = nama[j];
                jurusan[i] = jurusan[j];

                NIM[j] = tempNIM;
                tahunMasuk[j] = tempTahunMasuk;
                nama[j] = tempNama;
                jurusan[j] = tempJurusan;
            }
        }
    }

    tampilkanSemuaMahasiswa();
}

int main() {
    int pilihan;
    do {
        cout << "========== MENU MANAJEMEN DATA MAHASISWA ==========" << endl;
        cout << "1. Tambah Mahasiswa" << endl;
        cout << "2. Tampilkan Semua Mahasiswa" << endl;
        cout << "3. Cari Mahasiswa berdasarkan NIM" << endl;
        cout << "4. Tampilkan Mahasiswa berdasarkan Tahun Masuk" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
        case 1:
            tambahMahasiswa();
            break;
        case 2:
            tampilkanSemuaMahasiswa();
            break;
        case 3:
            AlgoritmaMencariMahasiswaByNIM();
            break;
        case 4:
            AlgoritmaSortByTahunMasuk();
            break;
        case 5:
            cout << "Terima kasih! Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
        cout << endl;
    } while (pilihan != 5);

    return 0;
}

/*
2. Algoritma yang digunakan:
bubblesort
array 
linearsearch, Algoritma ini cocok digunakan pada array/list dengan nilai yang tidak terurut. 

3. Perbedaan Mendasar antara Algoritma Stack dan Queue:

Algoritma Stack:
 - Prinsip kerja dari stack adalah LIFO (Last In, First Out), yang berarti elemen yang terakhir dimasukkan ke dalam
   stack akan menjadi elemen pertama yang dihapus dari stack.
 - Elemen baru ditambahkan ke bagian atas stack dan elemen dihapus dari bagian atas stack.
 - Hanya elemen paling atas yang dapat diakses atau dihapus dari stack.
 - Stack dapat diimplementasikan menggunakan tipe data seperti array atau linked list.


Algoritma Queue:
 - Prinsip kerja dari queue adalah FIFO (First In, First Out), yang berarti elemen yang pertama dimasukkan ke dalam
   queue akan menjadi elemen pertama yang dihapus dari queue.
 - Elemen baru ditambahkan ke bagian belakang queue dan elemen dihapus dari bagian depan queue.
 - Elemen pertama (di depan) dapat diakses atau dihapus dari queue.
 - Queue juga dapat diimplementasikan menggunakan tipe data seperti array atau linked list.

4. Penggunaan Algoritma Stack:

Ada beberapa situasi di mana algoritma Stack dapat digunakan secara efektif, antara lain:
- Mengefisiensikan memori
- Operasi Undo/Redo

5. Gambar
a. kedalaman struktur = 5

b. Membaca struktur pohon
left ST (subtree) - root - right ST
inorder: 1 5 8 10 12 15 20 22 25 28 30 36 38 40 45 48 50

left ST - right ST - root
Preorder: 25 20 10 5 1 8 12 15 22 36 30 28 40 38 48 45 50

left ST - right ST - root
Post: 1 8 15 5 12 10 22 20 28 38 45 50 48 40 36


*/