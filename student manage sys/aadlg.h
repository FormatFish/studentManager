#if !defined(AFX_AADLG_H__F2FC5886_B738_41B5_AC31_E386BC8734C7__INCLUDED_)
#define AFX_AADLG_H__F2FC5886_B738_41B5_AC31_E386BC8734C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// aadlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Caadlg dialog

class Caadlg : public CDialog
{
// Construction
public:
	Caadlg(CWnd* pParent = NULL);   // standard constructor
    
// Dialog Data
	//{{AFX_DATA(Caadlg)
	enum { IDD = IDD_DIALOG1 };
	CListCtrl	m_listctrl;	
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Caadlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Caadlg)
	afx_msg void OnButton1();
	afx_msg void OnChangeEdit2();
	afx_msg void OnFind();
	afx_msg void OnExit2();
	afx_msg void OnOpenfile();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AADLG_H__F2FC5886_B738_41B5_AC31_E386BC8734C7__INCLUDED_)
