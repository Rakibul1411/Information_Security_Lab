#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

using namespace std;

void SieveOfEratosthenes(int number, vector<bool>& prime) {
    for (long long i = 2; i * i <= number; ++i) {
        if (prime[i]) {
            for (long long j = i; j * i <= number; ++j) {
                prime[j * i] = false;
            }
        }
    }
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long long calc_dValue(long long eValue, long long phiFunction){
    long long d = 0;
    for (int k = 1; k <= phiFunction; ++k) {
        if((k * phiFunction + 1)%eValue == 0){
            d = (k * phiFunction + 1)/eValue;
            break;
        }
    }
    return d;
}

int modular(int base, unsigned int exp, unsigned int mod)
{
    int x = 1;
    int i;
    int power = base % mod;

    for (i = 0; i < sizeof(int) * 8; i++) {
        int least_sig_bit = 0x00000001 & (exp >> i);
        if (least_sig_bit)
            x = (x * power) % mod;
        power = (power * power) % mod;
    }

    return x;
}


int main() {
    int number;
    cout << "Enter the value of number to calculate Prime Number: ";
    cin >> number;
    cin.ignore();

    vector<bool> prime(number + 1, true);
    vector<int> primeNumber;
    SieveOfEratosthenes(number, prime);

    for (int i = 2; i <= number; ++i) {
        if (prime[i]) {
            primeNumber.push_back(i);
        }
    }

    int p_Value, q_Value;
    vector<int> shuffledNumbers = primeNumber;

    random_device rd;
    mt19937 g(rd());
    shuffle(shuffledNumbers.begin(), shuffledNumbers.end(), g);

    p_Value = shuffledNumbers[0];
    q_Value = shuffledNumbers[1];

    long long n = p_Value * q_Value;

    long long phiFunction;
    phiFunction = (p_Value - 1) * (q_Value - 1);

    long long e_Value;

    while (true) {
        random_device rd1;
        mt19937 gen(rd1());
        uniform_int_distribution<long long> dist(2, phiFunction - 1);
        e_Value = dist(gen);

        if (gcd(phiFunction, e_Value) == 1) {
            break;
        }
    }

    long long publicKey[2] = {e_Value, n};
    long long d_Value;
    d_Value = calc_dValue(e_Value, phiFunction);

    long long privateKey[2] = {d_Value, n};

    string plainText;
    cout <<"Enter the plain text for Encryption: ";
    getline(cin,plainText);
    char cipherText[10000];
    //Encryption
    long long i;
    for (i = 0; i < plainText.size(); ++i) {
        long long c = plainText[i];
        long long temp = 1;
        for (long long i = 1; i < e_Value; ++i) {
            temp = (temp*c) % n;
        }
        cout << temp << " ";
        cipherText[i] = char (temp);
    }
    cipherText[i] = '\0';
    for (long long i = 0; cipherText[i] != '\0' ; ++i) {
        cout << cipherText[i];
    }
    cout << "\nCipher text:  " <<cipherText << endl;

//    string inputPlainText;
//    //Decryption
//    for (char ch: cipherText) {
//        int c = static_cast<int>(ch);
//        int temp = c;
//        for (int i = 1; i < d_Value; ++i) {
//            temp = (temp*c) % n;
//        }
//
//        char decryptedChar = static_cast<char>(temp);
//        inputPlainText += decryptedChar;
//    }
//    cout << "Plain text:  " <<inputPlainText << endl;



    cout << "Value of phi: " << p_Value << " and e is: " << q_Value << " value of n is: " << n << endl;
    cout << "Value of phi: " << phiFunction << " and e is: " << e_Value << " d value is: " << d_Value;

    return 0;
}
