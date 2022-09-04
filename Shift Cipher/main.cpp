#include <iostream>
#include <math.h>
#include <cmath>

namespace ShiftCipher {
    const int ASCII_CODE = 97;

    std::string encrypt(std::string text,int key=1) {
        std::string ans="";
        for(char ch: text) {
            if((ch-ASCII_CODE) >= 0 && (ch-ASCII_CODE) <= 25) {
                ch = ((ch-ASCII_CODE)+key%26)+ASCII_CODE;
            }
            ans.push_back(ch);
        }
        return ans;
    }

    std::string decrypt(std::string text,int key=1) {
        std::string ans="";
        for(char ch: text) {
            if((ch-ASCII_CODE) >= 0 && (ch-ASCII_CODE) <= 25) {
                ch -= (ASCII_CODE + key);
                ch = (ch < 0 ? ch+26 : ch);
                ch = (ch%26)+ASCII_CODE;
            }
            ans.push_back(ch);
        }
        return ans;
    }
};

int main() {
    int key=7;
    std::string encryptText="metode shift cipher";
    std::string decryptText="tlavkl zopma jpwoly";

    std::cout << ShiftCipher::encrypt(encryptText,key) << "\n"
              << ShiftCipher::decrypt(decryptText,key);

    // bool programRunning=true;

    // while(programRunning) {
    //     std::string plaintext="";
    //     int key=1;
    //     int pilihan=1;

    //     printf("MENU");
    //     printf("1. Enkripsi");
    //     printf("2. Dekripsi");
    //     printf("3. Keluar");

    //     std::cout << "Pilihan: "; std::cin >> pilihan;

    //     switch(pilihan) {
    //         case 1:
    //             std::cout << "Masukkan teks yang ingin dienkripsi: ";
    //             std::cout << "Masukkan key: "; std::cin >> key;
    //             std::cout << "Hasil enkripsi = " << ShiftCipher::encrypt(plaintext,key);
    //             break;

    //         case 2:
    //             std::cout << "Masukkan teks yang ingin didekripsi: ";
    //             std::cout << "Masukkan key: "; std::cin >> key;
    //             std::cout << "Hasil dekripsi = " << ShiftCipher::decrypt(plaintext,key);
    //             break;

    //         case 3:
    //             programRunning=false;
    //             break;

    //         default: 
    //             printf("Ada kesalahan dalam memilih, silahkan coba lagi!");
    //             break;
    //     }
    // }
}