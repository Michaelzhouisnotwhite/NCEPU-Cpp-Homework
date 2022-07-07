#pragma once
#include <afx.h>

class CRectangle final :
	public CObject
{
public:
	~CRectangle() override;

	CPoint m_LeftTop, m_RightButtom;
	COLORREF m_RectColor;
	int m_nLineType;
	int m_nLineWidth;

	int m_nFillPattern;
	COLORREF m_FillColor;

	void Draw(CDC* pDc) const;

	CRectangle(CPoint m_leftTop, CPoint m_rightButton, int m_nPenWith, int m_nPenType, COLORREF penColor,
	           int fillPattern, COLORREF fillColor);
};
