/**
 * @file main.c
 *
 * @brief 
 *
 * @author Eric Aivazian
 */
 
#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"
#include "GPIO.h"


void shrinking_square (int cycles, int step_time);
void All_LEDs_On(int step_time, int duty_cycle);
void Blink_All_LEDs(int cycles, int step_time);
void Layers_move_up(int cycles, int step_time);
void cone(int cycles, int step_time);
void heart(int cycles, int step_time);
void square_corners (int cycles, int step_time);
void fireworks(int cycles, int step_time);
void spell_ECE425 (int cycles, int step_time);

int main(void)
{
	//initialize the 5x5x5 LED cube matrix
	LED_Cube_Init();
	
	// Initialize the SysTick timer used to provide blocking delay functions 
	SysTick_Delay_Init();
	
	
	while(1)
	{
		//layers move up animation 1
		Layers_move_up(5, 100);
		
		//shrinking cube animation
		shrinking_square(5,100);
		
		//cone
		cone(6,50);

		//beating heart animation
		heart(10,50);

		square_corners(1,75);

		//fireworks
		fireworks(4,100);
	
		//spell ECE425
		spell_ECE425(1,100);

		//blinking all lights animation
		Blink_All_LEDs(20,200);
		
	}
}


//ANIMATIONS

void shrinking_square (int cycles,int step_time)
{
	uint8_t* pattern1[]=
	{
		//front face square (15)
		LED111,LED211,LED311,LED411,LED511,
		LED112,LED113,LED114,
		LED512,LED513,LED514,
		LED115,LED215,LED315,LED415,LED515,
		
		//left side (6)
		LED121, LED131,LED141,
		LED125,LED135,LED145,
		
		//right side (6)
		LED521,LED531,LED541,
		LED525,LED535,LED545,

		//back side (15)
		LED151,LED251,LED351,LED451,LED551,
		LED152,LED153,LED154,
		LED552,LED553,LED554,
		LED155,LED255,LED355,LED455,LED555
		
	};
	
	size_t size1 = sizeof(pattern1) / sizeof(pattern1[0]);
	
	uint8_t* pattern2[] = 
	{
		//face
		LED222,LED322,LED422,
		LED223,
		LED423,
		LED224,LED324,LED424,
		
		//left
		LED232, LED234,
		//right
		LED432, LED434,
		
		//back
		LED242,LED342,LED442,
		LED243,
		LED443,
		LED244,LED344,LED444,
	};

	size_t size2 = sizeof(pattern2) / sizeof(pattern2[0]);

	uint8_t* pattern3[] =
	{
		LED333
	};
	size_t size3 = sizeof(pattern3) / sizeof(pattern3[0]);	
	
	for (int i = 0; i < cycles; i++)
	{
	LED_Control(pattern1,size1,step_time,100);
	LED_Control(pattern2,size2,step_time,100);	
	LED_Control(pattern3,size3,step_time,10);	
	LED_Control(pattern2,size2,step_time,100);	
	}
	LED_Control(pattern1,size1,step_time,100);
}



void Layers_move_up(int cycles,int step_time)
{
	uint8_t* pattern1[]= {
												LED115, LED215, LED315, LED415, LED515, 
												LED125, LED225, LED325, LED425, LED525, 
												LED135, LED235, LED335, LED435, LED535, 
												LED145, LED245, LED345, LED445, LED545, 
												LED155, LED255, LED355, LED455, LED555
												};
	
	uint8_t* pattern2[]= {
												LED114, LED214, LED314, LED414, LED514, 
												LED124, LED224, LED324, LED424, LED524, 
												LED134, LED234, LED334, LED434, LED534, 
												LED144, LED244, LED344, LED444, LED544, 
												LED154, LED254, LED354, LED454, LED554											
												};
	
	uint8_t* pattern3[]= {
												LED113, LED213, LED313, LED413, LED513, 
												LED123, LED223, LED323, LED423, LED523, 
												LED133, LED233, LED333, LED433, LED533, 
												LED143, LED243, LED343, LED443, LED543, 
												LED153, LED253, LED353, LED453, LED553									
												};

	uint8_t* pattern4[]= {
												LED112, LED212, LED312, LED412, LED512, 
												LED122, LED222, LED322, LED422, LED522, 
												LED132, LED232, LED332, LED432, LED532, 
												LED142, LED242, LED342, LED442, LED542, 
												LED152, LED252, LED352, LED452, LED552							
												};											
	uint8_t* pattern5[]= {
												LED111, LED211, LED311, LED411, LED511, 
												LED121, LED221, LED321, LED421, LED521, 
												LED131, LED231, LED331, LED431, LED531, 
												LED141, LED241, LED341, LED441, LED541, 
												LED151, LED251, LED351, LED451, LED551										
												};	

	size_t size1 = sizeof(pattern1) / sizeof(pattern1[0]);	
	size_t size2 = sizeof(pattern2) / sizeof(pattern2[0]);	
	size_t size3 = sizeof(pattern3) / sizeof(pattern3[0]);
	size_t size4 = sizeof(pattern4) / sizeof(pattern4[0]);
	size_t size5 = sizeof(pattern5) / sizeof(pattern5[0]);	
																							
	for (int i = 0; i < cycles; i++)
	{
	LED_Control(pattern1,size1,step_time,100);
	LED_Control(pattern2,size2,step_time,100);	
	LED_Control(pattern3,size3,step_time,100);
	LED_Control(pattern4,size4,step_time,100);
	LED_Control(pattern5,size5,step_time,100);
	}

	
}
	

