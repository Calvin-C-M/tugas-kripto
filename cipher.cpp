#include <iostream>
#include <math.h>

namespace ShiftCipher {
    const int ASCII_CODE_LC = 97;
    const int ASCII_CODE_UC = 65;

    std::string encrypt(std::string text,int key=1) {
        std::string ans="";
        for(char ch: text) {
            if((ch-ASCII_CODE_LC) >= 0 && (ch-ASCII_CODE_LC) <= 25) {
                ch = (((ch-ASCII_CODE_LC)+key)%26)+ASCII_CODE_LC;
            } else if((ch-ASCII_CODE_UC) >= 0 && (ch-ASCII_CODE_UC) <= 25) {
                ch = (((ch-ASCII_CODE_UC)+key)%26)+ASCII_CODE_UC;
            }
            ans.push_back(ch);
        }
        return ans;
    }

    std::string decrypt(std::string text,int key=1) {
        std::string ans="";
        for(char ch: text) {
            if((ch-ASCII_CODE_LC) >= 0 && (ch-ASCII_CODE_LC) <= 25) {
                ch -= (ASCII_CODE_LC + key);
                ch = (ch < 0 ? ch+26 : ch);
                ch = (ch%26)+ASCII_CODE_LC;
            } else if((ch-ASCII_CODE_UC) >= 0 && (ch-ASCII_CODE_UC) <= 25) {
                ch -= (ASCII_CODE_UC + key);
                ch = (ch < 0 ? ch+26 : ch);
                ch = (ch%26)+ASCII_CODE_UC;
            }
            ans.push_back(ch);
        }
        return ans;
    }
};
