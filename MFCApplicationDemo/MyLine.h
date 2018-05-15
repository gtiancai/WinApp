#pragma once
#include "stdafx.h"
#include <vector>
// #include <memory>

class MyLine
{
    POINT *topLeft, *bottomRight;
    // std::vector<std::shared_ptr<POINT*>> points;

public:
    MyLine() : topLeft(nullptr), bottomRight(nullptr) {}
    MyLine(POINT *topLeft, POINT *bottomRight) 
        : /*this->*/topLeft(topLeft), bottomRight(bottomRight){}
   ~ MyLine();

   void SetTopLeftPoint(const POINT& point)
   {
       // *this->topLeft = point; // null ptr exception
       if (nullptr == this->topLeft)
       {
           this->topLeft = new POINT();
       }

       this->topLeft->x = point.x;
       this->topLeft->y = point.y;
   }
   const POINT& GetTopLeftPoint() const
   {
       return *this->topLeft;
   }

   void SetBottomRightPoint(const POINT& point) 
   {
       // *this->bottomRight = point; 
       if (nullptr == this->bottomRight)
       {
           this->bottomRight = new POINT();
       }

       this->bottomRight->x = point.x;
       this->bottomRight->y = point.y;
   }

   const POINT& GetBottomRight() const
   {
       return *this->bottomRight;
   }

    void Draw(CDC & dc);
};
