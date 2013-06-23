#ifndef _menue_h_
#define _menue_h_


#include <stdio.h>
#include <avr/pgmspace.h> 
#include <stdlib.h>
#include <stddef.h> 


#define LCD_ROWS 4
#define LCD_COLUMNS 20

#define GetAddr(ptr,field) (void*) pgm_read_word( ( (uint8_t*) ptr) + offsetof (struct menu_item,field) )
//zwraca nam wskaznik na podane pole w strukturze

//FUNCTION TO SET MENU
	void Menu_Show();
	void Menu_SelectNext();
	void Menu_SelectPrev();
	void MenuClick();
	void MenuBack();
	void change_tmpUP();
	void change_tmpDown();
	void change_hUP();
	void change_hDown();
// END FUNCTION

typedef void (*menuitemfuncptr)(); //

struct PROGMEM menu_item
{
	const prog_char *text; //wskaznik na tekst w FLASHU! NAZWA MENU
	menuitemfuncptr menuitemfunc; // WSKAZNIK DO Wywolywanej funkcji po wybraniu danej pozycji menu
	const struct menu_item *parent; //rodzic
	const struct menu_item *submenu; //syn menu submenu
	const struct menu_item *prev; //poprzednik ziaaa
	const struct menu_item *next; //nastepny
};


#endif