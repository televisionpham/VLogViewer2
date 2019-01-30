
// VLogViewerDoc.h : interface of the CVLogViewerDoc class
//


#pragma once
#include "LogFile.h"

class CVLogViewerDoc : public CDocument
{
protected: // create from serialization only
	CVLogViewerDoc();
	DECLARE_DYNCREATE(CVLogViewerDoc)

// Attributes
private:
	CLogFile* m_logFile{ NULL };

// Operations
public:
	CLogFile* GetLogFile() const;

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CVLogViewerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
};
