
// 地信1班_07212393_2.h: 地信1班_07212393_2 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


// C地信1班072123932App:
// 有关此类的实现，请参阅 地信1班_07212393_2.cpp
//

class C地信1班072123932App : public CWinAppEx
{
public:
	C地信1班072123932App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C地信1班072123932App theApp;
