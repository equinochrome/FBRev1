#include "devices.h"
#include "autons.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/rtos.hpp" // IWYU pragma: keep 

void test(){
Arm.move_relative(825, 127);
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
int future = pros::millis() + 8500;
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
int future2 = pros::millis() + 10000;
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
Arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = true;
chassis.setPose(53,-57, 90);
// Get mogo and drive back

chassis.moveToPose( 8.75, -47.75, 120, 2000, {.forwards = false, .lead = .25, .minSpeed = 110});
pros::delay(1050);
Mogo.set_value(true);
pros::delay(175);
Hook.move(-127);
// pros::delay(100);
//Drop Mogo at corner
chassis.moveToPose( 30, -53.33, 180, 1000, { .lead = .25, .minSpeed = 100});
chassis.turnToHeading(270, 750);
chassis.moveToPose( 43, -55.33, 270, 1000, {.forwards = false,.lead = .25, .minSpeed = 100});
Mogo.set_value(false);
//Get Ring Stack at Alliance Stake
Arm.move_relative(300, 127);
Hook.move(-90);
chassis.moveToPose( 38, -17, -270, 1500, {.lead = .1, .minSpeed = 100});
pros::delay(200);
//chassis.turnToHeading(35, 1000);
chassis.moveToPoint( 52, 10, 1500, {.maxSpeed = 40});
Intake.move(127);
pros::delay(1550);
Hook.move(127);
// Get Mogo No.2 
chassis.moveToPoint(14, -32, 1500, {.forwards = false, .maxSpeed = 60});
pros::delay(1600);
Mogo.set_value(true);
//Sorting rings before scoring into Mogo no.2

 //Turn to stack no.2 and grab blue ring
Hook.move(-127);
pros::delay(400);
chassis.swingToHeading(205, lemlib::DriveSide::RIGHT, 600);
// chassis.turnToPoint(15, -55, 700, {.direction = lemlib::AngularDirection::CW_CLOCKWISE});
chassis.moveToPoint(11, -50, 1300, {.maxSpeed = 80}, false);
//Ladder Touch
chassis.moveToPose(12, -12, 0, 2500, {.minSpeed = 65});
pros::delay(1900);
Hook.move(0);
Intake.move(-127);
Lift.set_value(true);


}


void BlueNeg1(){
    BlueTeam = true;
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setPose(62,12, 0);
    chassis.moveToPose(62, 0, 0, 2000, {.forwards = false, .lead = .1, .minSpeed = 60});
    chassis.turnToHeading(270, 800);
    chassis.moveToPose(69.5, 0, 270, 2000, {.forwards = false, .lead = .25, .minSpeed = 60});
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
Arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = true;
chassis.setPose(-53,-57, -90);
// Get mogo and drive back
chassis.moveToPose( -9.55, -46.975, -120, 2000, {.forwards = false, .lead = .25, .minSpeed = 110});
pros::delay(1050);
Mogo.set_value(true);
pros::delay(175);
Hook.move(-127);
//pros::delay(100);
//Drop Mogo at corner
chassis.moveToPose( -30, -55.33, -180, 1000, { .lead = .25, .minSpeed = 100});
chassis.turnToHeading(-270, 750);
chassis.moveToPose( -45, -55.33, -270, 1000, {.forwards = false,.lead = .25, .minSpeed = 100});
Hook.move(127);
Mogo.set_value(false);
//Get Ring Stack at Alliance Stake
Arm.move_relative(300, 127);
Hook.move(-90);
Intake.move(127);
chassis.moveToPose( -43, -15, 245, 1500, {.lead = .1, .minSpeed = 100});
Intake.move(0);
pros::delay(100);
Intake.move(127);
chassis.moveToPoint( -60, 18, 2000, {.maxSpeed = 35});

pros::delay(1400);
Hook.move(127);
// Get Mogo No.2 
chassis.moveToPoint(-15, -28, 3000, {.forwards = false, .maxSpeed = 60}, false);
//Hook.move(127);
//pros::delay(1500);
Mogo.set_value(true);
//Sorting rings before scoring into Mogo no.2

 //Turn to stack no.2 and grab blue ring
pros::delay(400);
Intake.move(127);
chassis.swingToHeading(-205, lemlib::DriveSide::LEFT, 600, {.maxSpeed=90});
Hook.move(-127);
chassis.moveToPoint(-14, -51, 1300, {.maxSpeed = 80}, false);
//Ladder Touch
chassis.moveToPose(-12, -12, 0, 2500, {.minSpeed = 65});
pros::delay(1900);
Hook.move(0);
Intake.move(-127);
Lift.set_value(true);


}



