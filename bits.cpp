/*
 * bits.cpp
 *
 *  Created on: Nov 28, 2015
 *      Author: acs
 */

#include "bits.h"

#include<iostream>
#include<cassert>

namespace bits {

using namespace std;

template<typename T>
T abs(T d) {
   return (d > 0) ? d : -d;
}

LedBoard::LedBoard(TypeUC x, TypeUC y) {
   dimX_ = x;
   dimY_ = y;
   y = y / 8 + 1;
   // X rows and y/8+1 cols.
   data_ = new TypeUC*[x];
   for (TypeUC i = 0; i < x; ++i) {
      *(data_ + i) = new TypeUC[y];
   }
   for (TypeUC i = 0; i < x; ++i) {
      for (TypeUC j = 0; j < y; ++j) {
         data_[i][j] = 0;
      }
   }
}

LedBoard::~LedBoard() {
   for (TypeUC i = 0; i < dimX_; ++i) {
      delete[] data_[i];
   }
   delete[] data_;
}

void LedBoard::SetBit(TypeUC x, TypeUC y) {
   TypeUC byteY = y / 8;
   TypeUC bitY = y % 8;
   data_[x][byteY] |= 1 << bitY;
}

void LedBoard::UnsetBit(TypeUC x, TypeUC y) {
   TypeUC byteY = y / 8;
   TypeUC bitY = y % 8;
   data_[x][byteY] &= (~1 << bitY);
}

void LedBoard::Reset() {
   for (TypeUC i = 0; i < dimX_; ++i) {
      for (TypeUC j = 0; j < dimY_; ++j) {
         UnsetBit(i, j);
      }
   }
}

bool LedBoard::ReadBit(TypeUC x, TypeUC y) {
   TypeUC byteY = y / 8;
   TypeUC bitY = y % 8;
   return (data_[x][byteY] >> bitY) & 1;
}

void LedBoard::PrintScreen() {
   for (TypeUC x = 0; x < dimX_; ++x) {
      for (TypeUC y = 0; y < dimY_; ++y) {
         cout << ReadBit(x, y);
      }
      cout << endl;
   }
}

void LedBoard::DrawLine(TypeUC x1, TypeUC y1, TypeUC x2, TypeUC y2) {
   // Prevent airthmetic exception for slope = infinite.
   int x = x1, y = y1, diff = 0;
   int deltaY = (y2 > y1) ? 1 : -1;
   if (x2 == x1) {
      while (abs((int) (y2 - y1)) > diff) {
         SetBit(x, y);
         ++diff;
         y += deltaY;
      }
      return;
   }
   float m = (y2 - y1) / (x2 - x1);
   m = abs(m);
   int deltaX = (x2 > x1) ? 1 : -1;
   deltaY = (y2 > y1) ? m : -m;
   x = x1, y = y1, diff = 0;
   while (abs((int) (x2 - x1)) >= diff) {
      SetBit(x, y);
      y += deltaY;
      x += deltaX;
      ++diff;
   }
}

void LedBoard::DrawRect(TypeUC x1, TypeUC y1, TypeUC x2, TypeUC y2) {
   DrawLine(x1, y1, x1, y2);
   DrawLine(x1, y2, x2, y2);
   DrawLine(x2, y2, x2, y1);
   DrawLine(x2, y1, x1, y1);
}
}

