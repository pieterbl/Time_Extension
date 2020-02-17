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

#include <Arduino.h>
#include <Time_Extension_with_std_Arduino_time.hpp>

void setup() {
	Serial.begin(9600);
}

/*
 * In the below loop(), we want to proof that:
 *
 * 1. From now() define 'nowTime'
 *
 * 2. Starting from 'nowTime'
 *
 * 3. Using breakTime => makeTime, gives us time_t identical to 'nowTime'
 *
 * 4. Again starting from 'nowTime'
 *
 * 5. Using localtime => mktime, gives us time_t identical to 'nowTime'
 */
void loop() {

	// 1. now()
	time_t nowTime = now();
	String nowTimeStr = TimeExtension::getDateTimeString(nowTime);

	// 2. TimeLib::breakTime
	tmElements_t timeLibTimeStruct;
	::breakTime(nowTime, timeLibTimeStruct);

	// 3. TimeLib::makeTime
	time_t timeLibTime = ::makeTime(timeLibTimeStruct);
	String timeLibTimeStr = TimeExtension::getDateTimeString(timeLibTime);

	// 4. time::localtime
	tm stdTimeStruct = *(::localtime(&nowTime));

	// 5. time::mktime
	time_t stdTime = ::mktime(&stdTimeStruct);
	String stdTimeStr = TimeExtension::getDateTimeString(stdTime);

	Serial.print("from-now()      : ");
	Serial.println(nowTimeStr);
	Serial.print("from-TimeLib.h  : ");
	Serial.println(timeLibTimeStr);
	Serial.print("from-std-time.h : ");
	Serial.println(stdTimeStr);

	Serial.println();
	delay(1000);
}
