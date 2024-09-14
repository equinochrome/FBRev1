#include "devices.h"
#include "autons.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/rtos.hpp" // IWYU pragma: keep 

void test(){
BlueTeam = true;
Mogo.set_value(true);
int future = pros::millis() + 3000;
while (pros::millis()< future) {
     if(color.get_hue() > 30){
        Hook.move(-127);
    } else{
        pros::delay(125);
        Hook.move(127);
        pros::delay(20);
    }
    console.println("stopped");
    pros::delay(100); 
    Hook.move(0);
 }
};


void test2(){
    Mogo.set_value(true);
    Intake.move(127);
    while(1){
    if(color.get_hue() > 30){
        Hook.move(-127);
    } else{
        pros::delay(180);
        Hook.move(127);
        pros::delay(20);
    }
    }
};

void BluePos1(){
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = true;
int future = pros::millis() + 8000;
    chassis.setPose(53,-57, 90);
// Get mogo and drive back
    chassis.moveToPose( 8.75, -48.375, 120, 2000, {.forwards = false, .lead = .25, .minSpeed = 110});
    pros::delay(1050);
    Mogo.set_value(true);
    pros::delay(175);
     chassis.moveToPose( 53, -57.33, 90, 2000, {.lead = .25, .minSpeed = 100});
    pros::delay(400);

    //Mogo Drop to correct
   //  Mogo.set_value(false);
     //pros::delay(75);
     //Mogo.set_value(true);
    
     Hook.move(-100);
    Hook.move(0);
    Intake.move(-107);
    chassis.moveToPose( 67.5, -66.5, 100, 700, {.lead = .25, .minSpeed = 100});
    Intake.move(100);
    pros::delay(1000);
    Hook.move(-100);
    pros::delay(500);
    Intake.move(-127);
    pros::delay(500);
    Intake.move(127);
    while (pros::millis()< future) {
    if(color.get_hue() > 30){
        Hook.move(-127);
    } else{
        pros::delay(185);
        Hook.move(127);
        pros::delay(20);
    }
    console.println("stopped");
    pros::delay(100);
    Hook.move(-127);
    };
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
    Hook.move(0);
    chassis.moveToPose( 22, -23, 180, 2000, {.forwards = false, .lead = .6, .minSpeed = 50});
    pros::delay(720);
    Mogo.set_value(true);
    Intake.move(127);
    Hook.move(-127);

};

void BlueNeg1(){
    BlueTeam = true;
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setPose(62,12, 0);
    chassis.moveToPose(62, -.25, 0, 2000, {.forwards = false, .lead = .6, .minSpeed = 60});
    chassis.turnToHeading(270, 800);
    chassis.moveToPose(69.5, -.25, 270, 2000, {.forwards = false, .lead = .25, .minSpeed = 60});
    pros::delay(500);
    Hook.move(-127);
    pros::delay(500);
    Hook.move(0);
    chassis.moveToPose(50, 13, 300, 4000, {.lead = .4, .minSpeed = 100});
    chassis.turnToHeading(105, 1000);
    chassis.moveToPose(34, 23.7, 100, 2000, {.forwards = false, .lead = .25, .maxSpeed = 80});
    pros::delay(1000);
    Mogo.set_value(true);
    chassis.turnToHeading(0, 800);
    Intake.move(127);
    Hook.move(-127);
    chassis.moveToPose(36, 40, 345, 2000, {.lead = .25});
    chassis.turnToHeading(270, 800);
    chassis.moveToPose(20, 45, 280, 2000, {.lead = .4});
    chassis.swingToHeading(325, lemlib::DriveSide::LEFT, 800);
    chassis.moveToPose(20, 50, 305, 2000, {.lead = .6});
    pros::delay(500);
    chassis.moveToPose(36, 23.7, 305, 2000, {.forwards = false, .lead = .25, .minSpeed = 100});
    chassis.turnToHeading(305, 800);
    pros::delay(400);
    Intake.move(0);
    Hook.move(0);
    Mogo.set_value(false);
    chassis.moveToPose(24, 12, 135, 2000, {.lead = .25, .minSpeed = 100});
    pros::delay(400);
    Lift.set_value(true);
};

void RedPos1(){

}

void RedNeg1(){
    BlueTeam = false;
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setPose(-62,10.5, 0);
    chassis.moveToPose(-62, -.25, 0, 2000, {.forwards = false, .lead = .6, .minSpeed = 60});
    chassis.turnToHeading(90, 800);
    chassis.moveToPose(-69, -.25, 90, 2000, {.forwards = false, .lead = .25, .minSpeed = 60});
    pros::delay(500);
    Hook.move(-127);
    pros::delay(500);
    Hook.move(0);
    chassis.moveToPose(-50, 13, 120, 4000, {.lead = .4, .minSpeed = 100});
    chassis.turnToHeading(285, 1000);
    chassis.moveToPose(-28, 23.7, 262, 2000, {.forwards = false, .lead = .25, .maxSpeed = 80});
    pros::delay(1000);
    Mogo.set_value(true);
    chassis.turnToHeading(0, 800);
    Intake.move(127);
    Hook.move(-127);
    chassis.moveToPose(-32, 42, -345, 2000, {.lead = .25});
    chassis.turnToHeading(-270, 800);
    chassis.moveToPose(-19, 44, -280, 2000, {.lead = .4});
    chassis.swingToHeading(-325, lemlib::DriveSide::RIGHT, 800);
    chassis.moveToPose(-14.5, 50, -305, 2000, {.lead = .6});
    pros::delay(500);
    chassis.moveToPose(-36, 23.7, -305, 2000, {.forwards = false, .lead = .25, .minSpeed = 100});
    chassis.turnToHeading(-305, 800);
    pros::delay(400);
    Intake.move(0);
    Hook.move(0);
    Mogo.set_value(false);
    chassis.moveToPose(-22, 10, 135, 2000, {.lead = .25, .minSpeed = 100});
    pros::delay(400);
    Lift.set_value(true);
}