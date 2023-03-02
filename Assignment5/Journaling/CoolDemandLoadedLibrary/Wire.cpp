#include "Wire.h"
#include "WireVersions.h"
#include <fstream>
#include "..\Core\StringUtils.h"
#include "..\DataReader\DataObjectReader.h"
#include "..\DataReader\\DataReaderRegistrant.h"
#include "..\Core\GuidObject.h"


std::string Wire_VersionToken = "Wire_Version:";
std::string Wire_DistanceToken = "Wire_Distance:";


GuidObject* ReadWireVersion2(std::ifstream& streamObject);
GuidObject* ReadWireVersion3(std::ifstream& streamObject);

Wire* VersionUpWireVersion2(Wire2 *oldFeature);

static DataReaderRegistrant wire2registrant("Wire2", ReadWireVersion2);
static DataReaderRegistrant wire3registrant("Wire3", ReadWireVersion3);



Wire::Wire(std::string distance, int guid)
	: IWire(guid), m_distance(distance)
{

}
std::string Wire::GetVersion()
{
	return "3";
}

void ReadInWire(std::ifstream& streamObject)
{

	std::cout << "    ProcessWire" << std::endl;
	std::string line;
	getline(streamObject, line);

	//IExtrude* extrudeReadIn = nullptr;
	void* wireReadIn = nullptr;

	std::string version = line.substr(Wire_VersionToken.size(), line.size() - Wire_VersionToken.size());
	std::cout << "    " << Wire_VersionToken << " " << version << std::endl;

	std::string WireVersionToken = "Wire" + version;

	dataReaderFunction readerFunc = nullptr;

	readerFunc = DataObjectReader::GetInstance().GetReader(WireVersionToken);

	if (readerFunc != nullptr)
	{
		wireReadIn = readerFunc(streamObject);
	}


	IWire* wireReadInterface = (IWire*)wireReadIn;

	Wire* retVal = dynamic_cast<Wire*>(wireReadInterface);

	if (dynamic_cast<Wire*>(wireReadInterface) == nullptr)
	{
		if (version == "1")
		{

		}
		else if (version == "2")
		{
			Wire2* wireVersion2 = dynamic_cast<Wire2*>(wireReadInterface);
			retVal = VersionUpWireVersion2(wireVersion2);
		}
		// need to upgrade to latest Version
		
	}
	else
	{
		return; // We woudl probably like to return this retVal
	}

}

GuidObject * ReadWireVersion2(std::ifstream& streamObject)
{
	std::string line;

	std::string distance;


	bool done = false;
	while (!done)
	{
		getline(streamObject, line);
		std::cout << line << '\n';



		if (startsWith(line, EndRoutingFeatureToken))
		{
			done = true;
		}

		else if (startsWith(line, Wire_DistanceToken))
		{
			distance = line.substr(Wire_DistanceToken.size(), line.size() - Wire_DistanceToken.size());
			std::cout << "    " << Wire_DistanceToken << " " << distance << std::endl;
		}

	}
	// TODO totally made up guid
	int guid = 99999;

	// TODO no validation we read in all the right fields 

	return new Wire2(distance, guid);

}


GuidObject* ReadWireVersion3(std::ifstream& streamObject)
{

	throw std::exception("NIY");

	return nullptr;

}


Wire* VersionUpWireVersion2(Wire2 * oldFeature)
{
	Wire* retval = nullptr;

	//Old Items
	const std::string distance = oldFeature->GetDistance();

	//New Items
	std::string isAddition;
	std::string isSubtraction;

	int guid = oldFeature->GetGuid();

	std::cout << "    VersionUpExtrudeVersion2" << std::endl;


	retval = new Wire(distance, guid);

	return retval;

}
