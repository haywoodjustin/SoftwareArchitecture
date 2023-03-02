#pragma once
#include "DataReaderExports.h"
#include "dataReaderFunctionType.h"
#include <string>



class DATAREADER_API DataReaderRegistrant
{
public:

	DataReaderRegistrant(std::string registrantName, dataReaderFunction func);

	virtual ~DataReaderRegistrant();


private:
	std::string m_registrantName;
};
