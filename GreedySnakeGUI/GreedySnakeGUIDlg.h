// GreedySnakeGUIDlg.h : header file
//

#if !defined(AFX_GREEDYSNAKEGUIDLG_H__20AF998E_7692_4997_A2BD_1523EAAB6804__INCLUDED_)
#define AFX_GREEDYSNAKEGUIDLG_H__20AF998E_7692_4997_A2BD_1523EAAB6804__INCLUDED_

#include "GreedySnake.h"	// Added by ClassView
#include "FaceDetection.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGreedySnakeGUIDlg dialog

class CGreedySnakeGUIDlg : public CDialog
{
// Construction
public:
	CGreedySnakeGUIDlg(CWnd* pParent = NULL);	// standard constructor
	FaceDetection face;
// Dialog Data
	//{{AFX_DATA(CGreedySnakeGUIDlg)
	enum { IDD = IDD_GREEDYSNAKEGUI_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGreedySnakeGUIDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGreedySnakeGUIDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnTurnLeft();
	afx_msg void OnTurnRight();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_nChar;
	int lastDirection;
	int m_height;
	int m_width;

	GreedySnake snake;

public:
	afx_msg void OnBnClickedButton1();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GREEDYSNAKEGUIDLG_H__20AF998E_7692_4997_A2BD_1523EAAB6804__INCLUDED_)
