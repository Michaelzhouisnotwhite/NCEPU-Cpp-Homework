#pragma once
#include <afx.h>

class CLine :
	public CObject
{
	CPoint m_Start, m_End;
public:
	CLine();
	CLine(CPoint start, CPoint end);
	virtual ~CLine();
	void Draw(CDC* pDc) const;
};
