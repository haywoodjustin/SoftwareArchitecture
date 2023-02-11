#pragma once

#ifdef APPLICATION1_EXPORTS
#define APPLICATION1_API __declspec(dllexport)
#else
#define APPLICATION1_API __declspec(dllimport)
#endif