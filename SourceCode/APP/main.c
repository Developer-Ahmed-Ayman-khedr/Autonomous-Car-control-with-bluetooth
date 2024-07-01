/*
 * main.c
 *
 *  Created on: Jun 24, 2024
 *      Author: ahmed
 */

#include"AutonomousSourceCode.h"

int main(){
	AutonomousSourceCodeInitDrivers();
	while(1){
		AutonomousSourceCodeMain();
	}
	return 0;
}
