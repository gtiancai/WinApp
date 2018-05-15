#include "stdafx.h"
#include "MyLine.h"
/*
MyLine::MyLine()
{
    topLeft = bottomRight = nullptr;
}*/

MyLine::~MyLine()
{
    if (nullptr != topLeft)
    {
        delete topLeft;
    }

    if (nullptr != bottomRight)
    {
        delete bottomRight;
    }

    // points: using shared_ptr
}

void MyLine::Draw(CDC& dc)
{
    /*
    ::MoveToEx(dc, topLeft->x, topLeft->y, 0);
    ::LineTo(dc, bottomRight->x, bottomRight->y);
    */
    dc.MoveTo(topLeft->x, topLeft->y);
    dc.LineTo(bottomRight->x, bottomRight->y);
}