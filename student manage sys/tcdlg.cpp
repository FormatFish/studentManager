// tcdlg.cpp : implementation file
//

#include "stdafx.h"
#include "��½����.h"
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
	DDX_Control(pDX, IDC_LIST1, m_listctrl);  //��IDC_LIST1��m_listctrl��������
	
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
	
void Ctcdlg::OnButton1() //�Ҳ�����κ���û�ã��Լ�ɾ��������
{
	// TODO: Add your control notification handler code here
    CString str;
    CFileDialog
    FileDlg(FALSE,".txt",NULL,OFN_HIDEREADONLY| OFN_OVERWRITEPROMPT);

    FileDlg.m_ofn.lpstrInitialDir="c:\\\\";

    if(FileDlg.DoModal()==IDOK)

{ 


ofstream ofs(FileDlg.GetPathName());
CStatic*pst=(CStatic*)GetDlgItem(IDC_EDIT1);//��Ŀؼ�ID
pst->GetWindowText(str);
ofs<<str;
MessageBox("����ɹ�");
}
}

void Ctcdlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) //���Ҳû�ã�����
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

BOOL Ctcdlg::OnInitDialog() //��ʼ���Ի���
{
	CDialog::OnInitDialog();

	
	// TODO: Add extra initialization here
    
    m_listctrl.InsertColumn(0,"����",LVCFMT_CENTER,60);
	m_listctrl.InsertColumn(1,"ѧ��",LVCFMT_CENTER,80);
	m_listctrl.InsertColumn(2,"��������",LVCFMT_CENTER,80);
	m_listctrl.InsertColumn(3,"�Ա�",LVCFMT_CENTER,80);
	m_listctrl.InsertColumn(4,"��ϵ��ʽ",LVCFMT_CENTER,80);
	m_listctrl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);//��ʼ���б��
    GetDlgItem(IDC_GENXIN)->EnableWindow(false);
	GetDlgItem(IDC_SAVE)->EnableWindow(false);
	GetDlgItem(IDC_DEL)->EnableWindow(false);//��������Ϊ�˽�ѧ�ű༭�򡢱��水ť��ɾ����ť�һ���������ʹ�ã�
	SetTimer(1,1000,NULL);

	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Ctcdlg::OnAdd() //���ӹ���
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
		MessageBox("��������Ϊ�գ�","����",MB_OK);
		return ;
	}

	if(!lstrlen(XUEHAO))
	{
		MessageBox("ѧ�Ų���Ϊ�գ�","����",MB_OK);
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
           MessageBox("ѧ�����ظ���","����",MB_OK);
		   return ;
		}
	}

	if(!lstrlen(Date))
	{
		MessageBox("�������²���Ϊ�գ�","����",MB_OK);
		return;
	}

	if(!lstrlen(Sex))
	{
		MessageBox("�Ա���Ϊ�գ�","����",MB_OK);
		return;
	}

	if(!lstrlen(Connect))
	{
		MessageBox("��ϵ��ʽ����Ϊ�գ�","����",MB_OK);
		return;
	}

	//��ʼ��������
    int nRow = m_listctrl.InsertItem(Col, Name);//
	m_listctrl.SetItemText(nRow,1,XUEHAO);
	m_listctrl.SetItemText(nRow,2,Date);
	m_listctrl.SetItemText(nRow,3,Sex);
	m_listctrl.SetItemText(nRow,4,Connect);
	Col+=1;

	GetDlgItem(IDC_SAVE)->EnableWindow(true);
	GetDlgItem(IDC_DEL)->EnableWindow(true);//ʹ��ɾ�������水ť������

	SetDlgItemText(IDC_NAME,"");
	SetDlgItemText(IDC_XUEHAO,"");
	SetDlgItemText(IDC_TIME,"");
	SetDlgItemText(IDC_SEX,"");
	SetDlgItemText(IDC_CONNTECT,"");
}

