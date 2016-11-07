#include "DS2411.h"
#include <OneWire.h>
DS2411::DS2411(byte IOpin)
{
	_IOpin = IOpin;
}
void DS2411::getID(byte *IDdata)
{
	OneWire ds(_IOpin); 
	boolean present; 
	present = ds.reset(); 
	if (present == TRUE)
	{ 
		ds.write(0x33,0); // Read data command, leave ghost power off 
		for ( byte i = 0; i <8; i++) 
		{ 
			*(IDdata+i) = ds.read(); 
		} 
	}
}