
// MFCApplication1View.h: CMFCApplication1View 类的接口
//

#pragma once
#include<string>
using namespace std;
struct MyPoint
{
	int x;
	int y;
	int rank;
	string name;
	int id;
};
struct TPointSym {
	int id;
	string name;
	int numOfPts;      //点数量
	float* xCoords;
	float* yCoords;
	int* tai;
};

class CMFCApplication1View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication1View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication1View)

// 特性
public:
	CMFCApplication1Doc* GetDocument() const;
	MyPoint* pChinaPts;
	MyPoint* pCityPts;
	int chinaPtsCount;
	int cityPtsCount;
	TPointSym* pSyms;
	int numOfSyms;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	int readChinaFromFile();
	int readCityFromFile();
	int readSymbolFromFile();
	void DrawSymbol(double x1,double y1,TPointSym& Syms,double scale, CDC* pDC);


protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCApplication1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplication1View.cpp 中的调试版本
inline CMFCApplication1Doc* CMFCApplication1View::GetDocument() const
   { return reinterpret_cast<CMFCApplication1Doc*>(m_pDocument); }
#endif