void All_LEDs_On(int step_time, int duty_cycle)
{
	

	uint8_t* pattern1[]= {LED115, LED215, LED315, LED415, LED515, 
												LED125, LED225, LED325, LED425, LED525, 
												LED135, LED235, LED335, LED435, LED535, 
												LED145, LED245, LED345, LED445, LED545, 
												LED155, LED255, LED355, LED455, LED555,
		
												LED114, LED214, LED314, LED414, LED514, 
												LED124, LED224, LED324, LED424, LED524, 
												LED134, LED234, LED334, LED434, LED534, 
												LED144, LED244, LED344, LED444, LED544, 
												LED154, LED254, LED354, LED454, LED554,
	
												LED113, LED213, LED313, LED413, LED513, 
												LED123, LED223, LED323, LED423, LED523, 
												LED133, LED233, LED333, LED433, LED533, 
												LED143, LED243, LED343, LED443, LED543, 
												LED153, LED253, LED353, LED453, LED553,

												LED112, LED212, LED312, LED412, LED512, 
												LED122, LED222, LED322, LED422, LED522, 
												LED132, LED232, LED332, LED432, LED532, 
												LED142, LED242, LED342, LED442, LED542, 
												LED152, LED252, LED352, LED452, LED552,		
												
												LED111, LED211, LED311, LED411, LED511, 
												LED121, LED221, LED321, LED421, LED521, 
												LED131, LED231, LED331, LED431, LED531, 
												LED141, LED241, LED341, LED441, LED541, 
												LED151, LED251, LED351, LED451, LED551												
												};
	size_t size1 = sizeof(pattern1) / sizeof(pattern1[0]);	
	LED_Control(pattern1, size1, step_time, duty_cycle);
}



void Blink_All_LEDs(int cycles, int step_time)
{
	
		for (int i = 0; i < cycles; i++)
		{
			step_time = step_time * 0.90;
			int duty_cycle = 20 * (i+1);
			
			SysTick_Delay1ms(step_time);
			All_LEDs_On(step_time/2, duty_cycle);
		}
		for (int i = cycles; i > 0; i--)
		{
			step_time = step_time * 1.10;
			int duty_cycle = 20 * (i-1);
			
			SysTick_Delay1ms(step_time);
			All_LEDs_On(step_time/2, duty_cycle);
		}		
		
		
		SysTick_Delay1ms(200);
}

