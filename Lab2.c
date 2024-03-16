// ****************** Lab2.c ***************
// Program written by: put your names here
// Date Created: 1/18/2017 
// Last Modified: 12/31/2022 
#include "Lab2.h"
// Put your name and EID in the next two lines
char Name[] = "Vu";
char EID[] = "20210944";

#include <stdint.h>
#include <stdlib.h>

// Inputs: x1,y1 is the first point
//         x2,y2 is the second point
// Output: calculate distance
// see UART window to see if you have square, Manhattan or ECE319K distance
// The input/output values will be displayed in the UART window
int32_t Distance(int32_t x1, int32_t y1, int32_t x2, int32_t y2){
// Replace this following line with your solution
	int32_t Square_distance = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	int32_t Manhattan_distance = abs(x1 - x2) + abs(y1 - y2);
	int32_t ECE319K_distance = 0;
	if ( abs(x1 - x2) >= abs(y1 - y2) )
	{
		ECE319K_distance = abs(x1 - x2);
	}else
	{
		ECE319K_distance = abs(y1 - y2);
	}
  return Square_distance;
}

// Inputs: rect1 is x1,y1,w1,h1 the first rectangle
//         rect2 is x2,y2,w2,h2 the second rectangle
// Output: 1 if the rectangles overlap
//         0 if the rectances do not overlap
// Notes: x1 is rect1[0]  x2 is rect2[0]
//        y1 is rect1[1]  y2 is rect2[1]
//        w1 is rect1[2]  w2 is rect2[2]
//        h1 is rect1[3]  h2 is rect2[3]
// The input/output values will be displayed in the UART window
int32_t OverLap(int32_t rect1[4], int32_t rect2[4]){
// Replace this following line with your solution
	//1st Rect boundary
	int32_t top1 		= rect1[1];
	int32_t bot1 		= rect1[1] - rect1[3];
	int32_t left1 	= rect1[0];
	int32_t right1 	= rect1[0] + rect1[2];

	//2nd Rect boundary
	int32_t top2 		= rect2[1];
	int32_t bot2 		= rect2[1] - rect2[3];
	int32_t left2 	= rect2[0];
	int32_t right2 	= rect2[0] + rect2[2];
	
	//Overlap condition
	if ((top1 > bot2) &&
			(bot1 < top2) &&
			(left1 < right2) &&
			(right1 > left2))
	{
		return 1;
	}else return 0;
}
// do not edit this 2-D array
const char Hello[4][8] ={
   "Hello  ",    // language 0
   "\xADHola! ", // language 1
   "Ol\xA0    ", // language 2
   "All\x83   "  // language 3
};
// Hello[0][0] is 'H'
// Hello[0][1] is 'e'
// Hello[0][2] is 'l'
// Hello[0][3] is 'l'
// Hello[0][4] is 'o'
// Hello[1][0] is 0xAD
// Hello[1][1] is 'H'
// Hello[1][2] is 'o'
// Hello[1][3] is 'l'
// Hello[1][4] is 'a'
// Hello[1][5] is '!'
void LCD_OutChar(char letter);

// Print 7 characters of the hello message
// Inputs: language 0 to 3
// Output: none
// You should call LCD_OuChar exactly 7 times
void SayHello(uint32_t language){
// Replace this following line with your solution
	const char *helloMessage = Hello[language];
	for (int i = 0; i < 7; i++) 
	{ 
		LCD_OutChar(helloMessage[i]); 
	} 
}


