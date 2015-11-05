/*
 * Menu.c
 *
 *  Created on: 31.10.2015
 *      Author: Pascal
 */

#include "Menu.h"
#include "FDisp1.h"
#include "FRTOS1.h"
#include "UTIL1.h"
#include "stdlib.h"

char* menus[] = { "Snake\n", "Settings\n", "LED\n" };

void menu_title(void) {
	FDisp1_PixelDim x, y;
	FDisp1_PixelDim charHeight, totalHeight;
	GFONT_Callbacks *font = GFONT1_GetFont();
	GDisp1_Clear();
	FDisp1_GetFontHeight(font, &charHeight, &totalHeight);

	x = (GDisp1_GetWidth()
			- FDisp1_GetStringWidth((unsigned char*) "Menue", font, NULL)) / 2;
	y = 0;
	FDisp1_WriteString((unsigned char*) "Menue", GDisp1_COLOR_BLACK, &x, &y,
			font);

	GDisp1_UpdateFull();
}

void drawMenue(void) {
	int select = 0;
}

static void MenuTask(void *pvParameters) {
	menu_title();
	uint8_t selected = 2;
	uint8_t nbrOfMenus = sizeof(menus) / sizeof(char*);
	uint8_t buf[5];
	UTIL1_Num8uToStr(buf, sizeof(buf), nbrOfMenus);

	FDisp1_PixelDim charHeight, totalHeight;
	GFONT_Callbacks *font = GFONT1_GetFont();
	FDisp1_GetFontHeight(font, &charHeight, &totalHeight);
	FDisp1_PixelDim x, y;

	GDisp1_PixelDim radius = 2;
	GDisp1_PixelDim x_point = 5;
	GDisp1_PixelDim y_point = 10 + 12 * selected + charHeight / 2 - radius / 2;
	GDisp1_PixelColor circleColor = PDC1_PIXEL_BLACK;

	GDisp1_Clear();
	menu_title();
	int i = 0;
	x = 10;
	y = 10;
	uint8_t buf2[5];

	while (i < nbrOfMenus) {
		FDisp1_WriteString((unsigned char*) menus[i], GDisp1_COLOR_BLACK, &x,
				&y, font);
		i++;
	}

	GDisp1_DrawFilledCircle(x_point, y_point, radius, circleColor);
	//FDisp1_WriteString((unsigned char*) buf, GDisp1_COLOR_BLACK, &x, &y, font);
	//FDisp1_WriteString((unsigned char*) menus[1], GDisp1_COLOR_BLACK, &x, &y, font);
	GDisp1_UpdateFull();
	WAIT1_Waitms(300);
	for (;;) {
	}
}

void MENU_Init(void) {
	if (FRTOS1_xTaskCreate(
			MenuTask, /* pointer to the task */
			"Menu", /* task name for kernel awareness debugging */
			configMINIMAL_STACK_SIZE, /* task stack size */
			(void*)NULL, /* optional task startup argument */
			tskIDLE_PRIORITY, /* initial priority */
			(xTaskHandle*)NULL /* optional task handle to create */
	) != pdPASS) {
		/*lint -e527 */
		for (;;) {
		}; /* error! probably out of memory */
		/*lint +e527 */
	}
}

void MENU_deinit(void) {
	//Nothing to do here
}
