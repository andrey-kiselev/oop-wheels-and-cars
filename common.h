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
 * File:   common.h
 * Author: Andrey Kiselev <andrey.kiselev@oru.se>
 *
 * Created on September 13, 2017, 11:07 AM
 */

#ifndef COMMON_H
#define COMMON_H

// amount of wheels on a car
#define WHEEL_COUNT 4

// wheel radius in meters
#define WHEEL_RADIUS 0.4

// min and max wheel angles
#define MIN_WHEEL_ANGLE -25
#define MAX_WHEEL_ANGLE 25

// color
enum Color {red, green, blue};

#endif /* COMMON_H */

