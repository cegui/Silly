/***********************************************************************
    filename:   SILLYTGAImageLoader.cpp
    created:    11 Jun 2006
    author:     Olivier Delannoy 

    purpose:    Load TGA Image  
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

#include "loaders/SILLYTGAImageLoader.h"

#ifndef SILLY_OPT_INLINE
#define inline 
#include "loaders/SILLYTGAImageLoader.icpp"
#undef inline
#endif 
#include "SILLYDataSource.h" 
#include "loaders/SILLYTGAImageContext.h" 

#include <cstring> 

// Start section of namespace SILLY
namespace SILLY
{

TGAImageLoader::TGAImageLoader()
{
}

TGAImageLoader::~TGAImageLoader()
{
}

#ifdef SILLY_BE
#define READ_WORD(res, start)                   \
    (res) = (*data)[(start) + 1];               \
    (res) = (res) << 8;                         \
    (res) += (*data)[(start)];
#else 
#define READ_WORD(res, start)                   \
    (res) = (*data)[(start)];                   \
    (res) = (res) << 8;                          \
    (res) += (*data)[(start) + 1];
#endif 

ImageContext* TGAImageLoader::loadHeader(size_t& width, size_t& height, PixelFormat& formatSource, DataSource* data)
{
    
    byte idLength = data->getDataPtr()[0];
    byte colorMapType = data->getDataPtr()[1];
    byte imageType = data->getDataPtr()[2];
    byte depth;
    byte description;
    if ((imageType != 2 && imageType != 10) || colorMapType)
    {
        // Unsupported image format
        return 0;
    }
    // offset: 3 Skip color map + 5 bytes 
    // offset: 8 Skip xorg / yorg + 4 bytes 
    // offset:
    READ_WORD(width, 12);
    READ_WORD(height, 14);
    depth = (*data)[16] >> 3;    
    
    // We support BGR, RGB and RGBA image at the moment 
    if (depth < 2 && depth > 4) 
    {   
        return 0;
    }
    description = (*data)[17];
    TGAImageContext* context = new TGAImageContext;
    if (context)
    {
        context->d_idLength = idLength;
        context->d_imageType = imageType;
        context->d_width = width;
        context->d_height = height;
        context->d_depth = depth;
        context->d_description = description;
    }
    return context;
}

bool TGAImageLoader::loadImageData(PixelFormat resultFormat, DataSource* data, ImageContext* context)
{
    TGAImageContext* tga = static_cast<TGAImageContext*>(context);
    size_t bpp = tga->d_depth;
    size_t w = tga->d_width;
    size_t h = tga->d_height;    
    size_t imgSize = w * h * bpp;
    size_t offset = 18 + tga->d_idLength;
    size_t numPixels = w * h;
    const byte* input = data->getDataPtr() + offset;
    // Read image data 
    
    // Uncompressed 
    if (tga->d_imageType == 2)
    {
        byte red;
        byte green;
        byte blue;
        byte alpha;
        
        switch(bpp)
        {
        case 2: //BGR
            // Todo 
            for(size_t i = 0 ; i < numPixels ; ++i)
            {
                
            }
            break;
            
        case 3: // RGB
            alpha = 0xff;
            for(size_t i = 0 ; i < numPixels ; ++i)
            {
                red = *(input++);
                green = *(input++);
                blue = *(input++);
                context->setNextPixel(red, green, blue, alpha);
            }
            break;
            
        case 4: // RGBA 
            alpha = 0xff;
            for(size_t i = 0 ; i < numPixels ; ++i)
            {
                red = *(input++);
                green = *(input++);
                blue = *(input++);
                alpha = *(input++);
                context->setNextPixel(red, green, blue, alpha);
            }
            break;
        }
    }
    else 
    {
        size_t pixelsRead = 0;
        switch(bpp)
        {
        case 2:
            
            break;
        case 3:
            
            break;
            
        case 4:
                
            break;
        }    
    }
        /*
            size_t num, i, j;
            byte header;
      
            byte onePix[4];
            byte* pixRes = tga->d_pixels;
            
            while(pixelsRead < numPixels)
            {
                header = *(dataIn++);
                
                num = 1 + (header & 0x7f);
                if (header & 0x80)
                {
                    memcpy(onePix, dataIn, bpp);
                    dataIn += bpp;
                    for (i = 0 ; i < num ; ++i)
                    {
                        memcpy(pixRes, onePix, bpp);
                        pixRes += bpp;
                    }
                }
                else 
                {
                    memcpy(pixRes, dataIn, num * bpp);
                    dataIn += num * bpp;
                    pixRes += num * bpp;
                    
                }
                pixelsRead += num;
            }
        }
        // Check wether flipping is needed or not 
        if ((0x10 & tga->d_description) == 0)
        {
            byte *p1,*p2,*tmp;	// tmp pointers
            int len = w*bpp;		// length of horizontal line in bytes
            tmp = new byte[len];
            if ( !tmp )
                return false;
            
            int y,y2;
            y2 = h-1;
            for ( y = 0; y < h>>1; y++ )
            {
                p1 = (tga->d_pixels) + len * y;
                p2 = (tga->d_pixels) + len * y2;
                memcpy( tmp, p1, len );
                memcpy( p1, p2, len );
                memcpy( p2, tmp, len );
                y2--;
            }
            delete [] tmp;
        }
    }
    // Apply pixel conversion now 
    switch(resultFormat)
    {
    case PF_RGBA:
        convertToRGBA(tga);
        break;
        
    case PF_RGB:
        convertToRGB(tga);
        break;
        
    case PF_BGR:
        convertToBGR(tga);
        break;
    case PF_ORIGIN:
        
    };
        */
    return true; 
}
/*
void TGAImageLoader::convertToBGR(RawContainer& result, TGAImageContext* context)
{
    
}
void TGAImageLoader::convertToRGB(RawContainer& result, TGAImageContext* context)
{
    switch(context->bpp)
    {
    case 2:
    case 3:
        
    case 4:
    }
    
}

void TGAImageLoader::convertToRGBA(RawContainer& result, TGAImageContext* context)
{
    
}
void TGAImageLoader::destroyContext(ImageContext* context)
{
    delete context;
}
*/
} // End section of namespace SILLY 
