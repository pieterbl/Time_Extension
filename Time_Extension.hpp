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
#ifndef __TIME_EXTENSION_HPP__
#define __TIME_EXTENSION_HPP__

#ifdef __USE_STD_ARDUINO_TIME_H__
#include <time.h>
#endif // __USE_STD_ARDUINO_TIME_H__

#include <Arduino.h>
#include <TimeLib.h>

class TimeExtension {
public:

	static const char *DATE_TIME_FORMAT;

	static const char *DATE_FORMAT;

	static const char *TIME_FORMAT;

	TimeExtension() {
	}

	time_t getNow();

	const String getDateTimeString();

	const String getDateString();

	const String getTimeString();

	static const String getDateTimeString(time_t someTime);

	static const String getDateString(time_t someTime);

	static const String getTimeString(time_t someTime);

#ifdef __USE_STD_ARDUINO_TIME_H__

	/*
	 * TimeLib::tmElements_t => time_t, call TimeExtension::strftime
	 */
	static inline size_t strftime(char *s, size_t maxsize, const char *format,
			const tmElements_t *timeStructPtr) {

		time_t someTime = ::makeTime(*timeStructPtr);
		return TimeExtension::strftime(s, maxsize, format, someTime);
	}

	/*
	 * time_t => time::tm, call ::strftime
	 */
	static inline size_t strftime(char *s, size_t maxsize, const char *format,
			time_t someTime) {

		tm *timeStructPtr = ::localtime(&someTime);
		return ::strftime(s, maxsize, format, timeStructPtr);
	}

	/*
	 * time::tm stays time::tm, call ::strftime
	 */
	static inline size_t strftime(char *s, size_t maxsize, const char *format,
			const struct tm *timeStructPtr) {

		return ::strftime(s, maxsize, format, timeStructPtr);
	}

	/*
	 * Convenience version of strftime, using a char buf[512] for printing time strings.
	 * Likely not the fastest or most memory optimized implementation, but it works and is straightforward.
	 *
	 * TODO: decide if keep or not
	 */
	static inline String strftime(const char *format,
			const struct tm *timeStructPtr) {

		char buf[512];
		buf[0] = 0;
		TimeExtension::strftime(buf, (512 - 1), format, timeStructPtr);
		return buf;
	}

#endif // __USE_STD_ARDUINO_TIME_H__

private:

	static void addTwoDigitNumberWithZeroPrefix(String &str, uint8_t number);

};

#endif // __TIME_EXTENSION_HPP__
