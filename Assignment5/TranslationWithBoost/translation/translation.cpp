#include <boost/locale.hpp>
#include <iostream>

#include "..\LocalizationUtils\LocalizationUtils.h"

using namespace std;
using namespace boost::locale;

static void function1(int files)
{
    cout << format(Localize("You have {1} file in the directory",
        "You have {1} files in the directory",
        files)) % files << endl;
}

static void function2(int n)
{
    cout << format(Localize("Option1 {1} file in the directory",
        "Option2 {1} files in the directory",
        n)) % n << endl;
}

int main()
{

    #pragma warning(suppress : 4996)
    std::cout << Localize("Hello World") << std::endl;

    std::cout << Localize("Welcome splash screen", "Hello World") << std::endl;

    std::cout << Localize("file", "open") << std::endl;

    std::cout << Localize("internet connection", "open") << std::endl;

    int files = 1;

    //MSGS re-used
    std::cout << Localize("file", "open") << std::endl;

    std::cout << Localize( "internet connection", "open") << std::endl;

    function1(1);
    function1(4);

    function2(1);
    function2(2);
    function2(15);


}

