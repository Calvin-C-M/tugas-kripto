#include <iostream>
#include "shift.cpp"
#include "affine.cpp"

void menuShift(std::string command="ENCRYPT") {
    std::string text="";
    int key=1;

    std::cout << "Text: "; std::getline(std::cin,text);
    std::cout << "Key: "; std::cin >> key;

    if(command == "ENCRYPT") {
        std::cout << "Hasil enkripsi = " << ShiftCipher::encrypt(text,key) << "\n";
    } else {
        std::cout << "Hasil dekripsi = " << ShiftCipher::decrypt(text,key) << "\n";
    }
}

void menuAffine(std::string command="ENCRYPT") {
    std::string text="";
    int a=1,b=3;

    std::cout << "Text: "; std::getline(std::cin,text);
    std::cout << "Koefisien 1: "; std::cin >> a;
    std::cout << "Koefisien 2: "; std::cin >> b;

    if(command == "ENCRYPT") {
        std::cout << "Hasil enkripsi = " << AffineCipher::encrypt(text,a,b) << "\n";
    } else {
        std::cout << "Hasil dekripsi = " << AffineCipher::decrypt(text,a,b) << "\n";
    }
}

void menuCipher(std::string cipher="SHIFT") {
    int pilihan=1;

    printf("\nMENU CIPHER\n");
    printf("Pilihan Cipher: %s\n", cipher);
    printf("1. Enkripsi\n");
    printf("2. Dekripsi\n");
    printf("3. Kembali\n");
    
    std::cout << "Pilihan: "; std::cin >> pilihan; std::cin.ignore();

    switch(pilihan) {
        case 1:
        case 2:
            if(cipher == "SHIFT") {
                menuShift((pilihan == 1) ? "ENCRYPT" : "DECRYPT");
            } else if(cipher == "AFFINE") {
                menuAffine((pilihan == 1) ? "ENCRYPT" : "DECRYPT");
            }
            system("pause");
            mainMenu();
            break;

        case 3:
            mainMenu();
            return;
            break;

        default:
            printf("(X) Ada kesalahan dalam memilih, silahkan coba lagi!\n");
            system("pause");
            menuCipher();
            break;
    }
}

void mainMenu() {
    int pilihan=1;

    printf("\nMAIN MENU\n");
    printf("(!) Pilih cipher yang diiginkan\n");
    printf("1. Shift Cipher\n");
    printf("2. Affine Cipher\n");
    printf("3. Keluar\n");
    std::cout << "Pilihan: "; std::cin >> pilihan; std::cin.ignore();

    switch(pilihan) {
        case 1: menuCipher("SHIFT");
            break;

        case 2: menuCipher("AFFINE");
            break;

        case 3:
            printf("Exiting program...\n");
            system("pause");
            return;
            break;

        default:
            printf("(X) Ada kesalahan dalam memilih, silahkan coba lagi!\n");
            system("pause");
            mainMenu();
            break;
    }
}

int main() {
    mainMenu();
}