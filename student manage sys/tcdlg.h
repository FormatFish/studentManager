void InitLVColumn(HWND hwnd);
#if !defined(AFX_TCDLG_H__7F39A307_853B_459D_86C1_8CB4B0091FD9__INCLUDED_)
#define AFX_TCDLG_H__7F39A307_853B_459D_86C1_8CB4B0091FD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// tcdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Ctcdlg dialog

class Ctcdlg : public CDialog
{
// Construction
public:
	Ctcdlg(CWnd* pParent = NULL);   // standard constructor
    
// Dialog Data
	//{{AFX_DATA(Ctcdlg)
	enum { IDD = IDD_DIALOG2 };
	CListCtrl	m_listctrl;	
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Ctcdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
    HICON m_hIcon;
	// Generated message map functions
	//{{AFX_MSG(Ctcdlg)
	afx_msg void OnButton1();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnAdd();
	afx_msg void OnExit();
	afx_msg void OnDel();
	afx_msg void OnSave();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnChange();
	afx_msg void OnGenxin();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCDLG_H__7F39A307_853B_459D_86C1_8CB4B0091FD9__INCLUDED_)
