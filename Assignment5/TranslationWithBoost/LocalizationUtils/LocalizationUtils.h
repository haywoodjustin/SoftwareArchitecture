
#include "LocalizationUtilsExports.h"
#include <string>



/// <summary>
/// 
/// </summary>
/// <param name="msg"></param>
/// <param name="ctx"></param>
/// <returns></returns>
LOCALIZATIONUTILS_API std::string Localize(const std::string& ctx, const std::string& msg);


/// <summary>
/// 
/// </summary>
/// <param name="msgSing"></param>
/// <param name="msgPlural"></param>
/// <param name="count"></param>
/// <returns></returns>
LOCALIZATIONUTILS_API std::string Localize(const std::string& msgSing, const std::string& msgPlural, int count);

/// <summary>
/// 
/// </summary>
/// <param name="msg"></param>
/// <returns></returns>
[[deprecated("Replaced by context version, please migrate to void Localize(const std::string& msg, const std::string& ctx)")]]
LOCALIZATIONUTILS_API std::string Localize(const std::string& msg);

