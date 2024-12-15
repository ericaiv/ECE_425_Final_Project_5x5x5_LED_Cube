/**
 * @file GPIO.h
 *
 * @brief Header file for the GPIO driver to control 5x5x5 LED matrix. 
 *
 *
 * @author Eric Aivazian
 */



#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"
#include <stdint.h>
#include <stddef.h>


#define dmux_enable 0x04

// externs for arrays that contain the bit masks for PB0 - PB4 and PE0 - PE4
// Layer 1
extern uint8_t LED111[];
extern uint8_t LED211[];
extern uint8_t LED311[];
extern uint8_t LED411[];
extern uint8_t LED511[];

extern uint8_t LED121[];
extern uint8_t LED221[];
extern uint8_t LED321[];
extern uint8_t LED421[];
extern uint8_t LED521[];

extern uint8_t LED131[];
extern uint8_t LED231[];
extern uint8_t LED331[];
extern uint8_t LED431[];
extern uint8_t LED531[];

extern uint8_t LED141[];
extern uint8_t LED241[];
extern uint8_t LED341[];
extern uint8_t LED441[];
extern uint8_t LED541[];

extern uint8_t LED151[];
extern uint8_t LED251[];
extern uint8_t LED351[];
extern uint8_t LED451[];
extern uint8_t LED551[];

// Layer 2
extern uint8_t LED112[];
extern uint8_t LED212[];
extern uint8_t LED312[];
extern uint8_t LED412[];
extern uint8_t LED512[];

extern uint8_t LED122[];
extern uint8_t LED222[];
extern uint8_t LED322[];
extern uint8_t LED422[];
extern uint8_t LED522[];

extern uint8_t LED132[];
extern uint8_t LED232[];
extern uint8_t LED332[];
extern uint8_t LED432[];
extern uint8_t LED532[];

extern uint8_t LED142[];
extern uint8_t LED242[];
extern uint8_t LED342[];
extern uint8_t LED442[];
extern uint8_t LED542[];

extern uint8_t LED152[];
extern uint8_t LED252[];
extern uint8_t LED352[];
extern uint8_t LED452[];
extern uint8_t LED552[];

// Layer 3
extern uint8_t LED113[];
extern uint8_t LED213[];
extern uint8_t LED313[];
extern uint8_t LED413[];
extern uint8_t LED513[];

extern uint8_t LED123[];
extern uint8_t LED223[];
extern uint8_t LED323[];
extern uint8_t LED423[];
extern uint8_t LED523[];

extern uint8_t LED133[];
extern uint8_t LED233[];
extern uint8_t LED333[];
extern uint8_t LED433[];
extern uint8_t LED533[];

extern uint8_t LED143[];
extern uint8_t LED243[];
extern uint8_t LED343[];
extern uint8_t LED443[];
extern uint8_t LED543[];

extern uint8_t LED153[];
extern uint8_t LED253[];
extern uint8_t LED353[];
extern uint8_t LED453[];
extern uint8_t LED553[];

// Layer 4
extern uint8_t LED114[];
extern uint8_t LED214[];
extern uint8_t LED314[];
extern uint8_t LED414[];
extern uint8_t LED514[];

extern uint8_t LED124[];
extern uint8_t LED224[];
extern uint8_t LED324[];
extern uint8_t LED424[];
extern uint8_t LED524[];

extern uint8_t LED134[];
extern uint8_t LED234[];
extern uint8_t LED334[];
extern uint8_t LED434[];
extern uint8_t LED534[];

extern uint8_t LED144[];
extern uint8_t LED244[];
extern uint8_t LED344[];
extern uint8_t LED444[];
extern uint8_t LED544[];

extern uint8_t LED154[];
extern uint8_t LED254[];
extern uint8_t LED354[];
extern uint8_t LED454[];
extern uint8_t LED554[];


// Layer 5
extern uint8_t LED115[];
extern uint8_t LED215[];
extern uint8_t LED315[];
extern uint8_t LED415[];
extern uint8_t LED515[];

extern uint8_t LED125[];
extern uint8_t LED225[];
extern uint8_t LED325[];
extern uint8_t LED425[];
extern uint8_t LED525[];

extern uint8_t LED135[];
extern uint8_t LED235[];
extern uint8_t LED335[];
extern uint8_t LED435[];
extern uint8_t LED535[];

extern uint8_t LED145[];
extern uint8_t LED245[];
extern uint8_t LED345[];
extern uint8_t LED445[];
extern uint8_t LED545[];

extern uint8_t LED155[];
extern uint8_t LED255[];
extern uint8_t LED355[];
extern uint8_t LED455[];
extern uint8_t LED555[];


/**
 * @brief This function initializes the GPIO pins used to control the 5x5x5 LED cube matrix
 *				PB0 - PB4 control the anodes of the LEDs through decoders, PE0 - PE4 control the cathodes of the LEDs. 
 * 				PA2 controls the functionality of the decoder 
 * @param	NONE
 *
 * @return NONE
 */
void LED_Cube_Init(void);

/**
 * @brief This function controls the LEDs in the 5x5x5 LED matrix. 
 *				It takes the LED_array input arguement, which is an array of the LED_### subarrays and toggles the LED in each 
 * 				element of the array at a fast rate to make it appear as if all the LEDs in the array are on at the same time. 
 * 				The array_size input argument is the size of LED_array[]. ms_duration is the time that the LEDs will be on. Brightness 
 * 				is an integer that should range from 0 to 100 to set the brightness of the LED. 
 * @param LED_array[], array_size, ms_duration, brightness
 *
 * @return NONE
 */
void LED_Control(uint8_t* (LED_array[]),int array_size, int ms_duration, int brightness);
