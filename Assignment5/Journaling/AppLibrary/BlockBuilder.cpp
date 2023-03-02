#include "BlockBuilder.h"
#include <iostream>

Application::BlockBuilder::BlockBuilder(Application::Block* block, int guid) : GuidObject(guid), m_block(block)
{

	if (m_block == nullptr)
	{
		std::cout << "Block is creation mode" << std::endl;
	}
	else
	{
		std::cout << "Block is edit/query mode" << std::endl;
	}
}

JournalBlockBuilderTypes Application::BlockBuilder::GetType()
{
	return m_journalBlockBuilderTypes;
}
void Application::BlockBuilder::SetType(JournalBlockBuilderTypes type)
{
	m_journalBlockBuilderTypes = type;
}
