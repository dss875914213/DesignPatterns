#include "Command.h"

Command::Command(Barbecuer* receiver)
{
	m_receiver = receiver;
}

BakeMuttonCommand::BakeMuttonCommand(Barbecuer* receiver):
	Command(receiver)
{

}

void BakeMuttonCommand::ExceuteCommand()
{
	m_receiver->BakeMutton();
}

string BakeMuttonCommand::GetType()
{
	return "Mutton";
}

BakeChickenWingCommand::BakeChickenWingCommand(Barbecuer* receiver) :
	Command(receiver)
{

}

void BakeChickenWingCommand::ExceuteCommand()
{
	m_receiver->BakeChickenWing();
}

std::string BakeChickenWingCommand::GetType()
{
	return "ChickenWing";
}
