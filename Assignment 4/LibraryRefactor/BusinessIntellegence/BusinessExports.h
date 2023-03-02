#pragma once

#ifdef BUSINESSINTELLEGENCE_EXPORTS
#define BUSINESSINTELLEGENCE_API __declspec(dllexport)
#else
#define BUSINESSINTELLEGENCE_API __declspec(dllimport)
#endif