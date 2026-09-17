#include <iostream>

using namespace std;

int hitungPanjang(char str[]) {
    int panjang = 0;
    while (str[panjang] != '\0') {
        panjang++;
    }
    return panjang;
}

int main() {
    char pesan[100];
    cout << "Enter the secret message: ";
    cin >> pesan;

    int panjang_pesan = hitungPanjang(pesan);

    cout << "Encrypted Message: ";
    
    if (panjang_pesan > 0) {
        cout << pesan[0];
    }

    for (int i = 1; i < panjang_pesan; i++) {
        int nilai_sekarang = pesan[i] - 64;
        int nilai_sebelumnya = pesan[i - 1] - 64;

        int nilai_baru = nilai_sekarang + nilai_sebelumnya;

        if (nilai_baru > 26) {
            nilai_baru = nilai_baru % 26;
            if (nilai_baru == 0) {
                nilai_baru = 26;
            }
        }

        char huruf_baru = nilai_baru + 64;
        cout << huruf_baru;
    }

    cout << endl;

    return 0;
}