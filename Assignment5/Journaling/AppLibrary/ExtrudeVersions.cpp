#include "ExtrudeVersions.h"


Application::Extrude2::Extrude2(std::string distance, std::string targetFace, std::string vectorObject, std::string booleanType, int guid)
	: Application::IExtrude(guid) ,m_distance(distance), m_targetFace(targetFace), m_vectorObject(vectorObject), m_booleanType(booleanType)
{

}

std::string Application::Extrude2::GetVersion()
{
	return "2";
}