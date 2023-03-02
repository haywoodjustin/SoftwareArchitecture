#include "DataObjectReader.h"

DataObjectReader& DataObjectReader::GetInstance()
{
    static DataObjectReader instance;

    return instance;
}


DataObjectReader::DataObjectReader()
{

}


void DataObjectReader::AddReader(std::string name, dataReaderFunction func)
{

    std::cout << "Adding Reader for " << name << std::endl;

    m_mapOfReaderFunctions[name] = func;
}
void DataObjectReader::RemoveReader(std::string name)
{
    std::cout << "Removing Reader for " << name << std::endl;
    m_mapOfReaderFunctions.erase(name);
}
dataReaderFunction DataObjectReader::GetReader(std::string name)
{
    try
    {
        std::cout << "Getting Reader for " << name << std::endl;
        return m_mapOfReaderFunctions[name];
    }
    catch (std::exception e)
    {
        std::string msg = "No reader registered for " + name;
        throw std::exception(msg.c_str());
    }
}