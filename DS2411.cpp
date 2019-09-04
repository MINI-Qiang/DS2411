#include "DS2411.h"
#include <OneWire.h>
DS2411::DS2411(byte IOpin)
{
	_IOpin = IOpin;
}
void DS2411::Init()
{
	OneWire ds(_IOpin); 
	boolean present; 
	present = ds.reset(); 
	if (present == TRUE)
	{ 
		ds.write(0x33,0); // Read data command, leave ghost power off 
		for ( byte i = 0; i <8; i++) 
		{ 
			DataID[i] = ds.read(); 
			 //= *(IDdata+i);
			DataIDR[7-i] = DataID[i];
		} 
	}
}

// 获取ID
void DS2411::GetID(byte *DataNum)
{
	for ( byte i = 0; i <8; i++) 
		{
			*(DataNum+i) = DataID[i];
		}
}
// 获取MAC
void DS2411::GetMAC(byte *DataMAC)
{
	for ( byte i = 0; i<6; i++) 
		{
			*(DataMAC + i) = DataIDR[i+1];
		}
	DataMAC[0] =bitWrite(DataMAC[0], 0, 0);   //按照mac要求将mac地址的第一个字节的第一个bit 改为0
}

//

void DS2411::GetCharAll(char *StrNumber)
{
	tempStrNumber = "";
	for (byte a = 0; a < 8; a++)
	{
		if(DataIDR[a] <= 0x0F)   // 如果字符小于16 则需要补0
		{
			tempStrNumber = tempStrNumber + "0"+ String(DataIDR[a], HEX);
		}
		else
		{
			tempStrNumber = tempStrNumber + String(DataIDR[a], HEX);
		}
		
	}
	byte macStrLine =  tempStrNumber.length();  //获取字符串长度
	tempStrNumber.getBytes((unsigned char*)StrNumber, macStrLine+1);  //转换标题名
	tempStrNumber = "";
}


String DS2411::GetCharAll()
{
	tempStrNumber = "";
	for (byte a = 0; a < 8; a++)
	{
		if(DataIDR[a] <= 0x0F)   // 如果字符小于16 则需要补0
		{
			tempStrNumber = tempStrNumber + "0"+ String(DataIDR[a], HEX);
		}
		else
		{
			tempStrNumber = tempStrNumber + String(DataIDR[a], HEX);
		}
	}
	return tempStrNumber;
}


void DS2411::GetChar(char *StrNumber)
{
	tempStrNumber = "";
	for (byte a = 1; a < 7; a++)   //MAC 需要掐头去尾，取中间6字节
	{
		if(DataIDR[a] <= 0x0F)   // 如果字符小于16 则需要补0
		{
			tempStrNumber = tempStrNumber + "0"+ String(DataIDR[a], HEX);
		}
		else
		{
			tempStrNumber = tempStrNumber + String(DataIDR[a], HEX);
		}
	}
	byte macStrLine =  tempStrNumber.length();  //获取字符串长度
	tempStrNumber.getBytes((unsigned char*)StrNumber, macStrLine+1);  //转换标题名
	tempStrNumber = "";
}


String DS2411::GetChar()
{
	tempStrNumber = "";
	for (byte a = 1; a < 7; a++)   //MAC 需要掐头去尾，取中间6字节
	{
		if(DataIDR[a] <= 0x0F)   // 如果字符小于16 则需要补0
		{
			tempStrNumber = tempStrNumber + "0"+ String(DataIDR[a], HEX);
		}
		else
		{
			tempStrNumber = tempStrNumber + String(DataIDR[a], HEX);
		}
	}
	return tempStrNumber;
}