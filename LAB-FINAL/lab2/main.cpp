#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <iomanip>

using namespace std;

#define SHA_512_INPUT_REPRESENTATION_LENGTH 128
#define BLOCK_SIZE 1024


int main() {
    string inputText;
    cout << "Enter the string to Hash: ";
    getline(cin, inputText);

    cout << endl << "Before padding string is: " << inputText << endl << endl;

    string finalPlainText;

        for (char c : inputText) {
            finalPlainText += bitset<8>(c).to_string();
        }

        finalPlainText += '1';
        size_t plainTextSize = inputText.length() * 8;

        size_t numberOfZeros = BLOCK_SIZE - ((plainTextSize + SHA_512_INPUT_REPRESENTATION_LENGTH + 1) % BLOCK_SIZE);

        finalPlainText += string(numberOfZeros, '0');

        finalPlainText += bitset<SHA_512_INPUT_REPRESENTATION_LENGTH>(plainTextSize).to_string();

        int paddingbits = numberOfZeros + 1 + SHA_512_INPUT_REPRESENTATION_LENGTH;

        cout << "Padding length is: "<< paddingbits << endl << endl;

        int paddedStringLen = finalPlainText.size();

        int Block1024 = paddedStringLen/1024;

        cout << "Number of 1024 Block is: " << Block1024 << endl << endl;

        cout << "Padding string length is: " << paddedStringLen << endl << endl;

        cout << "After Padding string is: " << finalPlainText << endl;

  return 0;
}
