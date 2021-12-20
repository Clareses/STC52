/*
 * @Description  : C51模板文件 中断相关封装
 * @Author       : FZU Liao
 * @Date         : 2021-12-19 19:50:11
 * @LastEditors  : Liao
 * @LastEditTime : 2021-12-20 13:02:57
 * @FilePath     : \Interrupt.h
 * Copyright 2021 FZU Liao, All Rights Reserved. 
 */

#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

//中断总开关
//-----------------------------------------------------------------
void Interrupt_ALL_Enable();
void Interrupt_ALL_Disable();

//中断开启
//-----------------------------------------------------------------
// void Interrupt_TypeINTx_Enable();
void Interrupt_EXINT0_Enable();
void Interrupt_TIMEINT0_Enable();
void Interrupt_EXINT1_Enable();
void Interrupt_TIMEINT1_Enable();
void Interrupt_UARTINT_Enable();
void Interrupt_TIMEINT2_Enable();

//中断关闭
//-----------------------------------------------------------------
// void Interrupt_TypeINTx_Disable();
void Interrupt_EXINT0_Disable();
void Interrupt_TIMEINT0_Disable();
void Interrupt_EXINT1_Disable();
void Interrupt_TIMEINT1_Disable();
void Interrupt_UARTINT_Disable();
void Interrupt_TIMEINT2_Disable();

//中断函数设置
//-----------------------------------------------------------------
// void Interrupt_TypeINTx_SetFunc(void (*func)());
void Interrupt_EXINT0_SetFunc(void (*func)());
void Interrupt_TIMEINT0_SetFunc(void (*func)());
void Interrupt_EXINT1_SetFunc(void (*func)());
//TIMER1专用于UART，不能自定义
void Interrupt_UARTINT_SetFunc(void (*func)());
void Interrupt_TIMEINT2_SetFunc(void (*func)());

//中断优先级设定
//-----------------------------------------------------------------
// void Interrupt_TypeINTx_SetPriority(int Priority);
void Interrupt_EXINT0_SetPriority(int Priority);
void Interrupt_TIMEINT0_SetPriority(int Priority);
void Interrupt_EXINT1_SetPriority(int Priority);
//TIMER1专用于UART，不能自定义
void Interrupt_UARTINT_SetPriority(int Priority);
void Interrupt_TIMEINT2_SetPriority(int Priority);

//中断初始化(包括模式设置/中断函数设置等)
//-----------------------------------------------------------------
// void Interrupt_TypeINTx_Init();
void Interrupt_EXINT0_Init(int Mode,int Priority,void (*Func)());
void Interrupt_TIMEINT0_Init(int Priority,void (*Func)());
void Interrupt_EXINT1_Init(int Mode,int Priority,void (*Func)());

//TIMER1专用于UART，不能自定义

void Interrupt_UARTINT_Init(int Priority,void (*Func)());
void Interrupt_TIMEINT2_Init(int Priority,void (*Func)());

//中断复位
//-----------------------------------------------------------------
#endif