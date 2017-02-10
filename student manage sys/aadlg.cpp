// aadlg.cpp : implementation file
//

#include "stdafx.h"
#include "��½����.h"
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
	DDX_Control(pDX, IDC_LIST1, m_listctrl);  //��IDC_LSIT1��m_listctrl�����
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Caadlg, CDialog)           //����ϵͳҪ��Ӧ����Ϣ��������ctrl+w������
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

void Caadlg::OnFind()   //��ѯ��ť��ʵ��
{
	int nItemCount = m_listctrl.GetItemCount();
	if (nItemCount < 1)
	{
		MessageBox("���ȴ��ļ���","��ʾ",MB_OK);
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
		MessageBox("��ѯѧ�Ų���Ϊ�գ�","��ʾ",MB_OK);
		return;
	}

	for(int k=0;k<nItemCount;k++)
	{
         m_listctrl.GetItemText(k,1,Find,sizeof(Find)/sizeof(TCHAR));

		 if(!lstrcmp(Find,Search))
		 {
			 MessageBox("��Ϣ���ڣ�","��ʾ",MB_OK);
			 for(int j=0;j<5;j++)
			 {
				 m_listctrl.GetItemText(k,j,ListText,sizeof(ListText)/sizeof(TCHAR));
                 if (j ==0)
				 {
					 lstrcpy(Student,TEXT("������ "));
				 }

				 if (j ==1)
				 {
					 lstrcpy(Student,TEXT("ѧ�ţ� "));
				 }

				 if (j ==2)
				 {
					 lstrcpy(Student,TEXT("�������£� "));
				 }

				 if (j ==3)
				 {
					 lstrcpy(Student,TEXT("�Ա� "));
				 }

				 if (j ==4)
				 {
					 lstrcpy(Student,TEXT("��ϵ��ʽ�� "));
				 }
                 lstrcat(ListString,TEXT("\n\n"));
			     lstrcat(ListString,Student);
			     lstrcat(ListString,ListText);
				 
			 }
			 MessageBox(ListString,"��ϸ��Ϣ",MB_OK);  //ͨ��MessageBox()�ķ�ʽ�������ҵ�����Ϣ��ʾ����
			 break;
		 }
	}


	// TODO: Add your control notification handler code here
	
}

void Caadlg::OnExit2() 
{
	EndDialog(0);    //�˳��Ի���
	// TODO: Add your control notification handler code here
	
}

void Caadlg::OnOpenfile()  //���ļ�
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
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.hwndOwner = NULL;
	ofn.Flags = OFN_EXPLORER|OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST;//OFN_ALLOWMULTISELECT��ʾ��ѡ�����ļ�
      //������Щ��Ϊ�����ô򿪵ĶԻ���ĸ������ԣ����Բ��ùܣ�

		if(GetOpenFileName(&ofn))//GetOpenFileName()��GetSaveFileName()�ǲ�ͬ�ĸ��������Լ�������
	{
	
		TCHAR cName[256],cXuehao[256],cDate[256],cSex[256],cConnect[256];

		ZeroMemory(cName,sizeof(cName));
		ZeroMemory(cXuehao,sizeof(cXuehao));
		ZeroMemory(cDate,sizeof(cDate));
		ZeroMemory(cSex,sizeof(cSex));
		ZeroMemory(cConnect,sizeof(cConnect));
         
		//�������ļ��������������Ϥ�ġ�������ȥ������
		FILE * fp;

		while(! (fp = fopen(ofn.lpstrFile,"r")))  //��ֻ���ķ�ʽ���ļ�
		{
			int ret = MessageBox(TEXT("�޷���ָ���ļ�"),TEXT("�򿪴���"),MB_RETRYCANCEL|MB_ICONERROR|MB_DEFBUTTON2);

			if(IDCANCEL == ret)
			{
				return ;
			}
		}
		
		while(! feof(fp))
		{
			
			//��ȡ�ļ����뻺����
			fgets(cName,sizeof(cName)/sizeof(TCHAR),fp);//fgets���ļ���������EOF���з�'\n'�������
			cName[strlen(cName)-1] = TEXT('\0');//ȥ�����з�
			int Row = m_listctrl.InsertItem(Colum,cName);//�������
			
			

			fgets(cXuehao,sizeof(cXuehao)/sizeof(TCHAR),fp);
			cXuehao[strlen(cXuehao)-1] = TEXT('\0');
			
			m_listctrl.SetItemText(Row,1,cXuehao);//���ѧ��


			fgets(cDate,sizeof(cDate)/sizeof(TCHAR),fp);
			cDate[strlen(cDate)-1] = TEXT('\0');
			m_listctrl.SetItemText(Row,2,cDate);//�������


			fgets(cSex,sizeof(cSex)/sizeof(TCHAR),fp);
			cSex[strlen(cSex)-1] = TEXT('\0');
			m_listctrl.SetItemText(Row,3,cSex);//����Ա�


			fgets(cConnect,sizeof(cConnect)/sizeof(TCHAR),fp);
			cConnect[strlen(cConnect)-1] = TEXT('\0');
			m_listctrl.SetItemText(Row,4,cConnect);//�����ϵ��ʽ

			Colum+=1;


		}

		fclose(fp);//�ر��ļ�

	}
	// TODO: Add your control notification handler code here
	
}

BOOL Caadlg::OnInitDialog()   //�����������¶Ի���
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_listctrl.InsertColumn(0,"����",LVCFMT_CENTER,60);
	m_listctrl.InsertColumn(1,"ѧ��",LVCFMT_CENTER,80);
	m_listctrl.InsertColumn(2,"��������",LVCFMT_CENTER,80);
	m_listctrl.InsertColumn(3,"�Ա�",LVCFMT_CENTER,80);
	m_listctrl.InsertColumn(4,"��ϵ��ʽ",LVCFMT_CENTER,80);
	m_listctrl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);  //���Ƕ��б��ʼ�������������
	SetTimer(1,1000,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Caadlg::OnTimer(UINT nIDEvent)   //���ǻ�ȡ��ǰʱ�䣬��Ҫ�мǣ���ֻ�ܻ�ȡ��ǰ��̬��ʱ�䣬Ҫ��ʵ��ʱ��ÿ��仯һ�Σ��ú�SetTimer()���ʹ�ã�
{
	// TODO: Add your message handler code here and/or call default
	CString str;
	CTime time;
	time = CTime::GetCurrentTime();
	str = time.Format("%H:%M:%S");
	SetDlgItemText(IDC_TIMES,str);
	CDialog::OnTimer(nIDEvent);
}

void Caadlg::OnClose()   //�رնԻ���Ĵ�����������MessageBox()�����������Ĺ���
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnClose();
}
