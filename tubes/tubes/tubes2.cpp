#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Struktur data untuk menyimpan informasi siswa
struct Siswa {
    string nama;
    double lari;
    double renang;
    double pushup;
    double pullup;
};

// Database siswa
map<string, Siswa> database;

// Fungsi untuk menambahkan siswa ke database
void tambahSiswa() {
    Siswa siswa;
    cout << "Masukkan nama siswa: ";
    cin >> siswa.nama;
    cout << "Masukkan nilai lari: ";
    cin >> siswa.lari;
    cout << "Masukkan nilai renang: ";
    cin >> siswa.renang;
    cout << "Masukkan nilai pushup: ";
    cin >> siswa.pushup;
    cout << "Masukkan nilai pullup: ";
    cin >> siswa.pullup;

    // Hitung rata-rata
    double rataRata = (siswa.lari + siswa.renang + siswa.pushup + siswa.pullup) / 4.0;

    // Simpan siswa ke database
    database[siswa.nama] = siswa;

    // Cek apakah harus mengulang tahun depan
    if (rataRata < 80) {
        cout << "Nilai rata-rata kurang dari 80. Anda harus mengulang tahun depan." << endl;
    } else {
        cout << "Data siswa berhasil disimpan." << endl;
    }
}

// Fungsi untuk menampilkan data siswa
void tampilkanData() {
    cout << "Daftar siswa:" << endl;
    for (const auto& entry : database) {
        const Siswa& siswa = entry.second;
        cout << "Nama: " << siswa.nama << ", Rata-rata: " << (siswa.lari + siswa.renang + siswa.pushup + siswa.pullup) / 4.0 << endl;
    }
}

int main() {
    int pilihan;
    do {
        cout << "Menu:" << endl;
        cout << "1. Tambah Siswa" << endl;
        cout << "2. Tampilkan Data" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahSiswa();
                break;
            case 2:
                tampilkanData();
                break;
            case 3:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
        }
    } while (pilihan != 3);

    return 0;
}
