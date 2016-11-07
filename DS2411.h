#ifndef DS2411_H
#define DS2411_H
#include <Arduino.h>
class DS2411
{
	public:
		DS2411(byte iOpin);
		void getID(byte *IDdata);
		
	private:
		 uint8_t _IOpin;
};

#endif //DS2411_H