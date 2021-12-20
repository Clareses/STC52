/*
 * @Description  : 
 * @Author       : FZU Liao
 * @Date         : 2021-12-19 19:50:11
 * @LastEditors  : Liao
 * @LastEditTime : 2021-12-20 13:28:33
 * @FilePath     : \Uart.h
 * Copyright 2021 FZU Liao, All Rights Reserved. 
 */
#ifndef __UART_H__
#define __UART_H__

//串口初始化
void Uart_Init();

//串口发送8位数据(unsigned char)
void Uart_SendByte(unsigned char byte);

//串口接收8位数据
unsigned char Uart_ReceiveByte();

//设置串口中断函数
void Uart_SetINTFunc(void (*func)());


#endif