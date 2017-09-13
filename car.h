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
 * File:   car.h
 * Author: Andrey Kiselev <andrey.kiselev@oru.se>
 *
 * Created on September 13, 2017, 11:07 AM
 */

#ifndef CAR_H
#define CAR_H

#include <string>

#include "common.h"
#include "wheel.h"

#include <math.h>
#include <iostream>
#include <vector>

class Car {
    Color color;
    int weight;
    std::string model;
    double linearVelocity;
    double angularVelocity;

    std::vector<Wheel> * wheels;

public:

    /**
     * Default constructor. Wheels added explicitly to wheels.
     */
    Car() : color(Color::green), weight(1000), model("SAAB"), linearVelocity(0.0), angularVelocity(0.0) {

        std::cout << "Default Constructor" << std::endl;

        wheels = new std::vector<Wheel>;

        for (int i = 0; i < WHEEL_COUNT; i++) {
            this -> wheels->push_back(Wheel(WHEEL_RADIUS));
        }
    }

    /**
     * Non-default constructor.
     * @param col - Color
     * @param weight - weight in kg
     * @param model - model
     * @param lv - linear velocity
     * @param av - angular velocity
     */
    Car(Color col, int weight, std::string model, double lv, double av) : color(col), weight(weight), model(model), linearVelocity(lv), angularVelocity(av) {

        std::cout << "Non-default Constructor" << std::endl;

        wheels = new std::vector<Wheel>;

        for (int i = 0; i < WHEEL_COUNT; i++) {
            this -> wheels->push_back(Wheel(WHEEL_RADIUS));
        }
    }

    /**
     * Copy constructor
     * @param other - Car
     */
    Car(const Car& other) : color(other.color), weight(other.weight), model(other.model), linearVelocity(other.linearVelocity), angularVelocity(other.angularVelocity) {
        std::cout << "Copy Constructor" << std::endl;
        wheels = new std::vector<Wheel>;

        for (int i = 0; i < WHEEL_COUNT; i++) {
            this -> wheels->push_back(Wheel(WHEEL_RADIUS));
        }
    }

    /**
     * Copy assignment operator
     * @param other
     * @return 
     */
    Car& operator=(const Car& other) {
        this->color = other.color;
        this->weight = other.weight;
        this->model = other.model;
        this->linearVelocity = other.linearVelocity;
        this->angularVelocity = other.angularVelocity;
        std::cout << "Copy Assignment Operator" << std::endl;
        wheels = new std::vector<Wheel>;
        for (int i = 0; i < WHEEL_COUNT; i++) {
            this -> wheels->push_back(Wheel(WHEEL_RADIUS));
        }
        return *this;
    }

    /**
     * Copy constructor
     * @param other - Car
     */
    Car(Car&& other) : color(other.color), weight(other.weight), model(other.model), linearVelocity(other.linearVelocity), angularVelocity(other.angularVelocity) {
        std::cout << "Move Constructor" << std::endl;
        wheels = new std::vector<Wheel>;

        for (int i = 0; i < WHEEL_COUNT; i++) {
            this -> wheels->push_back(Wheel(WHEEL_RADIUS));
        }
    }

    /**
     * Copy assignment operator
     * @param other
     * @return 
     */
    Car& operator=(Car&& other) {
        this->color = other.color;
        this->weight = other.weight;
        this->model = other.model;
        this->linearVelocity = other.linearVelocity;
        this->angularVelocity = other.angularVelocity;
        std::cout << "Move Assignment Operator" << std::endl;
        wheels = new std::vector<Wheel>;
        for (int i = 0; i < WHEEL_COUNT; i++) {
            this -> wheels->push_back(Wheel(WHEEL_RADIUS));
        }
        return *this;
    }

    /**
     * Destructor
     */
    ~Car() {
        std::cout << "Destructor" << std::endl;
    }

    /**
     * Sets speed by setting RPM of all wheels.
     * @param speed
     * @return 
     */
    bool setSpeed(double speed) {
        if (speed > 0) {
            this -> linearVelocity = speed;
            for (Wheel wheel : * wheels) {
                wheel.setRPM(speed / (2 * M_PI * wheel.getRadius()));
            }
            return true;
        } else {
            return false;
        }
    }

    /**
     * Sets angle
     * @param angle
     * @return 
     */
    bool setTurningAngle(double angle) {
        for (Wheel wheel : * wheels) {
            wheel.setAngle(angle);
        }
        return true;
    }
};

#endif /* CAR_H */

