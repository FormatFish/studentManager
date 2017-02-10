// aadlg.cpp : implementation file
//

#include "stdafx.h"
#include "登陆界面.h"
#include "aadlg.h"

int Colum = 0;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Caadlg dialog


Caadlg::Caadlg(CWnd* pParent /*=NULL*/)
	: CDialog(Caadlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(Caadlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Caadlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Caadlg)
	DDX_Control(pDX, IDC_LIST1, m_listctrl);  //将IDC_LSIT1和m_listctrl相关联
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Caadlg, CDialog)           //这是系统要响应的消息，可以用ctrl+w来查找
	//{{AFX_MSG_MAP(Caadlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_EN_CHANGE(IDC_EDIT2, OnChangeEdit2)
	ON_BN_CLICKED(IDC_Find, OnFind)
	ON_BN_CLICKED(IDC_EXIT2, OnExit2)
	ON_BN_CLICKED(IDC_OPENFILE, OnOpenfile)
	ON_WM_TIMER()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Caadlg message handlers

void Caadlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	
}

void Caadlg::OnChangeEdit2() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

/*void Caadlg::OnChangeEditTime() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}*/

void Caadlg::OnFind()   //查询按钮的实现
{
	int nItemCount = m_listctrl.GetItemCount();
	if (nItemCount < 1)
	{
		MessageBox("请先打开文件！","提示",MB_OK);
		return;
	}
   
	TCHAR Find[256];
	ZeroMemory(&Find,sizeof(Find));
    
	TCHAR ListString[256];
	ZeroMemory(&ListString,sizeof(ListString));
	lstrcpy(ListString,TEXT("*************"));

	TCHAR ListText[256];
	ZeroMemory(&ListText,sizeof(ListText));

	TCHAR Student[256];
	ZeroMemory(&Student,sizeof(Student));

	TCHAR Search[256];
	ZeroMemory(&Search,sizeof(Search));
	GetDlgItemText(IDC_Search,Search,sizeof(Search));

	if(!lstrlen(Search))
	{
		MessageBox("查询学号不能为空！","提示",MB_OK);
		return;
	}

	for(int k=0;k<nItemCount;k++)
	{
         m_listctrl.GetItemText(k,1,Find,sizeof(Find)/sizeof(TCHAR));

		 if(!lstrcmp(Find,Search))
		 {
			 MessageBox("信息存在！","提示",MB_OK);
			 for(int j=0;j<5;j++)
			 {
				 m_listctrl.GetItemText(k,j,ListText,sizeof(ListText)/sizeof(TCHAR));
                 if (j ==0)
				 {
					 lstrcpy(Student,TEXT("姓名： "));
				 }

				 if (j ==1)
				 {
					 lstrcpy(Student,TEXT("学号： "));
				 }

				 if (j ==2)
				 {
					 lstrcpy(Student,TEXT("出生年月： "));
				 }

				 if (j ==3)
				 {
					 lstrcpy(Student,TEXT("性别： "));
				 }

				 if (j ==4)
				 {
					 lstrcpy(Student,TEXT("联系方式： "));
				 }
                 lstrcat(ListString,TEXT("\n\n"));
			     lstrcat(ListString,Student);
			     lstrcat(ListString,ListText);
				 
			 }
			 MessageBox(ListString,"详细信息",MB_OK);  //通过MessageBox()的方式将所查找到的信息显示出来
			 break;
		 }
	}


	// TODO: Add your control notification handler code here
	
}

void Caadlg::OnExit2() 
{
	EndDialog(0);    //退出对话框
	// TODO: Add your control notification handler code here
	
}