void RedNeg1(){
//SET UP
    BlueTeam = false;
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setPose(-62,10.5, 0);
    //ALLIANCE STAKE
    chassis.moveToPose(-62,-1, 0, 2000, {.forwards = false, .lead = .6, .minSpeed = 60});
    chassis.turnToHeading(90, 800);
    chassis.moveToPose(-69, -1, 90, 2000, {.forwards = false, .lead = .25, .minSpeed = 60});
    pros::delay(500);
    Hook.move(-127);
    pros::delay(500);
    Hook.move(0);
    chassis.moveToPose(-50, 13, 120, 4000, {.lead = .4, .minSpeed = 100});
    chassis.turnToHeading(285, 500);
    //GO TO MOGO
    chassis.moveToPose(-23, 23.7, 262, 2000, {.forwards = false, .lead = .25, .maxSpeed = 80});
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
    chassis.turnToHeading(-295, 600);
    pros::delay(400);
    //LADDER TOUCH
    chassis.moveToPose(-18, 8, 135, 1000, {.lead = .25, .minSpeed = 100});
  
}

void RedNeg2(){
//SET UP
    BlueTeam = false;
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setPose(-62,10.5, 0);
    //ALLIANCE STAKE
    chassis.moveToPose(-62,-1, 0, 2000, {.forwards = false, .lead = .6, .minSpeed = 60});
    chassis.turnToHeading(90, 800);
    chassis.moveToPose(-69, -1, 90, 2000, {.forwards = false, .lead = .25, .minSpeed = 60});
    pros::delay(500);
    Hook.move(-127);
    pros::delay(500);
    Hook.move(0);
    chassis.moveToPose(-50, 13, 120, 4000, {.lead = .4, .minSpeed = 100});
    chassis.turnToHeading(285, 500);
    //GO TO MOGO
    chassis.moveToPose(-23, 23.7, 262, 2000, {.forwards = false, .lead = .25, .maxSpeed = 80});
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
}