void Ctcdlg::OnExit()   //�˳��Ի��򣬵���������б��޸��������Ǳ��棬��Ҫ������ʾ
{
	if(Flag ==TRUE)
	{
		int Rect = MessageBox("�ļ�δ���棬�Ƿ񱣴�","��ʾ",MB_OKCANCEL);
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

void Ctcdlg::OnDel() //ɾ����
{
	Flag =TRUE;
	int nCount = m_listctrl.GetSelectionMark();
	if(nCount == -1)
	{
		MessageBox("��ѡ��Ҫɾ������Ŀ��","��ʾ",MB_OK);
		return;
	}
    else
	{
		m_listctrl.DeleteItem(nCount);
	}
	// TODO: Add your control notification handler code here
	
}

void Ctcdlg::OnSave() //�����ļ�
{
	OPENFILENAME ofn;
	char szFile[MAX_PATH];
	ZeroMemory(&ofn,sizeof(ofn));//��memset���ṹ������
	//ZeroMemory��memsetȡ0����ֵ
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = TEXT('\0');
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = TEXT("�����ļ�(*.*)\0*.*\0�ı��ļ�(*.txt)\0*.TXT\0�ĵ��ļ�(*.doc)\0*.doc\0");
	ofn.nFilterIndex = 2;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.hwndOwner = NULL;
	ofn.Flags = OFN_EXPLORER|OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST;//OFN_ALLOWMULTISELECT��ʾ��ѡ�����ļ�
//������Щ�������ùܣ�û�����˼

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
		 SaveStr[lstrlen(SaveStr)-1] = TEXT('\0') ;//�ļ����һ�в�����
		 fputs(SaveStr,fp);
		 fclose(fp);   //��Щ���ܶ���C���ļ��������Լ����Ű죬���Ͳ�˵��
							   
		
	}
	// TODO: Add your control notification handler code here
	
}

void Ctcdlg::OnTimer(UINT nIDEvent) //��ѧ����ȥ������ϸע��
{
	// TODO: Add your message handler code here and/or call default
	CString str;
	CTime time;
	time = CTime::GetCurrentTime();
	str = time.Format("%H:%M:%S");
	SetDlgItemText(IDC_TIMET,str);
	
	CDialog::OnTimer(nIDEvent);
}

void Ctcdlg::OnChange() //�޸Ĺ��ܵ�ʵ�֣����������ϸ��¹��ܣ�ԭ�������ҵ�Ҫ�޸ĵ��Ȼ��ɾ������������
{
	Flag =TRUE;
     
	TCHAR Search[256];
	ZeroMemory(&Search,sizeof(Search));
	GetDlgItemText(IDC_XUEHAOSEARCH,Search,sizeof(Search));

	TCHAR Find[256];
	ZeroMemory(&Find,sizeof(Find));

	if(!lstrlen(Search))
	{
		MessageBox("������Ҫ�޸ĵ�ѧ��","����",MB_OK);
		return;
	}

	GetDlgItem(IDC_GENXIN)->EnableWindow(true);
	int ItemCount = m_listctrl.GetItemCount();//�������

	for(int i=0; i<ItemCount; i++)
	{
		m_listctrl.GetItemText(i,1,Find,sizeof(Find)/sizeof(TCHAR));//��������

		if(! lstrcmp(Find,Search))
		{
			MessageBox("��Ϣ�ҵ��ˣ�","��ʾ",MB_OK); 
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

void Ctcdlg::OnGenxin() //���¹���
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

	int ItemCount = m_listctrl.GetItemCount();//�������
		for(int i=0; i<ItemCount; i++)
	{
		m_listctrl.GetItemText(i,1,Find,sizeof(Find)/sizeof(TCHAR));//��������

		if(! lstrcmp(Find,Search))
		{
			m_listctrl.DeleteItem(i);//ɾ��Ҫ�޸������������
			int cRow = m_listctrl.InsertItem(i,tName);
			m_listctrl.SetItemText(cRow,1,Search);
			m_listctrl.SetItemText(cRow,2,tDate);
			m_listctrl.SetItemText(cRow,3,tSex);
			m_listctrl.SetItemText(cRow,4,tConnect);
		}
	}
	// TODO: Add your control notification handler code here
	
}

void Ctcdlg::OnClose()  //�˳��Ի��򣬵���������б��޸��������Ǳ��棬��Ҫ������ʾ
{
	// TODO: Add your message handler code here and/or call default
	if(Flag ==TRUE)
	{
		int Rect = MessageBox("�ļ�δ���棬�Ƿ񱣴�","��ʾ",MB_OKCANCEL);
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
