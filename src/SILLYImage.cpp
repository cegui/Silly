/***********************************************************************
    filename:   SILLYImage.cpp
    created:    10 Jun 2006
    author:     Olivier Delannoy 

    purpose:    Implementation of the Image class  
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

#include "SILLYImage.h"

#ifndef SILLY_OPT_INLINE
#define inline 
#include "SILLYImage.icpp"
#undef inline
#endif 
#include "SILLYImageLoader.h"
#include "SILLYImageLoaderManager.h"
#include "SILLYImageContext.h"


// Start section of namespace SILLY
namespace SILLY
{

Image::Image(DataSource& source)
    : d_imageContext(0), d_imageLoader(0), d_data(&source)
{
    ImageLoaderList::iterator iter = ImageLoaderManager::getSingleton().begin();
    for (; ! d_imageLoader && iter != ImageLoaderManager::getSingleton().end() ; ++iter)
    {
        d_imageContext = (*iter)->parseHeader(d_imageHeader, d_data);
        if (d_imageContext)
            d_imageLoader = (*iter);
    }
    assert((! d_imageLoader || d_imageContext) && "ASSERT: Internal state of image invalid");
}

} // End section of namespace SILLY 