void skills(){
    //SETUP
chassis.setPose(-63, 0, 90);
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
//Score Preload
Hook.move(-117);
pros::delay(300); 
// Move forward and get mogo on right
Hook.move(0);
chassis.moveToPose(-50, 0, 90, 2000, {.minSpeed = 50}) ;
chassis.turnToHeading(0, 700);
chassis.moveToPose(-50, -28, 0, 2200, { .forwards = false, .minSpeed = 50}, false);
Mogo.set_value(true);
//Motion Chaining to get 2 rings
Hook.move(-117);
Intake.move(127);
chassis.moveToPose(-24, -25, 90, 1500);
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
    chassis.moveToPose(0, -62, 150, 2000, {.minSpeed = 60});
//Swing 
    chassis.swingToHeading(270, lemlib::DriveSide::LEFT, 700);
//3 Rings and mogo drop
    chassis.moveToPose(-48, -52, 270, 2000, {.minSpeed = 45}, false);
    pros::delay(500);
    chassis.moveToPose(-62, -52, 270, 2000, {.minSpeed = 45}, false);
     chassis.moveToPose(-63, -52, 270, 2000, {.minSpeed = 45}, false);
    pros::delay(1000);
     chassis.swingToHeading(180, lemlib::DriveSide::RIGHT, 700);
    chassis.moveToPose(-51, -63,180, 1000, {.minSpeed = 50});
    pros::delay(800);
     chassis.moveToPose(-66, -66, 45, 2000, { .forwards = false, .minSpeed = 60}, false);
    pros::delay(1100);
     Hook.move(0);
    pros::delay(100);

    Mogo.set_value(false);

    pros::delay(100);
  //Mogo 2
    chassis.moveToPose(-53.5, -24, 0, 2000, {.minSpeed = 65});
      Hook.move(-127);
    chassis.turnToHeading(180, 700);
    chassis.moveToPose(-55.5, 30, 180, 2000, { .forwards = false, .minSpeed = 50}, false);
    Mogo.set_value(true);
    Intake.move(127);
      chassis.moveToPose(-24, 18, 90, 1000,{ .lead= .5,.minSpeed=72, .earlyExitRange=2});
     // go to target position
    chassis.moveToPose(-8,55, 45, 2000, { .lead= .5,.minSpeed = 60}, false);
    //Swing 
    chassis.swingToHeading(270, lemlib::DriveSide::RIGHT, 700);
//3 Rings and mogo drop
    chassis.moveToPose(-48, 48, 270, 2000, {.minSpeed = 45}, false);
    pros::delay(500);
    chassis.moveToPose(-64, 48, 270, 2000, {.minSpeed = 45}, false);
    chassis.swingToHeading(0, lemlib::DriveSide::LEFT, 700);
    chassis.moveToPose(-53, 61,0, 2000, {.minSpeed = 50});
chassis.moveToPose(-66.5, 65, 145, 2000, { .forwards = false, .minSpeed = 60}, false);
    pros::delay(1200);
    Mogo.set_value(false);
    pros::delay(100);
    // 1 red ring
    chassis.moveToPose(12, 48, 90, 2000, {.minSpeed = 90});
    chassis.moveToPose(24, 18, 90, 2000, {.minSpeed = 70});
    pros::delay(800);
    Hook.move(0);

    // BLUE MOGO PUSH
    //chassis.moveToPose(48, 18, 60, 2000, {.minSpeed = 70});
    //chassis.moveToPose(60, 58, 0, 2000, {.minSpeed = 70});
    //Intake.move(0);
    //chassis.moveToPose(38, -16, 10, 2000, { .forwards = false, .minSpeed = 50}, false);
    //Mogo.set_value(true);
    //Hook.move(-127);
    //Intake.move(127);

    chassis.turnToHeading(310, 1000);
    chassis.moveToPoint(40.5, -5, 1900, { .forwards = false, .minSpeed = 60}, false);
    Mogo.set_value(true);
    pros::delay(150);
    Hook.move(-117);
    Intake.move(127);
    pros::delay(1500);
    chassis.moveToPoint(18, -23, 2000, {.minSpeed = 75});
    chassis.moveToPose(15, -50, 135, 2000, {.minSpeed = 60}, false);
    chassis.moveToPose(34, -64, 90, 2000, {.minSpeed = 60}, false);
    pros::delay(500);
    chassis.moveToPose(9, -54, 90, 2000, {.forwards = false, .minSpeed = 60}, false);
    chassis.moveToPose(34, -52, 90, 2000, {.minSpeed = 60}, false);
    chassis.moveToPoint(18, -40, 2000, {.forwards = false, .minSpeed = 75}, false);
    pros::delay(1000);
    Mogo.set_value(false);
    pros::delay(100);
    Hook.move(127);
    Intake.move(-127);
    chassis.moveToPose(54, 24, 25, 4000, {.minSpeed = 65}, false);
    chassis.moveToPose(59, 56   , 5, 2000, {.minSpeed = 70}, false);
    pros::delay(100);
    chassis.moveToPose(50, 24, 20, 2000, {.forwards = false, .minSpeed = 75});
    pros::delay(100);
    Intake.move(127);
    Hook.move(0);
    chassis.moveToPose(43, 48, 0, 3000, {.minSpeed = 60}, false);
    pros::delay(1000);
    Mogo.set_value(true);
    chassis.moveToPoint(43, 10, 10000, {.forwards = false, .minSpeed = 100}, false);
    chassis.turnToHeading(270, 1000);
    chassis.moveToPoint(64,1.25, 1500, {.forwards=false, .minSpeed=80}, false);
    pros::delay(500);
    Hook.move(-127);
    pros::delay(2000);
    chassis.moveToPoint(60,1.25, 1500, {.minSpeed=80}, false);
    chassis.turnToHeading(165, 700);
    Hook.move(127);
    Intake.move(-127);
    chassis.moveToPoint(60,-60, 1500, {.minSpeed=100}, false);
    // chassis.moveToPoint(48, 1.5, 4000, {.forwards = false, .minSpeed = 50}, false);
    // chassis.turnToHeading(270, 1000);

}


