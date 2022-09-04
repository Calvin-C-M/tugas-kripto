#include <iostream>

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
