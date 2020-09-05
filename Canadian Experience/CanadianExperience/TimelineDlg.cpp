/**
 * \file TimelineDlg.cpp
 *
 * \author funakoshi Silva
 */



#include "pch.h"
#include "CanadianExperience.h"
#include "TimelineDlg.h"



IMPLEMENT_DYNAMIC(CTimelineDlg, CDialog)

/**
 * Construtor
 * \param pParent Parent window (?)
 */
CTimelineDlg::CTimelineDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_TIMELINEDLG, pParent)
	, mNumFrames(0)
	, mFrameRate(0)
{

}

/**
 * Destructor
 */
CTimelineDlg::~CTimelineDlg()
{
}


/**
 * Exchanges data
 * \param pDX data exchange pointer
 */
void CTimelineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NUMFRAMES, mNumFrames);
	DDV_MinMaxInt(pDX, mNumFrames, 10, 10000);
	DDX_Text(pDX, IDC_FRAMERATE, mFrameRate);
	DDV_MinMaxInt(pDX, mFrameRate, 1, 60);
}

BEGIN_MESSAGE_MAP(CTimelineDlg, CDialog)
END_MESSAGE_MAP()

// CTimelineDlg message handlers


/**
* Pass a timeline object to this dialog box class.
* \param timeline The timeline object.
*/
void CTimelineDlg::SetTimeline(CTimeline *timeline)
{
	mTimeline = timeline;
	mNumFrames = mTimeline->GetNumFrames();
	mFrameRate = mTimeline->GetFrameRate();
}

/** Transfer dialog values to the Timeline object
*/
void CTimelineDlg::Take()
{
	mTimeline->SetNumFrames(mNumFrames);
	mTimeline->SetFrameRate(mFrameRate);
}
