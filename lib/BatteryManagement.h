#pragma once 

#include "mbed.h"
#include "hardwarestatus.h"

namespace Particula{

    class BatteryManagement{

        public:
            BatteryManagement(PinName ,PinName , PinName);
            
        public:        
            bool BatterySufficient(HardwareStatus* hardwareStatus);

        private:
            void SetErrorStatus(HardwareStatus* hardwareStatus);
            void ReadBatteryStatus();

        private:
            DigitalIn chs1;
            DigitalIn chs2;
            DigitalIn pg;

            bool chargestatus1 = false;
            bool chargestatus2 = false;
            bool powergood = false;
    };
};