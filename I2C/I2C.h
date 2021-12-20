/*
 * @Description  : I2C transmit
 * @Author       : FZU Liao
 * @Date         : 2021-12-20 23:14:49
 * @LastEditors  : Liao
 * @LastEditTime : 2021-12-20 23:18:03
 * @FilePath     : \I2C.h
 * Copyright 2021 FZU Liao, All Rights Reserved. 
 */

#ifndef __I2C_H__
#define __I2C_H__

void I2C_Start();
void I2C_Stop();
void I2C_SendByte(unsigned char Byte);
unsigned char I2C_ReceiveByte();
void I2C_SendACK();
unsigned char I2C_ReceiveACK();

#endif