/***********************************************************************
    filename:   SILLYBase.h
    created:    2006/06/10
    author:     Olivier Delannoy

    purpose:    Common header for the SILLY library 
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
#ifndef _SILLYBase_h_ 
#define _SILLYBase_h_ 
#include <vector>
#include <cassert>

#undef SILLY_OPT_INLINE 

#if defined(_WIN32) || defined(__WIN32__)
#   ifdef SILLY_EXPORTS
#       define SILLY_EXPORT __declspec(dllexport)
#   else
#       define SILLY_EXPORT __declspec(dllimport)
#   endif
#else
#   define SILLY_EXPORT
#endif

// Start of section namespace SILLY 
namespace SILLY
{
/*! 
  \brief 
  List all pixel format supported 
 */
enum PixelFormat
{
    PF_RGBA, //<! 32 bits, pixel format is 8 bits for R, G, B and A channel 
    PF_RGB,  //<! 24 bits, pixel format is 8 bits for R, G, B 
    
    PF_ORIGIN, //<! Use the format of the original image 
};
/*!
  \brief 
  Typename for a byte 
*/
typedef unsigned char byte;

/*!
  \brief 
  Typename for a byte container 
*/
typedef std::vector<byte> RawContainer;
  
} // End of section namespace SILLY 


#endif // end of guard _SILLYBase_h_
