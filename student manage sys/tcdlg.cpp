// tcdlg.cpp : implementation file
//

#include "stdafx.h"
#include "登陆界面.h"
#include "tcdlg.h"
#include "fstream.h"
#include "commctrl.h"
#include <commdlg.h>


int Col=0;
BOOL Flag = FALSE;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
ofstream ofs("test.txt");
/////////////////////////////////////////////////////////////////////////////
// Ctcdlg dialog


Ctcdlg::Ctcdlg(CWnd* pParent /*=NULL*/)
	: CDialog(Ctcdlg::IDD, pParent)
{



	
	//{{AFX_DATA_INIT(Ctcdlg)

	
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Ctcdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);


	//{{AFX_DATA_MAP(Ctcdlg)
	DDX_Control(pDX, IDC_LIST1, m_listctrl);  //将IDC_LIST1和m_listctrl关联起来
	
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Ctcdlg, CDialog)
	//{{AFX_MSG_MAP(Ctcdlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CHANGE, OnChange)
	ON_BN_CLICKED(IDC_GENXIN, OnGenxin)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Ctcdlg message handlers
	
void Ctcdlg::OnButton1() //我擦，这段函数没用！自己删啊！！！
{
	// TODO: Add your control notification handler code here
    CString str;
    CFileDialog
    FileDlg(FALSE,".txt",NULL,OFN_HIDEREADONLY| OFN_OVERWRITEPROMPT);

    FileDlg.m_ofn.lpstrInitialDir="c:\\\\";

    if(FileDlg.DoModal()==IDOK)

{ 


ofstream ofs(FileDlg.GetPathName());
CStatic*pst=(CStatic*)GetDlgItem(IDC_EDIT1);//你的控件ID
pst->GetWindowText(str);
ofs<<str;
MessageBox("保存成功");
}
}

void Ctcdlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) //这个也没用！！！
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

BOOL Ctcdlg::OnInitDialog() //初始化对话框
{
	CDialog::OnInitDialog();

	
	// TODO: Add extra initialization here
    
    m_listctrl.InsertColumn(0,"姓名",LVCFMT_CENTER,60);
	m_listctrl.InsertColumn(1,"学号",LVCFMT_CENTER,80);
	m_listctrl.InsertColumn(2,"出生年月",LVCFMT_CENTER,80);
	m_listctrl.InsertColumn(3,"性别",LVCFMT_CENTER,80);
	m_listctrl.InsertColumn(4,"联系方式",LVCFMT_CENTER,80);
	m_listctrl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);//初始化列表框
    GetDlgItem(IDC_GENXIN)->EnableWindow(false);
	GetDlgItem(IDC_SAVE)->EnableWindow(false);
	GetDlgItem(IDC_DEL)->EnableWindow(false);//上面三句为了将学号编辑框、保存按钮、删除按钮灰化（即不能使用）
	SetTimer(1,1000,NULL);

	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Ctcdlg::OnAdd() //增加功能
{
	// TODO: Add your control notification handler code here
	Flag =TRUE;
	TCHAR Name[256];
	ZeroMemory(&Name,sizeof(Name));
	GetDlgItemText(IDC_NAME,Name,sizeof(Name));

	TCHAR XUEHAO[256];
	ZeroMemory(&XUEHAO,sizeof(XUEHAO));
	GetDlgItemText(IDC_XUEHAO,XUEHAO,sizeof(XUEHAO));

	TCHAR Date[256];
	ZeroMemory(&Date,sizeof(Date));
	GetDlgItemText(IDC_TIME,Date,sizeof(Date));

	TCHAR Sex[256];
	ZeroMemory(&Sex,sizeof(Sex));
	GetDlgItemText(IDC_SEX,Sex,sizeof(Sex));

	TCHAR Connect[256];
	ZeroMemory(&Connect,sizeof(Connect));
	GetDlgItemText(IDC_CONNTECT,Connect,sizeof(Connect));
	if (!lstrlen(Name))
	{
		MessageBox("姓名不能为空！","错误",MB_OK);
		return ;
	}

	if(!lstrlen(XUEHAO))
	{
		MessageBox("学号不能为空！","错误",MB_OK);
		return;
	}
	TCHAR kSearch[256];
	ZeroMemory(&kSearch,sizeof(kSearch));
	int kItemCount =m_listctrl.GetItemCount();
	int Num;
	for(Num = 0;Num <kItemCount;Num++)
	{
		m_listctrl.GetItemText(Num,1,kSearch,sizeof(kSearch));
		if(!lstrcmp(kSearch,XUEHAO))
		{
           MessageBox("学号有重复！","错误",MB_OK);
		   return ;
		}
	}

	if(!lstrlen(Date))
	{
		MessageBox("出生年月不能为空！","错误",MB_OK);
		return;
	}

	if(!lstrlen(Sex))
	{
		MessageBox("性别不能为空！","错误",MB_OK);
		return;
	}

	if(!lstrlen(Connect))
	{
		MessageBox("联系方式不能为空！","错误",MB_OK);
		return;
	}

	//开始插入数据
    int nRow = m_listctrl.InsertItem(Col, Name);//
	m_listctrl.SetItemText(nRow,1,XUEHAO);
	m_listctrl.SetItemText(nRow,2,Date);
	m_listctrl.SetItemText(nRow,3,Sex);
	m_listctrl.SetItemText(nRow,4,Connect);
	Col+=1;

	GetDlgItem(IDC_SAVE)->EnableWindow(true);
	GetDlgItem(IDC_DEL)->EnableWindow(true);//使得删除、保存按钮可用了

	SetDlgItemText(IDC_NAME,"");
	SetDlgItemText(IDC_XUEHAO,"");
	SetDlgItemText(IDC_TIME,"");
	SetDlgItemText(IDC_SEX,"");
	SetDlgItemText(IDC_CONNTECT,"");
}

