//
//  main.cpp
//  Test1
//
//  Created by Simona Ivanova.
//

#include <iostream>
#include "CoupleWords.hpp"
#include "Dictionary.hpp"
using namespace std;

int main() {
    CoupleWords first("apple","the usually round, red or yellow, edible fruit of a small tree");
    CoupleWords second("wardrobe","a piece of furniture for holding clotes");
    CoupleWords thirth("frame","a border or case for enclosing a picture, mirror, etc");
    CoupleWords fourth("flower","the blossom of plant");
    CoupleWords fifth("school", "an institution for instruction in a particular skill or field");
    CoupleWords sixth("friend", "a person attavhed to another by feelings of affection or personal regard");
    CoupleWords seventh("carpet","a heavy fabric, commonly of wool or nylon, for covering floors");
    CoupleWords eighth("town","a thickly populated area, usually smaller than a city and larger than a village");
    CoupleWords nineth("bottle","a portable container for holding liquids");
    CoupleWords tenth("clothes","garments for the body");

    /*
    first.print();
    second.print();
    CoupleWords eleventh;
    eleventh.print();
    eleventh=thirth;
    eleventh.print();
    eleventh.setWord("apple");
    eleventh.print();
    eleventh.setMeaning("the usually round, red or yellow, edible fruit of a small tree");*/
    
    //Dictionary d1;
    //d1.print();
    CoupleWords arr[5]={first, second, thirth, fourth, fifth};
    Dictionary d1(5, arr);
    //d1.print();
    /*Dictionary d2=d1;
    d2.print();*/
    d1.addCoupleWords(sixth);
    d1.addCoupleWords(seventh);
    d1.addCoupleWords(eighth);
    d1.addCoupleWords(nineth);
    d1.addCoupleWords(tenth);
    d1.print();
    cout<<endl;
    
    d1.deleteCoupleWords(seventh);
    d1.print();
    cout<<endl;
    
    cout<<d1["flower"]<<endl;
    cout<<d1["bag"]<<endl;
    return 0;
}

