#include "pch.h"
#include "Line.h"

CLine::CLine()
{
	m_Start = CPoint(0, 0);
	m_End = CPoint(0, 0);
}

CLine::CLine(const CPoint start, const CPoint end)
{
	m_Start = start;
	m_End = end;
}

CLine::~CLine()
{
}

void CLine::Draw(CDC* pDc) const
{
	pDc->MoveTo(m_Start);
	pDc->LineTo(m_End);
}
