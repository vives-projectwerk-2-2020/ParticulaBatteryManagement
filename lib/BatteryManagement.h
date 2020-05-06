#pragma once 

#include "mbed.h"

namespace Particula{

    class BatteryManagement{

        public:
            BatteryManagement(PinName ,PinName , PinName );
        public:
            void SetErrorStatus(char * error_values);
            bool BatterySufficient();
        private:
            void ReadBatteryStatus();
        private:
            PinName chs1;
            PinName chs2;
            PinName pg;
            bool chargestatus1 = false;
            bool chargestatus2 = false;
            bool powergood = false;

    }
}