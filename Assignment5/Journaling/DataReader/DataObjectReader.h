#pragma once
#include "DataReaderExports.h"
#include <string>
#include "dataReaderFunctionType.h"


class DATAREADER_API DataObjectReader
{
public:

    static DataObjectReader& GetInstance();

    DataObjectReader(DataObjectReader const&) = delete;
    void operator=(DataObjectReader const&) = delete;

    void AddReader(std::string, dataReaderFunction func );
    void RemoveReader(std::string);
    dataReaderFunction GetReader(std::string);

private:
    DataObjectReader();

    std::map<std::string, dataReaderFunction> m_mapOfReaderFunctions;


};

