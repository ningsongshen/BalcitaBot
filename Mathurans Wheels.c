#pragma config(Sensor, dgtl1,  rear_end_detection, sensorTouch)
#pragma config(Motor,  port3,           right_wheels,  tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           left_wheels,   tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           right_arm,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           left_arm,      tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port7,           right_arm_2,   tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           left_arm_2,    tmotorVex393HighSpeed_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main(){

	// declare joystick variables
	int stick_left_vert, stick_right_hor;

	//float actual_left_vert = 0, actual_right_hor = 0;
	// declare motor variables
	//int l_motors, r_motors;

	while(true){
		//motor[test_port] = 127;

		// get joystick positions
		stick_left_vert = vexRT[Ch3];
		stick_right_hor = vexRT[Ch1];

		// calculate deadzones
		if(-13 < stick_left_vert && stick_left_vert < 13){
			stick_left_vert = 0;
		}
		if(-13 < stick_right_hor && stick_right_hor < 13){
			stick_right_hor = 0;
		}

		// p-controller (NOT IN USE)
		//actual_left_vert += (stick_left_vert - actual_left_vert) * 0.0003;
		//actual_right_hor += (stick_right_hor - actual_right_hor) * 0.0003;
		//
		// calculate motor speeds
		//l_motors = actual_left_vert + actual_right_hor;
		//r_motors = - actual_left_vert + actual_right_hor;

		// set motor speeds
		motor[right_wheels] = stick_left_vert + stick_right_hor;
		motor[left_wheels] = - stick_left_vert + stick_right_hor;

		// port 5 & 6 motor on button press
		if(vexRT[Btn6U] == 1){
			motor[right_arm] = -128;
			motor[right_arm_2] = -128;
			motor[left_arm] = 128;
			motor[left_arm_2] = 128;
		}
		else if(vexRT[Btn6D] == 1){
			motor[right_arm] = 128;
			motor[right_arm_2] = 128;
			motor[left_arm] = -128;
			motor[left_arm_2] = -128;
		}
		else{
			motor[right_arm] = 0;
			motor[left_arm] = 0;
		}

		// Rear end collision detection
		if(SensorValue[rear_end_detection] == 1){
			motor[right_wheels] = 128;
			motor[left_wheels] = -128;

		}
	}
}
