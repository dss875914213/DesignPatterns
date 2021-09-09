#include "User.h"

User::User(string name)
{
	m_name = name;
}

std::string User::GetName()
{
	return m_name;
}
