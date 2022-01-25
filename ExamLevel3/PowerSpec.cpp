#include "PowerSpec.hpp"
PowerSpec::PowerSpec(){
    voltage=230;
    amps=1;
    strcpy(ACDC, "AC");
}
PowerSpec::PowerSpec(const char* acdc, int v, int a){
    if(v<0 || a<0 || (strcmp(acdc, "AC")!=0 && strcmp(acdc, "DC")!=0)){
        cout<<"Invalid data!"<<endl;
        voltage=230;
        amps=1;
        strcpy(ACDC, "AC");
    }
    else{
        strcpy(ACDC, acdc);
        voltage=v;
        amps=a;
    }
}
const char* PowerSpec::getACDC() const{
    return ACDC;
}
int PowerSpec::getVoltage() const{
    return voltage;
}
int PowerSpec::getAmps() const{
    return amps;
}
int PowerSpec::getPower() const{
    return voltage*amps;
}
void PowerSpec::print() const{
    cout<<ACDC<<"; voltage = "<<voltage<<"; amps = "<<amps<<endl;
}

bool PowerSpec::operator==(const PowerSpec& other) const{
    return strcmp(ACDC, other.getACDC())==0 && voltage==other.getVoltage() && amps==other.getAmps();
}
bool PowerSpec::operator!=(const PowerSpec& other) const{
    return strcmp(ACDC, other.getACDC())!=0 || voltage!=other.getVoltage() || amps!=other.getAmps();
}
bool PowerSpec::operator<(const PowerSpec& other) const{
    return strcmp(ACDC, other.getACDC())==0 && (voltage<other.getVoltage() || (voltage==other.getVoltage() && amps<other.getAmps()));
}
bool PowerSpec::operator>(const PowerSpec& other) const{
    return strcmp(ACDC, other.getACDC())==0 && (voltage>other.getVoltage() || (voltage==other.getVoltage() && amps>other.getAmps()));
}
bool PowerSpec::operator<=(const PowerSpec& other) const{
    return operator<(other) || operator==(other);
}
bool PowerSpec::operator>=(const PowerSpec& other) const{
    return operator>(other) || operator==(other);
}
