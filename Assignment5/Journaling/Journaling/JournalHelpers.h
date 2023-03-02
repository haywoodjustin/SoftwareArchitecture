#pragma once
#include "JournalExports.h"
#include <string>
#include "JournalingTypes.h"

class GuidObject;

/// <summary>
/// Starts a Journal call for a method call on a canned global
/// </summary>
/// <param name="methodName"></param>
/// <param name="cannedGlobal"></param>
extern JOURNALING_API void JournalStartCall(std::string methodName, CannedGlobals cannedGlobal);

/// <summary>
/// Starts a Journal call for a method call on a class
/// </summary>
/// <param name="methodName"></param>
/// <param name="classObject"></param>
extern JOURNALING_API void JournalStartCall(std::string methodName, GuidObject* classObject);
/// <summary>
/// Ends the journal for the method call
/// </summary>
extern JOURNALING_API void JournalEndCall();
/// <summary>
/// Journals in a integer parameter
/// </summary>
/// <param name="value"></param>
/// <param name="paramName"></param>
extern JOURNALING_API void JournalIntInParam(int value, std::string paramName);
/// <summary>
/// Journals a return parameter as a integer
/// </summary>
/// <param name="value"></param>
/// <param name="paramName"></param>
extern JOURNALING_API void JournalReturnInt(int value, std::string paramName);
/// <summary>
/// Journals in a bool parameter
/// </summary>
/// <param name="value"></param>
/// <param name="paramName"></param>
extern JOURNALING_API void JournalBoolInParam(bool value, std::string paramName);
/// <summary>
/// Journals in a string parameter
/// </summary>
/// <param name="value"></param>
/// <param name="paramName"></param>
extern JOURNALING_API void JournalStringInParam(std::string value, std::string paramName);
/// <summary>
/// Journals in a class as a return parameter
/// </summary>
/// <param name="classObject"></param>
/// <param name="className"></param>
/// <param name="paramName"></param>
extern JOURNALING_API void JournalReturnClass(GuidObject* classObject, std::string className, std::string paramName);

/// <summary>
/// Journals in a class as a input parameter
/// </summary>
/// <param name="classObject"></param>
/// <param name="className"></param>
/// <param name="paramName"></param>
extern JOURNALING_API void JournalInClassParam(GuidObject* classObject, std::string className, std::string paramName);

