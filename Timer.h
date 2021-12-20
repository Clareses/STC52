/*
 * @Description  : C51模板文件 定时器相关封装
 * @Author       : FZU Liao
 * @Date         : 2021-12-19 19:50:11
 * @LastEditors  : Liao
 * @LastEditTime : 2021-12-20 13:21:34
 * @FilePath     : \Timer.h
 * Copyright 2021 FZU Liao, All Rights Reserved. 
 */

#ifndef __TIMER_H__
#define __TIMER_H__

//Timer0
//-----------------------------------------------------------------
// void Timer_Tx_SetMode(int Mode);//模式设置
// void Timer_Tx_Enable();//开启定时器
// void Timer_Tx_Disable();//关闭定时器
// void Timer_Tx_SetFunc(void (*func)());//设置定时器中断函数
// void Timer_Tx_SetPriority(int priority);//设置优先级
// void Timer_Tx_Delete();//定时器复位
// void Timer_Tx_Init(int Mode,int usx,int priority,void (*func)());//初始化

void Timer_T0_SetMode(int Mode);//模式设置
void Timer_T0_Enable();//开启定时器
void Timer_T0_Disable();//关闭定时器
void Timer_T0_SetFunc(void (*func)());//设置定时器中断函数
void Timer_T0_SetPriority(int priority);//设置优先级
void Timer_T0_Delete();//定时器复位
void Timer_T0_Init(int CLKorT,int Mode,int usx,int priority,void (*func)());//初始化

//Timer1不可定制

void Timer_T2_SetMode(int Mode);//模式设置
void Timer_T2_Enable();//开启定时器
void Timer_T2_Disable();//关闭定时器
void Timer_T2_SetFunc(void (*func)());//设置定时器中断函
void Timer_T2_SetPriority(int priority);//设置优先级
void Timer_T2_Delete();//定时器复位
void Timer_T2_Init(int CLKorT,int Mode,int usx,int priority,void (*func)());//初始化

#endif