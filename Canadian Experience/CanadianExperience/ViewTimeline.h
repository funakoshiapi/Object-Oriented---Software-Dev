/**
 * \file ViewTimeline.h
 *
 * \author Funakoshi Silva
 *
 */

#pragma once
class CMainFrame;

#include "PictureObserver.h"

/** View window for the animation timeline */
class CViewTimeline : public CScrollView, public CPictureObserver
{
	DECLARE_DYNCREATE(CViewTimeline)

public:
	/// stattic
    static const int Height = 90;     

	/**
	* Set the mainFrame pointer
	* \param mainFrame Pointer to the CMainFrame window
	*/
	void SetMainFrame(CMainFrame *mainFrame) { mMainFrame = mainFrame; }

	 /// keyframe
	/// \return
	virtual void UpdateObserver() override;

protected:
	CViewTimeline();           
	virtual ~CViewTimeline();


protected:
	/// keyframe
	/// \return
	virtual void OnDraw(CDC* pDC); 

	/// keyframe
   /// \return
	virtual void OnInitialUpdate();     

	DECLARE_MESSAGE_MAP()

public:
	/// keyframe
	/// \param pDC
	/// \return
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	 /// keyframe
	/// \return
    afx_msg void OnEditSetkeyframe();

	/// keyframe
	/// \return
    afx_msg void OnEditDeletekeyframe();
private:
	/// private
	CMainFrame  *mMainFrame = nullptr;

	/// private
	std::unique_ptr<Gdiplus::Bitmap> mPointer;

	/// private
	bool mMovingPointer = false;

public:
	
	/// \return
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	
   /// \return
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};


