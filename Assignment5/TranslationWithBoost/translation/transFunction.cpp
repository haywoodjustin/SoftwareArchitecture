
#include <boost/locale.hpp>
#include <iostream>
#include "transFunction.h"
#include "..\LocalizationUtils\LocalizationUtils.h"

using namespace std;
using namespace boost::locale;

void testFunction()
{
    cout << "This works\n"; 
    std::cout << Localize("file", "open") << std::endl;
    std::cout << Localize("internet connection", "open") << std::endl;
}