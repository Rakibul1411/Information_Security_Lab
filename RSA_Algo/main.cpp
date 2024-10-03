#include <iostream>
#include <cmath>
#include <vector>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool is_prime(int num) {
    if (num == 2)
        return true;
    if (num < 2 || num % 2 == 0)
        return false;
    for (int n = 3; n <= sqrt(num); n += 2) {
        if (num % n == 0)
            return false;
    }
    return true;
}

std::pair<std::pair<int, int>, std::pair<int, int>> key_generator() {
    int p, q;
    while (true) {
        std::cout << "Enter a prime number: ";
        std::cin >> p;
        std::cout << "Enter another prime number: ";
        std::cin >> q;

        if (!is_prime(p) || !is_prime(q)) {
            std::cout << "Both numbers must be prime. Please try again." << std::endl;
        } else {
            break;
        }
    }

    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 2;

    while (gcd(e, phi) != 1) {
        e++;
    }

    int d = 1;
    while ((d * e) % phi != 1) {
        d++;
    }

    return std::make_pair(std::make_pair(n, e), std::make_pair(n, d));
}

int mod_exp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

std::vector<int> encrypt(const std::string& message, std::pair<int, int> key) {
    int n = key.first;
    int e = key.second;
    std::vector<int> encrypted;
    for (char c : message) {
        encrypted.push_back(mod_exp(c, e, n));
    }
    return encrypted;
}

std::string decrypt(const std::vector<int>& encrypted, std::pair<int, int> key) {
    int n = key.first;
    int d = key.second;
    std::string decrypted;
    for (int val : encrypted) {
        decrypted += static_cast<char>(mod_exp(val, d, n));
    }
    return decrypted;
}

int main() {
    auto keys = key_generator();
    auto public_key = keys.first;   // (n, e)
    auto private_key = keys.second; // (n, d)

    std::cout << "Public Key: (" << public_key.first << ", " << public_key.second << ")" << std::endl;
    std::cout << "Private Key: (" << private_key.first << ", " << private_key.second << ")" << std::endl;

    std::string message = "hello world!";
    std::vector<int> encrypted_message = encrypt(message, public_key);
    std::cout << "Encrypted Message:" << std::endl;
    for (int val : encrypted_message) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::string decrypted_message = decrypt(encrypted_message, private_key);
    std::cout << "Decrypted Message: " << decrypted_message << std::endl;

    return 0;
}
