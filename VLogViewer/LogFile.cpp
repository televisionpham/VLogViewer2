#include "stdafx.h"
#include "LogFile.h"

CLogFile::CLogFile(CString strFilePath)
{
	m_strFilePath = strFilePath;
}

CLogFile::~CLogFile()
{
}

int CLogFile::LoadContent()
{
	FILE* fStream;
	errno_t errCode = _tfopen_s(&fStream, m_strFilePath, _T("r, ccs=UNICODE"));
	if (errCode != 0)
	{
		return errCode;
	}
	CStdioFile file{ fStream };
	m_ullFileSize = file.GetLength();
	CFileStatus fileStatus;
	file.GetStatus(fileStatus);
	m_lastModifiedTime = fileStatus.m_mtime;
	CString strLine;
	while (file.ReadString(strLine))
	{
		CItemInfo itemInfo;		
		itemInfo.SetTime(strLine.Mid(0, 24));
		int pos = strLine.Find(_T(" "), 26);
		itemInfo.SetType(strLine.Mid(25, pos - 25));
		itemInfo.SetContent(strLine.Mid(pos));
		m_items.AddTail(itemInfo);
	}
	file.Close();
	return 0;
}

CString CLogFile::GetFilePath() const
{
	return m_strFilePath;
}

CTime CLogFile::GetLastModifiedTime() const
{
	return m_lastModifiedTime;
}

ULONGLONG CLogFile::GetFileSize() const
{
	return m_ullFileSize;
}

CList<CItemInfo, CItemInfo&>& CLogFile::GetItems()
{
	return m_items;
}
