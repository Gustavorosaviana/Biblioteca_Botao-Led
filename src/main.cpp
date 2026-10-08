#include <Arduino.h>
#include "led.h"
#include "botao.h"

Led ledAmarelo(4);
Led ledVerde(6);
Led ledVermelho(15);

void setup() {
    ledAmarelo.iniciar();
    ledAmarelo.ativarPiscar();
    
    ledVerde.iniciar();
    ledVerde.ativarPiscar(1000);
    
    ledVermelho.iniciar();
    ledVermelho.ativarPiscar(2000);
}

void loop() {
    ledAmarelo.atualizar();
    ledVerde.atualizar();
    ledVermelho.atualizar();
}

