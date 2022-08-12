/*
 * atmega23.c
 *
 * Created: 7/29/2022 3:49:20 PM
 * Author : tokam
 */ 

#include "Application/App.h"

int main(void)
{
	App_init();
	
	while (1)
	{
		normal_mode();
	}
}