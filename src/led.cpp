//! scr/led.cpp

#include "led.h"

Led::Led(uint8_t pino) : _pinLed(pino){  // lista de incializacao 
    // _pinLed = pino;
}

void Led::ligar(){
    _estadoLed = HIGH;
}

void Led::desligar(){
    _estadoLed = LOW;
}

void Led::iniciar(){
    pinMode(_pinLed, OUTPUT);
    digitalWrite(_pinLed, _estadoLed);
    _tempoAcaoAnterior_ms = millis();
}

void Led::ativarPiscar(uint32_t tempoEspera_ms){
    _estaPiscando = true;
    _tempoEsperaAlternar_ms = tempoEspera_ms;
}

void Led::desativarPiscar(){
    _estaPiscando = false;
    _estadoLed = LOW;
}

void Led::atualizar(){
    if(_estaPiscando){
        const uint32_t tempoDecorrido = millis() - _tempoAcaoAnterior_ms;
       
        if(tempoDecorrido >= _tempoEsperaAlternar_ms){
            _tempoAcaoAnterior_ms = millis();
            alternar();
        } 
    }
    
    digitalWrite(_pinLed, _estadoLed);
}

void Led::alternar(){
    _estadoLed =! _estadoLed;
}

uint8_t Led::getPinLed(){
    return _pinLed;
}

void Led::setEstadoLed(bool estado){
    _estadoLed = estado;
}