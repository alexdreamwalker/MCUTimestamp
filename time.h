#ifndef TIME_H
#define TIME_H

/* get UNIX timestamp by the given years, months, days, hours, minutes and seconds */
uint32_t getTimeStamp(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second);

#endif