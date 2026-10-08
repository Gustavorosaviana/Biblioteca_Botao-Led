//! include/led.h

#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led{
    private:

    uint8_t _pinLed;
    bool _estadoLed = 0;
    uint32_t _tempoAcaoAnterior_ms = 0;
    bool _estaPiscando = false;
    uint32_t _tempoEsperaAlternar_ms = 0;

    public:
   
    //* ================METODOS===============
    Led (uint8_t pino); // metodo construtor sendo inicializado com valor prórpio
    
    void ligar();
    void desligar();
    void ativarPiscar(uint32_t tempoEspera_ms = 500);
    void iniciar();
    void atualizar();
    void alternar();
    void desativarPiscar();

    uint8_t getPinLed();

    void setEstadoLed(bool estado);
};



#endif