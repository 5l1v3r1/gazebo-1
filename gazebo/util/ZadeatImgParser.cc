/*
 * Copyright (C) 2012-2013 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>

#include "gazebo/util/ZadeatImgParser.hh"

using namespace gazebo;
using namespace util;

const int ZadeatImgParser::Width = 320;
const int ZadeatImgParser::Height = 240;
const unsigned char ZadeatImgParser::Bpp = 2;
const unsigned char ZadeatImgParser::TimestampLength = 8;

//////////////////////////////////////////////////
ZadeatImgParser::ZadeatImgParser(const std::string &_filename,
                                 const std::string &_dstDir)
    : ImgParser(_filename, _dstDir)
{
}

//////////////////////////////////////////////////
unsigned char ZadeatImgParser::GetBpp()
{
  return this->Bpp;
}

//////////////////////////////////////////////////
int ZadeatImgParser::GetHeight()
{
  return this->Height;
}

//////////////////////////////////////////////////
int ZadeatImgParser::GetWidth()
{
  return this->Width;
}

// double
static void swap8(void *v)
{
    char    in[8], out[8];
    memcpy(in, v, 8);
    out[0] = in[7];
    out[1] = in[6];
    out[2] = in[5];
    out[3] = in[4];
    out[4] = in[3];
    out[5] = in[2];
    out[6] = in[1];
    out[7] = in[0];
    memcpy(v, out, 8);
}

double ReverseDouble(const double _inDouble)
{
   double retVal;
   char *doubleToConvert = ( char* ) & _inDouble;
   char *returnDouble = ( char* ) & retVal;

   // swap the bytes into a temporary buffer
   returnDouble[0] = doubleToConvert[7];
   returnDouble[1] = doubleToConvert[6];
   returnDouble[2] = doubleToConvert[5];
   returnDouble[3] = doubleToConvert[4];
   returnDouble[4] = doubleToConvert[3];
   returnDouble[5] = doubleToConvert[2];
   returnDouble[6] = doubleToConvert[1];
   returnDouble[7] = doubleToConvert[0];

   return retVal;
}

//////////////////////////////////////////////////
void ZadeatImgParser::GetNextImage(unsigned char *_img)
{
  // Timestamp included in every image.
  unsigned char imgTimestamp[this->TimestampLength];

  double timeStamp = 0.0;

  this->logFile.read(reinterpret_cast<char *>(&timeStamp),
      this->TimestampLength);
  std::cout << "Timestamp: " << ReverseDouble(timeStamp) << std::endl;
  uint32_t size = this->GetWidth() * this->GetHeight() * this->GetBpp();
  this->logFile.read(reinterpret_cast<char *>(_img), size);
}

//////////////////////////////////////////////////
void ZadeatImgParser::ToRGB(const unsigned char *_src, unsigned char *_dst)
{
  for (int i = 0; i < GetHeight(); ++i)
    {
      for (int j = 0; j < this->GetWidth(); ++j)
      {
        int pixel = i * this->Width + j;
        int index = pixel * this->GetBpp();
        int dstIndex = pixel * 3;
        unsigned char r, g, b;
        if (pixel % 2 == 0)
        {
          this->Yuv2rgb(_src[index], _src[index + 1], _src[index + 3], r, g, b);
        }
        else
        {
          this->Yuv2rgb(_src[index], _src[index - 1], _src[index + 1], r, g, b);
        }
        _dst[dstIndex] = r;
        _dst[dstIndex + 1] = g;
        _dst[dstIndex + 2] = b;
      }
    }
}

//////////////////////////////////////////////////
void ZadeatImgParser::Yuv2rgb(const unsigned char _y, const unsigned char _u,
                              const unsigned char _v, unsigned char &_r,
                              unsigned char &_g, unsigned char &_b)
{
  int r = _y + ((1436 * (_v - 128)) >> 10);
  int g = _y - ((354 * (_u - 128) + 732 * (_v - 128)) >> 10);
  int b = _y + ((1814 * (_u - 128)) >> 10);

  r = std::min(255, std::max(0, r));
  g = std::min(255, std::max(0, g));
  b = std::min(255, std::max(0, b));

  _r = static_cast<unsigned char>(r);
  _g = static_cast<unsigned char>(g);
  _b = static_cast<unsigned char>(b);
}
