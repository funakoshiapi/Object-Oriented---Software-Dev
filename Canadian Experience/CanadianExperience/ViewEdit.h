/**
 * \file ViewEdit.h
 *
 * \author Funakoshi Silva
 *
 */

#pragma once



#include "PictureObserver.h"

class CMainFrame;
class CActor;
class CDrawable;


/**
* Set the mainFrame pointer
*/
class CViewEdit : public CScrollView, public CPictureObserver
{
	DECLARE_DYNCREATE(CViewEdit)

public:
	CViewEdit();         
	virtual ~CViewEdit();

	/**
	* Set the mainFrame pointer
	* \param mainFrame Pointer to the CMainFrame window
	* \return
	*/
	void SetMainFrame(CMainFrame *mainFrame) { mMainFrame = mainFrame; }

protected:
	/// \return
	virtual void OnDraw(CDC* pDC);
	
	/// \return
	virtual void OnInitialUpdate();     
	/// \return 
	virtual void UpdateObserver() override;

	DECLARE_MESSAGE_MAP()

public:
	/// \return
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	/// \return
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	/// \return		
    afx_msg void OnMouseMove(UINT nFlags, CPoint point); 
private:

	/// private
	Gdiplus::Point mLastMouse = Gdiplus::Point(0, 0);
	/// private
	CMainFrame  *mMainFrame = nullptr;
	/// Selected actor
	std::shared_ptr<CActor> mSelectedActor;
	/// selected drawable
	std::shared_ptr<CDrawable> mSelectedDrawable;
	
	
};


