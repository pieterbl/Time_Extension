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

const String TimeExtension::getDateTimeString() {
	time_t nowTime = now();
	String dateTime = "";
	dateTime += getDateString(nowTime);
	dateTime += " ";
	dateTime += getTimeString(nowTime);
	return dateTime;
}

const String TimeExtension::getDateString() {
	time_t nowTime = now();
	return getDateString(nowTime);
}

const String TimeExtension::getTimeString() {
	time_t nowTime = now();
	return getTimeString(nowTime);
}

const String TimeExtension::getDateString(time_t someTime) {

	String dateString = "";
	dateString += (year(someTime));
	dateString += "-";
	addTwoDigitNumberWithZeroPrefix(dateString, month(someTime));
	dateString += "-";
	addTwoDigitNumberWithZeroPrefix(dateString, day(someTime));

	return dateString;
}

const String TimeExtension::getTimeString(time_t someTime) {

	String timeString = "";
	addTwoDigitNumberWithZeroPrefix(timeString, hour(someTime));
	timeString += ":";
	addTwoDigitNumberWithZeroPrefix(timeString, minute(someTime));
	timeString += ":";
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
