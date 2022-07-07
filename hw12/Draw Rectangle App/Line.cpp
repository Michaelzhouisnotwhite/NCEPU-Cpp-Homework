// Line.cpp : 实现文件
//

#include "stdafx.h"
#include "Draw Rectangle App.h"
#include "Line.h"


// CLine

CLine::CLine()
{
}

CLine::~CLine()
{
}

CLine::CLine(CPoint start, CPoint end)
{
	m_StartPos = start;
	m_EndPos = end;
}
// CLine 成员函数


void CLine::Draw(CDC * pDc) const
{
	pDc->MoveTo(m_StartPos);
	pDc->LineTo(m_EndPos);
}
