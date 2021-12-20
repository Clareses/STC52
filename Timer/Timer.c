/*
 * @Description  : Timer模板文件
 * @Author       : FZU Liao
 * @Date         : 2021-12-19 19:50:11
 * @LastEditors  : Liao
 * @LastEditTime : 2021-12-20 13:23:26
 * @FilePath     : \Timer.c
 * Copyright 2021 FZU Liao, All Rights Reserved. 
 */
#include<regx52rc.h>
#include "Interrupt.h"


//宏定义部分
//-----------------------------------------------------------------

//Timer MODE控制 REGISTER
#define TIMER0_MODE_REGISTER TMOD
#define TIMER2_MODE_REGISTER T2MOD

//Timer0
/********************************/
#define TIMER_T0_ALLOW TR0 //定时器开关
#define TIMER_T0_TH TH0
#define TIMER_T0_TL TL0
#define TIMER_T0_TF TF0 //中断溢出位

//Timer2
/********************************/
#define TIMER_T2_ALLOW TR2 //定时器开关
#define TIMER_T2_TF TF2 //中断溢出位



//函数实现部分
//-----------------------------------------------------------------

//TIMER0
/********************************/

void Timer_T0_SetMode(int CLKorT,int Mode){
    TIMER0_MODE_REGISTER&=0xF0;
    TIMER0_MODE_REGISTER|=Mode;
    TIMER0_MODE_REGISTER|=CLKorT<<2;
}

void Timer_T0_Enable(){
    TIMER_T0_ALLOW=1;
    Interrupt_ALL_Enable();
    Interrupt_TIMEINT0_Enable();
}

void Timer_T0_Disable(){
    TIMER_T0_ALLOW=0;
    Interrupt_ALL_Disable();
    Interrupt_TIMEINT0_Disable();
}

void Timer_T0_SetFunc(void (*func)()){
    Interrupt_TIMEINT0_SetFunc(func);
}

void Timer_T0_SetPriority(int priority){
    Interrupt_TIMEINT0_SetPriority(priority);
}


void Timer_T0_Init(int CLKorT,int Mode,int usx,int priority,void (*func)()){
    Timer_T0_SetMode(CLKorT,Mode);
    TIMER_T0_TH=(65535-usx)/256;
    TIMER_T0_TL=(65535-usx)%256;
    Timer_T0_SetPriority(priority);
    Timer_T0_SetFunc(func);
    TIMER_T0_TF=0;
}

//TIMER2
/********************************/
    
void Timer_T2_SetMode(int CLKorT,int Mode){
    TIMER2_MODE_REGISTER&=0xF0;
    TIMER2_MODE_REGISTER|=Mode;
}

void Timer_T2_Enable(){
    TIMER_T2_ALLOW=1;
    Interrupt_ALL_Enable();
    Interrupt_TIMEINT2_Enable();
}

void Timer_T2_Disable(){
    TIMER_T2_ALLOW=0;
    Interrupt_ALL_Disable();
    Interrupt_TIMEINT2_Disable();
}

void Timer_T2_SetFunc(void (*func)()){
    Interrupt_TIMEINT2_SetFunc(func);
}

void Timer_T2_SetPriority(int priority){
    Interrupt_TIMEINT2_SetPriority(priority);
}


void Timer_T2_Init(int CLKorT,int Mode,int usx,int priority,void (*func)()){
    Timer_T2_SetMode(CLKorT,Mode);
    Timer_T2_SetPriority(priority);
    Timer_T2_SetFunc(func);
    TIMER_T2_TF=0;
}