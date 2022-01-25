#ifndef Transformer_hpp
#define Transformer_hpp

#include <stdio.h>
#include "PowerSpec.hpp"

class Transformer{
public:
    Transformer();
    Transformer(const char*, const PowerSpec&, const PowerSpec&);
    Transformer(const Transformer&);
    Transformer& operator=(const Transformer&);
    ~Transformer();
    
    const char* getBrand() const;
    PowerSpec getInSpec() const;
    PowerSpec getOutSpec() const;
    
    Transformer operator*(const Transformer&) const;
    
    void print() const;
private:
    char* brand;
    PowerSpec inSpec;
    PowerSpec outSpec;
    
    void copyTransformer(const Transformer&);
};

#endif /* Transformer_hpp */
