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

void BlueLeft1(){
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setPose(53,-57, 90);

    chassis.moveToPose( 9.5, -48, 122, 2000, {.forwards = false, .lead = .25, .minSpeed = 100});
    pros::delay(1100);
    Mogo.set_value(true);
    pros::delay(175);
    Hook.move(-127);
    chassis.moveToPose( 53, -57.33, 90, 2000, {.lead = .25, .minSpeed = 100});
    pros::delay(1100);
    // Mogo.set_value(false);
    // pros::delay(200);
    // Mogo.set_value(true);
    Hook.move(0);
    Intake.move(-127);
    chassis.moveToPose( 67, -66, 100, 700, {.lead = .25, .minSpeed = 100});
    pros::delay(200);
    Intake.move(127);
    Hook.move(-127);
    pros::delay(1000);
    chassis.moveToPoint(64, -68, 500);
    chassis.turnToHeading(70, 500);
    chassis.moveToPose( 24, -60, 45, 2000, {.forwards = false, .lead = .25, .minSpeed = 100});
    chassis.moveToPose( 48, -48, 0, 2000, {.lead = .25, .minSpeed = 100});
    chassis.moveToPose( 55, -55, 270, 2000, {.forwards = false, .lead = .25, .minSpeed = 100});
    pros::delay(200);
    Mogo.set_value(false);
};

void BlueLeft2(){

};