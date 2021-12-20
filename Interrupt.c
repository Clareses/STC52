/*
 * @Description  : Interrupt模板文件
 * @Author       : FZU Liao
 * @Date         : 2021-12-19 19:50:11
 * @LastEditors  : Liao
 * @LastEditTime : 2021-12-20 13:31:18
 * @FilePath     : \Interrupt.c
 * Copyright 2021 FZU Liao, All Rights Reserved. 
 */
#include<regx52rc.h>

//宏定义部分
//-----------------------------------------------------------------

//中断总开关
/********************************/
#define INTERRUPT_ALL_ALLOW EA

//中断独立开关
/********************************/
#define INTERRUPT_EXINT0_ALLOW EX0
#define INTERRUPT_TIMEINT0_ALLOW ET0
#define INTERRUPT_EXINT1_ALLOW EX1
#define INTERRUPT_TIMEINT1_ALLOW ET1
#define INTERRUPT_UARTINT_ALLOW ES
#define INTERRUPT_TIMEINT2_ALLOW ET2

//中断模式设置
/********************************/
#define INTERRUPT_EXINT_MODE0 0
#define INTERRUPT_EXINT_MODE1 1

#define INTERRUPT_EXINT0_MODE IT0
#define INTERRUPT_EXINT1_MODE IT1

//中断优先级设置
/********************************/
#define INTERRUPT_PRIORITY_0 0
#define INTERRUPT_PRIORITY_1 1
#define INTERRUPT_PRIORITY_2 2
#define INTERRUPT_PRIORITY_3 3

#define INTERRUPT_REGISER_PRIORITY IPH

#define INTERRUPT_EXINT0_PRIORITY_IP PX0
#define INTERRUPT_TIMEINT0_PRIORITY_IP PT0
#define INTERRUPT_EXINT1_PRIORITY_IP PX1
//TIMER1不可定制
#define INTERRUPT_UARTINT_PRIORITY_IP PS
#define INTERRUPT_TIMEINT2_PRIORITY_IP PT2

//特殊内部中断
#define INTERRUPT_UART_RECEIVEINT RI
#define INTERRUPT_UART_TRANSMITINT TI



//中断函数指针定义
/********************************/
void (*Interrupt_EXINT0_Func)();
void (*interrupt_TIMEINT0_Func)();
void (*Interrupt_EXINT1_Func)();
//TIMER1仅UART可用，不支持自定义
void (*Interrupt_UARTINT_Func)();
void (*interrupt_TIMEINT2_Func)();



//函数实现部分
//-----------------------------------------------------------------

//用户函数
/********************************/


/*总开关*******************************/
void Interrupt_ALL_Enable(){
    INTERRUPT_ALL_ALLOW=1;
}
void Interrupt_ALL_Disable(){
    INTERRUPT_ALL_ALLOW=0;
}

/*中断独立开关*******************************/
void Interrupt_EXINT0_Enable(){
    INTERRUPT_EXINT0_ALLOW=1;
}
void Interrupt_TIMEINT0_Enable(){
    INTERRUPT_TIMEINT0_ALLOW=1;
}
void Interrupt_EXINT1_Enable(){
    INTERRUPT_EXINT1_ALLOW=1;
}
void Interrupt_TIMEINT1_Enable(){
    INTERRUPT_TIMEINT1_ALLOW=1;
}
void Interrupt_UARTINT_Enable(){
    INTERRUPT_UARTINT_ALLOW=1;
}
void Interrupt_TIMEINT2_Enable(){
    INTERRUPT_TIMEINT2_ALLOW=1;
}
void Interrupt_EXINT0_Disable(){
    INTERRUPT_EXINT0_ALLOW=0;
}
void Interrupt_TIMEINT0_Disable(){
    INTERRUPT_TIMEINT0_ALLOW=0;
}
void Interrupt_EXINT1_Disable(){
    INTERRUPT_EXINT1_ALLOW=0;
}
void Interrupt_TIMEINT1_Disable(){
    INTERRUPT_TIMEINT1_ALLOW=0;
}
void Interrupt_UARTINT_Disable(){
    INTERRUPT_UARTINT_ALLOW=0;
}
void Interrupt_TIMEINT2_Disable(){
    INTERRUPT_TIMEINT2_ALLOW=0;
}

