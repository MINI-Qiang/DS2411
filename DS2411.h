#ifndef DS2411_H
#define DS2411_H
#include <Arduino.h>
class DS2411
{
	public:
		DS2411(byte iOpin);
		void Init();
		void GetID(byte *DataNum);   //get 8byte DS2411 number
		void GetMAC(byte *DataMAC);   //get 6byte Mac
		void GetCharAll(char *charNumber);   // char 16 byte
		String GetCharAll();
		void GetChar(char *charNumber);    // char  12 byte
		String GetChar();
	private:
		 uint8_t _IOpin;
		 uint8_t DataID[8];
		 uint8_t DataIDR[8];
		 String tempStrNumber;
};
#endif //DS2411_H