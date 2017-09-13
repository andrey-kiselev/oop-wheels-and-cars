/*
 * The MIT License
 *
 * Copyright 2017 Andrey Kiselev <andrey.kiselev@oru.se>.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/* 
 * File:   wheel.h
 * Author: Andrey Kiselev <andrey.kiselev@oru.se>
 *
 * Created on September 13, 2017, 11:07 AM
 */

#ifndef WHEEL_H
#define WHEEL_H

class Wheel {
    
    double radius, rpm, angle;
    
public:
    /**
     * This is a non-default constructor, which creates a Wheel with a given 
     * radius. The alternative is to create a setter for the radius, but that
     * would require creating the wheel at first and setting its radius. This 
     * constructor achieve the same effect in one step.
     * @param r - needed radius in meters
     */
    Wheel(double r): radius(r), rpm(0), angle(0) {
        // Everything is initialized in the Member Initialization List, so
        // nothing to do here.
    }
    
    /*
     * Since we defined a non-default constructor, the default constructor will
     * NOT be created automatically. But we do not need it anyway, because
     * having a wheel with undefined radius makes quite little sense.
     */
    
    /**
     * Get radius of the wheel.
     * @return radius is meters.
     */
    double getRadius(){
        return this->radius;
    }
    
    /**
     * Set wheel rotation speed in revolutions per minute (RPM).
     * @param rpm - rotation speed in RPM
     */
    void setRPM(double rpm){
        this->rpm = rpm;
    }
    
    /**
     * Get current RPM.
     * @return current RPM
     */
    double getRPM(){
        return this->rpm;
    }
    
    /**
     * Set wheel angle in degrees.
     * @param angle
     * @return false if invalid angle, true otherwise.
     */
    bool setAngle(double angle){
        if ((angle > MIN_WHEEL_ANGLE)&&(angle < MAX_WHEEL_ANGLE)){
            this->angle = angle;
            return true;
        } else {
            return false;
        }
    }
    
    /**
     * Get the current wheel angle.
     * @return angle in degrees.
     */
    double getAngle(){
        return this->angle;
    }    
};

#endif /* WHEEL_H */

