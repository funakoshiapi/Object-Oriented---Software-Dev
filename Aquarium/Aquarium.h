/**
 * \file Aquarium.h
 *
 * \author Funakoshi Silva
 *
 * 
 */

#pragma once
#include<memory>
#include <vector>
#include "Item.h"


 /** 
  *  Responsible to the aquarim enviroment of the system
  */
class CAquarium
{
public:


   
    // contructor
    CAquarium();
    // virtual
    virtual ~CAquarium();
    // call to draw
    void OnDraw(Gdiplus::Graphics* graphics);

    /**
   *  clean up items
   * \param item 
   */
    void Erased(std::shared_ptr<CItem> item);
     
    /**
*    add shared pointers
* \param item 
*/
	void Add(std::shared_ptr<CItem> item);

    std::shared_ptr<CItem> HitTest(int x, int y);



    /// Get the width of the aquarium
 /// \returns Aquarium width
    int GetWidth() const { return mBackground->GetWidth(); }

    /// Get the height of the aquarium
    /// \returns Aquarium height
    int GetHeight() const { return mBackground->GetHeight(); }






    /**
*   afraid funtion to control gillman behaviour
* \param item
*/
    bool Afraid(CItem* item);


    /**
    *   Save the Aquarium items position
    * \param filename
    */
	void Save(const std::wstring& filename);

    void Load(const std::wstring& filename);

  

    void Clear();

	void Update(double elapsed);


private:
    std::unique_ptr<Gdiplus::Bitmap> mBackground; ///< Background image

    /// All of the items to populate our aquarium
    std::vector<std::shared_ptr<CItem> > mItems;

    void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);
};

