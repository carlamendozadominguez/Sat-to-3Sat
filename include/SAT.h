#ifndef SAT_H
#define SAT_H

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class SAT {
  protected:
    vector<vector<int> > clausulas;
    int numVariables;
    int numClausulas;

  public:
    SAT();

    void setNumVariables(int n);
    void pushClausula(vector<int> clausula) ;

    int getNumVariables();
    int getNumClausulas();
    int getNumLiteralesClausula(int n);

    vector<int> getClausula(int n);
    vector<int> separarInt(string v);

    vector<string> separarString(string v) ;

    friend ifstream &operator>>( ifstream  &fich, SAT &S );
    friend ofstream &operator<<( ofstream  &fich, SAT &S );
    friend ostream &operator<<( ostream  &fich, SAT &S );
};


#endif