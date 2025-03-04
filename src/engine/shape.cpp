#include "shape.h"


// Getters for Square
float Square::getOriginX(){
    return OriginX;
}

float Square::getOriginY(){
    return OriginY;
}

float Square::getEndX(){
    return endX;
}

float Square::getEndY(){
    return endY;
}

// Setters for Square
float Square::setOriginX(float x){
    OriginX = x;
} 

float Square::setOriginY(float y){
    OriginY = y;
}


float Square::setEndX(float newEndx){
    endX = newEndx;
}

float Square::setEndY(float newEndY){
    endY = newEndY;
}

// Getters for Square
float Circle::getC_OriginX(){
    return C_OriginX;
}

float Circle::getC_OriginY(){
    return C_OriginY;
}

float Circle::getC_endX(){
    return C_endX;
}

float Circle::getC_endY(){
    return C_endY;
}

// Setters for Square
float Circle::setC_OriginX(float x){
    C_OriginX = x;
} 

float Circle::setC_OriginY(float y){
    C_OriginY = y;
}

float Circle::setC_endX(float C_newEndx){
    C_endX = C_newEndx;
}

float Circle::setC_endY(float C_newEndY){
    C_endY = C_newEndY;
}