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

// Fungsi untuk menghitung rata-rata nilai
double hitungRataRata(const Siswa& siswa) {
    return (siswa.lari + siswa.renang + siswa.pushup + siswa.pullup) / 4.0;
}

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

    // Hitung rata-rata nilai
    double rataRata = hitungRataRata(siswa);
    cout << "Nilai rata-rata: " << rataRata << endl;

    // Tambahkan siswa ke database
    database[siswa.nama] = siswa;
}

// Fungsi untuk mengecek apakah siswa harus mengulang tahun depan
bool perluMengulang(const Siswa& siswa) {
    double rataRata = hitungRataRata(siswa);
    return rataRata < 80.0;
}

int main() {
    int pilihan;
    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Siswa\n";
        cout << "2. Lihat Data Siswa\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahSiswa();
                break;
            case 2:
                cout << "\nData Siswa:\n";
                for (const auto& entry : database) {
                    cout << entry.first << ": " << (perluMengulang(entry.second) ? "Mengulang" : "Lulus") << endl;
                }
                break;
            case 3:
                cout << "Terima kasih! Sampai jumpa." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 3);

    return 0;
}
