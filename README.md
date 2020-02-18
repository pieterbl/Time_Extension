# Time\_Extension

Extension for the Arduino Time library (former DateTime library).
Extend the Arduino Time library with (e.g.) HH:MM:SS formatting.

## License

License information can be found [here](./LICENSE.md).

## Library Versions

| Include File | Specifics |
| ------------ | --------- |
| `Time_Extension.h` | Can be used with the original/unmodified [PaulStoffregen / Time](https://github.com/PaulStoffregen/Time) library. Only the (e.g.) `TimeExtension::getDateTimeString` functions will be available. |
| `Time_Extension_with_std_Arduino_time.h` | Can only be used with modified versions of the [PaulStoffregen / Time](https://github.com/PaulStoffregen/Time) library (see below). Next to the (e.g.) `TimeExtension::getDateTimeString` functions , `TimeExtension::strftime` functions will also be available. |

## Modified Versions of the [PaulStoffregen / Time](https://github.com/PaulStoffregen/Time) Library

Following will work:

1. You take and install the original `PaulStoffregen / Time` library, and delete the `Time.h` file from the installation directory.
2. You create and use your own fork of the `PaulStoffregen / Time` library, and delete the `Time.h` file from it.
3. Any other approach to get rid of the `Time.h` file in the `PaulStoffregen / Time` library.

## Provided Examples

| Example | Description |
| ------- | ----------- |
| [StrftimeForTimeLibAndStdTime](./examples/StrftimeForTimeLibAndStdTime/StrftimeForTimeLibAndStdTime.ino) | Illustrates formatting via `TimeExtension::getDateTimeString` and `TimeExtension::strftime`. In addition conversion from `time_t` to `TimeLib.h` time structure **_and back_**, and from `time.h` time structure `tm` **_and back_** are tested. Result validation is by visual inspection of `Serial.println()` output. |
| | **Status:** Since both libraries have different time offsets (TimeLib: 1970, time: 2000), we notice that the time calculation is identical, but the dates are 30 years apart. **In this case we have years 1970, 2000, respectively.** |
| [StrftimeExampleWithDS1307RTC](./examples/StrftimeExampleWithDS1307RTC/StrftimeExampleWithDS1307RTC.ino) | Similar like `StrftimeForTimeLibAndStdTime`, but with external DS1307 Real-Time-Clock. Combines the [StrftimeForTimeLibAndStdTime](./examples/StrftimeForTimeLibAndStdTime/StrftimeForTimeLibAndStdTime.ino) and the [Grove_RTC_DS1307_Extension/TimeLibSyncProviderDemo](https://github.com/pieterbl/Grove_RTC_DS1307_Extension/blob/master/examples/TimeLibSyncProviderDemo/TimeLibSyncProviderDemo.ino) examples. |
| | **Status:** Since both libraries have different time offsets (TimeLib: 1970, time: 200), we notice that the time calculation is identical, but the dates are 30 years apart. **In this case we have years 2020, 2050, respectively, with a Real-Time-Clock running the correct current time.** |

## Background Information

It took me a while to understand the situation regarding time related libraries for the Arduino.
My current understanding is documented here.
Please correct me where I'm wrong or incomplete.

1. The Arduino libraries come with a standard `time.h` library.
   - The `time.h` library for example offers the function `strftime`, for formatting of date/time strings. This function can be used to create typical YYYYMMDD / HHMMSS strings.
   - A discussion on how to convert the `strftime` result to a `String` can be found at [how-do-you-convert-a-formatted-print-statement-into-a-string-variable)](https://arduino.stackexchange.com/questions/52676/how-do-you-convert-a-formatted-print-statement-into-a-string-variable).
      - Note that this discussion does not seem to be related to a standard Arduino, but rather to [Getting Date & Time From NTP Server With ESP32](https://lastminuteengineers.com/esp32-ntp-server-date-time-tutorial/).  
2. There used to be an additional `DateTime.h` library in the now read-only [Arduino Playground](https://playground.arduino.cc/Code/DateTime/).
   - This library had a successor `Time.h` library, which was also hosted in the now read-only [Arduino Playground](https://playground.arduino.cc/Code/Time/).
3. The de-facto successor of the Arduino Playground `Time.h` library seems to be the [PaulStoffregen / Time](https://github.com/PaulStoffregen/Time) project on GitHub. February 2020, this project states:
   - Time is a library that provides timekeeping functionality for Arduino.
   - The code is derived from the Playground DateTime library but is updated to provide an API that is more flexible and easier to use.
   - A primary goal was to enable date and time functionality that can be used with a variety of external time sources with minimum differences required in sketch logic.
   - Example sketches illustrate how similar sketch code can be used with: a Real Time Clock, internet NTP time service, GPS time data, and Serial time messages from a computer for time synchronization.
4. February 2020: There is one problem with the standard `time.h` library and the [PaulStoffregen / Time](https://github.com/PaulStoffregen/Time) project on GitHub, which comes with `Time.h`. On Microsoft Windows platforms, you can only include one of these.
   - [This pull-request](https://github.com/PaulStoffregen/Time/pull/98) suggests to delete `Time.h` from mentioned GitHub project.
5. Note that the `strftime` function which is available via the Arduino `time.h` library, is not following the official C++ specification.
   - February 2020, file (e.g.) `\Sloeber_V4.3.2\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5\avr\include\time.h` states:
      - A complete description of `strftime()` is beyond the pale of this document.
      - Refer to [ISO/IEC document 9899](http://www.iso-9899.info/wiki/The_Standard) for details.
      - All conversions are made using the 'C Locale', ignoring the E or O modifiers. Due to the lack of a time zone 'name', the 'Z' conversion is also ignored.
   - This page seems to be a more official reference for the `strftime` function: <https://en.cppreference.com/w/c/chrono/strftime>.

## References

1. <https://arduino.stackexchange.com/questions/860/how-can-i-get-the-source-files-for-arduino-libraries>
2. <https://www.nongnu.org/avr-libc/>
3. <http://download.savannah.gnu.org/releases/avr-libc/>
