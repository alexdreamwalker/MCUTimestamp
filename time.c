#include "time.h"

const uint16_t daysInYear[] = { 0U, 31U, 59U, 90U, 120U, 151U, 181U, 212U, 243U, 273U, 304U, 334U, 365U };
const uint16_t daysInLeapYear[] = { 0U, 31U, 60U, 91U, 121U, 152U, 182U, 213U, 244U, 274U, 305U, 335U, 366U };
const uint16_t startCountYear = 1970U;
const uint32_t secondsPerDay = 86400U;

bool isLeapYear(uint16_t year) {
    if ((year % 4U) != 0U)
        return false;

    if ((year % 100U) == 0U)
        return ((year % 400U) == 0);

    return true;
}

uint32_t timeToSeconds(uint8_t hour, uint8_t minute, uint8_t second) {
    uint32_t totalSeconds = (((uint32_t)hour * 3600U) + ((uint32_t)minute * 60U)) + (uint32_t)second;
    return totalSeconds;
}

uint32_t dateToSeconds(uint16_t year, uint8_t month, uint8_t day) {
    const uint16_t *daysToMonth = isLeapYear(year) ? daysInLeapYear : daysInYear;
    if ((day >= 1)) {
        uint16_t previousYear = year - startCountYear;
        uint16_t previousYearLeap = previousYear + 1U;
        uint32_t daysInPreviousYears = ((((previousYear * 365U) + (previousYearLeap / 4U)) - (previousYear / 100U)) + (previousYear / 400U));
        uint32_t totalDays = ((daysInPreviousYears + daysToMonth[month - 1]) + day) - 1U;
        
        return (totalDays * secondsPerDay);
    }
    return 0U;
}

/* get UNIX timestamp by the given years, months, days, hours, minutes and seconds */
uint32_t getTimeStamp(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second){
    uint32_t timestamp = dateToSeconds(year, month, day) + timeToSeconds(hour, minute, second);
    return timestamp;
}
