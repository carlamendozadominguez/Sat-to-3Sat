#include "SAT3.h"

void SAT3::pushClausula(vector<int> clausula) {
    if(clausula.size() != 3) {
        throw invalid_argument( "No es una clausula 3-SAT" );
    } else {
        SAT::clausulas.push_back(clausula);
    }
};

ifstream &operator>>( ifstream  &fich, SAT3 &S ) {
    string line =" ";
    getline(fich,line);

    while(line[0] == 'c' && line[1] == ' ') {
        getline(fich,line);
    }

    if(line[0]!= 'p') {
        throw invalid_argument( "Falta p (ERROR Formato CNF)" );
    } else {
        vector<string> read = S.separarString(line);

        if (read.size() != 4) {
            throw invalid_argument( "Falta cnf (ERROR Formato CNF)" );
        }

        S.numVariables = atoi(read[2].c_str());
        S.numClausulas = atoi(read[3].c_str());

        vector<int> clausula;

        while(getline(fich,line)) {
            clausula = S.separarInt(line);
            if(clausula.at(clausula.size()-1) == 0)
                S.pushClausula(clausula);
            else
                throw invalid_argument( "Falta 0 (ERROR Formato CNF)" );
        }
    }
    return fich;
};