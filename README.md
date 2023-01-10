# PTP::Loggifyer
Welcome to **Loggifyer**, a simple, fast and cross-platform logger library.

**Loggifyer** is a logging library that makes it easy to add log messages to your C++ code using only **macros**. It is designed to be **lightweight**, **easy to use**, and **cross-platform**, supporting Windows, Linux, and macOS.

**Loggifyer** also supports different log levels, including Message, Info, Ok, Warning, and Error. You can use these log levels to control which log messages are displayed in your application.

**Loggifyer** is implemented as a singleton, which means that you can access the logging functionality from anywhere in your code.

Overall, **Loggifyer** is a simple and convenient way to add logging to your C++ projects, whether you are developing a small application or a large, complex software system. It is open-source and available under a permissive license, allowing you to use it freely in your own projects.

This library is from the [PTP](https://github.com/MrOrnithorynque/PTP/) library family.

## Features
- Simple and straightforward interface.
- Compatible with Windows, Linux, and Mac.
- Easy to read thanks to coherent coloring.
- Different Log levels : Message < Info < Ok < Warning < Error.
- Multi threading safe.
- Printf like formatting.
- Memory safe.
- Nice formatting option for messages with new lines.
- (WIP) Fully customizable with config file.

## Installation
To install **Loggifyer**, follow these steps:

1. Clone the repository or download the source code.
2. Run CMake to generate the build files for your platform.
3. Use the generated build files to build and install the library.
## Usage
To use **Loggifyer** in your project, simply include the Loggifyer.hpp header file and link the **PTP_Loggifyer** library to your project.

InAnyCppFile.cpp :
```cpp
#include "PTP/Loggifyer.hpp"

int main ( const int argc, const char** argv )
{
    PTP_LOG_INFO("This is a Info message.");
    PTP_LOG_MESSAGE("This is just a simple message.");
    PTP_LOG_OK("This is a Ok message to tell you that everything working properly.");
    PTP_LOG_WARNING("Be careful! you are looking good today. This was a Warning message.");
    PTP_LOG_ERROR("This is a Error log sample.");

    PTP_SET_LOG_LEVEL(ptp::Loggifyer::LogLevel::Error);

    PTP_LOG_WARNING("This warning will not be displayed.");
    PTP_LOG_ERROR("Only Error logs are displayed. because the log level is %d.", int(PTP_GET_LOG_LEVEL));

    PTP_SET_LOG_LEVEL(ptp::Loggifyer::LogLevel::Warning);

    PTP_LOG_INFO("This info will not be displayed.");
    PTP_LOG_MESSAGE("This Message log will not be displayed.");
    PTP_LOG_WARNING("This warning will be displayed.");
    PTP_LOG_ERROR("As you can see, only Error and Warning logs are displayed.");

    PTP_SET_LOG_LEVEL(ptp::Loggifyer::LogLevel::Message);

    PTP_DISABLE_LOGS

    PTP_LOG_ERROR("This error will not be displayed.");

    PTP_ENABLE_LOGS

    PTP_LOG_OK("This Ok message will be displayed because logs are enabled.");

    PTP_LOG_COMPLEX_FORMATTING(true);

    PTP_LOG_INFO("This is a Info message with complex formatting.\nBecause complex formatting is enabled.");

    PTP_LOG_COMPLEX_FORMATTING(false);

    PTP_LOG_INFO("This is a Info message without complex formatting.\nBecause complex formatting is disabled.");

    return 0;
}
```
Output (no colors are shown in this readme output but don't worry your output will be colored :shipit:):

<pre>
  <code>
/home/code/main.cpp(9)
[Info   ] 2023-01-10 15:16:11.974 : This is a Info message.s
/home/code/main.cpp(10)
[Message] 2023-01-10 15:16:12.045 : This is just a simple message.
/home/code/main.cpp(11)
<font color="#00CC00">[Ok     ]</font> 2023-01-10 15:16:12.048 : This is a Ok message to tell you that everything working properly.
/home/code/main.cpp(12)
<font color="#FFCC00">[Warning]</font> 2023-01-10 15:16:12.051 : Be careful! you are looking good today. This was a Warning message.
/home/code/main.cpp(13)
<font color="#CC0000">[Error  ]</font> 2023-01-10 15:16:12.054 : This is a Error log sample.
/home/code/main.cpp(18)
<font color="#CC0000">[Error  ]</font> 2023-01-10 15:16:12.062 : Only Error logs are displayed. because the log level is 4.
/home/code/main.cpp(24)
<font color="#FFCC00">[Warning]</font> 2023-01-10 15:16:12.064 : This warning will be displayed.
/home/code/main.cpp(25)
<font color="#CC0000">[Error  ]</font> 2023-01-10 15:16:12.065 : As you can see, only Error and Warning logs are displayed.
/home/code/main.cpp(35)
<font color="#00CC00">[Ok     ]</font> 2023-01-10 15:16:12.068 : This Ok message will be displayed because logs are enabled.
/home/code/main.cpp(39)
[Info   ] 2023-01-10 15:16:12.069 : This is a Info message with complex formatting.
                                    Because complex formatting is enabled.
/home/code/main.cpp(43)
[Info   ] 2023-01-10 15:16:12.072 : This is a Info message without complex formatting.
Because complex formatting is disabled.
  </code>
</pre>
