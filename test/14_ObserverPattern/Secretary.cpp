#include "Secretary.h"

void Subject::Attach(function<void(string)> observer)
{
	m_observers.push_back(observer);
}

//void Subject::Detach(void* observer)
//{
//	auto it = std::remove(m_observers.begin(), m_observers.end(), observer);
//	m_observers.erase(it, m_observers.end());
//}

void Subject::Notify()
{
	for (auto observer : m_observers)
	{
		observer(m_action);
	}
}

void Subject::SetAction(string action)
{
	m_action = action;
}

std::string Subject::GetAction()
{
	return m_action;
}
