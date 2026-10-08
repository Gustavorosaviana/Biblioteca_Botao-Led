#include <Arduino.h>
#include "led.h"
#include "botao.h"

Led ledAmarelo(4);
Led ledVerde(6);
Led ledVermelho(15);

Botao btn01(12);
Botao btn02(13);
Botao btn03(14);

void setup() {
    ledAmarelo.iniciar();
    ledVerde.iniciar();
    ledVermelho.iniciar();
    
    btn01.iniciar();
    btn02.iniciar();
    btn03.iniciar();
}

void loop() {
    if(btn01.pressionou()){
        ledVerde.ligar();
    }
    
    if(btn02.pressionou()){
       ledAmarelo.ligar();
    }
    
    if(btn03.pressionou()){
        ledVermelho.ligar();
    }
    
    ledAmarelo.atualizar();
    ledVerde.atualizar();
    ledVermelho.atualizar();
    btn01.atualizar();
    btn02.atualizar();
    btn03.atualizar();
}

