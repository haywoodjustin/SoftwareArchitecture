#pragma once

#include "AutomationBindingExports.h"
#include <string>


namespace AutomationAPI
{
	class Part;
	/// <summary>
	/// This represents an Session object which is needed for any automation workflow.
	/// </summary>
	class AUTOMATIONBINDING_API Session
	{
		public :
			/// <summary>
			/// This method should be called first in any automation program.
			/// </summary>
			/// This is used as the starting point in any automation workflow.
			/// <returns>Generates and\or returns the Session object.</returns>
			static Session* GetSession();


			/// <summary>
			/// Generates the Part File at the path specificed
			/// </summary>
			/// To save the part afterward  use [Part.Save()](@ref Part.Save())
			/// <param name="partFilePath">The path to the file to be created</param>
			/// <returns>The part created </returns>
			Part* MakePart(std::string partFilePath);

			/**
			* <summary>Opens an existing the Part File at the path specificed</summary>
			* To save the part afterware use [Save Method](@ref Part.Save())

			*/
			Part* OpenPart(std::string partFilePath);

			virtual ~Session();
			Session(const Session&) = delete;
			Session& operator=(const Session&) = delete;

		private:
			Session() = default;

	};

}


