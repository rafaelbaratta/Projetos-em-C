#include <string.h>
#include "comandos.h"

char* ola[] = { "oi", "ola", "opa", "eai", "hey", "aopa", "aoba", "Sara", NULL };
char* comoVai[] = { "blz?", "como vai?", "tudo bem?", "beleza?", "de boa?", "boa?", "bem?", "bao?", NULL };
char* tudoBem[] = { "beleza", "blz", "bem", "boa", "tudo otimo", "bom", "estou otimo", NULL };
char* tudoMal[] = { "mal", "ruim", "tudo pessimo", "tudo mal", NULL };
char* bomDia[] = { "bom dia", "b dia", "b. dia", NULL };
char* boaTarde[] = { "boa tarde", "b tarde", "b. tarde", NULL };
char* boaNoite[] = { "boa noite", "b noite", "b. noite", NULL };
char* legal[] = { "legal", "daora", "da hora", "bacana", "engracado", "engracada", "fantastico", "otimo", "excelente", NULL };
char* obrigado[] = { "obrigado", "obrigada", "obg", "valeu", "valew", "vlw", NULL };
char* tchau[] = { "tchau", "xau", "ciao", "adeus", "te logo", "te depois", "falou", "falow", "flw", NULL };
char* aniversario[] = { "aniversario", "hoje e meu aniversario", "niver", NULL };

char* ajuda[] = { "ajuda", "ajudar", "socorro", "como funciona", "comando", "funconamento", NULL };
char* horas[] = { "hora", "horas", "horario", NULL };
char* hoje[] = { "hoje", "data", "dia e hoje", NULL };
char* limpar[] = { "limpar", "esvaziar", "apagar", "resetar", NULL };
char* piada[] = { "piada", "trocadilho", NULL };
char* curiosidade[] = { "curiosidade", "informacao", "informacoes", NULL };
char* travaLingua[] = { "trava-lingua", "travalingua", "trava lingua", NULL };
char* calculos[] = { "calculo", "calculos", "calcular", "conta", "contas", "contar", "soma", "adicao", "subtracao", "multiplicacao", "divisao",
                    "somar", "adicionar", "subtrair", "multiplicar", "dividir", NULL };

char* olaRespostas[] = { "Oi, como posso te ajudar hoje?",
                        "Olá, do que você precisa?",
                        "Olá, tudo bem? Precisa de ajuda para algo?",
                        "Oi, como vai? Quer que te ajude em alguma coisa?",
                        "Eai, em que posso te ajudar?" };

char* comoVaiRespostas[] = { "Eu estou ótima, e você?",
                            "Eu estou bem, espero que você também!",
                            "Estou bem, e você? Como vai?",
                            "Melhor do que nunca, e você?",
                            "Tudo tranquilo, e aí, tudo bem?" };

char* tudoBemRespostas[] = { "Que bom, fico feliz em saber!",
                            "Que ótimo, é bom saber que você está bem!",
                            "Beleza, nada melhor do que nos sentir bem!",
                            "Excelente, tudo parece mais alegre quando estamos bem!",
                            "Que bom, uma pessoa bem sempre transmite boas energias!" };

char* tudoMalRespostas[] = { "Que pena, mas quem sabe não posso te fazer sentir melhor.",
                            "Que triste, precisa de alguma ajuda para algo?",
                            "Que pena, a partir de agora minha missão será melhorar seu astral.",
                            "Eu ficaria muito feliz se, após nossa conversa, você se sentisse melhor.",
                            "Que triste, espero que você se sinta melhor após nossa conversa." };

char* bomDiaRespostas[] = { "Bom dia, como posso te ajudar hoje?",
                           "Bom dia, nada melhor do que acordar com uma boa conversa, deseja algo?",
                           "Bom dia, espero que tenha tido uma boa noite de sono!",
                           "Bom dia, tudo bem com você?",
                           "Bom dia, hoje eu acordei pronta para te ajudar!" };

char* boaTardeRespostas[] = { "Boa tarde, precisa de ajuda com algo?",
                             "Boa tarde, nada melhor do que uma boa conversa após o almoço!",
                             "Boa tarde, como vai você?",
                             "Boa tarde, acabei de fazer uma boquinha e estou pronta para te ajudar!",
                             "Boa tarde, estou aqui para te ajudar, deseja algo?",
                             "Boa tarde, em que posso te ajudar?" };

char* boaNoiteRespostas[] = { "Boa noite, o que posso fazer por você?",
                             "Boa noite, nada melhor do que uma boa conversa antes de dormir!",
                             "Boa noite, como foi seu dia?",
                             "Boa noite, já terminei meu banho e estou pronta para te ajudar!",
                             "Boa noite, gostaria de ajuda com alguma coisa?" };

char* legalRespostas[] = { "Que bom que gostou, fico feliz por isso!",
                          "Legal mesmo, fico feliz que tenha gostado!",
                          "Sempre me alegra te ver feliz com algo.",
                          "Da hora mesmo, quer que te auxilie com algo mais?",
                          "Bacana, ver uma reação positiva me agrada!" };

char* obrigadoRespostas[] = { "Por nada, estou apenas fazendo meu serviço, estarei disponível para te ajudar em qualquer momento!",
                             "De nada, se precisar de algo mais, estou à disposição!",
                             "Não é por nada, sempre fico feliz por fazer um trabalho bem feito!",
                             "De nada, estarei sempre disposta a atender futuras solicitações!",
                             "Por nada, sempre estarei aqui se quiser mais alguma coisa." };

char* tchauRespostas[] = { "Que pena que você está de despedindo, espero te ver novamente em breve!",
                          "Adeus! Te vejo em breve!",
                          "Tchau, espero te ver novamente amanhã!",
                          "Tchau, foi muito boa nossa conversa, até mais.",
                          "Adeus, espero ter atendido a todas suas necessidades." };

char* aniversarioRespostas[] = { "Parabéns, feliz aniversário!!!",
                                "Meus parabéns, te desejo tudo de bom no dia de hoje!",
                                "Meus parabéns, que todos seus desejos se realizem!",
                                "Parabéns, quem sabe eu não posso te alegrar mais ainda nesse dia?",
                                "Isso me deixa muito feliz, gosto de saber que até em dias especiais as pessoas se lembram de mim." };