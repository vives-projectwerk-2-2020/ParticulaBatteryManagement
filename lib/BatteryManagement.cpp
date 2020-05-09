#include "BatteryManagement.h"

namespace Particula {

    BatteryManagement::BatteryManagement(PinName chargeSt1,PinName chargeSt2, PinName powerGd ){
        chs1 = chargeSt1;
        chs2 = chargeSt2;
        pg = powerGd;
    }

    void BatteryManagement::ReadBatteryStatus(){
        if(chs1 == 1){
            chargestatus1 = true;
        } else {
            chargestatus1 = false;
        }
        if(chs2 == 1){
            chargestatus2 = true;
        } else {
            chargestatus2 = false;
        }
        if(pg == 1){
            powergood = true;
        } else {
            powergood = false;
        }
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
            return true;
        } else {
            return false;
        }
    }





}