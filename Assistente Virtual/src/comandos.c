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
                        "Ol�, do que voc� precisa?",
                        "Ol�, tudo bem? Precisa de ajuda para algo?",
                        "Oi, como vai? Quer que te ajude em alguma coisa?",
                        "Eai, em que posso te ajudar?" };

char* comoVaiRespostas[] = { "Eu estou �tima, e voc�?",
                            "Eu estou bem, espero que voc� tamb�m!",
                            "Estou bem, e voc�? Como vai?",
                            "Melhor do que nunca, e voc�?",
                            "Tudo tranquilo, e a�, tudo bem?" };

char* tudoBemRespostas[] = { "Que bom, fico feliz em saber!",
                            "Que �timo, � bom saber que voc� est� bem!",
                            "Beleza, nada melhor do que nos sentir bem!",
                            "Excelente, tudo parece mais alegre quando estamos bem!",
                            "Que bom, uma pessoa bem sempre transmite boas energias!" };

char* tudoMalRespostas[] = { "Que pena, mas quem sabe n�o posso te fazer sentir melhor.",
                            "Que triste, precisa de alguma ajuda para algo?",
                            "Que pena, a partir de agora minha miss�o ser� melhorar seu astral.",
                            "Eu ficaria muito feliz se, ap�s nossa conversa, voc� se sentisse melhor.",
                            "Que triste, espero que voc� se sinta melhor ap�s nossa conversa." };

char* bomDiaRespostas[] = { "Bom dia, como posso te ajudar hoje?",
                           "Bom dia, nada melhor do que acordar com uma boa conversa, deseja algo?",
                           "Bom dia, espero que tenha tido uma boa noite de sono!",
                           "Bom dia, tudo bem com voc�?",
                           "Bom dia, hoje eu acordei pronta para te ajudar!" };

char* boaTardeRespostas[] = { "Boa tarde, precisa de ajuda com algo?",
                             "Boa tarde, nada melhor do que uma boa conversa ap�s o almo�o!",
                             "Boa tarde, como vai voc�?",
                             "Boa tarde, acabei de fazer uma boquinha e estou pronta para te ajudar!",
                             "Boa tarde, estou aqui para te ajudar, deseja algo?",
                             "Boa tarde, em que posso te ajudar?" };

char* boaNoiteRespostas[] = { "Boa noite, o que posso fazer por voc�?",
                             "Boa noite, nada melhor do que uma boa conversa antes de dormir!",
                             "Boa noite, como foi seu dia?",
                             "Boa noite, j� terminei meu banho e estou pronta para te ajudar!",
                             "Boa noite, gostaria de ajuda com alguma coisa?" };

char* legalRespostas[] = { "Que bom que gostou, fico feliz por isso!",
                          "Legal mesmo, fico feliz que tenha gostado!",
                          "Sempre me alegra te ver feliz com algo.",
                          "Da hora mesmo, quer que te auxilie com algo mais?",
                          "Bacana, ver uma rea��o positiva me agrada!" };

char* obrigadoRespostas[] = { "Por nada, estou apenas fazendo meu servi�o, estarei dispon�vel para te ajudar em qualquer momento!",
                             "De nada, se precisar de algo mais, estou � disposi��o!",
                             "N�o � por nada, sempre fico feliz por fazer um trabalho bem feito!",
                             "De nada, estarei sempre disposta a atender futuras solicita��es!",
                             "Por nada, sempre estarei aqui se quiser mais alguma coisa." };

char* tchauRespostas[] = { "Que pena que voc� est� de despedindo, espero te ver novamente em breve!",
                          "Adeus! Te vejo em breve!",
                          "Tchau, espero te ver novamente amanh�!",
                          "Tchau, foi muito boa nossa conversa, at� mais.",
                          "Adeus, espero ter atendido a todas suas necessidades." };

char* aniversarioRespostas[] = { "Parab�ns, feliz anivers�rio!!!",
                                "Meus parab�ns, te desejo tudo de bom no dia de hoje!",
                                "Meus parab�ns, que todos seus desejos se realizem!",
                                "Parab�ns, quem sabe eu n�o posso te alegrar mais ainda nesse dia?",
                                "Isso me deixa muito feliz, gosto de saber que at� em dias especiais as pessoas se lembram de mim." };