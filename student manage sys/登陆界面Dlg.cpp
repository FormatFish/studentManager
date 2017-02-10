// 登陆界面Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "登陆界面.h"
#include "登陆界面Dlg.h"
#include"aadlg.h"
#include"tcdlg.h"
#include "SkinH.h"
#pragma comment(lib,"SkinH.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString username="admin";
CString m_pwd="123";

CString Username="admin";
CString m_Pwd="123";



/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	;
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
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)    //在这里可以设置全局变量
{
	//{{AFX_DATA_INIT(CMyDlg)
	m_username = _T("");
	m_pwd = _T("");
	m_Username = _T("");
	m_Pwd = _T("");
	m_time = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Text(pDX, IDC_EDIT1, m_username);
	DDX_Text(pDX, IDC_EDIT2, m_pwd);
	DDX_Text(pDX, IDC_EDIT3, m_Username);
	DDX_Text(pDX, IDC_EDIT4, m_Pwd);
	//DDX_Text(pDX, IDC_TIMEX, m_time);
	//DDV_MaxChars(pDX, m_time, 20);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_WM_TIMER()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.
          	SkinH_Attach();//
	             
	SkinH_SetAero(1);
	SkinH_AdjustAero(127,0,0,4,0,0,-1,-1,-1);
	SkinH_SetMenuAlpha(191);      //为皮肤设置特效
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
	SetTimer(1,1000,NULL);  //这是关于当前时间的函数，他可以控制时间的秒数，1000的单位是ms
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyDlg::OnPaint() 
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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnButton1() 
{   int i;
	UpdateData(TRUE);
  if(m_username=="")
  {MessageBox("请输入用户名");
  return;
  }
  if(m_pwd=="")
  {MessageBox("请输入密码");
  return;
  }
if(m_username!=""&&m_pwd!="")
{
     if(m_username=="admin"&&m_pwd=="123")
   {
         AfxMessageBox("欢迎使用！");

         Ctcdlg cs;
		 cs.DoModal();
		
		 
   }
    else
   {
           AfxMessageBox("对不起，您输入的用户信息不正确，无法登录");
          
   } 
   
   

}
}

void CMyDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
		UpdateData(TRUE);
  if(m_Username=="")
  {MessageBox("请输入用户名");
  return;
  }
  if(m_Pwd=="")
  {MessageBox("请输入密码");
  return;
  }
if(m_Username!=""&&m_Pwd!="")
{
     if(m_Username=="admin"&&m_Pwd=="123")
   {
         AfxMessageBox("欢迎使用！");

         Caadlg cd;
		 cd.DoModal();
		
		 
   }
    else
   {
           AfxMessageBox("对不起，您输入的用户信息不正确，无法登录");
          
   } 
}
}

void CMyDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CString str;
	CTime time;
	time = CTime::GetCurrentTime();
	str = time.Format("%H:%M:%S");
	SetDlgItemText(IDC_TIMEX,str);
	CDialog::OnTimer(nIDEvent);
}

void CMyDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnClose();
}
