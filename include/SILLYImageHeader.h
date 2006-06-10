/***********************************************************************
    filename:   SILLYImageHeader.h
    created:    2006/06/10
    author:     Olivier Delannoy

    purpose:    Image header declaration for the SILLY library 
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
#ifndef _SILLYImageHeader_h_ 
#define _SILLYImageHeader_h_
#include "SILLYBase.h" 

// Start of section namespace SILLY 
namespace SILLY
{

/*! 
  \brief
  ImageHeader contains all information related to the image format 
*/
  
class SILLY_EXPORT ImageHeader
{
public:
    /*! 
      \brief 
      Default constructor 
    */
    ImageHeader();
    /*!
      \brief 
      Constructor
      
      \param width the width of the image in pixels 
      
      \param height the height of the image in pixels 
      
      \param format the type of pixels 
    */
    ImageHeader(size_t width, size_t height, PixelFormat format);
    /*!
      \brief 
      Get the width of the image 
      
      \return the number of pixel per row 
    */
    size_t getWidth() const;
    /*! 
      \brief 
      Set the width of an image 
      
      \param width the number of pixel per row 
    */
    void setWidth(size_t width);
    /*! 
      \brief 
      Get the number of row of an image 
      
      \return the number of row 
    */
    size_t getHeight() const;
    /*!
      \brief 
      Set the number of row 
      
      \param height the number of row 
    */
    void setHeight(size_t height);
    /*! 
      \brief 
      Get the pixel format used internaly by the image 
      
      \return the format use by the image source 
    */
    PixelFormat getPixelFormat() const;
    /*! 
      \brief
      Set the pixel format used by image storage 
      
      \param format the pixel format used to encode the image 
    */
    void setPixelFormat(PixelFormat format);


    /*! 
      \brief 
      Test wether the header is valid or not 
      
      \return true if the header is valid, false otherwise
    */
    bool isValid() const;
    

private:
    size_t d_width;             //!< Store the width of the image 
    size_t d_height;            //!< Store the height of the image 
    PixelFormat d_pixelFormat;  //!< Store the pixel format used
};
  
  
} // End of section namespace SILLY 

// Inclue inline function when needed 
#ifdef SILLY_OPT_INLINE
#include "SILLYImageHeader.icpp"
#endif 

#endif // end of guard _SILLYBase_h_
