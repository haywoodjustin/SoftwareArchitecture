#pragma once

#include "Extrude.h"
#include <string>
namespace Application
{
	class Extrude2 : public Feature, public IExtrude
	{
	public:
		Extrude2(std::string distance, std::string targetFace, std::string vectorObject, std::string booleanType, int m_guid);
		std::string GetVersion() override;

		virtual ~Extrude2()
		{

		}
		Extrude2() = delete;

		const std::string& GetDistance()
		{
			return m_distance;
		};
		const std::string& GetTargetFace()
		{
			return m_targetFace;
		};
		const std::string& GetVectorObject()
		{
			return m_vectorObject;
		};
		const std::string& GetBooleanType()
		{
			return m_booleanType;
		};


	private:
		std::string m_distance;
		std::string m_targetFace;
		std::string m_vectorObject;
		std::string m_booleanType;

	};
}


