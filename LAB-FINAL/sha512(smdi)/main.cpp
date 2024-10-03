
#include "sha512.h"
#include <iostream>

int main() {
    string inpt, encr;
    freopen("input.txt","r",stdin);
    getline(cin, inpt);
    encr = SHA512(inpt);
    cout <<"Hash Value is: " << encr << endl;
    return 0;
}
