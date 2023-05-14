#pragma once
#include "testStructs.h"
#include "iostream"
using namespace std;
#include "hls_stream.h"

extern "C" void unionTest(int i, ap_uint<1>* val);
