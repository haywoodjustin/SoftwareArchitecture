#pragma once

#ifdef APPLICATIONLIBRARY_EXPORTS
#define APPLICATIONLIBRARY_API __declspec(dllexport)
#else
#define APPLICATIONLIBRARY_API __declspec(dllimport)
#endif