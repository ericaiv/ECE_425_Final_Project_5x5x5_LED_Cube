/**
 * @file GPIO.c
 *
 * @brief Source code for the GPIO driver to control 5x5x5 LED matrix. 
 *
 *
 * @author Eric
 */

#include "GPIO.h"
#include "SysTick_Delay.h"
#include <stdint.h>
#include <stddef.h>


// Array definitions for bit masks to set and reset PB0 - PB4 and PE0 - PE4. The First element is the 
// bit mask for controling the anodes (connected to decoders) PB0 - PB4, The second element is the 
// bit mask for controlling the cathodes PE0 - PE4. 
// Layer 1
uint8_t LED111[] = {0x00, 0x01};
uint8_t LED211[] = {0x01, 0x01};
uint8_t LED311[] = {0x02, 0x01};
uint8_t LED411[] = {0x03, 0x01};
uint8_t LED511[] = {0x04, 0x01};

uint8_t LED121[] = {0x05, 0x01};
uint8_t LED221[] = {0x06, 0x01};
uint8_t LED321[] = {0x07, 0x01};
uint8_t LED421[] = {0x08, 0x01};
uint8_t LED521[] = {0x09, 0x01};

uint8_t LED131[] = {0x0A, 0x01};
uint8_t LED231[] = {0x0B, 0x01};
uint8_t LED331[] = {0x0C, 0x01};
uint8_t LED431[] = {0x0D, 0x01};
uint8_t LED531[] = {0x0E, 0x01};

uint8_t LED141[] = {0x0F, 0x01};
uint8_t LED241[] = {0x10, 0x01};
uint8_t LED341[] = {0x11, 0x01};
uint8_t LED441[] = {0x12, 0x01};
uint8_t LED541[] = {0x13, 0x01};

uint8_t LED151[] = {0x14, 0x01};
uint8_t LED251[] = {0x15, 0x01};
uint8_t LED351[] = {0x16, 0x01};
uint8_t LED451[] = {0x17, 0x01};
uint8_t LED551[] = {0x18, 0x01};

// Layer 2
uint8_t LED112[] = {0x00, 0x02};
uint8_t LED212[] = {0x01, 0x02};
uint8_t LED312[] = {0x02, 0x02};
uint8_t LED412[] = {0x03, 0x02};
uint8_t LED512[] = {0x04, 0x02};

uint8_t LED122[] = {0x05, 0x02};
uint8_t LED222[] = {0x06, 0x02};
uint8_t LED322[] = {0x07, 0x02};
uint8_t LED422[] = {0x08, 0x02};
uint8_t LED522[] = {0x09, 0x02};

uint8_t LED132[] = {0x0A, 0x02};
uint8_t LED232[] = {0x0B, 0x02};
uint8_t LED332[] = {0x0C, 0x02};
uint8_t LED432[] = {0x0D, 0x02};
uint8_t LED532[] = {0x0E, 0x02};

uint8_t LED142[] = {0x0F, 0x02};
uint8_t LED242[] = {0x10, 0x02};
uint8_t LED342[] = {0x11, 0x02};
uint8_t LED442[] = {0x12, 0x02};
uint8_t LED542[] = {0x13, 0x02};

uint8_t LED152[] = {0x14, 0x02};
uint8_t LED252[] = {0x15, 0x02};
uint8_t LED352[] = {0x16, 0x02};
uint8_t LED452[] = {0x17, 0x02};
uint8_t LED552[] = {0x18, 0x02};

// Layer 3
uint8_t LED113[] = {0x00, 0x04};
uint8_t LED213[] = {0x01, 0x04};
uint8_t LED313[] = {0x02, 0x04};
uint8_t LED413[] = {0x03, 0x04};
uint8_t LED513[] = {0x04, 0x04};

uint8_t LED123[] = {0x05, 0x04};
uint8_t LED223[] = {0x06, 0x04};
uint8_t LED323[] = {0x07, 0x04};
uint8_t LED423[] = {0x08, 0x04};
uint8_t LED523[] = {0x09, 0x04};

uint8_t LED133[] = {0x0A, 0x04};
uint8_t LED233[] = {0x0B, 0x04};
uint8_t LED333[] = {0x0C, 0x04};
uint8_t LED433[] = {0x0D, 0x04};
uint8_t LED533[] = {0x0E, 0x04};

uint8_t LED143[] = {0x0F, 0x04};
uint8_t LED243[] = {0x10, 0x04};
uint8_t LED343[] = {0x11, 0x04};
uint8_t LED443[] = {0x12, 0x04};
uint8_t LED543[] = {0x13, 0x04};

uint8_t LED153[] = {0x14, 0x04};
uint8_t LED253[] = {0x15, 0x04};
uint8_t LED353[] = {0x16, 0x04};
uint8_t LED453[] = {0x17, 0x04};
uint8_t LED553[] = {0x18, 0x04};

// Layer 4
uint8_t LED114[] = {0x00, 0x08};
uint8_t LED214[] = {0x01, 0x08};
uint8_t LED314[] = {0x02, 0x08};
uint8_t LED414[] = {0x03, 0x08};
uint8_t LED514[] = {0x04, 0x08};

uint8_t LED124[] = {0x05, 0x08};
uint8_t LED224[] = {0x06, 0x08};
uint8_t LED324[] = {0x07, 0x08};
uint8_t LED424[] = {0x08, 0x08};
uint8_t LED524[] = {0x09, 0x08};

