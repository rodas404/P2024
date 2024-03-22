
#include "funcao.h"

// Nome: Rodrigo Miguel Pessoa da Bernarda
// Número: 2021136740


// Recebe:
// Endereço inicial de uma variável do tipo data (limD)
// Variável do tipo submissao (sub)

// Devolve a classificação obtida pela submissão

// Regras para calcular a classificação:
// 1. Submissão sub deve ter sido submetida na data indicada por limD, até às 11.55. Se cumprir estas restrições, devolve 10.
// Se tiver sido submetida na data indicada, mas depois das 11.55, perde 1 ponto por cada minuto de atraso. A partir das 12.05 passa a ter cotação 0
// Se a submissão tiver data diferente da referenciada por limD, deve ser devolvido o valor 0

// A função deve igualmente atualizar a data referenciada por limD, passando-a para o dia seguinte.
// Esta atualização deve ser efetuada depois de calcular a nota a atribuir à submissão

int calculaNota(data* limD, submissao sub){
    int nota = 0;
    if(sub.dataSub.dia == limD->dia && sub.dataSub.mes == limD->mes && sub.dataSub.ano == limD->ano){
        if(sub.horaSub.h<11 ||(sub.horaSub.h == 11 && sub.horaSub.m<=55))
            nota = 10;
        else if((sub.horaSub.h==11 && sub.horaSub.m>=56) ||(sub.horaSub.h == 12 && sub.horaSub.m<=05))
            nota = 10 - ((sub.horaSub.h*60 + sub.horaSub.m)-(11*60 + 55));
    }

    if(limD->mes == 4 || limD->mes == 6 || limD->mes == 9 || limD->mes == 11 && limD->dia == 30){
        (limD->mes)++;
        (limD->dia) = 1;
    }
    else if(limD->mes == 2){
        if((limD->ano % 4 == 0 && limD->ano % 100 != 0) || (limD->ano % 400 ==0)){
            if(limD->dia >= 29){
                (limD->dia)=1;
                (limD->mes)++;
            }
            else
                (limD->dia)++;
        }
        else{
            if(limD->dia >= 28){
                (limD->dia)=1;
                (limD->mes)++;
            }
            else
                (limD->dia)++;
        }
    }
    else if(limD->dia == 31 && limD->mes == 12){
        (limD->dia)=1;
        (limD->mes)=1;
        (limD->ano)++;
    }
    else if(limD->dia == 31){
        (limD->dia)=1;
        (limD->mes)++;
    }
    else
        (limD->dia)++;

    return nota;
}