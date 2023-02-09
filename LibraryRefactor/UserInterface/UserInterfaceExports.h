#pragma once

#ifdef USERINTERFACE_EXPORTS
#define USERINTERFACE_API __declspec(dllexport)
#else
#define USERINTERFACE_API __declspec(dllimport)
#endif