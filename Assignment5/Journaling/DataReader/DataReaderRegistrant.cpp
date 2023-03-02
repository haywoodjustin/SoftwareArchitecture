#include "DataReaderRegistrant.h"
#include "DataObjectReader.h"




DataReaderRegistrant::DataReaderRegistrant(std::string registrantName, dataReaderFunction func)
{
	DataObjectReader::GetInstance().AddReader(registrantName, func);
	m_registrantName = registrantName;
}


DataReaderRegistrant::~DataReaderRegistrant()
{
	DataObjectReader::GetInstance().RemoveReader(m_registrantName);
}