void BlueSoloAwp(){
//Set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
Arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = true;
chassis.setPose(55.5,32, 0);
//Bump Robor
chassis.moveToPose(52, 45, 330, 2500, {.minSpeed = 100});
pros::delay(650);
Intake.move(127);
chassis.moveToPoint(55.5, 34, 1000, {.forwards = false, .minSpeed = 60});
chassis.turnToPoint(24, 24, 700, {.forwards = false});
chassis.moveToPoint(15, 22, 2000, {.forwards = false, .maxSpeed = 75}, false);
Mogo.set_value(true);
pros::delay(150);
Hook.move(-105);
pros::delay(500);
chassis.moveToPoint(24, 40, 1500, {}, false);
pros::delay(500);
chassis.moveToPoint(7, 48, 1500, {}, false);
chassis.moveToPoint(24, 38, 1500, {.forwards = false}, false);
pros::delay(500);
chassis.moveToPoint(48, -4, 3000);
pros::delay(1000);
Mogo.set_value(false);
Intake.move(-127);
chassis.moveToPoint(20, -26, 3000, {.forwards = false, .maxSpeed = 75}, false);
Mogo.set_value(true);
Intake.move(127);
chassis.moveToPoint(24, -50, 3000, {}, false);
pros::delay(1000);
Hook.move(0);
Intake.move(-127);
chassis.moveToPoint(8, -8, 2000, {.forwards = false}, false);
Lift.set_value(true);
}

void RedSoloAwp(){
//Set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
Arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = false;
chassis.setPose(-55.5,32, 0);
chassis.moveToPose(-52, 45, -330, 2500, {.minSpeed = 100});
pros::delay(650);
Intake.move(127);
chassis.moveToPoint(-55.5, 34, 1000, {.forwards = false, .minSpeed = 60});
chassis.turnToPoint(-24, 24, 700, {.forwards = false});
chassis.moveToPoint(-14, 22.5, 2000, {.forwards = false, .maxSpeed = 75}, false);
Mogo.set_value(true);
pros::delay(150);
Hook.move(-127);
pros::delay(500);
chassis.moveToPoint(-23,40, 1500, {}, false);
pros::delay(500);
chassis.moveToPoint(-7, 48, 1500, {}, false);
chassis.moveToPoint(-24, 38, 1500, {.forwards = false}, false);
pros::delay(500);
chassis.moveToPoint(-48, -4, 3000);
pros::delay(1000);
Mogo.set_value(false);
Intake.move(-127);
chassis.moveToPoint(-20, -27, 3000, {.forwards = false, .maxSpeed = 75}, false);
Mogo.set_value(true);
Intake.move(127);
chassis.moveToPoint(-24, -50, 3000, {}, false);
pros::delay(1250);
Hook.move(0);
Intake.move(-127);
chassis.moveToPoint(-7, -8, 2000, {.forwards = false}, false);
Lift.set_value(true);
}

