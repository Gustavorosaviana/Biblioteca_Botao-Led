//! scr/botao.cpp

#include "botao.h"

Botao::Botao(uint8_t pino): _pinBotao(pino){ // lista de incializacao

}

void Botao::iniciar(){
    pinMode(_pinBotao, INPUT_PULLUP);
    digitalWrite(_pinBotao, _estadoAtualBotao);
} 

void Botao::atualizar(){
    _pressionou = false;
    _soltou = false;

    _estadoAtualBotao = digitalRead(_pinBotao);
    
    if(_estadoAtualBotao != _estadoAnteriorBotao){
        _estadoAnteriorBotao = _estadoAtualBotao;
        _ultimaMudanca_ms = millis();
        return;
     }

     if(_tempoDecorrido() < _tempoDebounce_ms){
        return;
     }

     if(_estadoAtualBotao == _estadoAnteriorBotao){
        return;
     }

     _estadoAnteriorBotao = _estadoAtualBotao;

     const bool botaoPressionado =! _estadoAtualBotao;
            
    botaoPressionado 
    ? _pressionou = true 
    : _soltou = true;
}


// void Botao::atualizar(){
//     _pressionou = false;
//     _soltou = false;
    
//     _estadoAtualBotao = digitalRead(_pinBotao);
    
//     if(_estadoAtualBotao != _estadoAnteriorBotao){
//         _estadoAnteriorBotao = _estadoAtualBotao;
//         _ultimaMudanca_ms = millis();
//     }
    
//     if(_tempoDecorrido() > _tempoDebounce_ms){
        
//         const bool acaoExecutada = (_estadoUltimaAcao == _estadoAtualBotao);
//         if(!acaoExecutada){
//             _estadoUltimaAcao = _estadoAtualBotao;
        
//             const bool botaoPressionado =! _estadoAtualBotao;
            
//             botaoPressionado 
//             ? _pressionou = true 
//             : _soltou = true;
//         }
//     }
// }

bool Botao::pressionou(){
    return _pressionou;
}

bool Botao::soltou(){
    return _soltou;
}

uint32_t Botao::_tempoDecorrido(){
    return millis() - _ultimaMudanca_ms;
}