#include "crc.h"
#include <stdio.h>

int main()
{
	crcTest();
	return 0;
}

/**
**************************************************************************************************
* @Brief    Single byte data inversion
* @Param
*            @DesBuf: destination buffer
*            @SrcBuf: source buffer
* @RetVal    None
* @Note      (MSB)0101_0101 ---> 1010_1010(LSB)
**************************************************************************************************
*/
void InvertUint8(unsigned char* DesBuf, unsigned char* SrcBuf)
{
	int i;
	unsigned char temp = 0;

	for (i = 0; i < 8; i++)
	{
		if (SrcBuf[0] & (1 << i))
		{
			temp |= 1 << (7 - i);
		}
	}
	DesBuf[0] = temp;
}

/**
**************************************************************************************************
* @Brief    double byte data inversion
* @Param
*            @DesBuf: destination buffer
*            @SrcBuf: source buffer
* @RetVal    None
* @Note      (MSB)0101_0101_1010_1010 ---> 0101_0101_1010_1010(LSB)
**************************************************************************************************
*/
void InvertUint16(unsigned short* DesBuf, unsigned short* SrcBuf)
{
	int i;
	unsigned short temp = 0;

	for (i = 0; i < 16; i++)
	{
		if (SrcBuf[0] & (1 << i))
		{
			temp |= 1 << (15 - i);
		}
	}
	DesBuf[0] = temp;
}

unsigned char CRC4_ITU(unsigned char* puchMsg, unsigned int usDataLen)
{

}

unsigned short CRC16_CCITT(unsigned char* puchMsg, unsigned int usDataLen)
{
	unsigned short wCRCin = 0x0000;
	unsigned short wCPoly = 0x1021;
	unsigned char wChar = 0;

	while (usDataLen--)
	{
		wChar = *(puchMsg++);
		InvertUint8(&wChar, &wChar);
		wCRCin ^= (wChar << 8);

		for (int i = 0; i < 8; i++)
		{
			if (wCRCin & 0x8000)
			{
				wCRCin = (wCRCin << 1) ^ wCPoly;
			}
			else
			{
				wCRCin = wCRCin << 1;
			}
		}
	}
	InvertUint16(&wCRCin, &wCRCin);
	return (wCRCin);
}

unsigned short CRC16_CCITT_FALSE(unsigned char* puchMsg, unsigned int usDataLen)
{
	unsigned short wCRCin = 0xFFFF;
	unsigned short wCPoly = 0x1021;
	unsigned char wChar = 0;

	while (usDataLen--)
	{
		wChar = *(puchMsg++);
		wCRCin ^= (wChar << 8);

		for (int i = 0; i < 8; i++)
		{
			if (wCRCin & 0x8000)
			{
				wCRCin = (wCRCin << 1) ^ wCPoly;
			}
			else
			{
				wCRCin = wCRCin << 1;
			}
		}
	}
	return (wCRCin);
}

unsigned short CRC16_XMODEM(unsigned char* puchMsg, unsigned int usDataLen)
{
	unsigned short wCRCin = 0x0000;
	unsigned short wCPoly = 0x1021;
	unsigned char wChar = 0;

	while (usDataLen--)
	{
		wChar = *(puchMsg++);
		wCRCin ^= (wChar << 8);

		for (int i = 0; i < 8; i++)
		{
			if (wCRCin & 0x8000)
			{
				wCRCin = (wCRCin << 1) ^ wCPoly;
			}
			else
			{
				wCRCin = wCRCin << 1;
			}
		}
	}
	return (wCRCin);
}

unsigned short CRC16_X25(unsigned char* puchMsg, unsigned int usDataLen)
{
	unsigned short wCRCin = 0xFFFF;
	unsigned short wCPoly = 0x1021;
	unsigned char wChar = 0;

	while (usDataLen--)
	{
		wChar = *(puchMsg++);
		InvertUint8(&wChar, &wChar);
		wCRCin ^= (wChar << 8);

		for (int i = 0; i < 8; i++)
		{
			if (wCRCin & 0x8000)
			{
				wCRCin = (wCRCin << 1) ^ wCPoly;
			}
			else
			{
				wCRCin = wCRCin << 1;
			}
		}
	}
	InvertUint16(&wCRCin, &wCRCin);
	return (wCRCin ^ 0xFFFF);
}

