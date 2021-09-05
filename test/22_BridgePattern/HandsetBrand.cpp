#include "HandsetBrand.h"

void HandsetBrand::SethandsetSoft(HandsetSoft* soft)
{
	m_pSoft = soft;
}

void HandsetBrandN::Run()
{
	m_pSoft->Run();
}

void HandsetBrandM::Run()
{
	m_pSoft->Run();
}
