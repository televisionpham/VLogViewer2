#pragma once
class CItemInfo
{
public:
	CItemInfo();
	~CItemInfo();
	CString GetTime() const;
	void SetTime(CString strValue);
	CString GetType() const;
	void SetType(CString strValue);
	CString GetContent() const;
	void SetContent(CString strValue);

private:
	CString m_strTime;
	CString m_strType;
	CString m_strContent;
};

