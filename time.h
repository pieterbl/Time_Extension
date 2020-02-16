/*
 * (C)2012 Michael Duane Rice All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer. Redistributions in binary
 * form must reproduce the above copyright notice, this list of conditions
 * and the following disclaimer in the documentation and/or other materials
 * provided with the distribution. Neither the name of the copyright holders
 * nor the names of contributors may be used to endorse or promote products
 * derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef TIME_H

#ifdef __cplusplus
extern "C" {
#endif

#include <inttypes.h>
#include <stdlib.h>

/**
 time_t represents seconds elapsed from Midnight, Jan 1 2000 UTC (the Y2K 'epoch').
 Its range allows this implementation to represent time up to Tue Feb 7 06:28:15 2136 UTC.
 */
typedef uint32_t time_t;

/**
 The tm structure contains a representation of time 'broken down' into components of the
 Gregorian calendar.

 The value of tm_isdst is zero if Daylight Saving Time is not in effect, and is negative if
 the information is not available.

 When Daylight Saving Time is in effect, the value represents the number of
 seconds the clock is advanced.

 See the set_dst() function for more information about Daylight Saving.
 */
struct tm {
	int8_t tm_sec; /**< seconds after the minute - [ 0 to 59 ] */
	int8_t tm_min; /**< minutes after the hour - [ 0 to 59 ] */
	int8_t tm_hour; /**< hours since midnight - [ 0 to 23 ] */
	int8_t tm_mday; /**< day of the month - [ 1 to 31 ] */
	int8_t tm_wday; /**< days since Sunday - [ 0 to 6 ] */
	int8_t tm_mon; /**< months since January - [ 0 to 11 ] */
	int16_t tm_year; /**< years since 1900 */
	int16_t tm_yday; /**< days since January 1 - [ 0 to 365 ] */
	int16_t tm_isdst; /**< Daylight Saving Time flag */
};

/**
 A complete description of strftime() is beyond the pale of this document.
 Refer to ISO/IEC document 9899 for details.

 All conversions are made using the 'C Locale', ignoring the E or O modifiers. Due to the lack of
 a time zone 'name', the 'Z' conversion is also ignored.
 */
size_t strftime(char *s, size_t maxsize, const char *format,
		const struct tm *timeptr);

#ifdef __cplusplus
}
#endif

#endif /* TIME_H  */
