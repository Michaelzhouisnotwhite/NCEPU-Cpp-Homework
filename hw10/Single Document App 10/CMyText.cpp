#include "pch.h"
#include "CMyText.h"
IMPLEMENT_SERIAL(CMyText, CObject, 0)
void CMyText::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_strText << m_textPos << m_textColor;
	}
	else
	{
		ar >> m_strText >> m_textPos >> m_textColor;
	}
}


CMyText::CMyText()
{
	m_strText = "";
	m_textPos = CPoint(10, 10);
	m_textColor = RGB(0, 0, 0);
}


CMyText::CMyText(const CString text, const CPoint pos, const COLORREF color)
	:m_strText(text)
	,m_textPos(pos)
	,m_textColor(color)
{
	
}

CMyText::~CMyText()
{
}

