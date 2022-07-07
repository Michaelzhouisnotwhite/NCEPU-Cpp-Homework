#include "pch.h"
#include "CStorageTextInfo.h"


CStorageTextInfo::CStorageTextInfo(CPoint point, CString m_strText, COLORREF color)
{
	m_vPoints.push_back(point);
	m_vstrTexts.push_back(m_strText);
	m_vColor.push_back(color);
}

void CStorageTextInfo::PushBack(CPoint point, const CString mStrText, COLORREF color)
{
	m_vPoints.push_back(point);
	m_vstrTexts.push_back(mStrText);
	m_vColor.push_back(color);
}

BOOL CStorageTextInfo::SearchStorage(CPoint point)
{
	int len = m_vPoints.size();
	int x = point.x;
	int y = point.y;
	for (int i = len - 1; i >= 0; i--)
	{
		if (x <= m_vPoints[i].x + font_width && x >= m_vPoints[i].x &&
			y <= m_vPoints[i].y + font_height && y >= m_vPoints[i].y)
		{
			index = i;
			return TRUE;
		}
	}
	index = -1;
	return FALSE;
}

CStorageTextInfo::GoalInfo* CStorageTextInfo::GetRecentInfo()
{
	if (index > -1)
	{
		auto* gr = new GoalInfo{m_vPoints[index], m_vstrTexts[index], IntRgb(index)};

		return gr;
	}
	return nullptr;
}

void CStorageTextInfo::ChangeIndex(CPoint point, CString m_strText, COLORREF color)
{
	m_vPoints[index] = point;
	m_vstrTexts[index] = m_strText;
	m_vColor[index] = color;
}

int CStorageTextInfo::IntRgb(int index)
{
	switch (m_vColor[index])
	{
	case RGB(255, 0, 0):
		return 0;
	case RGB(0, 255, 0):
		return 1;
	case RGB(0, 0, 255):
		return 2;
	default:
		return -1;
	}
}
