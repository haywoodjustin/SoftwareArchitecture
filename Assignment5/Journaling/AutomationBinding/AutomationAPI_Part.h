#pragma once

#include "AutomationBindingExports.h"
#include <string>


namespace AutomationAPI
{

	class FeatureCollection;
	class RoutingCollection;
	class PartImpl;
	/// <summary>
	/// Represents a part file in our sample CAD application.
	/// </summary>
	/// An instance of this object can be obtained from the class [Session](@ref Session)
	class AUTOMATIONBINDING_API Part
	{
		public :

			/**
			* <summary>Saves the Part File.</summary>  More commetns and details blah blah blah
			*/
			void Save();

			/**
			* <summary>Makes a Widget Feature</summary> Even More commetns and details blah blah blah
			*/
			void MakeWidgetFeature(bool option1, int values);

			/**
			* Returns the Feature collection for the part.
			*/
			FeatureCollection* Features();


			/**
			* Returns the Routing collection for the part.
			*/
			RoutingCollection* Routing();
			/*
			* Internal Usage only.
			*/
			static Part* CreatePart(int guid);

			virtual ~Part();
			Part() = delete;

		private:
			
			Part(int guid);
			PartImpl *m_partImpl;

	};

}