/*中断函数初始化*******************************/
void Interrupt_EXINT0_SetFunc(void (*func)()){
    Interrupt_EXINT0_Func=func;
}
void Interrupt_TIMEINT0_SetFunc(void (*func)()){
    interrupt_TIMEINT0_Func=func;
}
void Interrupt_EXINT1_SetFunc(void (*func)()){
    Interrupt_EXINT1_Func=func;
}
//TIMER1专用于UART，不能自定义
void Interrupt_UARTINT_SetFunc(void (*func)()){
    Interrupt_UARTINT_Func=func;
}
void Interrupt_TIMEINT2_SetFunc(void (*func)()){
    interrupt_TIMEINT2_Func=func;
}

/*中断优先级设定*******************************/
void Interrupt_EXINT0_SetPriority(int Priority){
    INTERRUPT_EXINT0_PRIORITY_IP=Priority%2;
    INTERRUPT_REGISER_PRIORITY&=0xFE;
    INTERRUPT_REGISER_PRIORITY|=(Priority/2);
}
void Interrupt_TIMEINT0_SetPriority(int Priority){
    INTERRUPT_TIMEINT0_PRIORITY_IP=Priority%2;
    INTERRUPT_REGISER_PRIORITY&=0xFD;
    INTERRUPT_REGISER_PRIORITY|=(Priority/2)<<1;
}
void Interrupt_EXINT1_SetPriority(int Priority){
    INTERRUPT_EXINT1_PRIORITY_IP=Priority%2;
    INTERRUPT_REGISER_PRIORITY&=0xFB;
    INTERRUPT_REGISER_PRIORITY|=(Priority/2)<<2;
}

//TIMER1专用于UART，不能自定义

void Interrupt_UARTINT_SetPriority(int Priority){
    INTERRUPT_UARTINT_PRIORITY_IP=Priority%2;
    INTERRUPT_REGISER_PRIORITY&=0xEF;
    INTERRUPT_REGISER_PRIORITY|=(Priority/2)<<4;
}
void Interrupt_TIMEINT2_SetPriority(int Priority){
    INTERRUPT_TIMEINT2_PRIORITY_IP=Priority%2;
    INTERRUPT_REGISER_PRIORITY&=0xDF;
    INTERRUPT_REGISER_PRIORITY|=(Priority/2)<<5;
}


/*中断初始化*******************************/
void Interrupt_EXINT0_Init(int Mode,int Priority,void (*Func)()){
    INTERRUPT_EXINT0_MODE=Mode;
    Interrupt_EXINT0_SetPriority(Priority);
    Interrupt_EXINT0_SetFunc(Func);
}
void Interrupt_TIMEINT0_Init(int Priority,void (*Func)()){
    Interrupt_TIMEINT0_SetPriority(Priority);
    Interrupt_TIMEINT0_SetFunc(Func);
}
void Interrupt_EXINT1_Init(int Mode,int Priority,void (*Func)()){
    INTERRUPT_EXINT1_MODE=Mode;
    Interrupt_EXINT1_SetPriority(Priority);
    Interrupt_EXINT1_SetFunc(Func);
}
//TIMER1专用于UART，不能自定义
void Interrupt_UARTINT_Init(int Priority,void (*Func)()){
    Interrupt_UARTINT_SetPriority(Priority);
    Interrupt_UARTINT_SetFunc(Func);
}
void Interrupt_TIMEINT2_Init(int Priority,void (*Func)()){
    Interrupt_TIMEINT2_SetPriority(Priority);
    Interrupt_TIMEINT2_SetFunc(Func);
}

//中断调用函数
/********************************/
void InterruptRoutine0() interrupt 0{
    (*Interrupt_EXINT0_Func)();
}
void InterruptRoutine1() interrupt 1{
    (*interrupt_TIMEINT0_Func)();
}
void InterruptRoutine2() interrupt 2{
    (*Interrupt_EXINT1_Func)();
}
//Timer1无法定制
void InterruptRoutine4() interrupt 4{
    if(INTERRUPT_UART_RECEIVEINT==1){
        INTERRUPT_UART_RECEIVEINT=0;
        (*Interrupt_UARTINT_Func)();
    }
}
void InterruptRoutine5() interrupt 5{
    (*interrupt_TIMEINT2_Func)();
}