uint8_t LED134[] = {0x0A, 0x08};
uint8_t LED234[] = {0x0B, 0x08};
uint8_t LED334[] = {0x0C, 0x08};
uint8_t LED434[] = {0x0D, 0x08};
uint8_t LED534[] = {0x0E, 0x08};

uint8_t LED144[] = {0x0F, 0x08};
uint8_t LED244[] = {0x10, 0x08};
uint8_t LED344[] = {0x11, 0x08};
uint8_t LED444[] = {0x12, 0x08};
uint8_t LED544[] = {0x13, 0x08};

uint8_t LED154[] = {0x14, 0x08};
uint8_t LED254[] = {0x15, 0x08};
uint8_t LED354[] = {0x16, 0x08};
uint8_t LED454[] = {0x17, 0x08};
uint8_t LED554[] = {0x18, 0x08};


// Layer 5
uint8_t LED115[] = {0x00, 0x10};
uint8_t LED215[] = {0x01, 0x10};
uint8_t LED315[] = {0x02, 0x10};
uint8_t LED415[] = {0x03, 0x10};
uint8_t LED515[] = {0x04, 0x10};

uint8_t LED125[] = {0x05, 0x10};
uint8_t LED225[] = {0x06, 0x10};
uint8_t LED325[] = {0x07, 0x10};
uint8_t LED425[] = {0x08, 0x10};
uint8_t LED525[] = {0x09, 0x10};

uint8_t LED135[] = {0x0A, 0x10};
uint8_t LED235[] = {0x0B, 0x10};
uint8_t LED335[] = {0x0C, 0x10};
uint8_t LED435[] = {0x0D, 0x10};
uint8_t LED535[] = {0x0E, 0x10};

uint8_t LED145[] = {0x0F, 0x10};
uint8_t LED245[] = {0x10, 0x10};
uint8_t LED345[] = {0x11, 0x10};
uint8_t LED445[] = {0x12, 0x10};
uint8_t LED545[] = {0x13, 0x10};

uint8_t LED155[] = {0x14, 0x10};
uint8_t LED255[] = {0x15, 0x10};
uint8_t LED355[] = {0x16, 0x10};
uint8_t LED455[] = {0x17, 0x10};
uint8_t LED555[] = {0x18, 0x10};





// function to initialize GPIO pins used for 5x5x5 LED cube matrix
void LED_Cube_Init(void)
{
	//Initialize decoder enable
	SYSCTL -> RCGCGPIO |= 0x01;
	GPIOA -> DIR |= 0x0C;
	GPIOA -> AFSEL &= ~0x0C;
	GPIOA -> DEN |= 0x0C;
	GPIOA -> DATA &= ~0x0C;
	
	
	//Initialize column select
	SYSCTL -> RCGCGPIO |= 0x02;
	GPIOB -> DIR |= 0x1F;
	GPIOB -> AFSEL &= ~0x1F;
	GPIOB -> DEN |= 0x1F;
	GPIOB -> DATA &= ~0x1F;
	
	
	//Initialize layer select
	SYSCTL -> RCGCGPIO |= 0x10;
	GPIOE -> DIR |= 0x1F;
	GPIOE -> AFSEL &= ~0x1F;
	GPIOE -> DEN |= 0x1F;
	GPIOE -> DATA |= 0x1F;
}



// Function to control the LEDs S
void LED_Control(uint8_t* (LED_array[]),int array_size, int ms_duration, int brightness)
{
	if (brightness > 250)
	{
		brightness = 250;
	}
			
	int us_duration = ms_duration * 1000;   //converting ms to us
	int deadtime = 10;											
	int elapsed_time = 0;
	int ontime = 40*brightness/100;					//duration HIGH 
	int offtime = 100-ontime;								//duration LOW
	
	while(elapsed_time < us_duration)				//function will run for the duration of us_duration
	{
		for (int i = 0; i < array_size; i++)	//indexing through all elements of LED_array[]
		{
			uint8_t *SubArray = LED_array[i];		//accessing element i of LED_array[], which are the SubArrays 
																					//contating the hex bit masks for the LEDs

			GPIOB -> DATA |= SubArray[0];				//setting GPIOB pin HIGH for anodes
			GPIOE -> DATA &= ~ SubArray[1];			//reseting GPIOE pin LOW for cathodes
			SysTick_Delay1us(deadtime);					//delay to accomodate for switching of GPIOB and GPIOE before turning on DMUX
			GPIOA -> DATA |= dmux_enable;				//enabling DMUX, LEDs turn on
			SysTick_Delay1us(ontime);						//DMUX on for duration of ontime
		
			GPIOA -> DATA &= ~(dmux_enable);		//disabling DMUX, LEDs turn off
			SysTick_Delay1us(deadtime);					//delay to accomodate for switching of GPIOB and GPIOE before turning on DMUX
			GPIOB -> DATA &= ~SubArray[0];			//reseting GPIOB pin LOW for anodes
			GPIOE -> DATA |= SubArray[1];				//setting GPIOE pins HIGH for cathodes
			SysTick_Delay1us(offtime);					//DMUX off for duration of offtime

			elapsed_time = elapsed_time + (ontime + offtime + deadtime + deadtime);		//calculating time elapsed
			
			if (i == array_size)
			{
				i = 0;			//after indexing all elements of LED_array[], i is reset and for loop repeatsS
			}
		}
	}
}



