#ifndef SNAPSHOT_H
#define SNAPSHOT_H

#include "stackClass.h"

using namespace std;

class snapShot_c
{
public:
    stack_c reserveStack;
    vector<columStack_c> colums;
    vector<endStack_c> endStacks;

    snapShot_c();

    ~snapShot_c();
};

#endif // SNAPSHOT_H