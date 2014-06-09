#include <Wire.h>
#include <RTC8564.h>

void setup()
{
  Serial.begin(9600);
  Rtc.begin();
// sync date and time if needed. Write value of BCD format.
/*
  byte date_and_time[7]; 
  date_and_time[0] = 0x00;  // 秒 
  date_and_time[1] = 0x53;  // 分 
  date_and_time[2] = 0x10;  // 時 
  date_and_time[3] = 0x04;  // 日 
  date_and_time[4] = 0x04;  // 曜日 
  date_and_time[5] = 0x06;  // 月 
  date_and_time[6] = 0x14;  // 年
  Rtc.sync(date_and_time); 
*/  
}

void loop()
{
  delay(1000);
  Rtc.available();  
  Serial.print(0x2000+Rtc.years(),HEX);
  Serial.print("/");
  Serial.print(Rtc.months(),HEX);
  Serial.print("/");
  Serial.print(Rtc.days(),HEX);
  Serial.print(" ");
  Serial.print(Rtc.hours(),HEX);
  Serial.print(":");
  Serial.print(Rtc.minutes(),HEX);
  Serial.print(":");
  Serial.println(Rtc.seconds(),HEX);
}