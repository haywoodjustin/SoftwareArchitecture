#include "CoreUtils.h"

#include <windows.h>

#include <iostream>

static bool determinedBasePath = false;
static std::string basePath;

std::string BasePath() {
    if (!determinedBasePath)
    {
        TCHAR buffer[MAX_PATH] = { 0 };
        GetModuleFileName(NULL, buffer, MAX_PATH);
        std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
        std::wstring wStr = std::wstring(buffer).substr(0, pos);

        std::string tmp = std::string(wStr.begin(), wStr.end());

        std::string tmp1 = RemoveLastDirectory(tmp);
        basePath = RemoveLastDirectory(tmp1);
    }

    return basePath;
}

std::string RemoveLastDirectory(const std::string& dirPath)
{
    auto pos = dirPath.find_last_of("\\");
    std::string retVal = dirPath.substr(0, pos);

    return retVal;
}
