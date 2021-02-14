#include <iostream>
#include <string>

using namespace std;

int string_to_int(char lettera) {
    /*
     * int a = string_to_int('1');
     */
    if (lettera == '1') return 1;
    if (lettera == '2') return 2;
    if (lettera == '3') return 3;
    if (lettera == '4') return 4;
    if (lettera == '5') return 5;
    if (lettera == '6') return 6;
    if (lettera == '7') return 7;
    if (lettera == '8') return 8;
    if (lettera == '9') return 9;
    if (lettera == '0') return 0;
    return -1;
}


bool codiceValido(string barcode) {
    /*
     * bool valido = codiceValido('8472619843285');
     */
    int l = 13;

    if (barcode.length() != l) return false;

    int array[l];

    for(int i = 0; i < l; i++){
        array[i]= string_to_int(barcode[i]);
    }

    int sd = 0, sp = 0;

    for (int i = 0; i < (l - 1)/2; i++){ // 0 1 2 3 4 5
        sp += array[i*2];   // 0 2 4 6 8 10
        sd += array[i*2+1]; // 1 3 5 7 9 11
    }

    int somma = sd * 3 + sp;
    int complemento = ( 10 - (somma % 10) ) % 10; 
    if (complemento == array[l-1]) {
        return true;
    }
    else {
        return false;
    }
}
