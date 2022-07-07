#pragma once

// CLine ÃüÁîÄ¿±ê

class CLine final : public CObject
{
	int m_nLineType;
	int m_nLineWith;
	COLORREF m_LineCOlor;
public:
	CLine();
	~CLine() override;

	
	CLine(CPoint start, CPoint end);

	CPoint m_StartPos, m_EndPos;
	void Draw(CDC *pDc) const;
};


