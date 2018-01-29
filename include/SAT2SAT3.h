#ifndef SATTOSAT3_H
#define SATTOSAT3_H

#include "SAT.h"
#include "SAT3.h"

using namespace std;

class SATto3SAT {
  public:
    SATto3SAT() {};
    SAT3 convertSATto3SAT(SAT S);
};

#endif