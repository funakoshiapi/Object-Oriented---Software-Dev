/**
 * \file TimelineDlg.h
 *
 * \author Funakoshi Silva
 *
 */

#pragma once

#include "Timeline.h"



/**
 * 
 * Dialog box properties
 */
class CTimelineDlg : public CDialog
{
	DECLARE_DYNAMIC(CTimelineDlg)

public:
	CTimelineDlg(CWnd* pParent = NULL);   
	virtual ~CTimelineDlg();

	void SetTimeline(CTimeline * timeline);

	void Take();

// Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIMELINEDLG };
#endif

protected:
	 /// dodataexaxhange
    /// \return
	virtual void DoDataExchange(CDataExchange* pDX);    


	DECLARE_MESSAGE_MAP()
private:

	/// private
	CTimeline* mTimeline = nullptr;

	///  frames
	int mNumFrames;

	
	

	/// frame rate
	int mFrameRate;
};
