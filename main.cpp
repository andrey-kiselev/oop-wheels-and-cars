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
 * File:   main.cpp
 * Author: Andrey Kiselev <andrey.kiselev@oru.se>
 *
 * Created on September 13, 2017, 11:07 AM
 */

#include <cstdlib>
#include <deque>
#include <iterator>

#include "car.h"

int main(int argc, char** argv) {
    
    /* IMPORTANT NOTE: This car is declared directly and therefore will be
     * allocated in the stack segment of memory. 
     * Default Constructor */    
    Car stackCar;
    
    /* IMPORTANT NOTE: This car is declared through a pointer and therefore
     * it will be allocated on the heap segment. It is extremely important to
     * remember to delete it when it will not be needed. */
    Car * heapCar = new Car(Color::green, 800, "Volvo", 0.0, 0.0);
    
    /* This car will be created using copy constructor, because it is being 
     * copied from already existing car. */
    Car copyCar = * heapCar;
    
    /* This copyACar will be created and then the copy assignment operator will
     * be used to copy its members from stackCar. */
    Car * copyACar = new Car;
    * copyACar = stackCar;
    
    /* Move constructor is *usually* invoked when the right part is an
     * rvalue reference. But this depends on the compiler. To invoke the move
     * constructor manually, std::move function can be used. */
    Car moveCar =  std::move( * heapCar );

    /* Finally, this part invoked move assignment operator and using a 
     * previously created car as a source. */
    Car * moveACar = new Car;
    * moveACar = std::move( stackCar );

    delete heapCar;
    delete copyACar;
    delete moveACar;
    
    return 0;
}

