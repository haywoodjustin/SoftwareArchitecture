// PatrickLocal.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "LocalizationUtils.h"
#include "LocalizationUtilsInternal.h"
#include <boost/locale.hpp>

using namespace boost::locale;

static generator* genPtr = nullptr;

static bool isInitialized = false;


void LocalizeUtilsInit()
{
    
    // Specify location of dictionaries
    genPtr = new generator();
    // TODO you will need to change this value to your local directory of where mo file
    genPtr->add_messages_path("C:\\Users\\polek\\source\\repos\\boost_starting\\translation");
    genPtr->add_messages_domain("messages");

    std::locale::global(( *genPtr)("de_DE.UTF - 8"));

    std::cout.imbue(std::locale());

    isInitialized = true;

}


std::string Localize(const std::string & msg)
{
    if (!isInitialized)
    {
        LocalizeUtilsInit();
    }

    // Display a message using current system locale
    std::string  retval = translate(msg);
    return retval;

}

std::string Localize(const std::string& msgSing, const std::string& msgPlural, int count)
{

    std::string  retval = translate(msgSing, msgPlural, count);
    return retval;
}

std::string Localize(const std::string& ctx, const std::string& msg)
{

    if (!isInitialized)
    {
        LocalizeUtilsInit();
    }


    std::string  retval = translate(ctx, msg);
    return retval;
}
