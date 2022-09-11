#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>

namespace AffineCipher {
    const int ASCII_CODE_LC=97;
    const int ASCII_CODE_UC=65;
    const std::string VALID_STRING_LC="abcdefghijklmnopqrstuvwxyz";
    const std::string VALID_STRING_UC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    bool koefIsValid(int koef1, int koef2, int totalChar) {
        int stringSize=static_cast<int>(VALID_STRING_LC.size());
        return (
            (koef2 >= 0 && koef2 <= (stringSize-1))
            &&
            (std::__gcd(koef1,stringSize) == 1)
        );
    }

    int modInverse(int a, int b) {
        for (int i = 1; i < b; i++)
            if (((a%b) * (i%b)) % b == 1)
                return i;
        return 0;
    }

    std::string encrypt(std::string text="abc", int koef1=1, int koef2=3) {
        std::string ans="";

        for(char ch: text) {
            if((ch-ASCII_CODE_LC) >= 0 && (ch-ASCII_CODE_LC) <= 25) {
                ch = ((((ch-ASCII_CODE_LC)*koef1)+koef2)%26)+ASCII_CODE_LC;
            } else if((ch-ASCII_CODE_UC) >= 0 && (ch-ASCII_CODE_UC) <= 25) {
                ch = ((((ch-ASCII_CODE_UC)*koef1)+koef2)%26)+ASCII_CODE_UC;
            }
            ans.push_back(ch);
        }

        return ans;
    }

    std::string decrypt(std::string text="abc", int koef1=1, int koef2=3) {
        std::string ans="";
        int invKoef1=modInverse(koef1,static_cast<int>(VALID_STRING_LC.size()));
        int invKoef2=(invKoef1*koef2)%26;

        for(char ch: text) {
            if((ch-ASCII_CODE_LC) >= 0 && (ch-ASCII_CODE_LC) <= 25) {
                ch = ((((ch-ASCII_CODE_LC)*invKoef1)-invKoef2)%26)+ASCII_CODE_LC;
            } else if((ch-ASCII_CODE_UC) >= 0 && (ch-ASCII_CODE_UC) <= 25) {
                ch = ((((ch-ASCII_CODE_UC)*invKoef1)-invKoef2)%26)+ASCII_CODE_UC;
            }
            ans.push_back(ch);
        }

        return ans;
    }
};