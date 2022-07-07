#include "stdafx.h"
#include "CRectangle.h"

CRectangle::~CRectangle()
{
}

void CRectangle::Draw(CDC* pDc) const
{
	CPen *pPenOld = nullptr, penNew;
	CBrush brushNew;
	if (m_nFillPattern == -1)
	{
		brushNew.CreateSolidBrush(m_FillColor);
	}
	else
	{
		brushNew.CreateHatchBrush(m_nFillPattern, m_FillColor);
	}
	CBrush* pBrushOld = pDc->SelectObject(&brushNew);
	pDc->Rectangle(m_LeftTop.x, m_LeftTop.y, m_RightButtom.x, m_RightButtom.y);
	pDc->SelectObject(pPenOld);
	penNew.DeleteObject();
	pDc->SelectObject(pBrushOld);
	brushNew.DeleteObject();
}

CRectangle::CRectangle(const CPoint m_leftTop, const CPoint m_rightButton, const int m_nPenWith, const int m_nPenType,
                       const COLORREF penColor,
                       const int fillPattern, const COLORREF fillColor): m_LeftTop(m_leftTop),
                                                                         m_RightButtom(m_rightButton),
                                                                         m_RectColor(penColor), m_nLineType(m_nPenType),
                                                                         m_nLineWidth(m_nPenWith),
                                                                         m_nFillPattern(fillPattern),
                                                                         m_FillColor(fillColor)
{
}