void cone(int cycles, int step_time)
{	
	uint8_t* pattern1[]= {
												LED111, LED211, LED311, LED411, LED511, 
												LED121, LED221, LED321, LED421, LED521, 
												LED131, LED231, LED331, LED431, LED531, 
												LED141, LED241, LED341, LED441, LED541, 
												LED151, LED251, LED351, LED451, LED551
	};
	
	uint8_t* pattern2[]= {
																				LED332,
		
		
												LED111, LED211, LED311, LED411, LED511, 
												LED121, LED221, LED321, LED421, LED521, 
												LED131, LED231,					LED431, LED531, 
												LED141, LED241, LED341, LED441, LED541, 
												LED151, LED251, LED351, LED451, LED551
	};	

	uint8_t* pattern3[]= {
																				LED333,
																
																LED222, LED322, LED422,
																LED232,				  LED432,				
																LED242, LED342, LED442, 
		
												LED111, LED211, LED311, LED411, LED511, 
												LED121, 												LED521, 
												LED131,													LED531, 
												LED141, 												LED541, 
												LED151, LED251, LED351, LED451, LED551
	};	
	
												
	uint8_t* pattern4[]= {
																				LED334,
		
																LED223, LED323, LED423,
																LED233, 				LED433,				
																LED243, LED343, LED443, 
		
																LED222, LED322, LED422,
																LED232, 				LED432,				
																LED242, LED342, LED442, 
		
												LED111, LED211, LED311, LED411, LED511, 
												LED121, 												LED521, 
												LED131,													LED531, 
												LED141, 												LED541, 
												LED151, LED251, LED351, LED451, LED551
	};	
	

	uint8_t* pattern5[]= {
																				LED335,
		
																LED224, LED324, LED424,
																LED234, 				LED434,				
																LED244, LED344, LED444,
		
																LED223, LED323, LED423,
																LED233,					LED433,				
																LED243, LED343, LED443, 
		
												LED112, LED212, LED312, LED412, LED512, 
												LED122, 												LED522, 
												LED132, 												LED532, 
												LED142,													LED542, 
												LED152, LED252, LED352, LED452, LED552,
		
												LED111, LED211, LED311, LED411, LED511, 
												LED121, 												LED521, 
												LED131, 												LED531, 
												LED141,													LED541, 
												LED151, LED251, LED351, LED451, LED551
	};		
	
	uint8_t* pattern6[]= {
																				LED335,
		
																LED224, LED324, LED424,
																LED234, 			 	LED434,				
																LED244, LED344, LED444,
		
																LED223, LED323, LED423,
																LED233, 				LED433,				
																LED243, LED343, LED443, 
		
												LED112, LED212, LED312, LED412, LED512, 
												LED122,												 	LED522, 
												LED132, 												LED532, 
												LED142,													LED542, 
												LED152, LED252, LED352, LED452, LED552
	};					


	uint8_t* pattern7[]= {
																				LED335,
		
																LED224, LED324, LED424,
																LED234, 			  LED434,				
																LED244, LED344, LED444,
		
												LED113, LED213, LED313, LED413, LED513, 
												LED123, LED223, LED323, LED423, LED523, 
												LED133, LED233,					LED433, LED533, 
												LED143, LED243, LED343, LED443, LED543, 
												LED153, LED253, LED353, LED453, LED553
	};	

	uint8_t* pattern8[]= {
																				LED335,
		
												LED114, LED214, LED314, LED414, LED514, 
												LED124, LED224, LED324, LED424, LED524, 
												LED134, LED234, 				LED434, LED534, 
												LED144, LED244, LED344, LED444, LED544, 
												LED154, LED254, LED354, LED454, LED554
	};												

	uint8_t* pattern9[]= {
												LED115, LED215, LED315, LED415, LED515, 
												LED125, LED225, LED325, LED425, LED525, 
												LED135, LED235, LED335, LED435, LED535, 
												LED145, LED245, LED345, LED445, LED545, 
												LED155, LED255, LED355, LED455, LED555
	};		
						

	uint8_t* pattern10[]= {
												LED115, LED215, LED315, LED415, LED515, 
												LED125, LED225, LED325, LED425, LED525, 
												LED135, LED235, 			 	LED435, LED535, 
												LED145, LED245, LED345, LED445, LED545, 
												LED155, LED255, LED355, LED455, LED555,
																				
																				LED334
	};													
	
	uint8_t* pattern11[]= {
												LED115, LED215, LED315, LED415, LED515, 
												LED125,													LED525, 
												LED135,													LED535, 
												LED145,													LED545, 
												LED155, LED255, LED355, LED455, LED555,
																
																LED224, LED324, LED424,
																LED234, 				LED434, 
																LED244, LED344, LED444,
			
																				LED333
	};													
	
	uint8_t* pattern12[]= {
												LED115, LED215, LED315, LED415, LED515, 
												LED125,													LED525, 
												LED135,													LED535, 
												LED145,													LED545, 
												LED155, LED255, LED355, LED455, LED555,
																
																LED224, LED324, LED424,
																LED234, 				LED434, 
																LED244, LED344, LED444,

																LED223, LED323, LED423,
																LED233, 				LED433, 
																LED243, LED343, LED443,
		
																				LED332
	};		

	uint8_t* pattern13[]= {
												LED115, LED215, LED315, LED415, LED515, 
												LED125,													LED525, 
												LED135,													LED535, 
												LED145,													LED545, 
												LED155, LED255, LED355, LED455, LED555,
	
												LED114, LED214, LED314, LED414, LED514, 
												LED124,													LED524, 
												LED134,													LED534, 
												LED144,													LED544, 
												LED154, LED254, LED354, LED454, LED554,
		
																LED223, LED323, LED423,
																LED233, 				LED433, 
																LED243, LED343, LED443,

																LED222, LED322, LED422,
																LED232,					LED432, 
																LED242, LED342, LED442,
		
																				LED331
	};														
	
	
	uint8_t* pattern14[]= {
												LED114, LED214, LED314, LED414, LED514, 
												LED124,													LED524, 
												LED134,													LED534, 
												LED144,													LED544, 
												LED154, LED254, LED354, LED454, LED554,
		
																LED223, LED323, LED423,
																LED233, 				LED433, 
																LED243, LED343, LED443,

																LED222, LED322, LED422,
																LED232, 				LED432, 
																LED242, LED342, LED442,
		
																				LED331
	};									

	uint8_t* pattern15[]= {		
												LED113, LED213, LED313, LED413, LED513, 
												LED123, LED223, LED323, LED423, LED523, 
												LED133, LED233, 				LED433, LED533, 
												LED143, LED243, LED343, LED443, LED543, 
												LED153, LED253, LED353, LED453, LED553,

																LED222, LED322, LED422,
																LED232, 				LED432, 
																LED242, LED342, LED442,
		
																				LED331
	};									

	uint8_t* pattern16[]= {		
												LED112, LED212, LED312, LED412, LED512, 
												LED122, LED222, LED322, LED422, LED522, 
												LED132, LED232, 			 	LED432, LED532, 
												LED142, LED242, LED342, LED442, LED542, 
												LED152, LED252, LED352, LED452, LED552,
		
																				LED331
	};									



	size_t size1 = sizeof(pattern1) / sizeof(pattern1[0]);	
	size_t size2 = sizeof(pattern2) / sizeof(pattern2[0]);	
	size_t size3 = sizeof(pattern3) / sizeof(pattern3[0]);
	size_t size4 = sizeof(pattern4) / sizeof(pattern4[0]);
	size_t size5 = sizeof(pattern5) / sizeof(pattern5[0]);	
	size_t size6 = sizeof(pattern6) / sizeof(pattern6[0]);	
	size_t size7 = sizeof(pattern7) / sizeof(pattern7[0]);
	size_t size8 = sizeof(pattern8) / sizeof(pattern8[0]);
	size_t size9 = sizeof(pattern9) / sizeof(pattern9[0]);			
	size_t size10 = sizeof(pattern10) / sizeof(pattern10[0]);	
	size_t size11 = sizeof(pattern11) / sizeof(pattern11[0]);	
	size_t size12 = sizeof(pattern12) / sizeof(pattern12[0]);
	size_t size13 = sizeof(pattern13) / sizeof(pattern13[0]);
	size_t size14 = sizeof(pattern14) / sizeof(pattern14[0]);
	size_t size15 = sizeof(pattern15) / sizeof(pattern15[0]);
	size_t size16 = sizeof(pattern16) / sizeof(pattern16[0]);
												
	for (int i = 0; i < cycles; i++)
	{
	LED_Control(pattern1,size1,step_time,100);
	LED_Control(pattern2,size2,step_time,100);	
	LED_Control(pattern3,size3,step_time,100);
	LED_Control(pattern4,size4,step_time,100);
	LED_Control(pattern5,size5,step_time,100);
		
	LED_Control(pattern6,size6,step_time,100);	
	LED_Control(pattern7,size7,step_time,100);
	LED_Control(pattern8,size8,step_time,100);
	LED_Control(pattern9,size9,step_time,100);
		
	LED_Control(pattern10,size10,step_time,100);	
	LED_Control(pattern11,size11,step_time,100);
	LED_Control(pattern12,size12,step_time,100);
	LED_Control(pattern13,size13,step_time,100);
	LED_Control(pattern14,size14,step_time,100);	
	LED_Control(pattern15,size15,step_time,100);
	LED_Control(pattern16,size16,step_time,100);
	//LED_Control(pattern17,size17,step_time,100);
	}
	
}	
	
