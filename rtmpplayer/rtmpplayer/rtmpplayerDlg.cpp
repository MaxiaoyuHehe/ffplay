
// rtmpplayerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "rtmpplayer.h"
#include "rtmpplayerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CrtmpplayerDlg �Ի���




CrtmpplayerDlg::CrtmpplayerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CrtmpplayerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CrtmpplayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_URL, m_url);
}

BEGIN_MESSAGE_MAP(CrtmpplayerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, &CrtmpplayerDlg::OnBnClickedStart)
	ON_BN_CLICKED(IDC_PAUSE, &CrtmpplayerDlg::OnBnClickedPause)
	ON_BN_CLICKED(IDC_STOP, &CrtmpplayerDlg::OnBnClickedStop)
	ON_BN_CLICKED(IDC_ABOUT, &CrtmpplayerDlg::OnBnClickedAbout)
END_MESSAGE_MAP()


// CrtmpplayerDlg ��Ϣ�������

BOOL CrtmpplayerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_url.SetWindowText(_T("rtmp://live.hkstv.hk.lxdns.com/live/hks live=1"));

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CrtmpplayerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CrtmpplayerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CrtmpplayerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CrtmpplayerDlg::OnBnClickedStart()
{
	LPTSTR url=(LPTSTR)malloc(MAX_PATH);
	m_url.GetWindowText(url,MAX_PATH);
#ifdef _UNICODE
	USES_CONVERSION;
	ff_start(W2A(url),this->GetDlgItem(IDC_SCREEN2)->GetSafeHwnd());
	ff_start(W2A(url),this->GetDlgItem(IDC_SCREEN1)->GetSafeHwnd());
#else
	ff_start(url,this->GetDlgItem(IDC_SCREEN1)->GetSafeHwnd());
#endif
	free(url);
}


void CrtmpplayerDlg::OnBnClickedPause()
{
	ff_pause();
}


void CrtmpplayerDlg::OnBnClickedStop()
{
	ff_stop();
}


void CrtmpplayerDlg::OnBnClickedAbout()
{
	CAboutDlg dlg;
	dlg.DoModal();
}
