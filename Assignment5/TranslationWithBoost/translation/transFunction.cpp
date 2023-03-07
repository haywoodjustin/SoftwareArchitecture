
#include <boost/locale.hpp>
#include <iostream>
#include "transFunction.h"
#include "..\LocalizationUtils\LocalizationUtils.h"

using namespace std;
using namespace boost::locale;

void testFunction()
{
    std::cout << Localize("ocean", "current") << std::endl;
    std::cout << Localize("time", "current") << std::endl;
    std::cout << Localize("file", "open") << std::endl;
    std::cout << Localize("internet connection", "open") << std::endl;
}