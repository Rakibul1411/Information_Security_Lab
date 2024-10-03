#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
    int number;
    cout << "Enter the number: ";
    cin >> number;

    clock_t start = clock();
    auto start1 = high_resolution_clock::now();
    vector<bool> prime(number+1, true);

    for (int i = 2; i < number; ++i) {
        if(prime[i]){
            long long j = i+i;
            while (j <= number){
                prime[j] = false;
                j += i;
            }
        }
    }

    cout << "All prime number from 1 To " << number << " is: ";
    for (int i = 2; i < number; ++i) {
        if (prime[i]) {
            cout << i << " ";
        }
    }

    clock_t end = clock();
    auto end1 = high_resolution_clock::now();

    // Calculate the elapsed time
    auto duration = duration_cast<seconds>(end1 - start1);

    cout << "\n\nElapsed time(Modern): " << duration.count() << " seconds" << endl;

    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;

    cout << "\nElapsed time: " << elapsed_time << " seconds" << endl;

    //cout << "CLOCKS_PER_SEC is: " << CLOCKS_PER_SEC << endl;


    return 0;
}
