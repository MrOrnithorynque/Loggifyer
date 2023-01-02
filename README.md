# PTP::Loggifyer
Welcome to **Loggifyer**, a simple, fast and cross-platform logger library.

This library is from the [PTP](https://github.com/MrOrnithorynque/PTP/) library family.


## Features
- Simple and straightforward interface.
- Compatible with Windows, Linux, and Mac.
- Easy to read thanks to coherent coloring.
- Different Log levels : Message < Info < Warning < Error.
- Multi threading safe.
- Printf like formatting.
- Memory safe.
- Nice formatting option for messages with new lines.
- (FUTURE) Fully customizable with config file.

## Installation
To install **Loggifyer**, follow these steps:

1. Clone the repository or download the source code.
2. Run CMake to generate the build files for your platform.
3. Use the generated build files to build and install the library.
## Usage
To use **Loggifyer** in your project, simply include the Loggifyer.hpp header file and link the **PTP_Loggifyer** library to your project.

InAnyCppFile.cpp :
```cpp
#include "PTP_Loggifyer.hpp"

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
[Info   ] 0000-00-00 00:00:00.000 : This is a Info message.
[Message] 0000-00-00 00:00:00.000 : This is just a simple message.
<font color="#00CC00">[Ok     ] 0000-00-00 00:00:00.000 : This is a Ok message to tell you that everything working properly.</font>
<font color="#FFCC00">[Warning] 0000-00-00 00:00:00.000 : Be careful! you are looking good today. This was a Warning message.</font>
<font color="#CC0000">[Error  ] 0000-00-00 00:00:00.000 : This is a Error log sample.</font>
<font color="#CC0000">[Error  ] 0000-00-00 00:00:00.000 : Only Error logs are displayed. because the log level is 4.</font>
<font color="#FFCC00">[Warning] 0000-00-00 00:00:00.000 : This warning will be displayed.</font>
<font color="#CC0000">[Error  ] 0000-00-00 00:00:00.000 : As you can see, only Error and Warning logs are displayed.</font>
<font color="#00CC00">[Ok     ] 0000-00-00 00:00:00.000 : This Ok message will be displayed because logs are enabled.</font>
[Info   ] 2023-01-02 13:36:37.871 : This is a Info message with complex formatting.
                                    Because complex formatting is enabled.
[Info   ] 2023-01-02 13:36:37.875 : This is a Info message without complex formatting.
  </code>
</pre>
