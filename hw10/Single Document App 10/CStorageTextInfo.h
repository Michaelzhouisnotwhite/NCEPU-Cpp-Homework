#pragma once
#include <vector>
using namespace std;

class CStorageTextInfo
{
public:
	vector<CPoint> m_vPoints;
	vector<CString> m_vstrTexts;
	vector<COLORREF> m_vColor;

	int index = -1;

	struct GoalInfo
	{
		CPoint point;
		CString message;
		int nRgb;
	};

	int font_height = 25;
	int font_width = 20;
	CStorageTextInfo() = default;
	CStorageTextInfo(CPoint point, CString m_strText, COLORREF color);
	~CStorageTextInfo() = default;

	void PushBack(CPoint point, CString mStrText, COLORREF color);

	GoalInfo* GetRecentInfo();
	BOOL SearchStorage(CPoint point);

	void ChangeIndex(CPoint point, CString m_strText, COLORREF color);
	int IntRgb(int index);
};
