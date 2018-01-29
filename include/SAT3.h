#ifndef SAT3_H
#define SAT3_H

#include "SAT.h"

using namespace std;

class SAT3 : public SAT {
  public:
    SAT3() {};

    void pushClausula(vector<int> clausula);

    friend ifstream &operator>>( ifstream  &fich, SAT3 &S );
};

#endif