void heart(int cycles, int step_time)
{
	uint8_t* pattern1[]= {LED311, LED212, LED113, LED114, LED215, LED314, LED415, LED514, LED513, LED412};
	uint8_t* pattern2[]= {LED321, LED222, LED123, LED124, LED225, LED324, LED425, LED524, LED523, LED422};
	uint8_t* pattern3[]= {LED331, LED232, LED133, LED134, LED235, LED334, LED435, LED534, LED533, LED432};
	uint8_t* pattern4[]= {LED341, LED242, LED143, LED144, LED245, LED344, LED445, LED544, LED543, LED442};
	uint8_t* pattern5[]= {LED351, LED252, LED153, LED154, LED255, LED354, LED455, LED554, LED553, LED452};
	
	//uint8_t* test[]= {LED143};
	
	size_t size1 = sizeof(pattern1) / sizeof(pattern1[0]);
	size_t size2 = sizeof(pattern2) / sizeof(pattern2[0]);
	size_t size3 = sizeof(pattern3) / sizeof(pattern3[0]);
	size_t size4 = sizeof(pattern4) / sizeof(pattern4[0]);
	size_t size5 = sizeof(pattern5) / sizeof(pattern5[0]);

	//size_t sizetest = sizeof(test) / sizeof(test[0]);
	
	for (int i = 0; i < cycles; i++)
	{
		LED_Control(pattern5,size5,step_time,80);	
		LED_Control(pattern4,size4,step_time,80);	
		LED_Control(pattern3,size3,step_time,80);	
		LED_Control(pattern2,size2,step_time,80);	
		LED_Control(pattern1,size1,step_time,80);	
		LED_Control(pattern2,size2,step_time,80);	
		LED_Control(pattern3,size3,step_time,80);	
		LED_Control(pattern4,size4,step_time,80);	
		LED_Control(pattern5,size5,step_time+70,80);	
		
		//LED_Control(test,sizetest,step_time,20);
	}						
}

