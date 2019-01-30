#include "stdafx.h"
#include "ItemInfo.h"


CItemInfo::CItemInfo()
{
}


CItemInfo::~CItemInfo()
{
}

CString CItemInfo::GetTime() const
{
	return m_strTime;
}

void CItemInfo::SetTime(CString strValue)
{
	m_strTime = strValue;
}

CString CItemInfo::GetType() const
{
	return m_strType;
}

void CItemInfo::SetType(CString strValue)
{
	m_strType = strValue;
}

CString CItemInfo::GetContent() const
{
	return m_strContent;
}

void CItemInfo::SetContent(CString strValue)
{
	m_strContent = strValue;
}
