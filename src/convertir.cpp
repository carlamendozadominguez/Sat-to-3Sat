#include "SAT2SAT3.h"

#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char** argv) {

    if(argc != 2) {
        cerr << "ERROR: Se necesita el archivo CNF" << endl;
        return -1;
    }

    try {
        //Leemos el fichero
        ifstream fich;
        fich.open(argv[1]);
        //Fichero de salida
        ofstream out;
        out.open("output.txt",ios::trunc);

        SAT S;
        fich >> S;

        SATto3SAT converter;
        SAT3 S3 = converter.convertSATto3SAT(S);
        
        cout << S3;
        out << S3;
    } catch (const invalid_argument &ia){
        cerr << "Invalid argument: " << ia.what() << endl;
    }

}

