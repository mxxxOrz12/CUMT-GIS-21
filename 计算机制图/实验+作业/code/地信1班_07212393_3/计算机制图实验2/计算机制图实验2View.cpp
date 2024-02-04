
// 计算机制图实验2View.cpp: C计算机制图实验2View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "计算机制图实验2.h"
#endif

#include "计算机制图实验2Doc.h"
#include "计算机制图实验2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C计算机制图实验2View

IMPLEMENT_DYNCREATE(C计算机制图实验2View, CView)

BEGIN_MESSAGE_MAP(C计算机制图实验2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C计算机制图实验2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// C计算机制图实验2View 构造/析构

C计算机制图实验2View::C计算机制图实验2View() noexcept
{
	// TODO: 在此处添加构造代码

}

C计算机制图实验2View::~C计算机制图实验2View()
{
}

BOOL C计算机制图实验2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

void MidPointLine(int x0, int y0, int x1, int y1, int color, CDC* pDC)
{
	int a, b, d1, d2, d, x, y;
	if (x0 > x1 && y0 > y1)
	{
		int tmp;
		tmp = x0;
		x0 = x1;
		x1 = tmp;
		int tmp2;
		tmp2 = y0;
		y0 = y1;
		y1 = tmp2;
	}
	
    float k = (float)(y1 - y0) / (x1 - x0);
	a = y0 - y1;
	b = x1 - x0;
	if (k>=0&&k<=1)
	{
		d1 = a + a;
		d2 = a + b + a + b;
		d = a + a+b;
		x = x0;
		y = y0;
		while (x <= x1)
		{
			pDC->SetPixel(x, y, color);
			if(d < 0)
			{
				x++;
				y++;
				d += d2;
			}
			else {
				x++;
				d += d1;
			}
		}
	}
	else if (x0 == x1)
	{
		y = y0;
		while (y <= y1)
		{
			pDC->SetPixel(x0, y, color);
			y++;
		}
	}
	else if (k<0&&k>=-1)
	{
		d1 = a + a;
		d2 = a + a - b - b;
		d = a + a - b;
		x = x0;
		y = y0;
		while (x <= x1)
		{
			pDC->SetPixel(x, y, color);
			if (d < 0)
			{
				x++;
				d += d1;
			}
			else {
				x++;
				y--;
				d += d2;
			}
		}

	}
	else if (k < -1)
	{
		d1 = -b - b;
		d2 = a + a - b - b;
		d = a - b - b;
		x = x0;
		y = y0;
		while (x <= x1)
		{
			pDC->SetPixel(x, y, color);
			if (d < 0)
			{
				x++;
				y--;
				d += d2;
			}
			else {
				y--;
				d += d1;
			}
		}
	}

	else if (k > 1)
	{
		d1 = b + b;
		d2 = a + a + b + b;
		d = a + b + b;
		x = x0;
		y = y0;
		while (x <= x1)
		{
			pDC->SetPixel(x, y, color);
			if (d < 0)
			{
				y++;
				d += d1;
			}
			else {
				x++;
				y++;
				d += d2;
			}
		}
	}
}
// C计算机制图实验2View 绘图

void C计算机制图实验2View::OnDraw(CDC* pDC)
{
	C计算机制图实验2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	/*pDC->MoveTo(100, 150);
	pDC->LineTo(300, 400);

	CPen pen(PS_DASH, 4, RGB(255, 0, 0));
	pDC->SelectObject(&pen);
	pDC->MoveTo(100, 150);
	pDC->LineTo(400, 300);*/

	MidPointLine(200, 500, 800, 500,RGB(255,0,0), pDC);
	MidPointLine(500, 200, 500, 800, RGB(255, 0, 0), pDC);
	MidPointLine(800, 650, 200, 350, RGB(0, 255, 0), pDC);
	MidPointLine(650, 800, 350, 200, RGB(0, 255, 0), pDC);
	MidPointLine(200, 650, 800, 350, RGB(0, 0, 255), pDC);
	MidPointLine(350, 800, 650, 200, RGB(0, 0, 255), pDC);


	// TODO: 在此处为本机数据添加绘制代码
}


// C计算机制图实验2View 打印


void C计算机制图实验2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C计算机制图实验2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C计算机制图实验2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C计算机制图实验2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void C计算机制图实验2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C计算机制图实验2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C计算机制图实验2View 诊断

#ifdef _DEBUG
void C计算机制图实验2View::AssertValid() const
{
	CView::AssertValid();
}

void C计算机制图实验2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C计算机制图实验2Doc* C计算机制图实验2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C计算机制图实验2Doc)));
	return (C计算机制图实验2Doc*)m_pDocument;
}
#endif //_DEBUG


// C计算机制图实验2View 消息处理程序
