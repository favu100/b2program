#include <iostream>
#include "BSet.hpp"
#include "BBoolean.hpp"

using namespace std;

#ifndef BUTILS_H
#define BUTILS_H

#define BOOL (BSet<BBoolean>(BBoolean(true), BBoolean(false)))

#endif