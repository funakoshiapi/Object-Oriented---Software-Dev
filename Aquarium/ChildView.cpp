/**
 * \file ChildView.cpp
 *
 * \author Funakoshi Silva
 */



#include "pch.h"
#include "framework.h"
#include "Step2.h"
#include "DoubleBufferDC.h"
#include "ChildView.h"
#include "Aquarium.h"
#include "FishBeta.h"
#include "Bubbles.h"
#include "Carp.h"
#include "DecorCastle.h"




#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace Gdiplus;
using namespace std;

/// Initial fish X location
const int InitialX = 200;

/// Initial fish Y location
const int InitialY = 200;

// CChildView

/**
 * Constructor
 */
CChildView::CChildView()
{
    srand((unsigned int)time(nullptr));

}

/**
 * Destructor
 */
CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_ADDFISH_BETAFISH, &CChildView::OnAddfishBetafish)
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONUP()
    ON_WM_MOUSEMOVE()
    ON_WM_ERASEBKGND()
    ON_COMMAND(ID_Menu, &CChildView::OnMenu)
    ON_COMMAND(ID_ADDFISH_CARP, &CChildView::OnAddfishCarp)
	ON_COMMAND(ID_ADDITEM_CASTLE, &CChildView::OnAdditemCastle)
    ON_COMMAND(ID_ADDITEM_SAVEAS32777, &CChildView::OnAdditemSaveas32777)
    ON_COMMAND(ID_SAVEAS_OPEN, &CChildView::OnOpen)
    ON_WM_TIMER()
    ON_COMMAND(ID_ADDITEM_SAVEAS32780, &CChildView::OnAdditemSaveas32780)
END_MESSAGE_MAP()



// CChildView message handlers

/** This function is called before the window is created.
 * \param cs A structure with the window creation parameters
 * \returns TRUE
 */

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

/** This function is called to draw in the window.
*
* This function is called in response to a drawing message
* whenever we need to redraw the window on the screen.
* It is responsible for painting the window.
*/



/**
 * This function is called to draw in the window.
 */
void CChildView::OnPaint()
{
    CPaintDC paintDC(this);     // device context for painting
    CDoubleBufferDC dc(&paintDC); // device context for painting
   
    Graphics graphics(dc.m_hDC);    // Create GDI+ graphics context

    mAquarium.OnDraw(&graphics);

    if (mFirstDraw)
    {
        mFirstDraw = false;
        SetTimer(1, FrameDuration, nullptr);

        /*
         * Initialize the elapsed time system
         */
        LARGE_INTEGER time, freq;
        QueryPerformanceCounter(&time);
        QueryPerformanceFrequency(&freq);

        mLastTime = time.QuadPart;
        mTimeFreq = double(freq.QuadPart);

        


    }

    /*
     * Compute the elapsed time since the last draw
     */
    LARGE_INTEGER time;
    QueryPerformanceCounter(&time);
    long long diff = time.QuadPart - mLastTime;
    double elapsed = double(diff) / mTimeFreq;
    mLastTime = time.QuadPart;
    mAquarium.Update(elapsed);


}



/**
 *  handler to alocate and add beta fish
 */
void CChildView::OnAddfishBetafish()
{
    auto fish = make_shared<CFishBeta>(&mAquarium);
    fish->SetLocation(InitialX, InitialY);
    mAquarium.Add(fish);
    Invalidate();
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
    mGrabbedItem = mAquarium.HitTest(point.x, point.y);
    if (mGrabbedItem != nullptr)
    {
        mAquarium.Add(mGrabbedItem);
        mAquarium.Erased(mGrabbedItem); 
    }
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
    // TODO: Add your message handler code here and/or call default

    OnMouseMove(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
    // See if an item is currently being moved by the mouse
    if (mGrabbedItem != nullptr)
    {
        // If an item is being moved, we only continue to 
        // move it while the left button is down.
        if (nFlags & MK_LBUTTON)
        {
            mGrabbedItem->SetLocation(point.x, point.y);
        }
        else
        {
            // When the left button is released, we release the
            // item.
            mGrabbedItem = nullptr;
        }

        // Force the screen to redraw
        Invalidate();
    
}

    CWnd::OnMouseMove(nFlags, point);
}

/**
 * Erase the background
 *
 * This is disabled to eliminate flicker
 * \param pDC Device context
 * \returns FALSE
 */

BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
    // TODO: Add your message handler code here and/or call default

    return FALSE;
}


// bubble handler
void CChildView::OnMenu()
{

    auto fish = make_shared<CBubbles>(&mAquarium);
    fish->SetLocation(InitialX, InitialY);
    mAquarium.Add(fish);
    Invalidate();

}

// carp handler
void CChildView::OnAddfishCarp()
{
    auto fish = make_shared<CCarp>(&mAquarium);
    fish->SetLocation(InitialX, InitialY);
    mAquarium.Add(fish);
    Invalidate();
}

//// Guilman handller
//void CChildView::OnAddfishGillman()
//{
//    auto fish = make_shared<CGilman>(&mAquarium);
//    fish->SetLocation(InitialX, InitialY);
//    mAquarium.Add(fish);
//    Invalidate();
//}

// Castle handler for menu Item
void CChildView::OnAdditemCastle()
{
    auto item = make_shared<CDecorCastle>(&mAquarium);
    item->SetLocation(InitialX, InitialY);
    mAquarium.Add(item);
    Invalidate();
}

// Save file Handler 
void CChildView::OnAdditemSaveas32777()
{

    CFileDialog dlg(false,  // false = Save dialog box
        L".aqua",           // Default file extension
        nullptr,            // Default file name (none)
        OFN_OVERWRITEPROMPT,      // Flags (warn it overwriting file)
        L"Aquarium Files (*.aqua)|*.aqua|All Files (*.*)|*.*||"); // Filter

    if (dlg.DoModal() != IDOK)
        return;

    wstring filename = dlg.GetPathName();

    mAquarium.Save(filename);
}



/**
 * This function is called when an File Open menu item is selected.
 *
 * It loads the aquarium from a file.
 */

void CChildView::OnOpen()
{
    CFileDialog dlg(true,  // true = Open dialog box
        L".aqua",           // Default file extension
        nullptr,            // Default file name (none)
        0,    // Flags
        L"Aquarium Files (*.aqua)|*.aqua|All Files (*.*)|*.*||");  // Filter
    if (dlg.DoModal() != IDOK)
        return;

    wstring filename = dlg.GetPathName();


    mAquarium.Load(filename);
    Invalidate();
}


void CChildView::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: Add your message handler code here and/or call default

    Invalidate();
    CWnd::OnTimer(nIDEvent);
}


void CChildView::OnAdditemSaveas32780()
{
    CFileDialog dlg(false,  // false = Save dialog box
        L".aqua",           // Default file extension
        nullptr,            // Default file name (none)
        OFN_OVERWRITEPROMPT,      // Flags (warn it overwriting file)
        L"Aquarium Files (*.aqua)|*.aqua|All Files (*.*)|*.*||"); // Filter

    if (dlg.DoModal() != IDOK)
        return;

    wstring filename = dlg.GetPathName();

    mAquarium.Save(filename);
}
