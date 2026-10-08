//! include/botao.h

#ifndef BOTAO_H
#define BOTAO_H

#include <Arduino.h>

class Botao{
    private:
        uint8_t _pinBotao;
        bool _estadoAtualBotao = HIGH;
        bool _estadoAnteriorBotao = HIGH;
        bool _pressionou = false;
        bool _soltou = false;
        uint32_t _ultimaMudanca_ms = 0;
        uint32_t _tempoDebounce_ms = 20;
        bool _estadoUltimaAcao = HIGH;
        uint32_t _tempoDecorrido();


    public:
        Botao(uint8_t pino);
        void iniciar();
        void atualizar();
        bool pressionou();
        bool soltou();


};

#endif