void square_corners (int cycles, int step_time)
{
	
	//shrink to LED111
	uint8_t* pattern1[] = {
		//front face square (15)
		LED111,LED211,LED311,LED411,LED511,
		LED112,LED113,LED114,
		LED512,LED513,LED514,
		LED115,LED215,LED315,LED415,LED515,
		
		//left side (6)
		LED121, LED131,LED141,
		LED125,LED135,LED145,
		
		//right side (6)
		LED521,LED531,LED541,
		LED525,LED535,LED545,

		//back side (15)
		LED151,LED251,LED351,LED451,LED551,
		LED152,LED153,LED154,
		LED552,LED553,LED554,
		LED155,LED255,LED355,LED455,LED555
	};
	
	uint8_t* pattern2[] = {
		//front face square (15)
		LED111,LED211,LED311,LED411,
		LED112,LED113,
		LED412,LED413,
		LED114,LED214,LED314,LED414,
		
		//left side (6)
		LED121, LED131,
		LED124,LED134,
		
		//right side (6)
		LED421,LED431,
		LED424,LED434,

		//back side (15)
		LED141,LED241,LED341,LED441,
		LED142,LED143,
		LED442,LED443,
		LED144,LED244,LED344,LED444
	};

	
	uint8_t* pattern3[] = {
		//front face square (15)
		LED111,LED211,LED311,
		LED112,
		LED312,
		LED113,LED213,LED313,
		
		//left side (6)
		LED121,
		LED123,
		
		//right side (6)
		LED321,
		LED323,

		//back side (15)
		LED131,LED231,LED331,
		LED132,
		LED332,
		LED133,LED233,LED333,
	};


	uint8_t* pattern4[] = {
		LED111,LED211,LED112,LED212,
		LED121,LED221,LED122,LED222
	};
	
	uint8_t* pattern5[] = {LED111};
	
	//shrink to LED511
	uint8_t* pattern6[] = {
		//front face square (15)
		LED511,LED211,LED311,LED411,
		LED212,LED213,
		LED512,LED513,
		LED514,LED214,LED314,LED414,
		
		//left side (6)
		LED221, LED231,
		LED224, LED234,
		
		//right side (6)
		LED521,LED531,
		LED524,LED534,

		//back side (15)
		LED541,LED241,LED341,LED441,
		LED242,LED243,
		LED542,LED543,
		LED544,LED244,LED344,LED444,
	};

	
	uint8_t* pattern7[] = {
		//front face square (15)
		LED511,LED311,LED411,
		LED312,
		LED512,
		LED513,LED313,LED413,
		
		//left side (6)
		LED321,LED521,
		
		//right side (6)
		LED323,LED523,

		//back side (15)
		LED531,LED331,LED431,
		LED332,
		LED532,
		LED533,LED333,LED433,
	};


	uint8_t* pattern8[] = {
		LED411,LED511,LED421,LED521,
		LED412,LED512,LED422,LED522		
	};
	
	uint8_t* pattern9[] = {LED511};
		
	//shrink to LED151	
	uint8_t* pattern10[] = {
		//front face square (15)
		LED121,LED221,LED321,LED421,
		LED122,LED123,
		LED422,LED423,
		LED124,LED224,LED324,LED424,
		
		//left side (6)
		LED131, LED141,
		LED134, LED144,
		
		//right side (6)
		LED431,LED441,
		LED434,LED444,

		//back side (15)
		LED151,LED251,LED351,LED451,
		LED152,LED153,
		LED452,LED453,
		LED154,LED254,LED354,LED454
	};

	
	uint8_t* pattern11[] = {
		//front face square (15)
		LED131,LED231,LED331,
		LED132,
		LED332,
		LED133,LED233,LED333,
		
		//left side (6)
		LED141,
		LED143,
		
		//right side (6)
		LED341,
		LED343,

		//back side (15)
		LED151,LED251,LED351,
		LED152,
		LED352,
		LED153,LED253,LED353,
	};


	uint8_t* pattern12[] = {
		LED141,LED241,LED142,LED242,
		LED151,LED251,LED152,LED252
	};
	
	uint8_t* pattern13[] = {LED151};
	
	
	//shrink to LED551
	uint8_t* pattern14[] = {
		//front face square (15)
		LED521,LED221,LED321,LED421,
		LED222,LED223,
		LED522,LED523,
		LED524,LED224,LED324,LED424,
		
		//left side (6)
		LED231, LED241,
		LED234, LED244,
		
		//right side (6)
		LED531,LED541,
		LED534,LED544,

		//back side (15)
		LED551,LED251,LED351,LED451,
		LED252,LED253,
		LED552,LED553,
		LED554,LED254,LED354,LED454,
	};

	
	uint8_t* pattern15[] = {
		//front face square (15)
		LED531,LED331,LED431,
		LED332,
		LED532,
		LED533,LED333,LED433,
		
		//left side (6)
		LED341,LED541,
		
		//right side (6)
		LED343,LED543,

		//back side (15)
		LED551,LED351,LED451,
		LED352,
		LED552,
		LED553,LED353,LED453,
	};


	uint8_t* pattern16[] = {
		LED441,LED541,LED451,LED551,
		LED442,LED542,LED452,LED552		
	};
	
	uint8_t* pattern17[] = {LED551};

	
	
	//shrink to LED115
	uint8_t* pattern18[] = {
		//front face square (15)
		LED112,LED212,LED312,LED412,
		LED113,LED114,
		LED413,LED414,
		LED115,LED215,LED315,LED415,
		
		//left side (6)
		LED122, LED132,
		LED125, LED135,
		
		//right side (6)
		LED422,LED432,
		LED425,LED435,

		//back side (15)
		LED142,LED242,LED342,LED442,
		LED143,LED144,
		LED443,LED444,
		LED145,LED245,LED345,LED445
	};

	
	uint8_t* pattern19[] = {
		//front face square (15)
		LED113,LED213,LED313,
		LED114,
		LED314,
		LED115,LED215,LED315,
		
		//left side (6)
		LED123,
		LED125,
		
		//right side (6)
		LED323,
		LED325,

		//back side (15)
		LED133,LED233,LED333,
		LED134,
		LED334,
		LED135,LED235,LED335,
	};


	uint8_t* pattern20[] = {
		LED115,LED215,LED114,LED214,
		LED125,LED225,LED124,LED224
	};
	
	uint8_t* pattern21[] = {LED115};
	
	
	
	
	//shrink to LED515
	uint8_t* pattern22[] = {
		//front face square (15)
		LED512,LED212,LED312,LED412,
		LED213,LED214,
		LED513,LED514,
		LED515,LED215,LED315,LED415,
		
		//left side (6)
		LED222, LED232,
		LED225, LED235,
		
		//right side (6)
		LED522,LED532,
		LED525,LED535,

		//back side (15)
		LED542,LED242,LED342,LED442,
		LED243,LED244,
		LED543,LED544,
		LED545,LED245,LED345,LED445,
	};

	
	uint8_t* pattern23[] = {
		//front face square (15)
		LED513,LED313,LED413,
		LED314,
		LED514,
		LED515,LED315,LED415,
		
		//left side (6)
		LED323,LED523,
		
		//right side (6)
		LED325,LED525,

		//back side (15)
		LED533,LED333,LED433,
		LED334,
		LED534,
		LED535,LED335,LED435,
	};


	uint8_t* pattern24[] = {
		LED414,LED514,LED424,LED524,
		LED415,LED515,LED425,LED525		
	};
	
	uint8_t* pattern25[] = {LED515};
	
	
	//shrink to LED151	
	uint8_t* pattern26[] = {
		//front face square (15)
		LED122,LED222,LED322,LED422,
		LED123,LED124,
		LED423,LED424,
		LED125,LED225,LED325,LED425,
		
		//left side (6)
		LED132, LED142,
		LED135, LED145,
		
		//right side (6)
		LED432,LED442,
		LED435,LED445,

		//back side (15)
		LED152,LED252,LED352,LED452,
		LED153,LED154,
		LED453,LED454,
		LED155,LED255,LED355,LED455
	};

	
	uint8_t* pattern27[] = {
		//front face square (15)
		LED133,LED233,LED333,
		LED134,
		LED334,
		LED135,LED235,LED335,
		
		//left side (6)
		LED143,
		LED145,
		
		//right side (6)
		LED343,
		LED345,

		//back side (15)
		LED153,LED253,LED353,
		LED154,
		LED354,
		LED155,LED255,LED355,
	};


	uint8_t* pattern28[] = {
		LED144,LED244,LED145,LED245,
		LED154,LED254,LED155,LED255
	};
	
	uint8_t* pattern29[] = {LED155};
	
	
	//shrink to LED555
	uint8_t* pattern30[] = {
		//front face square (15)
		LED522,LED222,LED322,LED422,
		LED223,LED224,
		LED523,LED524,
		LED525,LED225,LED325,LED425,
		
		//left side (6)
		LED232, LED242,
		LED235, LED245,
		
		//right side (6)
		LED532,LED542,
		LED535,LED545,

		//back side (15)
		LED552,LED252,LED352,LED452,
		LED253,LED254,
		LED553,LED554,
		LED555,LED255,LED355,LED455,
	};

	
	uint8_t* pattern31[] = {
		//front face square (15)
		LED533,LED333,LED433,
		LED334,
		LED534,
		LED535,LED335,LED435,
		
		//left side (6)
		LED343,LED543,
		
		//right side (6)
		LED345,LED545,

		//back side (15)
		LED553,LED353,LED453,
		LED354,
		LED554,
		LED555,LED355,LED455,
	};


	uint8_t* pattern32[] = {
		LED444,LED544,LED454,LED554,
		LED445,LED545,LED455,LED555		
	};
	
	uint8_t* pattern33[] = {LED555};

	
	size_t size1 = sizeof(pattern1) / sizeof(pattern1[0]);
	
	//shrink to LED111
	size_t size2 = sizeof(pattern2) / sizeof(pattern2[0]);
	size_t size3 = sizeof(pattern3) / sizeof(pattern3[0]);
	size_t size4 = sizeof(pattern4) / sizeof(pattern4[0]);
	size_t size5 = sizeof(pattern5) / sizeof(pattern5[0]);

	//shrink to LED511
	size_t size6 = sizeof(pattern6) / sizeof(pattern6[0]);
	size_t size7 = sizeof(pattern7) / sizeof(pattern7[0]);
	size_t size8 = sizeof(pattern8) / sizeof(pattern8[0]);
	size_t size9 = sizeof(pattern9) / sizeof(pattern9[0]);

	//shrink to LED151
	size_t size10 = sizeof(pattern10) / sizeof(pattern10[0]);
	size_t size11 = sizeof(pattern11) / sizeof(pattern11[0]);
	size_t size12 = sizeof(pattern12) / sizeof(pattern12[0]);
	size_t size13 = sizeof(pattern13) / sizeof(pattern13[0]);

	//shrink to LED551
	size_t size14 = sizeof(pattern14) / sizeof(pattern14[0]);
	size_t size15 = sizeof(pattern15) / sizeof(pattern15[0]);
	size_t size16 = sizeof(pattern16) / sizeof(pattern16[0]);
	size_t size17 = sizeof(pattern17) / sizeof(pattern17[0]);

	//shrink to LED115
	size_t size18 = sizeof(pattern18) / sizeof(pattern18[0]);
	size_t size19 = sizeof(pattern19) / sizeof(pattern19[0]);
	size_t size20 = sizeof(pattern20) / sizeof(pattern20[0]);
	size_t size21 = sizeof(pattern21) / sizeof(pattern21[0]);
	
	
	//shrink to LED515
	size_t size22 = sizeof(pattern22) / sizeof(pattern22[0]);
	size_t size23 = sizeof(pattern23) / sizeof(pattern23[0]);
	size_t size24 = sizeof(pattern24) / sizeof(pattern24[0]);
	size_t size25 = sizeof(pattern25) / sizeof(pattern25[0]);
	
	//shrink to LED155
	size_t size26 = sizeof(pattern26) / sizeof(pattern26[0]);
	size_t size27 = sizeof(pattern27) / sizeof(pattern27[0]);
	size_t size28 = sizeof(pattern28) / sizeof(pattern28[0]);
	size_t size29 = sizeof(pattern29) / sizeof(pattern29[0]);
		
	//shrink to LED555
	size_t size30 = sizeof(pattern30) / sizeof(pattern30[0]);
	size_t size31 = sizeof(pattern31) / sizeof(pattern31[0]);
	size_t size32 = sizeof(pattern32) / sizeof(pattern32[0]);
	size_t size33 = sizeof(pattern33) / sizeof(pattern33[0]);
		
		
	for (int i = 0; i < cycles; i++)
	{
		//shrink to LED111
		LED_Control(pattern1,size1,step_time,80);	
		LED_Control(pattern2,size2,step_time,80);	
		LED_Control(pattern3,size3,step_time,80);	
		LED_Control(pattern4,size4,step_time,80);			
		LED_Control(pattern5,size5,step_time,20);	
		LED_Control(pattern4,size4,step_time,80);			
		LED_Control(pattern3,size3,step_time,80);	
		LED_Control(pattern2,size2,step_time,80);	
		LED_Control(pattern1,size1,step_time,80);	
	
		//shrink to LED511
		LED_Control(pattern1,size1,step_time,80);	
		LED_Control(pattern6,size6,step_time,80);	
		LED_Control(pattern7,size7,step_time,80);	
		LED_Control(pattern8,size8,step_time,80);			
		LED_Control(pattern9,size9,step_time,20);	
		LED_Control(pattern8,size8,step_time,80);			
		LED_Control(pattern7,size7,step_time,80);	
		LED_Control(pattern6,size6,step_time,80);	
		LED_Control(pattern1,size1,step_time,80);	

		//shrink to LED151
		LED_Control(pattern1,size1,step_time,80);	
		LED_Control(pattern10,size10,step_time,80);	
		LED_Control(pattern11,size11,step_time,80);	
		LED_Control(pattern12,size12,step_time,80);			
		LED_Control(pattern13,size13,step_time,20);	
		LED_Control(pattern12,size12,step_time,80);			
		LED_Control(pattern11,size11,step_time,80);	
		LED_Control(pattern10,size10,step_time,80);	
		LED_Control(pattern1,size1,step_time,80);	
		

		//shrink to LED551
		LED_Control(pattern1,size1,step_time,80);	
		LED_Control(pattern14,size14,step_time,80);	
		LED_Control(pattern15,size15,step_time,80);	
		LED_Control(pattern16,size16,step_time,80);			
		LED_Control(pattern17,size17,step_time,20);	
		LED_Control(pattern16,size16,step_time,80);			
		LED_Control(pattern15,size15,step_time,80);	
		LED_Control(pattern14,size14,step_time,80);	
		LED_Control(pattern1,size1,step_time,80);	
		
		
		//shrink to LED115
		LED_Control(pattern1,size1,step_time,80);	
		LED_Control(pattern18,size18,step_time,80);	
		LED_Control(pattern19,size19,step_time,80);	
		LED_Control(pattern20,size20,step_time,80);			
		LED_Control(pattern21,size21,step_time,20);	
		LED_Control(pattern20,size20,step_time,80);			
		LED_Control(pattern19,size19,step_time,80);	
		LED_Control(pattern18,size18,step_time,80);	
		LED_Control(pattern1,size1,step_time,80);	
		
		//shrink to LED515
		LED_Control(pattern1,size1,step_time,80);	
		LED_Control(pattern22,size22,step_time,80);	
		LED_Control(pattern23,size23,step_time,80);	
		LED_Control(pattern24,size24,step_time,80);			
		LED_Control(pattern25,size25,step_time,20);	
		LED_Control(pattern24,size24,step_time,80);			
		LED_Control(pattern23,size23,step_time,80);	
		LED_Control(pattern22,size22,step_time,80);	
		LED_Control(pattern1,size1,step_time,80);	
		
		
		//shrink to LED155
		LED_Control(pattern1,size1,step_time,80);	
		LED_Control(pattern26,size26,step_time,80);	
		LED_Control(pattern27,size27,step_time,80);	
		LED_Control(pattern28,size28,step_time,80);			
		LED_Control(pattern29,size29,step_time,20);	
		LED_Control(pattern28,size28,step_time,80);			
		LED_Control(pattern27,size27,step_time,80);	
		LED_Control(pattern26,size26,step_time,80);	
		LED_Control(pattern1,size1,step_time,80);	
		
		
		//shrink to LED555
		LED_Control(pattern1,size1,step_time,80);	
		LED_Control(pattern30,size30,step_time,80);	
		LED_Control(pattern31,size31,step_time,80);	
		LED_Control(pattern32,size32,step_time,80);			
		LED_Control(pattern33,size33,step_time,20);	
		LED_Control(pattern32,size32,step_time,80);			
		LED_Control(pattern31,size31,step_time,80);	
		LED_Control(pattern30,size30,step_time,80);	
		LED_Control(pattern1,size1,step_time,80);	
	}

}
	


