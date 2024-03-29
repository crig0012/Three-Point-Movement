//
//  MathUtils.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-01-09.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef MATH_UTILS_H
#define MATH_UTILS_H

class MathUtils
{
public:
    //Returns a number to the nearest power of 2
    static unsigned int nextPowerOf2(unsigned int value);
    
    //Degrees and radians conversion functions
    static float radiansToDegrees(float radians);
    static float degressToRadians(float degrees);
    
    //Are 2 values within a certain range with each other
    static bool withinRange(float valueA, float valueB, float range);
    
    static float distance(float x1, float y1, float x2, float y2);
};

#endif
