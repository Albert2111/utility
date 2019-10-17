#pragma once
void InvertUint8(unsigned char* DesBuf, unsigned char* SrcBuf);
void InvertUint16(unsigned short* DesBuf, unsigned short* SrcBuf);

unsigned char CRC4_ITU(unsigned char* puchMsg, unsigned int usDataLen);

unsigned short CRC16_CCITT(unsigned char* puchMsg, unsigned int usDataLen);
unsigned short CRC16_CCITT_FALSE(unsigned char* puchMsg, unsigned int usDataLen);
unsigned short CRC16_XMODEM(unsigned char* puchMsg, unsigned int usDataLen);
unsigned short CRC16_X25(unsigned char* puchMsg, unsigned int usDataLen);
unsigned short CRC16_MODBUS(unsigned char* puchMsg, unsigned int usDataLen);
unsigned short CRC16_IBM(unsigned char* puchMsg, unsigned int usDataLen);
unsigned short CRC16_MAXIM(unsigned char* puchMsg, unsigned int usDataLen);
unsigned short CRC16_USB(unsigned char* puchMsg, unsigned int usDataLen);

void crcTest(void);
