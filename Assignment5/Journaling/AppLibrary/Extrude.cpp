#include "Extrude.h"
#include "ExtrudeVersions.h"
#include <fstream>
#include "..\Core\StringUtils.h"
#include "..\DataReader\DataObjectReader.h"
#include "..\DataReader\\DataReaderRegistrant.h"


std::string Extrude_VersionToken = "Extrude_Version:";
std::string Extrude_DistanceToken = "Extrude_Distance:";
std::string Extrude_TargetFaceToken = "Extrude_TargetFace:";
std::string Extrude_VectorToken = "Extrude_Vector:";
std::string Extrude_BooleanToken = "Extrude_Boolean:";
std::string Extrude_GuidToken = "Extrude_Guid:";


GuidObject* ReadExtrudeVersion2(std::ifstream& streamObject);
GuidObject* ReadExtrudeVersion3(std::ifstream& streamObject);

Application::Extrude* VersionUpExtrudeVersion2(Application::Extrude2* oldFeature);

static DataReaderRegistrant extrude2registrant("Extrude2", ReadExtrudeVersion2);
static DataReaderRegistrant extrude3registrant("Extrude3", ReadExtrudeVersion3);



Application::Extrude::Extrude(std::string distance, std::string targetFace, std::string vectorObject, std::string isAddition, std::string isSubtraction, int guid)
	: Application::IExtrude(guid), m_distance(distance), m_targetFace(targetFace), m_vectorObject(vectorObject), m_isAddition(isAddition), m_isSubtraction(isSubtraction)
{

}
std::string Application::Extrude::GetVersion()
{
	return "3";
}

void ReadInExtrude(std::ifstream& streamObject)
{

	std::cout << "    ProcessExtrude" << std::endl;
	std::string line;
	getline(streamObject, line);

	void* extrudeReadIn = nullptr;

	std::string version = line.substr(Extrude_VersionToken.size(), line.size() - Extrude_VersionToken.size());
	std::cout << "    " << Extrude_VersionToken << " " << version << std::endl;

	std::string ExtrudeVersionToken = "Extrude" + version;

	dataReaderFunction readerFunc = nullptr;

	readerFunc = DataObjectReader::GetInstance().GetReader(ExtrudeVersionToken);

	if (readerFunc != nullptr)
	{
		extrudeReadIn = readerFunc(streamObject);
	}
	
	Application::IExtrude* extrudeReadInterface = (Application::IExtrude*)extrudeReadIn;

	Application::IExtrude* retVal2 = dynamic_cast<Application::IExtrude*>(extrudeReadInterface);

	Application::Extrude* retVal = dynamic_cast<Application::Extrude*>(extrudeReadInterface);

	Application::Extrude2* retVal3 = dynamic_cast<Application::Extrude2*>(retVal2);

	if (retVal == nullptr)
	{
		if (version == "1")
		{

		}
		else if (version == "2")
		{
			Application::Extrude2* extrudeVersion2 = dynamic_cast<Application::Extrude2*>(extrudeReadInterface);
			retVal = VersionUpExtrudeVersion2(extrudeVersion2);
		}
		// need to upgrade to latest Version
		
	}
	else
	{
		return; // We woudl probably like to return this retVal
	}
	// TODO I believe we are leaking the Extrude Object here :(
}

GuidObject * ReadExtrudeVersion2(std::ifstream& streamObject)
{
	std::string line;

	std::string distance;
	std::string targetFace;
	std::string vectorObject;
	std::string booleanType;
	int guid = -1;

	bool done = false;
	while (!done)
	{
		getline(streamObject, line);
		std::cout << line << '\n';



		if (startsWith(line, EndFeatureToken))
		{
			done = true;
		}

		else if (startsWith(line, Extrude_DistanceToken))
		{
			distance = line.substr(Extrude_DistanceToken.size(), line.size() - Extrude_DistanceToken.size());
			std::cout << "    " << Extrude_DistanceToken << " " << distance << std::endl;
		}
		else if (startsWith(line, Extrude_TargetFaceToken))
		{
			targetFace = line.substr(Extrude_TargetFaceToken.size(), line.size() - Extrude_TargetFaceToken.size());
			std::cout << "    " << Extrude_TargetFaceToken << " " << targetFace << std::endl;
		}
		else if (startsWith(line, Extrude_VectorToken))
		{
			vectorObject = line.substr(Extrude_VectorToken.size(), line.size() - Extrude_VectorToken.size());
			std::cout << "    " << Extrude_VectorToken << " " << vectorObject << std::endl;
		}
		else if (startsWith(line, Extrude_BooleanToken))
		{
			booleanType = line.substr(Extrude_BooleanToken.size(), line.size() - Extrude_BooleanToken.size());
			std::cout << "    " << Extrude_BooleanToken << " " << booleanType << std::endl;
		}
		else if (startsWith(line, Extrude_GuidToken))
		{
			std::string temp = line.substr(Extrude_GuidToken.size(), line.size() - Extrude_GuidToken.size());
			guid = std::stoi(temp);
			std::cout << "    " << Extrude_GuidToken << " " << guid << std::endl;
		}

	}

	// TODO no validation we read in all the right fields 

	return new Application::Extrude2(distance, targetFace, vectorObject, booleanType, guid);

}


GuidObject* ReadExtrudeVersion3(std::ifstream& streamObject)
{

	throw std::exception("NIY");

	return nullptr;

}


Application::Extrude* VersionUpExtrudeVersion2(Application::Extrude2 * oldFeature)
{
	Application::Extrude* retval = nullptr;

	//Old Items
	const std::string distance = oldFeature->GetDistance();
	const std::string targetFace = oldFeature->GetTargetFace();
	const std::string vectorObject = oldFeature->GetVectorObject();
	const std::string booleanType = oldFeature->GetBooleanType();
	int guid = oldFeature->GetGuid();

	//New Items
	std::string isAddition;
	std::string isSubtraction;

	std::cout << "    VersionUpExtrudeVersion2" << std::endl;

	if (booleanType == "Intersect")
	{
		isAddition = "True";
		isSubtraction = "False";
	}
	else
	{
		throw std::exception("NIY");
	}

	retval = new Application::Extrude(distance, targetFace, vectorObject, isAddition, isSubtraction, guid);

	return retval;

}
