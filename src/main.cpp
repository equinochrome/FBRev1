#pragma once 
#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "api.h" // IWYU pragma: keep 
#include "robodash/api.h" // IWYU pragma: keep
#include "autons.h" // IWYU pragma: keep
#include "devices.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/abstract_motor.hpp" // IWYU pragma: keep
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/motors.hpp" // IWYU pragma: keep
#include "pros/rtos.hpp"


 
 using rd::Console;
   Console console;

  rd::Selector selector({
    {"test", &test},
   {"test2", &test2},
{"BluePos1", &BluePos1},
{"BluePos2", &BluePos2},
{"BlueNeg1", &BlueNeg1},
{"RedPos1", &RedPos1},
{"RedNeg1", &RedNeg1},
{"RedNeg2", &RedNeg2},
{"skills", &skills},

});
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */



void initialize() {
    chassis.calibrate();
    
    
    

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    pros::delay(100);
        console.println("Erm what the sigma");
	        selector.run_auton();
}


/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */


void opcontrol() {
Lift.set_value(false);
bool MogoState = false;

    // loop forever
    while (true) {
        
        // get left y and right y positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    // move the robot
        chassis.tank(leftY, rightY);
      
        if(controller.get_digital(DIGITAL_R2)){
            Intake.move(127);
        }
        else if(controller.get_digital(DIGITAL_R1)){
            Intake.move(-127);
        } else{
            Intake.move(0);
        }

        if(controller.get_digital(DIGITAL_L2)){
            Hook.move(127);
        }
        else if(controller.get_digital(DIGITAL_L1)){
            Hook.move(-127);
        } else{
            Hook.move(0);
        }

        if (controller.get_digital(DIGITAL_UP)){
        Lift.set_value(true);
        } else if(controller.get_digital(DIGITAL_DOWN)){
        Lift.set_value(false);
        }

        if (controller.get_digital(DIGITAL_A)){
        Mogo.set_value(true);
        } else if(controller.get_digital(DIGITAL_B)){
        Mogo.set_value(false);
        }

        // delay to save resources
        pros::delay(25);

    }

   


}