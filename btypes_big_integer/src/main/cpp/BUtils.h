#include <iostream>
#include "BSet.h"
#include "BBoolean.h"

using namespace std;

#ifndef BUTILS_H
#define BUTILS_H

#define BOOL (BSet<BBoolean>(BBoolean(true), BBoolean(false)))

#endif