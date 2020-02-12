/**
 * \file Item.h
 *
 * \author Funakoshi Silva
 *
 * 
 */

#pragma once
#include <memory>
#include <string>
#include "XmlNode.h"


/**
 * will be used in this class                                        
 */
class CAquarium;
/**
 * Items class
 */
class CItem
{
public:

  
    
	//DESTRUCTOR
    virtual ~CItem();

    /** The X location of the item
    * \returns X location in pixels */
    double GetX() const { return mX; }

    /** The Y location of the item
    * \returns Y location in pixels */
    double GetY() const { return mY; }




    
        /**
        * Class for a fish of type Bubbles
        *\return mItemImage
        */
    int GetHeight() const{ return mItemImage->GetHeight(); }



    /**
      * Class for a fish of type Bubbles
      *\return mItemImage
      */
    int GetWidth() const { return mItemImage->GetWidth(); }


    /// Default constructor (disabled)
    CItem() = delete;

    /// Copy constructor (disabled)
    CItem(const CItem&) = delete;

    /// Get the aquarium this item is in
    /// \returns Aquarium pointer
    CAquarium* GetAquarium() { return mAquarium; }
   



    /// Set the mirror status
/// \param m New mirror flag
    void SetMirror(bool m) { mMirror = m; }




    /// Set the item location
    /// \param x X location
    /// \param y Y location
   virtual void SetLocation(double x, double y) { mX = x; mY = y; }

    /// Draw this item
  /// \param graphics Graphics device to draw on
   virtual void Draw(Gdiplus::Graphics* graphics);

   /// Handle updates for animation
/// \param elapsed The time since the last update
   virtual void Update(double elapsed) {}

   /**
   * Class for a fish of type Bubbles
   *\param node
   *\return itemNode
   */
   virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);
   /// xml save function
/// \param node
   virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

    /** Test this item to see if it has been clicked on
 * \param x X location on the aquarium to test
 * \param y Y location on the aquarium to test
 * \return true if clicked on */
    virtual bool HitTest(int x, int y) ;


    /**
    *  commnunicate to aquarium
    *\return mAquarium
    */

    CAquarium* getAquarium()
    {
        return mAquarium;
    }




protected:

    /// used to identyfy what fis is being placed in the aquarium
    /// \param aquarium 
    /// \param filename 
    CItem(CAquarium* aquarium, const std::wstring& filename);

private:

    /// The aquarium this item is contained in
    CAquarium* mAquarium;

    /// The image of this fish
    std::unique_ptr<Gdiplus::Bitmap> mItemImage;

    // Item location in the aquarium
    double  mX = 0;     ///< X location for the center of the item
    double  mY = 0;     ///< Y location for the center of the item
    bool mMirror = false;   ///< True mirrors the item image

};

