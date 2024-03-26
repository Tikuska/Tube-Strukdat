#include <iostream>
#include <string>
#include <map>

// Struktur untuk menyimpan data peserta
struct Peserta {
    std::string nama;
    int nilaiLari;
    int nilaiRenang;
    int nilaiPushup;
    int nilaiPullup;
    int nilaiTotal() {
        return nilaiLari + nilaiRenang + nilaiPushup + nilaiPullup;
    }
};

// Fungsi untuk menampilkan menu utama
void tampilkanMenu() {
    std::cout << "Sistem Informasi Penghitungan Nilai Jasmani\n";
    std::cout << "1. Login\n";
    std::cout << "2. Input Nilai\n";
    std::cout << "3. Keluar\n";
    std::cout << "Pilih menu: ";
}

// Fungsi untuk login
bool login(std::map<std::string, std::string>& akun) {
    std::string username, password;
    std::cout << "Masukkan username: ";
    std::cin >> username;
    std::cout << "Masukkan password: ";
    std::cin >> password;

    if (akun.find(username) != akun.end() && akun[username] == password) {
        std::cout << "Login berhasil!\n";
        return true;
    } else {
        std::cout << "Login gagal. Silakan coba lagi.\n";
        return false;
    }
}

// Fungsi utama
int main() {
    std::map<std::string, std::string> akun; // Database akun
    std::map<std::string, Peserta> dataPeserta; // Database peserta
    int pilihanMenu;
    bool isLoggedIn = false;

    // Contoh akun (username:password)
    akun["admin"] = "admin123";

    do {
        tampilkanMenu();
        std::cin >> pilihanMenu;
        switch (pilihanMenu) {
            case 1: // Login
                isLoggedIn = login(akun);
                break;
            case 2: // Input Nilai
                if (isLoggedIn) {
                    Peserta p;
                    std::cout << "Masukkan nama peserta: ";
                    std::cin >> p.nama;
                    std::cout << "Masukkan nilai lari: ";
                    std::cin >> p.nilaiLari;
                    std::cout << "Masukkan nilai renang: ";
                    std::cin >> p.nilaiRenang;
                    std::cout << "Masukkan nilai pushup: ";
                    std::cin >> p.nilaiPushup;
                    std::cout << "Masukkan nilai pullup: ";
                    std::cin >> p.nilaiPullup;

                    dataPeserta[p.nama] = p;

                    if (p.nilaiTotal() < 70) {
                        std::cout << "Nilai total kurang dari 70, peserta harus mengulang tahun depan.\n";
                    } else {
                        std::cout << "Selamat, Anda lulus!\n";
                    }
                } else {
                    std::cout << "Silakan login terlebih dahulu.\n";
                }
                break;
            case 3: // Keluar
                std::cout << "Terima kasih telah menggunakan sistem.\n";
                return 0;
            default:
                std::cout << "Menu tidak valid. Silakan coba lagi.\n";
        }
    } while (true);

    return 0;
}
