#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>

std::vector<int> computeLPS(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> lps(m, 0);
    int length = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        }
        else {
            if (length != 0) {
                length = lps[length - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

void kmpSearch(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();
    std::vector<int> lps = computeLPS(pattern);
    int i = 0;
    int j = 0;

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;

            if (j == m) {
                std::cout << "Pattern found at index " << i - j << std::endl;
                j = lps[j - 1];
            }
        }
        else {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }
}

int main() {
    std::string text = "ABABDABACDABABCABAB";
    std::string pattern = "ABABCABAB";
    kmpSearch(text, pattern);

    return 0;
}