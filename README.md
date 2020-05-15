# BatteryManagement
The BatteryManagement is a simple library to communicate with the MCP7871 battery charge controller


## Functions

### UML DIAGRAM

```bash
----------------------------------------------
|             BatteryManagement              |
----------------------------------------------
| -chs1 : DigitalIn                          |
| -chs2 : DigitalIn                          |
| -pg : DigitalIn                            |
| -chargestatus1 : bool                      |
| -chargestatus2 : bool                      |
| -powergood : bool                          |
|--------------------------------------------|
| +BatterySufficient(HardwareStatus*) : bool | 
| -SetErrorStatus(HardwareStatus*) : void    |
| -ReadBatteryStatus : void                  |
----------------------------------------------
```

### Functional
SetErrorStatus(HardwareStatus*) : does a bitwise operation on the given HardwareStatus to set the correct bits 

BatterySufficient(HardwareStatus*) : returns if the battery is not low 

ReadBatteryStatus() : set the flags according to the set pins



## Example

```cpp 
#include "mbed.h"
#include "BatteryManagement.h"
#include "hardwarestatus.h

//using namespace std;
using namespace Particula;
Serial pc(USBTX,USBRX);

int main(){
    printf("\r\n--------------------------------------------\n");
    printf("\r\nThis is an example of how to use the library\n");
    printf("\r\n--------------------------------------------\n");
    BatteryManagement bm(D2,D1,D0);               
    HardwareStatus hardwarestatus;
    
    while(true){                                            // endless loop   
        printf("\r\nThe battery is low: %B\n", bm.BatterySufficient(hardwarestatus));
        printf("\r\nHardware status (hex): %X \r\n", hardwarestatus.get_state());
        ThisThread::sleep_for(4000);                       // waites for 4 secondes
    }       
}
```


