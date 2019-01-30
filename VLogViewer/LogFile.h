#pragma once
#include "ItemInfo.h"

class CLogFile
{
public:
	CLogFile(CString strFilePath);
	~CLogFile();
	int LoadContent();
	CString GetFilePath() const;
	CTime GetLastModifiedTime() const;
	ULONGLONG GetFileSize() const;
	CList<CItemInfo, CItemInfo&>& GetItems();

private:
	CString m_strFilePath;
	CTime m_lastModifiedTime;
	ULONGLONG m_ullFileSize;
	CList<CItemInfo, CItemInfo&> m_items{};
};