unsigned short CRC16_MODBUS(unsigned char* puchMsg, unsigned int usDataLen)
{
	unsigned short wCRCin = 0xFFFF;
	unsigned short wCPoly = 0x8005;
	unsigned char wChar = 0;

	while (usDataLen--)
	{
		wChar = *(puchMsg++);
		InvertUint8(&wChar, &wChar);
		wCRCin ^= (wChar << 8);

		for (int i = 0; i < 8; i++)
		{
			if (wCRCin & 0x8000)
			{
				wCRCin = (wCRCin << 1) ^ wCPoly;
			}
			else
			{
				wCRCin = wCRCin << 1;
			}
		}
	}
	InvertUint16(&wCRCin, &wCRCin);
	return (wCRCin);
}

unsigned short CRC16_IBM(unsigned char* puchMsg, unsigned int usDataLen)
{
	unsigned short wCRCin = 0x0000;
	unsigned short wCPoly = 0x8005;
	unsigned char wChar = 0;

	while (usDataLen--)
	{
		wChar = *(puchMsg++);
		InvertUint8(&wChar, &wChar);
		wCRCin ^= (wChar << 8);

		for (int i = 0; i < 8; i++)
		{
			if (wCRCin & 0x8000)
			{
				wCRCin = (wCRCin << 1) ^ wCPoly;
			}
			else
			{
				wCRCin = wCRCin << 1;
			}
		}
	}
	InvertUint16(&wCRCin, &wCRCin);
	return (wCRCin);
}

unsigned short CRC16_MAXIM(unsigned char* puchMsg, unsigned int usDataLen)
{
	unsigned short wCRCin = 0x0000;
	unsigned short wCPoly = 0x8005;
	unsigned char wChar = 0;

	while (usDataLen--)
	{
		wChar = *(puchMsg++);
		InvertUint8(&wChar, &wChar);
		wCRCin ^= (wChar << 8);

		for (int i = 0; i < 8; i++)
		{
			if (wCRCin & 0x8000)
			{
				wCRCin = (wCRCin << 1) ^ wCPoly;
			}
			else
			{
				wCRCin = wCRCin << 1;
			}
		}
	}
	InvertUint16(&wCRCin, &wCRCin);
	return (wCRCin ^ 0xFFFF);
}

unsigned short CRC16_USB(unsigned char* puchMsg, unsigned int usDataLen)
{
	unsigned short wCRCin = 0xFFFF;
	unsigned short wCPoly = 0x8005;
	unsigned char wChar = 0;

	while (usDataLen--)
	{
		wChar = *(puchMsg++);
		InvertUint8(&wChar, &wChar);
		wCRCin ^= (wChar << 8);

		for (int i = 0; i < 8; i++)
		{
			if (wCRCin & 0x8000)
			{
				wCRCin = (wCRCin << 1) ^ wCPoly;
			}
			else
			{
				wCRCin = wCRCin << 1;
			}
		}
	}
	InvertUint16(&wCRCin, &wCRCin);
	return (wCRCin ^ 0xFFFF);
}

void crcTest(void)
{
	unsigned char data[] = { 0xAA, 0x12, 0x56, 0x21, 0xFF };
	printf_s("%x\n", CRC4_ITU(data, sizeof(data) / sizeof(unsigned char)));
	printf_s("%x\n", CRC16_CCITT(data, sizeof(data) / sizeof(unsigned char)));
	printf_s("%x\n", CRC16_CCITT_FALSE(data, sizeof(data) / sizeof(unsigned char)));
	printf_s("%x\n", CRC16_XMODEM(data, sizeof(data) / sizeof(unsigned char)));
	printf_s("%x\n", CRC16_X25(data, sizeof(data) / sizeof(unsigned char)));
	printf_s("%x\n", CRC16_MODBUS(data, sizeof(data) / sizeof(unsigned char)));
	printf_s("%x\n", CRC16_IBM(data, sizeof(data) / sizeof(unsigned char)));
	printf_s("%x\n", CRC16_MAXIM(data, sizeof(data) / sizeof(unsigned char)));
	printf_s("%x\n", CRC16_USB(data, sizeof(data) / sizeof(unsigned char)));

}
