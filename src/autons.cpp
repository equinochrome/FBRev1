#pragma once
#include "devices.h"
#include "autons.h"
#include "pros/rtos.hpp" // IWYU pragma: keep 

void test(){
    chassis.setPose(0,0,0);
    chassis.moveToPoint(0,48,100000000);
};

void test2(){
    chassis.setPose(0,0,0);
    
    chassis.turnToHeading(90, 100000);
};