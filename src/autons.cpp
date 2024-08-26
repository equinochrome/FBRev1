#include "devices.h"
#include "autons.h"
#include "pros/rtos.hpp" // IWYU pragma: keep 

void test(){
    chassis.setPose(0,0,0);
    chassis.moveToPoint(0,-48,100000000);
    Mogo.set_value(true);
};

void test2(){
    chassis.setPose(0,0,0);
    
    chassis.turnToHeading(90, 100000);
};

void BlueLeft1(){
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setPose(53,-57, 90);

    chassis.moveToPose( 8.5, -48.9, 122.25, 2000, {.forwards = false, .lead = .25, .minSpeed = 100});
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
    chassis.moveToPose( 67.5, -66.5, 100, 700, {.lead = .25, .minSpeed = 100});
    Intake.move(100);
    pros::delay(700);
    Hook.move(-127);
    pros::delay(500);
    Intake.move(-127);
    pros::delay(500);
    Intake.move(127);
    pros::delay(1500);
    chassis.moveToPose( 36, -60, 90, 2000, {.forwards = false, .lead = .25, .minSpeed = 100});
    Intake.move(-127);
    chassis.moveToPose( 53, -53, 45, 1500, {.lead = .25, .minSpeed = 100});
    chassis.turnToHeading(315, 800);
    pros::delay(200);
    Mogo.set_value(false);
    Intake.move(127);
    chassis.turnToHeading(270, 800);
    chassis.moveToPose( 22, -46, 270, 1500, {.lead = .25, .maxSpeed = 100});
    chassis.turnToHeading(180, 800);
    chassis.moveToPose( 24, -28, 180, 2000, {.forwards = false, .lead = .6});
};

void BlueLeft2(){

};