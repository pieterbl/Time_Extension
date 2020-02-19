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

tm *GLOBAL_TIME = 0;

void updateGlobalTime() {
	time_t nowTime = now();
	GLOBAL_TIME = ::localtime(&nowTime);
}

void setup() {
	Serial.begin(9600);
}

void loop() {
	updateGlobalTime();
	size_t testNum = 1;
	runTest(testNum++, 4, 1, "", "");
	runTest(testNum++, 5, 5, "%Y", "2020");
	runTest(testNum++, 4, 0, "%Y", "");
	runTest(testNum++, 4, 3, "xx", "xx");
	runTest(testNum++, 4, 0, "xxxx", "");
	runTest(testNum++, 5, 4, "xxxx", "xxxx");
}

void runTest(size_t testNum, size_t maxSize, size_t expectedBytesWritten,
		const char *formatStr, const char *expectedOutput) {

	char buf[128];
	buf[0] = 0;

	size_t bytesWritten = ::strftime(buf, maxSize, formatStr, GLOBAL_TIME);

	Serial.print(testNum);
	Serial.print(": ");
	serialPrint("maxSize:", maxSize, ", ");
	serialPrint("expectedBytesWritten:", expectedBytesWritten, ", ");
	serialPrint("bytesWritten:", bytesWritten, ", ");
	serialPrint("formatStr:'", formatStr, "', ");
	serialPrint("expectedOutput:'", expectedOutput, "', ");
	serialPrint("output:'", buf, "', ");

	Serial.println();
	Serial.println();
	delay(500);
}

void serialPrint(const char *prefix, const char *value, const char *postfix) {
	Serial.print(prefix);
	Serial.print(value);
	Serial.print(postfix);
}

void serialPrint(const char *prefix, size_t value, const char *postfix) {
	Serial.print(prefix);
	Serial.print(value);
	Serial.print(postfix);
}
