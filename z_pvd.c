/*
 * z_pvd.c
 *
 *  Created on: Nov 1, 2021
 *      Author: mauro
 *
 *
 *  In order to use PVD feature:
 *	1) enable PVD interrupt into NVIC section on CubeMX
 * 	2) copy z_pvd.c file in the "SRC" directory and z_pvd.h in "INC" into your project
 *  3) add an '#include "z_pvd.h"' into main.h
 *	4) setup instructions to execute on powerdown detection into the below PVD callback function
 *  5) call PVD_init() fuction in the main.c function before the main loop
 *
 *  more info on the youtube video: https://youtu.be/AHBGlCDGqhE
 *
 */

#include <main.h>



/**
  * @brief  called by PVD interrupt
  * 		in case of Powerdown.
  */
void HAL_PWR_PVDCallback() {
static uint8_t done=0;  

	if (!done){
		// add here instruction must be executed on powerdown detection 
	}
};




/**
  * @brief  setup and start Power Voltage Detector interrupt
  * 		calling HAL_PWR_PVDCallback() in case of powerdown.
  */
void PVD_Init(void) {

	PWR_PVDTypeDef sConfigPVD;

	sConfigPVD.PVDLevel	= PWR_PVDLEVEL_0;
	sConfigPVD.Mode = PWR_PVD_MODE_IT_RISING_FALLING;
	HAL_PWR_PVDConfig(&sConfigPVD);
	HAL_PWR_EnablePVD();

}
