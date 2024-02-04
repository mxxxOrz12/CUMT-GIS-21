
// 地信1班_07212393_2View.cpp: C地信1班072123932View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "地信1班_07212393_2.h"
#endif

#include "地信1班_07212393_2Doc.h"
#include "地信1班_07212393_2View.h"
#include<fstream>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C地信1班072123932View

IMPLEMENT_DYNCREATE(C地信1班072123932View, CView)

BEGIN_MESSAGE_MAP(C地信1班072123932View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C地信1班072123932View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_FILE_OPEN, &C地信1班072123932View::OnFileOpen)
END_MESSAGE_MAP()

// C地信1班072123932View 构造/析构

C地信1班072123932View::C地信1班072123932View() noexcept
{
	// TODO: 在此处添加构造代码
	pChinaPts = NULL;
	chinaPtsCount = 0;
	pCityPts = NULL;
	cityPtsCount = 0;
}

C地信1班072123932View::~C地信1班072123932View()
{
}

BOOL C地信1班072123932View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}
int  C地信1班072123932View::readChinaFromFile()
{
	ifstream ifle("D:\\CUMT\\GIS课程\\计算机制图\\07212393-马骁-地信1班\\code\\地信1班_07212393_5\\China.txt");
	ifle >> chinaPtsCount;
	if (pChinaPts) delete[] pChinaPts;
	pChinaPts = new MyPoint[chinaPtsCount];
	string temp;
	ifle >> temp >> temp >> temp >> temp >> temp;

	for (int i = 0; i < chinaPtsCount; i++)
	{
		ifle >> pChinaPts[i].id >> temp >> pChinaPts[i].x >> temp >> pChinaPts[i].y;
	}
	return 0;
}

int C地信1班072123932View::readCityFromFile()
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


// C地信1班072123932View 绘图

void C地信1班072123932View::OnDraw(CDC* pDC)
{
	C地信1班072123932Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CPen pen(PS_SOLID, 1, RGB(255, 0, 0)); // 创建红色实线画笔
	CBrush brush(RGB(255, 255, 255)); // 创建无填充色画刷
	pDC->SelectObject(&pen); // 选入画笔
	pDC->SelectObject(&brush); // 选入画刷
	for (int i = 0; i < chinaPtsCount - 1; i++)//绘制china
	{
		pDC->MoveTo(pChinaPts[i].x, 600 - pChinaPts[i].y);
		pDC->LineTo(pChinaPts[i + 1].x, 600 - pChinaPts[i + 1].y);
	}
	for (int i = 0; i < cityPtsCount; i++)//绘制city
	{
		pDC->Ellipse(pCityPts[i].x - 2, 600 - pCityPts[i].y - 2, pCityPts[i].x + 2, 600 - pCityPts[i].y + 2);
		////////////////////////////////////////////////////////////////////
		//////字符串类型转换，将string转为CString
		////////////////////////////////////////////////////////////////////
#ifdef _UNICODE //如果是unicode工程
		USES_CONVERSION; CString tempStr(pCityPts[i].name.c_str());
#else //如果是多字节工程
		CString ans;
		tempStr.Format("%s", pCityPts[i].name.c_str());
#endif // _UNICODE
		////////////////////////////////////////////////////////////////////
		pDC->TextOut(pCityPts[i].x + 3, 600 - pCityPts[i].y + 3, tempStr); //输出注记
	}

	// TODO: 在此处为本机数据添加绘制代码

	// TODO: 在此处为本机数据添加绘制代码
}


// C地信1班072123932View 打印


void C地信1班072123932View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C地信1班072123932View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C地信1班072123932View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C地信1班072123932View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void C地信1班072123932View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C地信1班072123932View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C地信1班072123932View 诊断

#ifdef _DEBUG
void C地信1班072123932View::AssertValid() const
{
	CView::AssertValid();
}

void C地信1班072123932View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C地信1班072123932Doc* C地信1班072123932View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C地信1班072123932Doc)));
	return (C地信1班072123932Doc*)m_pDocument;
}
#endif //_DEBUG


// C地信1班072123932View 消息处理程序


void C地信1班072123932View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	readChinaFromFile();
	readCityFromFile();

	Invalidate();
}
