// GreedySnakeGUIDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GreedySnakeGUI.h"
#include "GreedySnakeGUIDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGreedySnakeGUIDlg dialog

CGreedySnakeGUIDlg::CGreedySnakeGUIDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGreedySnakeGUIDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGreedySnakeGUIDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGreedySnakeGUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGreedySnakeGUIDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGreedySnakeGUIDlg, CDialog)
	//{{AFX_MSG_MAP(CGreedySnakeGUIDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_TURNLEFT, OnTurnLeft)
	ON_BN_CLICKED(IDC_TURNRIGHT, OnTurnRight)
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CGreedySnakeGUIDlg::OnBnClickedButton1)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGreedySnakeGUIDlg message handlers

BOOL CGreedySnakeGUIDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	lastDirection=1;
	m_width=snake.getWidth();
	m_height=snake.getHeight();
	SetTimer(1,500,NULL);
	
//	SetActiveWindow();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGreedySnakeGUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGreedySnakeGUIDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{

		
	//}
	//	snake.changeDirection(LEFT);


		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGreedySnakeGUIDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGreedySnakeGUIDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default

	int side = 20;
	CClientDC dc(this);
	CBrush brushSpace(RGB(255,0,0));
	CBrush brushSnake(RGB(0,255,0));
	CBrush brushWall(RGB(0,0,0));
	CBrush brushNut(RGB(255,255,0));
	
	if(!snake.moveForward())
	{
		KillTimer(1);
		MessageBox("死啦!");
	}
	snake.refresh();
	for(int i=0;i<m_height;i++)
	{	
		for(int j=0;j<m_width;j++)
		{
			if(snake.block[i][j].getType()==SNAKE)
				dc.FillRect(CRect(CPoint(j*side,i*side),
				CPoint((j+1)*side-1,(i+1)*side-1)),&brushSnake);
			else if(snake.block[i][j].getType()==WALL)
				dc.FillRect(CRect(CPoint(j*side,i*side),
				CPoint((j+1)*side-1,(i+1)*side-1)),&brushWall);
			else if(snake.block[i][j].getType()==SPACE)
				dc.FillRect(CRect(CPoint(j*side,i*side),
				CPoint((j+1)*side-1,(i+1)*side-1)),&brushSpace);
			else if(snake.block[i][j].getType()==NUT)
				dc.FillRect(CRect(CPoint(j*side,i*side),
				CPoint((j+1)*side-1,(i+1)*side-1)),&brushNut);
		}
	}

	switch(face.getDirection())
	{
	case LEFT:
		OnTurnLeft();break;
	case RIGHT:
		OnTurnRight();break;
	}


//	CDialog::OnTimer(nIDEvent);
}

void CGreedySnakeGUIDlg::OnTurnRight() 
{	
	if(lastDirection==1)
		lastDirection=4;
	else
		lastDirection-=1;
	snake.changeDirection(lastDirection);	
}

void CGreedySnakeGUIDlg::OnTurnLeft() 
{
	// TODO: Add your control notification handler code here
	if(lastDirection==4)
		lastDirection=1;
	else
		lastDirection+=1;
	snake.changeDirection(lastDirection);	
}



void CGreedySnakeGUIDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
//	int x;
	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}



void CGreedySnakeGUIDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}
