# Arduino DS2411-arduino-libraries
DS2411 arduino  libraries

DS2411 - Part Number Search
 
Get MAC  example: 0 0 13 B8 9C F2   byte

Get SyStem example:000013b89cf2   String or Char[]


DS2411 功能增补
* 获取 芯片ID  8byte（64bit）
* 将芯片ID反向，去掉家族码和校验位，处理成MAC地址 6byte （48bit） 方便W5500(W5100) enc28j60等硬件使用
* 以字符串的方式返回16进制文本，方便作为系统设备名称使用

OneWire libraries from https://github.com/PaulStoffregen/OneWire 
  