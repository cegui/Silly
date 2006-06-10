/***********************************************************************
    filename:   SILLYImage.h
    created:    10 Jun 2006
    author:     Olivier Delannoy

    purpose:    Image class definition
*************************************************************************/
/***************************************************************************
 *   Copyright (C) 2004 - 2006 Paul D Turner & The CEGUI Development Team
 *
 *   Permission is hereby granted, free of charge, to any person obtaining
 *   a copy of this software and associated documentation files (the
 *   "Software"), to deal in the Software without restriction, including
 *   without limitation the rights to use, copy, modify, merge, publish,
 *   distribute, sublicense, and/or sell copies of the Software, and to
 *   permit persons to whom the Software is furnished to do so, subject to
 *   the following conditions:
 *
 *   The above copyright notice and this permission notice shall be
 *   included in all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 *   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *   OTHER DEALINGS IN THE SOFTWARE.
 ***************************************************************************/
#ifndef _SILLYImage_h_ 
#define _SILLYImage_h_
#include "SILLYBase.h" 
#include "SILLYDataSource.h"
#include "SILLYImageLoader.h" 
// Start of section namespace SILLY 
namespace SILLY
{
class ImageContext;		// Forward declaration

  
/*! 
  \brief
    Image is the main user class of the library 
*/
class SILLY_EXPORT Image
{
public:
    /*! 
      \brief 
      Constructor 
      
      \param data the raw input containing the image 
    */
    Image(DataSource& data);
    
    ~Image();
    
    /*! 
      \brief 
      Retrieve the information concerning the image object 
      
    */
    const ImageHeader& getImageHeader();
    
    /*!
      \brief 
      Fill result with pixel of the image converted to \em resultFormat
      
      \param result the container that is going to contains the result 
      
      \param resultFormat the pixel format to be used for storing the result 
      
      \return true on success false if an error occured 
    */
    bool getPixels(RawContainer& result, PixelFormat resultFormat = PF_ORIGIN);
    
private:
    ImageHeader d_imageHeader;  //!< Store the image header 
    ImageContext* d_imageContext; //!< Store a pointer to the image context 
    ImageLoader* d_imageLoader; //!< Store a pointer to the image loader used 
    DataSource* d_data;         //!< Store a pointer to the input data 
    
    // Disabled operation
    Image(Image&);
    Image& operator=(Image&);
};

} // End of section namespace SILLY 

// Inclue inline function when needed 
#ifdef SILLY_OPT_INLINE
#include "SILLYImage.icpp"
#endif 

#endif // end of guard _SILLYImage_h_
