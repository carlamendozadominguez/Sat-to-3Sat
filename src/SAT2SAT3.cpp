#include "SAT2SAT3.h"

SAT3 SATto3SAT::convertSATto3SAT(SAT S) {
    vector<int> clausula;
    SAT3 S3;
    int dummy = 0;
    int totalClausulas = 0;

    dummy = S.getNumVariables() + 1;

    for(int i = 0 ; i < S.getNumClausulas(); i++) {
        clausula = S.getClausula(i);
        clausula.pop_back();

        int numVariablesClaus = clausula.size();
        vector<int> nuevaClausula;

        switch (numVariablesClaus) {
            //Si solo tengo una variable en la clausula metemos 3 veces la variable
            case 1:
            for(int i= 0; i < 3 ; i++)
                nuevaClausula.push_back(clausula[0]);

            S3.pushClausula(nuevaClausula);
            totalClausulas += 1;
            nuevaClausula.clear();
            break;

            //Si tengo dos variables en una clausula
            case 2:
            for(int i = 0; i < 2; i++) {
                nuevaClausula.push_back(clausula[i]);
            }

            nuevaClausula.push_back(dummy); //dummy es el numero de la nueva variable
            totalClausulas += 1;
            S3.pushClausula(nuevaClausula);
            nuevaClausula.clear();

            dummy *= -1; //Cambiamos de signo
            nuevaClausula.push_back(dummy);

            for(int i = 0; i < 2; i++) {
                nuevaClausula.push_back(clausula[i]);
            }

            S3.pushClausula(nuevaClausula);
            totalClausulas += 1;
            nuevaClausula.clear();

            dummy *= -1;
            dummy += 1; //Creamos una nueva variable

            break;

            //Si tengo 3 variables, meto la clausula entera
            case 3:
            for (int i = 0; i < 3; ++i) {
                nuevaClausula.push_back(clausula[i]);
            }

            S3.pushClausula(nuevaClausula);
            totalClausulas += 1;
            nuevaClausula.clear();
            break;

            //Si tengo 4 o mas variables 
            default:
            for(int i = 0; i < 2; i++) {
                nuevaClausula.push_back(clausula[i]);
            }

            nuevaClausula.push_back(dummy);
            S3.pushClausula(nuevaClausula);
            nuevaClausula.clear();

            int Xn = 2; //Sera el numero de variable (x1) que meteremos en la nueva clausula
            int dummySig;
            int numVarTemp = clausula.size() - 2;

            while( numVarTemp > 2) {

                dummySig = dummy + 1; //Creo una nueva variable que anadire
                dummy *= -1; //Cambio de signo

                nuevaClausula.push_back(dummy);
                nuevaClausula.push_back(clausula[Xn]);
                nuevaClausula.push_back(dummySig);

                S3.pushClausula(nuevaClausula);
                nuevaClausula.clear();

                totalClausulas += 1;
                dummy = dummySig;

                numVarTemp -= 1;
                Xn += 1;

            }

            dummy *= -1; //Cambio signo

            nuevaClausula.push_back(dummy);
            nuevaClausula.push_back(clausula[Xn]);
            nuevaClausula.push_back(clausula[Xn + 1]);
            S3.pushClausula(nuevaClausula);
            totalClausulas += 1;
            nuevaClausula.clear();

            dummy *= -1;
            dummy += 1; //Cambio de variable

        }
    }
    S3.setNumVariables(dummy);
    return S3;
}
