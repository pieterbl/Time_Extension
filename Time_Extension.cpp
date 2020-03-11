/*
 MIT License

 Copyright (c) 2020 Pieter Bloemendaal (https://github.com/pieterbl)

 Project Time_Extension
 (https://github.com/pieterbl/Time_Extension)

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */
#include <Time_Extension.hpp>
#include <TimeLib.h>

const char *TimeExtension::DATE_TIME_FORMAT = "%Y-%m-%d %H:%M:%S";

const char *TimeExtension::DATE_FORMAT = "%Y-%m-%d";

const char *TimeExtension::TIME_FORMAT = "%H:%M:%S";

time_t TimeExtension::getNow() {
	return ::now();
}

const String TimeExtension::getDateTimeString() {
	time_t nowTime = getNow();
	return getDateTimeString(nowTime);
}

const String TimeExtension::getDateString() {
	time_t nowTime = getNow();
	return getDateString(nowTime);
}

const String TimeExtension::getTimeString() {
	time_t nowTime = getNow();
	return getTimeString(nowTime);
}

/*
 * Straight-forward, likely the not the fasted or most memory optimized implementation,
 * without much magic. KISS.
 */
const String TimeExtension::getDateTimeString(time_t someTime) {

	String dateTime = "";
	dateTime.reserve(24);

	dateTime += getDateString(someTime);
	dateTime += ' ';
	dateTime += getTimeString(someTime);

	return dateTime;
}

/*
 * Straight-forward, likely the not the fasted or most memory optimized implementation,
 * without much magic. KISS.
 */
const String TimeExtension::getDateString(time_t someTime) {

	String dateString = "";
	dateString.reserve(12);

	dateString += year(someTime);
	dateString += '-';
	addTwoDigitNumberWithZeroPrefix(dateString, month(someTime));
	dateString += '-';
	addTwoDigitNumberWithZeroPrefix(dateString, day(someTime));

	return dateString;
}

/*
 * Straight-forward, likely the not the fasted or most memory optimized implementation,
 * without much magic. KISS.
 */
const String TimeExtension::getTimeString(time_t someTime) {

	String timeString = "";
	timeString.reserve(10);

	addTwoDigitNumberWithZeroPrefix(timeString, hour(someTime));
	timeString += ':';
	addTwoDigitNumberWithZeroPrefix(timeString, minute(someTime));
	timeString += ':';
	addTwoDigitNumberWithZeroPrefix(timeString, second(someTime));

	return timeString;
}

void TimeExtension::addTwoDigitNumberWithZeroPrefix(String &str,
		uint8_t number) {

	if (number < 10) {
		str += '0';
	}
	str += number;
}