void Caadlg::OnOpenfile()  //打开文件
{
    OPENFILENAME ofn;
	char szFile[MAX_PATH];
	ZeroMemory(&ofn,sizeof(ofn));//用memset给结构体清零
	//ZeroMemory是memset取0的特值
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = TEXT('\0');
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = TEXT("所有文件(*.*)\0*.*\0文本文件(*.txt)\0*.TXT\0文档文件(*.doc)\0*.doc\0");
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.hwndOwner = NULL;
	ofn.Flags = OFN_EXPLORER|OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST;//OFN_ALLOWMULTISELECT表示能选择多个文件
      //上面这些是为了设置打开的对话框的各种属性（可以不用管）

		if(GetOpenFileName(&ofn))//GetOpenFileName()和GetSaveFileName()是不同的概念，你可以自己试试先
	{
	
		TCHAR cName[256],cXuehao[256],cDate[256],cSex[256],cConnect[256];

		ZeroMemory(cName,sizeof(cName));
		ZeroMemory(cXuehao,sizeof(cXuehao));
		ZeroMemory(cDate,sizeof(cDate));
		ZeroMemory(cSex,sizeof(cSex));
		ZeroMemory(cConnect,sizeof(cConnect));
         
		//以下是文件操作，必须很熟悉的……查书去！！！
		FILE * fp;

		while(! (fp = fopen(ofn.lpstrFile,"r")))  //以只读的方式打开文件
		{
			int ret = MessageBox(TEXT("无法打开指定文件"),TEXT("打开错误"),MB_RETRYCANCEL|MB_ICONERROR|MB_DEFBUTTON2);

			if(IDCANCEL == ret)
			{
				return ;
			}
		}
		
		while(! feof(fp))
		{
			
			//读取文件存入缓冲区
			fgets(cName,sizeof(cName)/sizeof(TCHAR),fp);//fgets遇文件结束符号EOF或换行符'\n'读入结束
			cName[strlen(cName)-1] = TEXT('\0');//去掉换行符
			int Row = m_listctrl.InsertItem(Colum,cName);//输出姓名
			
			

			fgets(cXuehao,sizeof(cXuehao)/sizeof(TCHAR),fp);
			cXuehao[strlen(cXuehao)-1] = TEXT('\0');
			
			m_listctrl.SetItemText(Row,1,cXuehao);//输出学号


			fgets(cDate,sizeof(cDate)/sizeof(TCHAR),fp);
			cDate[strlen(cDate)-1] = TEXT('\0');
			m_listctrl.SetItemText(Row,2,cDate);//输出日期


			fgets(cSex,sizeof(cSex)/sizeof(TCHAR),fp);
			cSex[strlen(cSex)-1] = TEXT('\0');
			m_listctrl.SetItemText(Row,3,cSex);//输出性别


			fgets(cConnect,sizeof(cConnect)/sizeof(TCHAR),fp);
			cConnect[strlen(cConnect)-1] = TEXT('\0');
			m_listctrl.SetItemText(Row,4,cConnect);//输出联系方式

			Colum+=1;


		}

		fclose(fp);//关闭文件

	}
	// TODO: Add your control notification handler code here
	
}

BOOL Caadlg::OnInitDialog()   //在这个类里出事对话框！
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_listctrl.InsertColumn(0,"姓名",LVCFMT_CENTER,60);
	m_listctrl.InsertColumn(1,"学号",LVCFMT_CENTER,80);
	m_listctrl.InsertColumn(2,"出生年月",LVCFMT_CENTER,80);
	m_listctrl.InsertColumn(3,"性别",LVCFMT_CENTER,80);
	m_listctrl.InsertColumn(4,"联系方式",LVCFMT_CENTER,80);
	m_listctrl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);  //这是对列表初始化并添加网格线
	SetTimer(1,1000,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Caadlg::OnTimer(UINT nIDEvent)   //这是获取当前时间，但要切记：这只能获取当前静态的时间，要想实现时间每秒变化一次，得和SetTimer()配合使用！
{
	// TODO: Add your message handler code here and/or call default
	CString str;
	CTime time;
	time = CTime::GetCurrentTime();
	str = time.Format("%H:%M:%S");
	SetDlgItemText(IDC_TIMES,str);
	CDialog::OnTimer(nIDEvent);
}

void Caadlg::OnClose()   //关闭对话框的处理处，建议用MessageBox()来体验下它的功能
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnClose();
}
