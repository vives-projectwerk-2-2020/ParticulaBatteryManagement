# BatteryManagement
The BatteryManagement is a simple library to communicate with the MCP7871 battery charge controller


## Functions

### UML DIAGRAM

```bash
------------------------------------
|        BatteryManagement         |
------------------------------------
| -chs1 : PinName                  |
| -chs2 : PinName                  |
| -pg : PinName                    |
| -chargestatus1 : bool            |
| -chargestatus2 : bool            |
| -powergood : bool                |
|----------------------------------|
| +SetErrorStatus(char*) : void    |
| +BatterySufficient : bool        | 
| -ReadBatteryStatus : void        |
------------------------------------
```

### Functional
SetErrorStatus(char*) : does a bitwise operation on the given char* to set the correct bits 

BatterySufficient() : returns if the battery is not low 

ReadBatteryStatus() : set the flags according to the set pins



## Example

```cpp 
#include "mbed.h"
#include "BatteryManagement.h"

//using namespace std;
using namespace Particula;
Serial pc(USBTX,USBRX);

int main(){
    printf("\r\n--------------------------------------------\n");
    printf("\r\nThis is an example of how to use the library\n");
    printf("\r\n--------------------------------------------\n");
    BatteryManagement bm(D2,D1,D0);               
    
    while(true){                                            // endless loop
        printf("\r\nThe battery is low: %B\n", bm.BatterySufficient());
        char error_values = 0x00;
        bm.SetErrorStatus(error_values);
        printf("\r\nThe value of error_values is: %d\n", error_values);
        ThisThread::sleep_for(4000);                       // waites for 4 secondes
    }       

}