void Ctcdlg::OnExit()   //退出对话框，但是如果你列表修改了又忘记保存，需要进行提示
{
	if(Flag ==TRUE)
	{
		int Rect = MessageBox("文件未保存，是否保存","提示",MB_OKCANCEL);
        if(Rect==IDOK)
		{
			return;
		}
		else
		{
			EndDialog(0);
		}
	}
	else
		EndDialog(0);
	// TODO: Add your control notification handler code here
	
}

void Ctcdlg::OnDel() //删除项
{
	Flag =TRUE;
	int nCount = m_listctrl.GetSelectionMark();
	if(nCount == -1)
	{
		MessageBox("请选择要删除的项目！","提示",MB_OK);
		return;
	}
    else
	{
		m_listctrl.DeleteItem(nCount);
	}
	// TODO: Add your control notification handler code here
	
}

void Ctcdlg::OnSave() //保存文件
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
	ofn.nFilterIndex = 2;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.hwndOwner = NULL;
	ofn.Flags = OFN_EXPLORER|OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST;//OFN_ALLOWMULTISELECT表示能选择多个文件
//上面这些东西不用管，没多大意思

	if (GetSaveFileName(&ofn))
	{
			FILE * fp;

		 fp = fopen(ofn.lpstrFile,"w");
         int ItemCount =m_listctrl.GetItemCount();
		 int i,j;
		 TCHAR SaveString[256];
		 TCHAR SaveStr[256];
		 ZeroMemory(&SaveStr,sizeof(SaveStr));
		 ZeroMemory(&SaveString,sizeof(SaveString));
		 for(i=0;i<ItemCount;i++)
		 {
			 for(j=0;j<5;j++)
			 {
				 m_listctrl.GetItemText(i,j,SaveString,sizeof(SaveString)/sizeof(TCHAR));
                 lstrcat(SaveStr,SaveString);
				 lstrcat(SaveStr,TEXT("\n"));
			 }
		 }
		 SaveStr[lstrlen(SaveStr)-1] = TEXT('\0') ;//文件最后一行不换行
		 fputs(SaveStr,fp);
		 fclose(fp);   //这些功能都是C的文件操作，自己看着办，俺就不说了
							   
		
	}
	// TODO: Add your control notification handler code here
	
}

