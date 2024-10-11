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
    pros::delay(700);
    Hook.move(0);

};

void BluePos2(){
    //Set up
int future2 = pros::millis() + 9000;
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = true;
int future = pros::millis() + 8000;
chassis.setPose(53,-57, 90);
// Get mogo and drive back
chassis.moveToPose( 9, -48.475, 120, 2000, {.forwards = false, .lead = .25, .minSpeed = 110});
pros::delay(1050);
Mogo.set_value(true);
pros::delay(175);
Hook.move(-127);
pros::delay(100);
//Drop Mogo at corner
chassis.moveToPose( 30, -55.33, 180, 1000, { .lead = .25, .minSpeed = 100});
chassis.turnToHeading(270, 750);
chassis.moveToPose( 45, -55.33, 180, 1000, {.forwards = false,.lead = .25, .minSpeed = 100});
Mogo.set_value(false);
//Get Ring Stack at Alliance Stake
Hook.move(-60);
chassis.moveToPose( 42, -15, -270, 1500, {.lead = .1, .minSpeed = 100});
pros::delay(100);
//chassis.turnToHeading(35, 1000);
chassis.moveToPoint( 50, 8, 1500, {.maxSpeed = 40});
Intake.move(127);
pros::delay(1300);
Hook.move(0);
// Get Mogo No.2 
chassis.moveToPoint(16, -28, 1500, {.forwards = false, .maxSpeed = 60});
pros::delay(1500);
Mogo.set_value(true);
//Sorting rings before scoring into Mogo no.2
Hook.move(-50);
while (pros::millis()< future2) {
    if(color.get_hue() < 30){
     pros::delay(165);
    Hook.move(127);
    } else{
        Hook.move(-127);
    }
    };
 //Turn to stack no.2 and grab blue ring
chassis.swingToHeading(205, lemlib::DriveSide::RIGHT, 1000);
chassis.turnToPoint(15, -55, 700, {.direction = lemlib::AngularDirection::CW_CLOCKWISE});
chassis.moveToPoint(15, -45, 1000, {.maxSpeed = 80});
//Ladder Touch
chassis.moveToPose(20, 0, 135, 1000);
pros::delay(1900);
Hook.move(127);
Intake.move(-127);
Lift.set_value(true);


}


void BlueNeg1(){
    BlueTeam = true;
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setPose(62,12, 0);
    chassis.moveToPose(62, -.25, 0, 2000, {.forwards = false, .lead = .1, .minSpeed = 60});
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
    chassis.moveToPose(24, 12, 135, 2000, {.lead = .25, .minSpeed = 100});
    pros::delay(400);
    Lift.set_value(true);
};

