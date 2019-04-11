#include <iostream>
#include "BSet.cpp"
#include "BBoolean.cpp"

using namespace std;

#ifndef BUTILS_H
#define BUTILS_H

#define BOOL (BSet<BBoolean>(BBoolean(true), BBoolean(false)))

#endif