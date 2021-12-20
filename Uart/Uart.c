/*
 * @Description  : 
 * @Author       : FZU Liao
 * @Date         : 2021-12-19 19:50:11
 * @LastEditors  : Liao
 * @LastEditTime : 2021-12-20 13:27:09
 * @FilePath     : \Uart.c
 * Copyright 2021 FZU Liao, All Rights Reserved. 
 */
#include <regx52rc.h>
#include "Interrupt.h"

#define SERIAL_CONTROL_RIGISTER SCON
#define POWER_CONTROL_RIGISTER PCON

void Uart_Init(void){
	POWER_CONTROL_RIGISTER |= 0x80;
	SERIAL_CONTROL_RIGISTER = 0x50;
	AUXR &= 0xBF;
	AUXR &= 0xFE;
	TMOD &= 0x0F;
	TMOD |= 0x20;
	TL1 = 0xFA;	
	TH1 = 0xFA;	
	ET1 = 0;
	TR1 = 1;
}

void Uart_SendByte(unsigned char byte){
    SBUF=byte;
    while(TI==0);
    TI=0;
}

unsigned char Uart_ReceiveByte(){
    unsigned char res=SBUF;
    return res;
}

void Uart_SetINTFunc(void (*func)()){
    Interrupt_UARTINT_SetFunc(func);
}