void BlueSigSAwp(){
//Set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
Arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = true;
chassis.setPose(55.5,12, 0);
//Alliance Stake
chassis.moveToPose(55.5, 1, 3, 2000, {.forwards= false, .minSpeed = 80, .earlyExitRange= 3}, false);
chassis.turnToHeading(270, 500,{lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
chassis.moveToPose(64,4,270, 700,{.forwards=false, .minSpeed=80}, false);
Hook.move(-127);
pros::delay(300);
chassis.moveToPoint(58, 0, 1000, {.minSpeed=80, .earlyExitRange=2});
//Get Mogo on Neg Side + Push Alliance bot
Intake.move(127);
chassis.moveToPose(57, 29, 345, 2000, { .minSpeed= 80, .earlyExitRange=1}, false);
Hook.move(0);
chassis.moveToPose(58, 13, 345, 700, {.forwards=false, .minSpeed=100, .earlyExitRange=1});
chassis.moveToPose(20,34, 120, 4000, { .forwards= false, .lead=.6, .minSpeed=70}, false);
Mogo.set_value(true);
Hook.move(-127);
chassis.moveToPoint(24, 46, 2000, { .minSpeed= 80, .earlyExitRange=1});
chassis.moveToPoint(24, 36, 1500, { .minSpeed= 65, .earlyExitRange=1}, false);
Mogo.set_value(false);
Intake.move(-127);
//Mogo on Pos Side
chassis.moveToPoint(44, 0, 1500, { .minSpeed= 80, .earlyExitRange=1});
chassis.moveToPoint(48, -28, 1500, { .minSpeed= 80, .earlyExitRange=1});
chassis.moveToPose(20, -20, 120, 2000, {.forwards = false, .minSpeed=90}, false);
Mogo.set_value(true);
Intake.move(127);
chassis.moveToPose(24, -60, 180, 2000);

}

void BlueSigSAwp2(){
    //Set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
Arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = true;
chassis.setPose(55.5,12, 0);
//Alliance Stake
chassis.moveToPose(55.5, 1, 3, 2000, {.forwards= false, .minSpeed = 80, .earlyExitRange= 3}, false);
chassis.turnToHeading(270, 500,{lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
chassis.moveToPose(64,4,270, 700,{.forwards=false, .minSpeed=80}, false);
Hook.move(-127);
pros::delay(300);
chassis.moveToPoint(58, 0, 1000, {.minSpeed=80, .earlyExitRange=2});
//Get Mogo on Neg Side + Push Alliance bot
Intake.move(127);
chassis.moveToPose(57, 29, 345, 2000, { .minSpeed= 80, .earlyExitRange=1}, false);
Hook.move(0);
chassis.moveToPose(58, 13, 345, 700, {.forwards=false, .minSpeed=100, .earlyExitRange=1});
chassis.moveToPose(20,34, 120, 4000, { .forwards= false, .lead=.6, .minSpeed=70}, false);
Mogo.set_value(true);
Hook.move(-127);
chassis.moveToPoint(12, 0, 1000);
}
void RedSigSAWP(){
    //Set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
Arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = false;
chassis.setPose(-55.5,12, 0);
//Alliance Stake
chassis.moveToPose(-55.5, 1, 3, 2000, {.forwards= false, .minSpeed = 80, .earlyExitRange= 3}, false);
chassis.turnToHeading(-270, 500,{lemlib::AngularDirection::CW_CLOCKWISE});
chassis.moveToPose(-64,4,-270, 700,{.forwards=false, .minSpeed=80}, false);
Hook.move(-127);

}

void red4ring(){
       //Set up
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
Arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
BlueTeam = false;
chassis.setPose(-50, 36 ,270 );
//Grab Mogo
chassis.moveToPose(-24,24, 280, 2000, {.forwards = false, .minSpeed = 90}, false);
Mogo.set_value(true);
//Move Arm push top blue ring and score red ring
Arm.move_relative(825, 127);
chassis.moveToPose(-24, 40, 0, 2000, {.earlyExitRange = 2});
Intake.move(127);
Hook.move(-127);
//Ring Stack
chassis.moveToPose(-8, 45, 90, 1000);
pros::delay(100);
chassis.moveToPoint(-15, 45, 1000);
Arm.move_relative(-825, 127);
chassis.turnToHeading(80, 1000);
chassis.moveToPoint(-8, 50, 1000);
pros::delay(100);
// Ladder Touch
chassis.moveToPose(-24, -10, 0, 1000, {.forwards = false}, false);
chassis.turnToHeading(180, 100);
pros::delay(100);
Lift.set_value(true);






}