void fireworks(int cycles, int step_time)
{
	uint8_t* pattern1[] = {LED331};
	uint8_t* pattern2[] = {LED332};
	uint8_t* pattern3[] = {LED333};
	uint8_t* pattern4[] = {LED334};
	
	uint8_t* pattern5[] = {LED225, LED425, LED245, LED445, LED325, LED435, LED345, LED235};
	uint8_t* pattern6[] = {LED114, LED514, LED154, LED554, LED314, LED534, LED354, LED134};
	uint8_t* pattern7[] = {LED114, LED513, LED153, LED554, LED313, LED534, LED353, LED134};
	uint8_t* pattern8[] = {LED113, LED512, LED152, LED553, LED312, LED533, LED352, LED133};
	uint8_t* pattern9[] = {LED112, LED511, LED151, LED552, LED311, LED532, LED351, LED132};
	uint8_t* pattern10[] = {LED111, LED551, LED531, LED131};
	
	size_t size1 = sizeof(pattern1) / sizeof(pattern1[0]);
	size_t size2 = sizeof(pattern2) / sizeof(pattern2[0]);
	size_t size3 = sizeof(pattern3) / sizeof(pattern3[0]);
	size_t size4 = sizeof(pattern4) / sizeof(pattern4[0]);
	size_t size5 = sizeof(pattern5) / sizeof(pattern5[0]);
	size_t size6 = sizeof(pattern6) / sizeof(pattern6[0]);
	size_t size7 = sizeof(pattern7) / sizeof(pattern7[0]);
	size_t size8 = sizeof(pattern8) / sizeof(pattern8[0]);
	size_t size9 = sizeof(pattern9) / sizeof(pattern9[0]);	
	size_t size10 = sizeof(pattern10) / sizeof(pattern10[0]);	


	for (int i = 0; i < cycles; i++)
	{
		//shrink to LED111
		LED_Control(pattern1,size1,step_time,10);	
		LED_Control(pattern2,size2,step_time,10);	
		LED_Control(pattern3,size3,step_time,10);	
		LED_Control(pattern4,size4,step_time,10);	
		LED_Control(pattern5,size5,step_time*1.5,50);	
		LED_Control(pattern6,size6,step_time*1.5,50);	
		LED_Control(pattern7,size7,step_time*1.5,40);	
		LED_Control(pattern8,size8,step_time*1.5,25);	
		LED_Control(pattern9,size9,step_time*1.5,10);	
		LED_Control(pattern10,size10,step_time*1.5,5);	
		SysTick_Delay1ms(step_time);	
	}

};


