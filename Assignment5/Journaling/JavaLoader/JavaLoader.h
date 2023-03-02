#pragma once

#include "JavaLoaderExports.h"
#include <string>

extern JAVALOADER_API void CreateJVM();

extern JAVALOADER_API void RunJavaProgramWithOutClassLoader(std::string msg);
extern JAVALOADER_API void RunJavaProgramWithClassLoader(std::string classFile);

extern JAVALOADER_API void DestroyJVM();

