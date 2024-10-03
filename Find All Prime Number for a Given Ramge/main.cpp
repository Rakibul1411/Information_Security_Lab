#include <iostream>
#include <vector>

using namespace std;

void SieveOfEratosthenes(int number, vector<bool>& prime) {
    for (long long i = 2; i*i < number; ++i) {
        if(prime[i]){
            for (long long j = i; j*i <= number ; ++j) {
                prime[j*i] = false;
            }
        }
    }
}

int main() {
    int number;
    cout << "Enter the value of number: ";
    cin >> number;

    vector<bool> prime(number+1, true);
    vector<int> primeNumber;
    SieveOfEratosthenes(number, prime);

    cout << "All Prime Number from 1 To " << number << " is: " << endl;
    for (int i = 2; i <= number ; ++i) {
        if(prime[i]) {
            cout << i << " ";
            primeNumber.push_back(i);
        }
    }

    cout << "\nAll Prime Number from 1 To " << number << " is: " << endl;
    for(auto const& num: primeNumber){
        cout << num << " ";
    }

    return 0;
}
