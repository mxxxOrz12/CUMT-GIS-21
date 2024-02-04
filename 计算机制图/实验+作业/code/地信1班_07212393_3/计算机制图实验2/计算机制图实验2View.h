
// 计算机制图实验2View.h: C计算机制图实验2View 类的接口
//

#pragma once


class C计算机制图实验2View : public CView
{
protected: // 仅从序列化创建
	C计算机制图实验2View() noexcept;
	DECLARE_DYNCREATE(C计算机制图实验2View)

// 特性
public:
	C计算机制图实验2Doc* GetDocument() const;

// 操作
public:

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
	virtual ~C计算机制图实验2View();
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
};

#ifndef _DEBUG  // 计算机制图实验2View.cpp 中的调试版本
inline C计算机制图实验2Doc* C计算机制图实验2View::GetDocument() const
   { return reinterpret_cast<C计算机制图实验2Doc*>(m_pDocument); }
#endif

