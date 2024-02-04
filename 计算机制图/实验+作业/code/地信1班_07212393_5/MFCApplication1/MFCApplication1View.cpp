
// MFCApplication1View.cpp: CMFCApplication1View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include<fstream>

// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_FILE_OPEN, &CMFCApplication1View::OnFileOpen)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication1View 构造/析构

CMFCApplication1View::CMFCApplication1View() noexcept
{
	// TODO: 在此处添加构造代码
	pChinaPts = NULL;
	chinaPtsCount = 0;
	pCityPts = NULL;
	cityPtsCount = 0;
	pSyms = NULL;
	numOfSyms = 0;
}
int CMFCApplication1View::readChinaFromFile()
{
	ifstream ifle("D:\\CUMT\\GIS课程\\计算机制图\\07212393-马骁-地信1班\\code\\地信1班_07212393_5\\China.txt");
	ifle >> chinaPtsCount;
	if (pChinaPts) delete[] pChinaPts;
	pChinaPts = new MyPoint[chinaPtsCount];
	string temp;
	ifle >> temp >> temp >> temp>>temp>>temp;

	for (int i = 0; i < chinaPtsCount; i++)
	{
		ifle >> pChinaPts[i].id >> temp >> pChinaPts[i].x >> temp >> pChinaPts[i].y;
	}
	return 0;
}
int CMFCApplication1View::readCityFromFile()
{
	ifstream ifile("D:\\CUMT\\GIS课程\\计算机制图\\07212393-马骁-地信1班\\code\\地信1班_07212393_5\\City.txt");
	ifile >> cityPtsCount;
	if (pCityPts) delete[] pCityPts;
	pCityPts = new MyPoint[cityPtsCount];
	string temp;
	ifile >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp;

	for (int i = 0; i < cityPtsCount; i++)
	{
		ifile >> pCityPts[i].id >> temp >> pCityPts[i].name >> temp >> pCityPts[i].rank >> temp >> pCityPts[i].x >> temp >> pCityPts[i].y;
	}
	return 0;
}
int CMFCApplication1View::readSymbolFromFile()
{
	ifstream ifile("D:\\CUMT\\GIS课程\\计算机制图\\07212393-马骁-地信1班\\code\\地信1班_07212393_5\\Symbol.txt");//将文件绑定在一个文件流上
	ifile >> numOfSyms;
	if (pSyms)
	{
		delete[] pSyms;
	}
	pSyms = new TPointSym[numOfSyms];
	string temp;
	ifile >> temp >> temp >> temp >> temp >> temp >> temp;
	for (int i = 0; i < numOfSyms; i++)
	{
		ifile >> pSyms[i].id >> pSyms[i].name >> pSyms[i].numOfPts;
		pSyms[i].xCoords = new float[pSyms[i].numOfPts];
		pSyms[i].yCoords = new float[pSyms[i].numOfPts];
		pSyms[i].tai = new int[pSyms[i].numOfPts];
		for (int j = 0; j < pSyms[i].numOfPts; j++)
		{
			ifile >> pSyms[i].xCoords[j]>> pSyms[i].yCoords[j] >> pSyms[i].tai[j];
		}
		
	}
	return 0;
}


CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View 绘图

void CMFCApplication1View::OnDraw(CDC* pDC)
{


	ASSERT_VALID(pDC);
	if (!pDC)
		return;
	// TODO: 在此处为本机数据添加绘制代码

	CPen pen(PS_SOLID, 1, RGB(255, 0, 0)); // 创建红色实线画笔
	CBrush brush(RGB(255, 255, 255)); // 创建无填充色画刷
	pDC->SelectObject(&pen); // 选入画笔
	pDC->SelectObject(&brush); // 选入画刷
	for (int i = 0; i < chinaPtsCount; i++)
	{
		if (i == 0)
		{
			pDC->MoveTo(pChinaPts[i].x, 600-pChinaPts[i].y);
		}
		else
		{
			pDC->LineTo(pChinaPts[i].x, 600-pChinaPts[i].y);
		}
	}

	// 绘制City
	for (int i = 0; i < cityPtsCount; i++)
	{
		if (pCityPts[i].rank == 1)
		{
			DrawSymbol(pCityPts[i].x - 2, 600 - pCityPts[i].y - 2, pSyms[0], 10, pDC);
		}
		else {
			DrawSymbol(pCityPts[i].x - 2, 600 - pCityPts[i].y - 2, pSyms[1], 10, pDC);
		}

		//CString tempStr(pCityPts[i].name.c_str());
		//pDC->TextOutW(pCityPts[i].x + 3, 600 - pCityPts[i].y + 3, tempStr);
	}


}


// CMFCApplication1View 打印


void CMFCApplication1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFCApplication1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication1View 诊断

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View 消息处理程序
void CMFCApplication1View::DrawSymbol(double x1, double y1, TPointSym& Syms, double scale, CDC* pDC)
{
	int lastTai = Syms.tai[0];
	for (int i = 1; i < Syms.numOfPts; i++)
	{
		if (lastTai == 1)
		{
			pDC->MoveTo(Syms.xCoords[i - 1] * scale + x1, Syms.yCoords[i - 1] * scale + y1);
			pDC->LineTo(Syms.xCoords[i] * scale + x1, Syms.yCoords[i] * scale + y1);
		}
		lastTai = Syms.tai[i];
	}
}


void CMFCApplication1View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	readChinaFromFile();
	readCityFromFile();
	readSymbolFromFile();
	Invalidate();
	
}


void CMFCApplication1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
	
}
