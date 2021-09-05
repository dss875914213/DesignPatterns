#include "Request.h"

void Request::SetRequestType(string requestType)
{
	m_requestType = requestType;
}

std::string Request::GetRequestType()
{
	return m_requestType;
}

void Request::SetRequestContent(string requestContent)
{
	m_requestContent = requestContent;
}

std::string Request::GetRequestContent()
{
	return m_requestContent;
}

void Request::SetNumber(int number)
{
	m_number = number;
}

int Request::GetNumber()
{
	return m_number;
}
