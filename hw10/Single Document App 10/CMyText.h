#pragma once
#include <afx.h>
class CMyText :
    public CObject
{
    DECLARE_SERIAL(CMyText)
public:
    virtual void Serialize(CArchive& ar);
    CMyText();
    CMyText(CString text, CPoint pos, COLORREF color);
    virtual ~CMyText();
public:
    CString m_strText;
    CPoint m_textPos;
    COLORREF m_textColor;
};

