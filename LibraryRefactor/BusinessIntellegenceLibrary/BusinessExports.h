#pragma once

#ifdef BUSINESSINTELLEGENCELIBRARY_EXPORTS
#define BUSINESSINTELLEGENCELIBRARY_API __declspec(dllexport)
#else
#define BUSINESSINTELLEGENCELIBRARY_API __declspec(dllimport)
#endif