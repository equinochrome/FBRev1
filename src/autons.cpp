#include "devices.h"
#include "autons.h"
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
};

void BlueLeft1(){
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = true;
int future = pros::millis() + 8000;
    chassis.setPose(53,-57, 90);
// Get mogo and drive back
    chassis.moveToPose( 9.70, -49.4, 120, 2000, {.forwards = false, .lead = .25, .minSpeed = 110});
    pros::delay(1250);
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
    pros::delay(700);
    Hook.move(-127);
    pros::delay(500);
    Intake.move(-127);
    pros::delay(500);
    Intake.move(127);
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
    chassis.moveToPose( 22, -25, 180, 2000, {.forwards = false, .lead = .6, .minSpeed = 50});
    pros::delay(720);
    // Mogo.set_value(true);
    // Intake.move(127);
    // Hook.move(-127);

};

void BlueLeft2(){
BlueTeam = true;
};