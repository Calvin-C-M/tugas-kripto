#include <iostream>
#include "cipher.cpp"

int main() {
    bool programRunning=true;

    while(programRunning) {
        std::string plaintext="";
        int key=1;
        int pilihan=1;

        printf("MENU");
        printf("1. Enkripsi");
        printf("2. Dekripsi");
        printf("3. Keluar");

        std::cout << "Pilihan: "; std::cin >> pilihan;

        switch(pilihan) {
            case 1:
                std::cout << "Masukkan teks yang ingin dienkripsi: ";
                std::cout << "Masukkan key: "; std::cin >> key;
                std::cout << "Hasil enkripsi = " << ShiftCipher::encrypt(plaintext,key);
                break;

            case 2:
                std::cout << "Masukkan teks yang ingin didekripsi: ";
                std::cout << "Masukkan key: "; std::cin >> key;
                std::cout << "Hasil dekripsi = " << ShiftCipher::decrypt(plaintext,key);
                break;

            case 3:
                programRunning=false;
                break;

            default: 
                printf("Ada kesalahan dalam memilih, silahkan coba lagi!");
                break;
        }
    }
}