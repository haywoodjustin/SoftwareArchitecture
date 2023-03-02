#pragma once


#ifdef USERINTERFACELIBRARY_EXPORTS
#define USERINTERFACELIBRARY_API __declspec(dllexport)
#else
#define USERINTERFACELIBRARY_API __declspec(dllimport)
#endif