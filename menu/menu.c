#include "oled.h"
#include "menu.h"
static void (*current_operation_index)(void);
typedef struct
{
    uint8_t current;//当前状态索引号
    uint8_t next; //向下一个
	uint8_t last;//向上一个
    uint8_t enter; //确定
	uint8_t back;	//返回
    void (*current_operation)(void); //当前状态应该执行的操作
} Menu_table;

Menu_table  table[13]=
{
    {0,0,0,1,0,(*fun0)},//一级界面  时钟界面
		
    {1,2,4,6,0,(*fun1)},
    {2,3,1,7,0,(*fun2)},
    {3,4,2,8,0,(*fun3)},
    {4,1,3,9,0,(*fun4)},
};

uint8_t  func_index = 0;//主程序此时所在界面的索引值
void  Menu_key_set(void)
{
		if(next_key == 0)
		{   
			//HAL_Delay(15);
			while(next_key==0);
			func_index=table[func_index].next;//按键next按下后的索引号
			OLED_Clear();
		}
	 if(last_key == 0)
		{
			//HAL_Delay(15);
			while(last_key==0);
			func_index=table[func_index].last;
			OLED_Clear();
		}
		if(enter_key == 0)
		{
			//HAL_Delay(15);
			while(enter_key==0);
			func_index=table[func_index].enter;
			OLED_Clear();
		}
		if(back_key == 0)
		{
			//HAL_Delay(15);
			while(back_key==0);
			func_index=table[func_index].back;
			OLED_Clear();
		}

  current_operation_index=table[func_index].current_operation;//执行当前索引号所对应的功能函数。
  (*current_operation_index)();//执行当前操作函数
}
void fun0(void)
{
	OLED_ShowString(0,0,"hello world",16,1);
	OLED_ShowString(0,16,"first",16,1);
	OLED_Refresh();
}
void fun1()
{
	OLED_ShowString(0,0,"2-1",16,0);
	OLED_ShowString(0,16,"2-2",16,1);
	OLED_ShowString(0,32,"2-3",16,1);
	OLED_ShowString(0,48,"2-4",16,1);
	OLED_Refresh();
}
void fun2()
{
	OLED_ShowString(0,0,"2-1",16,1);
	OLED_ShowString(0,16,"2-2",16,0);
	OLED_ShowString(0,32,"2-3",16,1);
	OLED_ShowString(0,48,"2-4",16,1);
	OLED_Refresh();
}
void fun3()
{
	OLED_ShowString(0,0,"2-1",16,1);
	OLED_ShowString(0,16,"2-2",16,1);
	OLED_ShowString(0,32,"2-3",16,0);
	OLED_ShowString(0,48,"2-4",16,1);
	OLED_Refresh();
}
void fun4()
{
	OLED_ShowString(0,0,"2-1",16,1);
	OLED_ShowString(0,16,"2-2",16,1);
	OLED_ShowString(0,32,"2-3",16,1);
	OLED_ShowString(0,48,"2-4",16,0);
	OLED_Refresh();
}


