#pragma once
#include <iostream>
#include <map>
#include <string>
#include "..\Core\GuidObject.h"

typedef GuidObject* (*dataReaderFunction)(std::ifstream& streamObject);