/*
 * @Description  : I2C transmit
 * @Author       : FZU Liao
 * @Date         : 2021-12-20 23:18:13
 * @LastEditors  : Liao
 * @LastEditTime : 2021-12-20 23:39:43
 * @FilePath     : \I2C.c
 * Copyright 2021 FZU Liao, All Rights Reserved. 
 */

#include <regx52rc.h>

#define I2C_SCLK P21
#define I2C_SDTA P20


//开启总线传输
void I2C_Start(){
    I2C_SCLK=1;
    I2C_SDTA=1;
    I2C_SDTA=0;
    I2C_SCLK=0;
}

//关闭总线传输
void I2C_Stop(){
    I2C_SCLK=0;
    I2C_SDTA=0;
    I2C_SCLK=1;
    I2C_SDTA=1;
}

//发送八位数据
void I2C_SendByte(unsigned char Byte){
    int i;
    I2C_SCLK=0;
    for(i=0;i<8;i++){
        I2C_SDTA=Byte&(0x80>>i);
        I2C_SCLK=1;
        I2C_SCLK=0;
    }
    I2C_SCLK=0;
}

//接收八位数据
unsigned char I2C_ReceiveByte(){
    unsigned char i , Data;
    I2C_SDTA=1;
    I2C_SCLK=0;
    Data=0x00;
    for(i=0;i<8;i++){
        I2C_SCLK=1;
        if(I2C_SDTA) Data|=(0x80>>i);
        I2C_SCLK=0;
    }
    I2C_SCLK=0;
    return Data;
}

//发送应答位
void I2C_SendACK(unsigned char ACKbit){
    I2C_SCLK=0;
    I2C_SDTA=ACKbit;
    I2C_SCLK=1;
    I2C_SCLK=0;
}

//接收应答位
unsigned char I2C_ReceiveACK(){
    unsigned char ACKbit;
    I2C_SCLK=0;
    I2C_SCLK=1;
    ACKbit=I2C_SDTA;
    I2C_SCLK=0;
    return ACKbit;
}
