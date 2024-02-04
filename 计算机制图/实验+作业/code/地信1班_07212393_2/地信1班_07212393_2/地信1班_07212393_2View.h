
// 地信1班_07212393_2View.h: C地信1班072123932View 类的接口
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


class C地信1班072123932View : public CView
{
protected: // 仅从序列化创建
	C地信1班072123932View() noexcept;
	DECLARE_DYNCREATE(C地信1班072123932View)

// 特性
public:
	C地信1班072123932Doc* GetDocument() const;
	MyPoint* pChinaPts;
	MyPoint* pCityPts;
	int chinaPtsCount;
	int cityPtsCount;

// 操作
public:
	int readChinaFromFile();
	int readCityFromFile();
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C地信1班072123932View();
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
};

#ifndef _DEBUG  // 地信1班_07212393_2View.cpp 中的调试版本
inline C地信1班072123932Doc* C地信1班072123932View::GetDocument() const
   { return reinterpret_cast<C地信1班072123932Doc*>(m_pDocument); }
#endif

