

/**
 * \file ChildView.h
 *
 * \author Funakoshi Silva
 *
 * 
 */




// ChildView.h : interface of the CChildView class
//


#pragma once
#include "Aquarium.h"
#include"DecorCastle.h"


/// Frame duration in milliseconds
const int FrameDuration = 30;

// CChildView window

/**
 * The child window our program draws in.
 */

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions

private:
  /// An object that describes our aquarium
    CAquarium  mAquarium;

    /// Any item we are currently dragging
    std::shared_ptr<CItem> mGrabbedItem;

    /// True until the first time we draw
    bool mFirstDraw = true;
    long long mLastTime = 0;    ///< Last time we read the timer
    double mTimeFreq = 0;       ///< Rate the timer updates


protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()


public:
    /// handlers
	afx_msg void OnAddfishBetafish();
    /**
  * Draw this item
  * \param nFlags
  * \param point
  */
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    /// handlers
   /**
    * Draw this item
    * \param nFlags
    * \param point
    */
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    /**
    * Draw this item
    * \param nFlags
    * \param point 
    */
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    
      /**
    * Class for a fish of type Bubbles
    *\param pDC
    */
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    /// handlers
	afx_msg void OnMenu();
    /// handlers
	afx_msg void OnAddfishCarp();
    /// handlers
	afx_msg void OnAdditemCastle();
    /// handlers
	afx_msg void OnAdditemSaveas();
    /// handlers
	afx_msg void OnAdditemSaveas32777();
    /// handlers
	afx_msg void OnOpen();
    /**
    * Class for a fish of type Bubbles
    *\param nIDEvent
    */
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    /// handlers
    afx_msg void OnAdditemSaveas32780();
};
