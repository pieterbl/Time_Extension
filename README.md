# Time\_Extension

Extension for the Arduino Time library (former DateTime library).
Extend the Arduino Time library with (e.g.) HH:MM:SS formatting.

## License

License information can be found [here](./LICENSE.md).

## Background Information

It took me a while to understand the situation regarding time related libraries for the Arduino.
My current understanding is documented here.
Please correct me where I'm wrong or incomplete.

1. The Arduino libraries come with a standard `time.h` library.
   - The `time.h` library for example offers the function `strftime`, for formatting of date/time strings. This function can be used to create typical YYYYMMDD / HHMMSS strings.
   - A discussion on how to convert the `strftime` result to a `String` can be found at [how-do-you-convert-a-formatted-print-statement-into-a-string-variable)](https://arduino.stackexchange.com/questions/52676/how-do-you-convert-a-formatted-print-statement-into-a-string-variable).
2. There used to be an additional `DateTime.h` library in the now read-only [Arduino Playground](https://playground.arduino.cc/Code/DateTime/).
   - This library had a successor `Time.h` library, which was also hosted in the now read-only [Arduino Playground](https://playground.arduino.cc/Code/Time/).
3. The de-facto successor of the Arduino Playground `Time.h` library seems to be the [PaulStoffregen / Time](https://github.com/PaulStoffregen/Time) project on GitHub. February 2020, this project states:
   - Time is a library that provides timekeeping functionality for Arduino.
   - The code is derived from the Playground DateTime library but is updated to provide an API that is more flexible and easier to use.
   - A primary goal was to enable date and time functionality that can be used with a variety of external time sources with minimum differences required in sketch logic.
   - Example sketches illustrate how similar sketch code can be used with: a Real Time Clock, internet NTP time service, GPS time data, and Serial time messages from a computer for time synchronization.
4. There is one problem with the standard `time.h` library and the [PaulStoffregen / Time](https://github.com/PaulStoffregen/Time) project on GitHub, which comes with `Time.h`. On Microsoft Windows platforms, you can only include one of these.
   - [This pull-request](https://github.com/PaulStoffregen/Time/pull/98) suggests to delete `Time.h` from mentioned GitHub project.
5. Note that the `strftime` function which is available via the Arduino `time.h` library, is not following the official c++ specification.
   - February 2020, file `\Sloeber_V4.3.2\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5\avr\include\time.h` states:
      - A complete description of strftime() is beyond the pale of this document.
      - Refer to [ISO/IEC document 9899](http://www.iso-9899.info/wiki/The_Standard) for details.
      - All conversions are made using the 'C Locale', ignoring the E or O modifiers. Due to the lack of a time zone 'name', the 'Z' conversion is also ignored.
   - This page seems to be a more official reference for the `strftime` function: <https://en.cppreference.com/w/c/chrono/strftime>