void Ctcdlg::OnTimer(UINT nIDEvent) //看学生端去，有详细注释
{
	// TODO: Add your message handler code here and/or call default
	CString str;
	CTime time;
	time = CTime::GetCurrentTime();
	str = time.Format("%H:%M:%S");
	SetDlgItemText(IDC_TIMET,str);
	
	CDialog::OnTimer(nIDEvent);
}

void Ctcdlg::OnChange() //修改功能的实现，但必须配上更新功能，原理是先找到要修改的项，然后删除该项并重新添加
{
	Flag =TRUE;
     
	TCHAR Search[256];
	ZeroMemory(&Search,sizeof(Search));
	GetDlgItemText(IDC_XUEHAOSEARCH,Search,sizeof(Search));

	TCHAR Find[256];
	ZeroMemory(&Find,sizeof(Find));

	if(!lstrlen(Search))
	{
		MessageBox("请输入要修改的学号","错误",MB_OK);
		return;
	}

	GetDlgItem(IDC_GENXIN)->EnableWindow(true);
	int ItemCount = m_listctrl.GetItemCount();//表项个数

	for(int i=0; i<ItemCount; i++)
	{
		m_listctrl.GetItemText(i,1,Find,sizeof(Find)/sizeof(TCHAR));//遍历表项

		if(! lstrcmp(Find,Search))
		{
			MessageBox("信息找到了！","提示",MB_OK); 
		}
	}
    
	SetDlgItemText(IDC_XUEHAO,TEXT("*****"));
    GetDlgItem(IDC_XUEHAO)->EnableWindow(false);
	SetDlgItemText(IDC_NAME,TEXT(""));
	SetDlgItemText(IDC_TIME,TEXT(""));
	SetDlgItemText(IDC_SEX,TEXT(""));
	SetDlgItemText(IDC_CONNTECT,TEXT(""));


	// TODO: Add your control notification handler code here
	
}

void Ctcdlg::OnGenxin() //更新功能
{
	TCHAR Search[256];
	ZeroMemory(&Search,sizeof(Search));
	GetDlgItemText(IDC_XUEHAOSEARCH,Search,sizeof(Search));

	TCHAR tName[256];
	ZeroMemory(&tName,sizeof(tName));
	GetDlgItemText(IDC_NAME,tName,sizeof(tName));

	TCHAR tDate[256];
	ZeroMemory(&tDate,sizeof(tDate));
	GetDlgItemText(IDC_TIME,tDate,sizeof(tDate));

	TCHAR tSex[256];
	ZeroMemory(&tSex,sizeof(tSex));
	GetDlgItemText(IDC_SEX,tSex,sizeof(tSex));

	
	TCHAR tConnect[256];
	ZeroMemory(&tConnect,sizeof(tConnect));
	GetDlgItemText(IDC_CONNTECT,tConnect,sizeof(tConnect));

	TCHAR Find[256];
	ZeroMemory(&Find,sizeof(Find));

	int ItemCount = m_listctrl.GetItemCount();//表项个数
		for(int i=0; i<ItemCount; i++)
	{
		m_listctrl.GetItemText(i,1,Find,sizeof(Find)/sizeof(TCHAR));//遍历表项

		if(! lstrcmp(Find,Search))
		{
			m_listctrl.DeleteItem(i);//删除要修改项，并重新载入
			int cRow = m_listctrl.InsertItem(i,tName);
			m_listctrl.SetItemText(cRow,1,Search);
			m_listctrl.SetItemText(cRow,2,tDate);
			m_listctrl.SetItemText(cRow,3,tSex);
			m_listctrl.SetItemText(cRow,4,tConnect);
		}
	}
	// TODO: Add your control notification handler code here
	
}

void Ctcdlg::OnClose()  //退出对话框，但是如果你列表修改了又忘记保存，需要进行提示
{
	// TODO: Add your message handler code here and/or call default
	if(Flag ==TRUE)
	{
		int Rect = MessageBox("文件未保存，是否保存","提示",MB_OKCANCEL);
        if(Rect==IDOK)
		{
			return;
		}
		else
		{
			EndDialog(0);
		}
	}
	else
		EndDialog(0);
	CDialog::OnClose();
}