void spell_ECE425 (int cycles, int step_time)
{
	uint8_t* E1[] = {
		LED115, LED215, LED315, LED415, LED515,
		LED114,
		LED113, LED213, LED313, LED413,
		LED112,										
		LED111, LED211, LED311, LED411, LED511
	};

	uint8_t* E2[] = {
		LED125, LED225, LED325, LED425, LED525,
		LED124,
		LED123, LED223, LED323, LED423,
		LED122,										
		LED121, LED221, LED321, LED421, LED521
	};

	uint8_t* E3[] = {
		LED135, LED235, LED335, LED435, LED535,
		LED134,
		LED133, LED233, LED333, LED433,
		LED132,										
		LED131, LED231, LED331, LED431, LED531
	};
	
	uint8_t* E4[] = {
		LED145, LED245, LED345, LED445, LED545,
		LED144,
		LED143, LED243, LED343, LED443,
		LED142,										
		LED141, LED241, LED341, LED441, LED541
	};

	uint8_t* E5[] = {
		LED155, LED255, LED355, LED455, LED555,
		LED154,
		LED153, LED253, LED353, LED453,
		LED152,										
		LED151, LED251, LED351, LED451, LED551
	};
	
	
	
	uint8_t* C1[] = {
						LED215, LED315, LED415, LED515,
		LED114,
		LED113, 
		LED112,										
						LED211, LED311, LED411, LED511					
	};


	uint8_t* C2[] = {
						LED225, LED325, LED425, LED525,
		LED124,
		LED123, 
		LED122,										
						LED221, LED321, LED421, LED521					
	};


	uint8_t* C3[] = {
						LED235, LED335, LED435, LED535,
		LED134,
		LED133, 
		LED132,										
						LED231, LED331, LED431, LED531					
	};
	
	uint8_t* C4[] = {
						LED245, LED345, LED445, LED545,
		LED144,
		LED143, 
		LED142,										
						LED241, LED341, LED441, LED541					
	};

	uint8_t* C5[] = {
						LED255, LED355, LED455, LED555,
		LED154,
		LED153, 
		LED152,										
						LED251, LED351, LED451, LED551					
	};
	
	uint8_t* FOUR1[] = {
		LED115, 							 	LED415,
		LED114,									LED414,
		LED113, LED213, LED313, LED413, LED513,
														LED412,
														LED411, 
	};
	
	uint8_t* FOUR2[] = {
		LED125, 							 	LED425,
		LED124,									LED424,
		LED123, LED223, LED323, LED423, LED523,
														LED422,
														LED421, 
	};
	
	uint8_t* FOUR3[] = {
		LED135, 							 	LED435,
		LED134,									LED434,
		LED133, LED233, LED333, LED433, LED533,
														LED432,
														LED431, 
	};
	
	uint8_t* FOUR4[] = {
		LED145, 							 	LED445,
		LED144,									LED444,
		LED143, LED243, LED343, LED443, LED543,
														LED442,
														LED441, 
	};
	
	uint8_t* FOUR5[] = {
		LED155, 							 	LED455,
		LED154,									LED454,
		LED153, LED253, LED353, LED453, LED553,
														LED452,
														LED451, 
	};

		uint8_t* TWO1[] = {
		LED115, LED215, LED315, LED415, LED515,
																	  LED514,
		LED113, LED213, LED313, LED413, LED513,
		LED112,												
		LED111, LED211, LED311, LED411, LED511
	};	
	
		uint8_t* TWO2[] = {
		LED125, LED225, LED325, LED425, LED525,
																	  LED524,
		LED123, LED223, LED323, LED423, LED523,
		LED122,												
		LED121, LED221, LED321, LED421, LED521
	};
	
	uint8_t* TWO3[] = {
		LED135, LED235, LED335, LED435, LED535,
																	  LED534,
		LED133, LED233, LED333, LED433, LED533,
		LED132,												
		LED131, LED231, LED331, LED431, LED531
	};
	
		uint8_t* TWO4[] = {
		LED145, LED245, LED345, LED445, LED545,
																	  LED544,
		LED143, LED243, LED343, LED443, LED543,
		LED142,												
		LED141, LED241, LED341, LED441, LED541
	};
		
		uint8_t* TWO5[] = {
		LED155, LED255, LED355, LED455, LED555,
																	  LED554,
		LED153, LED253, LED353, LED453, LED553,
		LED152,												
		LED151, LED251, LED351, LED451, LED551
	};
		

		uint8_t* FIVE1[] = {
		LED115, LED215, LED315, LED415, LED515,
		LED114, 
		LED113, LED213, LED313, LED413, LED513,
																	  LED512,			
		LED111, LED211, LED311, LED411, LED511
	};

		uint8_t* FIVE2[] = {
		LED125, LED225, LED325, LED425, LED525,
		LED124, 
		LED123, LED223, LED323, LED423, LED523,
																	  LED522,			
		LED121, LED221, LED321, LED421, LED521
	};		
		
		uint8_t* FIVE3[] = {
		LED135, LED235, LED335, LED435, LED535,
		LED134, 
		LED133, LED233, LED333, LED433, LED533,
																	  LED532,			
		LED131, LED231, LED331, LED431, LED531
	};	
		
		uint8_t* FIVE4[] = {
		LED145, LED245, LED345, LED445, LED545,
		LED144, 
		LED143, LED243, LED343, LED443, LED543,
																	  LED542,			
		LED141, LED241, LED341, LED441, LED541
	};	

		uint8_t* FIVE5[] = {
		LED155, LED255, LED355, LED455, LED555,
		LED154, 
		LED153, LED253, LED353, LED453, LED553,
																	  LED552,			
		LED151, LED251, LED351, LED451, LED551
	};	
		
	size_t size_E1 = sizeof(E1) / sizeof(E1[0]);
	size_t size_E2 = sizeof(E2) / sizeof(E2[0]);
	size_t size_E3 = sizeof(E3) / sizeof(E3[0]);
	size_t size_E4 = sizeof(E4) / sizeof(E4[0]);
	size_t size_E5 = sizeof(E5) / sizeof(E5[0]);
	
	size_t size_C1 = sizeof(C1) / sizeof(C1[0]);
	size_t size_C2 = sizeof(C2) / sizeof(C2[0]);
	size_t size_C3 = sizeof(C3) / sizeof(C3[0]);
	size_t size_C4 = sizeof(C4) / sizeof(C4[0]);
	size_t size_C5 = sizeof(C5) / sizeof(C5[0]);

	size_t size_FOUR1 = sizeof(FOUR1) / sizeof(FOUR1[0]);
	size_t size_FOUR2 = sizeof(FOUR2) / sizeof(FOUR2[0]);
	size_t size_FOUR3 = sizeof(FOUR3) / sizeof(FOUR3[0]);
	size_t size_FOUR4 = sizeof(FOUR4) / sizeof(FOUR4[0]);
	size_t size_FOUR5 = sizeof(FOUR5) / sizeof(FOUR5[0]);
	
	size_t size_TWO1 = sizeof(TWO1) / sizeof(TWO1[0]);
	size_t size_TWO2 = sizeof(TWO2) / sizeof(TWO2[0]);
	size_t size_TWO3 = sizeof(TWO3) / sizeof(TWO3[0]);
	size_t size_TWO4 = sizeof(TWO4) / sizeof(TWO4[0]);
	size_t size_TWO5 = sizeof(TWO5) / sizeof(TWO5[0]);
	
	size_t size_FIVE1 = sizeof(FIVE1) / sizeof(FIVE1[0]);
	size_t size_FIVE2 = sizeof(FIVE2) / sizeof(FIVE2[0]);
	size_t size_FIVE3 = sizeof(FIVE3) / sizeof(FIVE3[0]);
	size_t size_FIVE4 = sizeof(FIVE4) / sizeof(FIVE4[0]);
	size_t size_FIVE5 = sizeof(FIVE5) / sizeof(FIVE5[0]);


	for (int i = 0; i < cycles; i++)
	{
		LED_Control(E5,size_E5,step_time,50);
		LED_Control(E4,size_E4,step_time,50);
		LED_Control(E3,size_E3,step_time,50);
		LED_Control(E2,size_E2,step_time,50);
		LED_Control(E1,size_E1,step_time,50);

		LED_Control(C5,size_C5,step_time,50);
		LED_Control(C4,size_C4,step_time,50);
		LED_Control(C3,size_C3,step_time,50);
		LED_Control(C2,size_C2,step_time,50);
		LED_Control(C1,size_C1,step_time,50);		

		LED_Control(E5,size_E5,step_time,50);
		LED_Control(E4,size_E4,step_time,50);
		LED_Control(E3,size_E3,step_time,50);
		LED_Control(E2,size_E2,step_time,50);
		LED_Control(E1,size_E1,step_time,50);

		LED_Control(FOUR5,size_FOUR5,step_time,50);
		LED_Control(FOUR4,size_FOUR4,step_time,50);
		LED_Control(FOUR3,size_FOUR3,step_time,50);
		LED_Control(FOUR2,size_FOUR2,step_time,50);
		LED_Control(FOUR1,size_FOUR1,step_time,50);		
		
		LED_Control(TWO5,size_TWO5,step_time,50);
		LED_Control(TWO4,size_TWO4,step_time,50);
		LED_Control(TWO3,size_TWO3,step_time,50);
		LED_Control(TWO2,size_TWO2,step_time,50);
		LED_Control(TWO1,size_TWO1,step_time,50);	
		
		LED_Control(FIVE5,size_FIVE5,step_time,50);
		LED_Control(FIVE4,size_FIVE4,step_time,50);
		LED_Control(FIVE3,size_FIVE3,step_time,50);
		LED_Control(FIVE2,size_FIVE2,step_time,50);
		LED_Control(FIVE1,size_FIVE1,step_time,50);		
	}

}

