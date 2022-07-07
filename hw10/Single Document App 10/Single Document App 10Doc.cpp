
// Single Document App 10Doc.cpp: CSingleDocumentApp10Doc 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Single Document App 10.h"
#endif

#include "Single Document App 10Doc.h"
#include "CMyText.h"
#include "CTextDlg.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSingleDocumentApp10Doc

IMPLEMENT_DYNCREATE(CSingleDocumentApp10Doc, CDocument)

BEGIN_MESSAGE_MAP(CSingleDocumentApp10Doc, CDocument)
	ON_COMMAND(ID_32772, &CSingleDocumentApp10Doc::OnAddText)
END_MESSAGE_MAP()


// CSingleDocumentApp10Doc 构造/析构

CSingleDocumentApp10Doc::CSingleDocumentApp10Doc() noexcept
{
	// TODO: 在此添加一次性构造代码

}


CSingleDocumentApp10Doc::~CSingleDocumentApp10Doc()
{
}


BOOL CSingleDocumentApp10Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CSingleDocumentApp10Doc 序列化

void CSingleDocumentApp10Doc::Serialize(CArchive& ar)
{
	m_textList.Serialize(ar);
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CSingleDocumentApp10Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CSingleDocumentApp10Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CSingleDocumentApp10Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CSingleDocumentApp10Doc 诊断

#ifdef _DEBUG
void CSingleDocumentApp10Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSingleDocumentApp10Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSingleDocumentApp10Doc 命令


void CSingleDocumentApp10Doc::OnAddText()
{
	// TODO: 在此添加命令处理程序代码
	CTextDlg tdlg;

	if (tdlg.DoModal() == IDOK)
	{
		const int x = tdlg.m_nX;
		const int y = tdlg.m_nY;
		const CString msg = tdlg.m_strText;
		const int nRgb = tdlg.nRgb;

		COLORREF cref = RGB(0, 0, 0);
		switch (nRgb)
		{
		case 0:
			cref = RGB(255, 0, 0);
			break;
		case 1:
			cref = RGB(0, 255, 0);
			break;
		case 2:
			cref = RGB(0, 0, 255);
			break;
		default:
			cref = RGB(0, 0, 0);
			break;
		}
		const COLORREF color = cref;
		const auto pText = new CMyText(msg, CPoint(x, y), color);
		m_textList.AddTail(pText);
		SetModifiedFlag();
		UpdateAllViews(nullptr);
	}
	
}

void CSingleDocumentApp10Doc::RemoveTextList()
{
	POSITION pos = m_textList.GetHeadPosition();
	while (pos != nullptr)
	{
		const auto pText = dynamic_cast<CMyText*>(m_textList.GetNext(pos));
		delete pText;
	}
	m_textList.RemoveAll();
}

void CSingleDocumentApp10Doc::DeleteContents()
{
	// TODO: 在此添加专用代码和/或调用基类
	RemoveTextList();
	CDocument::DeleteContents();
}
