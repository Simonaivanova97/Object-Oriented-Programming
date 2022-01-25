#include "Transformer.hpp"
void Transformer::copyTransformer(const Transformer& other){
    brand=new char[strlen(other.brand)+1];
    assert(brand!=NULL);
    strcpy(brand, other.brand);
    inSpec=other.inSpec;
    outSpec=other.outSpec;
}
Transformer::Transformer(){
    brand=new char[strlen("Unknown")+1];
    assert(brand!=NULL);
    strcpy(brand, "Unknown");
    inSpec=PowerSpec("DC",0,0);
    outSpec=PowerSpec("DC", 0, 0);
}
Transformer::Transformer(const char* b, const PowerSpec& iS, const PowerSpec& oS){
    brand=new char[strlen(b)+1];
    assert(brand!=NULL);
    strcpy(brand, b);
    inSpec=iS;
    outSpec=oS;
}
Transformer::Transformer(const Transformer& other){
    copyTransformer(other);
}
Transformer& Transformer::operator=(const Transformer& other){
    if(this!=&other){
        delete []brand;
        copyTransformer(other);
    }
    return *this;
}
Transformer::~Transformer(){
    delete []brand;
}
const char* Transformer::getBrand() const{
    return brand;
}
PowerSpec Transformer::getInSpec() const{
    return inSpec;
}
PowerSpec Transformer::getOutSpec() const{
    return outSpec;
}
Transformer Transformer::operator*(const Transformer& other) const{
    if(getOutSpec()==other.getInSpec()){
        char* newBrand=new char[strlen(brand)+strlen(other.brand)+1+1];
        assert(newBrand!=NULL);
        strcat(newBrand, brand);
        strcat(newBrand, "-");
        strcat(newBrand, other.getBrand());
        Transformer t(newBrand, getInSpec(), other.getOutSpec());
        delete []newBrand;
        return t;
    }
    else{
        return *this;
    }
}
void Transformer::print() const{
    cout<<"Brand: "<<brand<<endl;
    cout<<"InSpec: ";
    inSpec.print();
    cout<<"OutSpec: ";
    outSpec.print();
}

