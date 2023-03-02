#include "Block.h"
#include <fstream>
#include "..\Core\StringUtils.h"


void ProcessBlock(std::ifstream& streamObject)
{
	std::cout << "    ProcessBlock" << std::endl;

	std::string line;
	bool done = false;
	while (!done)
	{
		getline(streamObject, line);
		std::cout << line << '\n';

		if (startsWith(line, EndFeatureToken))
		{
			done = true;
		}
		
		//NIY 

		//else if (startsWith(line, ""))
		//{
		//	std::string partFileName = line.substr(EndFeatureToken.size(), line.size() - EndFeatureToken.size());
		//	cout << "    " << EndFeatureToken << " " << partFileName << endl;
		//}

	}
}