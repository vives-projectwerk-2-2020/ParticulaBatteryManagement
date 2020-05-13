#include "BatteryManagement.h"

namespace Particula {

    BatteryManagement::BatteryManagement(PinName chargeSt1,PinName chargeSt2, PinName powerGd){
        this->chs1 = chargeSt1;
        this->chs2 = chargeSt2;
        this->pg = powerGd;
    }

    void BatteryManagement::ReadBatteryStatus(){
        DigitalIn CH1(chs1,PullDown);
        DigitalIn CH2(chs2,PullDown);
        DigitalIn PG(pg,PullDown);

        chargestatus1 = (CH1.read() == 1);
        chargestatus2 = (CH2.read() == 1);
        powergood = (PG.read() == 1);

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