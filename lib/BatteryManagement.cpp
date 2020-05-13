#include "BatteryManagement.h"

namespace Particula {

    BatteryManagement::BatteryManagement(PinName chargeSt1,PinName chargeSt2, PinName powerGd)
        :chs1(chargeSt1,PullDown), chs2(chargeSt2,PullDown), pg(powerGd,PullDown){

    }

    void BatteryManagement::ReadBatteryStatus(){
        chargestatus1 = (chs1.read() == 1);
        chargestatus2 = (chs2.read() == 1);
        powergood = (pg.read() == 1);

    }

    void BatteryManagement::SetErrorStatus(HardwareStatus* hardwareStatus){
        ReadBatteryStatus();
        if(chargestatus1){
            (*hardwareStatus).set_stat1();
        } 
        if(chargestatus2){
            (*hardwareStatus).set_stat2();
        } 
        if(powergood){
            (*hardwareStatus).set_pg();
        }
    }

    bool BatteryManagement::BatterySufficient(HardwareStatus* hardwareStatus){
        ReadBatteryStatus();
        SetErrorStatus(hardwareStatus);
        if (!chargestatus1 && chargestatus2 && powergood){
            return false;
        } else {
            return true;
        }
    }





}