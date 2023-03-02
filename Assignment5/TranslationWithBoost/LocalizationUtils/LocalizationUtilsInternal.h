#pragma once

/// <summary>
/// This is used to initialize the Localization standard setup
/// 
/// This is architectured to be setup on the first call to Localize.  The
/// current methodolgy only allows the local to be setup for the program run
/// and cannot be switch while running
/// </summary>
void LocalizeUtilsInit();
