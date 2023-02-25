#ifndef __menu_h
#define __menu_h
#include "stm32f1xx_hal.h"
#define back_key	  HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_7)
#define enter_key  	HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_4)
#define last_key   	 HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5)
#define next_key	   HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)
void  Menu_key_set(void);
void fun0(void);
void fun1(void);
void fun2(void);
void fun3(void);
void fun4(void);
#endif

