#pragma once
#include "AutomationBindingExports.h"
#include "AutomationAPI_IBuilder.h"

namespace AutomationAPI
{
	class CADObject;


	/// <summary>
	/// WireBuilder comment
	/// </summary>
	class AUTOMATIONBINDING_API WireBuilder : public IBuilder
	{
		public:
			enum WireBuilderTypes
			{
				TypesOption1, /**Option1 */
				TypesOption2 /**Option2.*/
			};

			void SetType(WireBuilderTypes type);
			WireBuilderTypes GetType();

			void SetOrigin1(int x, int y, int z);
			void GetOrigin1(int &x, int &y, int &z);

			void SetOrigin2(int x, int y, int z);
			void GetOrigin2(int& x, int& y, int& z);


			CADObject* Commit() override;
		private:


	};
}
