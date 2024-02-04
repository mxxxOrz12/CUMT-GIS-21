﻿
// 计算机制图实验2.h: 计算机制图实验2 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


// C计算机制图实验2App:
// 有关此类的实现，请参阅 计算机制图实验2.cpp
//

class C计算机制图实验2App : public CWinAppEx
{
public:
	C计算机制图实验2App() noexcept;


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

extern C计算机制图实验2App theApp;
