/***********************************************************************
    filename:   SILLYPNGImageLoader.cpp
    created:    11 Jun 2006
    author:     Olivier Delannoy 

    purpose:    Definition of the PNGImageLoader methods  
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
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "loaders/SILLYPNGImageLoader.h"

#ifndef SILLY_OPT_INLINE
#define inline 
#include "loaders/SILLYPNGImageLoader.icpp"
#undef inline
#endif

#include "loaders/SILLYPNGImageContext.h" 
#include <png.h>

// Start section of namespace SILLY
namespace SILLY
{

ImageContext* PNGImageContext::loadHeader(PixelFormat& format, DataSource* data)
{
    // Check PNG Header 
    if (png_sig_cmp(data->getDataPtr(), 0, 8))
    {
        return 0;
    }
    
    png_structp png_ptr = png_create_read_struct(
        PNG_LIBPNG_VER_STRING, 
        NULL, NULL, NULL);
    if (png_ptr == 0)
    {
        return 0;
    }
    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (info_ptr == 0)
    {
        png_destroy_read_struct(&png_ptr, NULL, NULL);
        return 0;
    }
    if (setjmp(png_jmpbuf(png_ptr)))
    {
        png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
        return 0;
    }
    
    // Set error function
    // 0, error, warning
    png_set_error_fn(png_ptr, 0, 0, 0);
    //We might need a change here 
    //DataSource does not maintains any internal state about the progression
    //of the reading 
    // TODO create a simple object around DataSource*
    png_set_read_fn(png_ptr, data, data_read_function);

    png_set_sib_bytes(png_ptr, 8);
    
    png_set_read_fn(png_ptr, 

    


    PNGImageContext* result = new PNGImageContext(
    
    
    
    
}

 

} // End section of namespace SILLY 