void RedPos1(){
  //Set up
int future2 = pros::millis() + 10000;
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = true;
int future = pros::millis() + 8000;
chassis.setPose(-53,-57, -90);
// Get mogo and drive back
//chassis.moveToPose( -9, -48.475, -120, 2000, {.forwards = false, .lead = .25, .minSpeed = 110});
 chassis.moveToPose( -6.8, -47.475, -120, 2000, {.forwards = false, .lead = .25});
pros::delay(1300);
Mogo.set_value(true);
pros::delay(175);
Hook.move(-127);
pros::delay(100);
//Drop Mogo at corner
chassis.moveToPose( -30, -55.33, -180, 1000, { .lead = .25, .minSpeed = 100});
chassis.turnToHeading(-270, 750);
chassis.moveToPose( -55, -55.33, -180, 1000, {.forwards = false,.lead = .25, .minSpeed = 100});
Mogo.set_value(false);
chassis.moveToPose( -40, -55.33, -180, 1000, {.lead = .25, .minSpeed = 100});
//Get Ring Stack at Alliance Stake
Hook.move(-60);
chassis.moveToPose( -42, -22, 270, 1500, {.lead = .1, .minSpeed = 100});
pros::delay(100);
chassis.moveToPoint( -50, 8, 1500, {.maxSpeed = 40});
Intake.move(127);
pros::delay(1700);
Hook.move(0);
// Get Mogo No.2 
chassis.moveToPoint(-16, -28, 1500, {.forwards = false, .maxSpeed = 60});
pros::delay(1500);
Mogo.set_value(true);
//Sorting rings before scoring into Mogo no.2
Hook.move(-50);
while (pros::millis()< future2) {
    if(color.get_hue() > 30){
     pros::delay(165);
    Hook.move(127);
    } else{
        Hook.move(-127);
    }
    };
//Turn to stack no.2 and grab blue ring
chassis.swingToHeading(-205, lemlib::DriveSide::LEFT, 700);
chassis.turnToPoint(-15, -55, 700, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
chassis.moveToPoint(-15, -45, 700, {.maxSpeed = 80});
Hook.move(-127);
//Ladder Touch
chassis.moveToPose(-20, 0, -135, 2000,{}, false);
Intake.move(-127);
Lift.set_value(true);
}


void RedNeg1(){
//SET UP
    BlueTeam = false;
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setPose(-62,10.5, 0);
    //ALLIANCE STAKE
    chassis.moveToPose(-62, -.25, 0, 2000, {.forwards = false, .lead = .6, .minSpeed = 60});
    chassis.turnToHeading(90, 800);
    chassis.moveToPose(-69, -.25, 90, 2000, {.forwards = false, .lead = .25, .minSpeed = 60});
    pros::delay(500);
    Hook.move(-127);
    pros::delay(500);
    Hook.move(0);
    chassis.moveToPose(-50, 13, 120, 4000, {.lead = .4, .minSpeed = 100});
    chassis.turnToHeading(285, 500);
    //GO TO MOGO
    chassis.moveToPose(-27, 23.7, 262, 2000, {.forwards = false, .lead = .25, .maxSpeed = 80});
    pros::delay(1000);
    Mogo.set_value(true);
    chassis.turnToHeading(0, 800);
    //GO TO MID STACK
    Intake.move(127);
    Hook.move(-127);
    chassis.moveToPose(-30, 42, -345, 2000, {.lead = .25});
    chassis.turnToHeading(-250, 800);
    chassis.moveToPose(-13, 44, -280, 2000, {.lead = .4});
    chassis.swingToHeading(-325, lemlib::DriveSide::RIGHT, 800);
    chassis.moveToPose(-12.5, 52, -295, 2000, {.lead = .6});
    pros::delay(500);
    chassis.moveToPose(-35 , 24.7, -285, 2000, {.forwards = false, .lead = .25, .minSpeed = 100});
    chassis.turnToHeading(-295, 800);
    pros::delay(400);
    //LADDER TOUCH
    Intake.move(0);
    Hook.move(0);
    chassis.moveToPose(-22, 10, 135, 2000, {.lead = .25, .minSpeed = 100});
    pros::delay(400);
    Lift.set_value(true);
}

void RedNeg2(){

}

void skills(){
    //SETUP
chassis.setPose(-63, 0, 90);
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
//Score Preload
Hook.move(-117);
pros::delay(300); 
// Move forward and get mogo on right
chassis.moveToPose(-50, 0, 90, 2000, {.minSpeed = 50}) ;
chassis.turnToHeading(0, 700);
chassis.moveToPose(-50, -30, 0, 2000, { .forwards = false, .minSpeed = 50}, false);
Mogo.set_value(true);
//Motion Chaining to get 2 rings
Intake.move(127);
chassis.moveToPose(-24, -30, 90, 1000);
 chassis.moveToPose(
        -18,
        -25,
        90,
        1000,
        {.minSpeed=72, .earlyExitRange=2}
        // a minSpeed of 72 means that the chassis will slow down as
        // it approaches the target point, but it won't come to a full stop

        // an earlyExitRange of 8 means the movement will exit 8" away from
        // the target point
    );

    // go to target position
    chassis.moveToPose(0, -60, 150, 2000, {.minSpeed = 60});
//Swing 
    chassis.swingToHeading(270, lemlib::DriveSide::LEFT, 700);
//3 Rings and mogo drop
    chassis.moveToPose(-64, -50, 270, 2000, {.minSpeed = 45}, false);
    pros::delay(500);
 
    chassis.swingToHeading(180, lemlib::DriveSide::RIGHT, 700);
    chassis.moveToPose(-48, -66,180, 1000, {.minSpeed = 50});
    chassis.moveToPose(-66, -66, 45, 2000, { .forwards = false, .minSpeed = 60}, false);
    pros::delay(700);
    Mogo.set_value(false);
    pros::delay(100);
//Mogo 2
    chassis.moveToPose(-50, -24, 0, 2000, {.minSpeed = 65});
    chassis.turnToHeading(180, 700);
    chassis.moveToPose(-54, 28, 180, 2000, { .forwards = false, .minSpeed = 50}, false);
    Mogo.set_value(true);
    Intake.move(127);
    chassis.moveToPose(-24, 23, 90, 1000,{ .lead= .5,.minSpeed=72, .earlyExitRange=2});
     // go to target position
    chassis.moveToPose(-10, 50, 45, 2000, { .lead= .5,.minSpeed = 60}, false);
    //Swing 
    chassis.swingToHeading(270, lemlib::DriveSide::RIGHT, 700);
//3 Rings and mogo drop
    chassis.moveToPose(-60, 48, 270, 2000, {.minSpeed = 45}, false);
    pros::delay(500);
    chassis.swingToHeading(0, lemlib::DriveSide::LEFT, 700);
    chassis.moveToPose(-50, 64,0, 1000, {.minSpeed = 50});
    chassis.moveToPose(-62, 62, 135, 2000, { .forwards = false, .minSpeed = 60}, false);
    pros::delay(700);
    Mogo.set_value(false);
    pros::delay(100);
// walll stake
    // pick up one red
    chassis.moveToPose(24, 44, 90, 4000, {.minSpeed = 90}, false);
    Hook.move(0);
    Mogo.set_value(true);
}