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

    void BatteryManagement::SetErrorStatus(char * error_values){
        ReadBatteryStatus();
        if(chargestatus1){
            (*error_values) |= (1u << 10);
        } 
        if(chargestatus2){
            (*error_values) |= (1u << 11);
        } 
        if(powergood){
            (*error_values) |= (1u << 12);
        }
    }

    bool BatteryManagement::BatterySufficient(){
        ReadBatteryStatus();
        if (!chargestatus1 && chargestatus2 && powergood){
            return true;
        } else {
            return false;
        }
    }





}