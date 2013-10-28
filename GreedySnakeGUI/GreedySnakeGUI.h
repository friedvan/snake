// GreedySnakeGUI.h : main header file for the GREEDYSNAKEGUI application
//

#if !defined(AFX_GREEDYSNAKEGUI_H__4A986C1D_F2B2_4199_B5C0_082A95C06D6E__INCLUDED_)
#define AFX_GREEDYSNAKEGUI_H__4A986C1D_F2B2_4199_B5C0_082A95C06D6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGreedySnakeGUIApp:
// See GreedySnakeGUI.cpp for the implementation of this class
//

class CGreedySnakeGUIApp : public CWinApp
{
public:
	CGreedySnakeGUIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGreedySnakeGUIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGreedySnakeGUIApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GREEDYSNAKEGUI_H__4A986C1D_F2B2_4199_B5C0_082A95C06D6E__INCLUDED_)
