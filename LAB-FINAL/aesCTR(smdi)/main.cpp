#include "aesCTR.h"
#include<iostream>
using namespace std;


int main()
{

    string inpt, encr;
    freopen("input.txt","r",stdin);
    getline(cin, inpt);
    encr = ctr_encryption(inpt);
    write_file(encr);
    string decr;
    decr = getDecryptedText(encr);
    write_dec_file(decr, inpt.size());


    return 0;
}