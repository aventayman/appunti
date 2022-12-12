#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define N_CASELLE     64

const char disposizione_iniziale[] = "RNBQKBNRpppppppp________________________________ppppppppRNBQKBNR";

typedef struct{
    char tipo;
    int posizione;
    int eliminato;
}Pezzo;

void disegna_scacchiera(char* scacchiera){
    int k = 0;
    printf("     ");
    for (int i = 0; i < 8; i++) {
        printf("______");
    }
    printf("_\n     ");
    for (int i = 0; i < 8; i++) {
        printf("|     ");
    }
    printf("|\n  8  ");
    for (int i = 0; i < N_CASELLE; i++) {
        if ((i)%8 == 0) {
            k++;
        }
        printf("|");
        if (scacchiera[N_CASELLE - 8*k + i%8] == '_')
            printf("     ");
        else
            printf("  %c  ", scacchiera[N_CASELLE - 8*k + i%8]);
        if ((i + 1)%8 == 0) {
            printf("|\n     ");
            for (int j = 0; j < 8; j++) {
                printf("|_____");
            }
            printf("|\n");
            if (i != N_CASELLE -1) {
                printf("     ");
                for (int j = 0; j < 8; j++) {
                    printf("|     ");
                }
                printf("|\n  %d  ", 7 - i/8);
            }
        }
    }
    printf("\n     ");
    for (int i = 0; i < 8; ++i) {
        printf("   %c  ", 'a' + i);
    }
    printf("\n\n");
}

void inizializza_scacchiera(char *scacchiera_corrente, Pezzo *pezzi_bianco, Pezzo *pezzi_nero) {
    strncpy(scacchiera_corrente, disposizione_iniziale, N_CASELLE);
    for (int i = 0; i < 16; ++i) {
        pezzi_bianco[i].eliminato = 0;
        pezzi_bianco[i].posizione = i;
        pezzi_nero[i].eliminato = 0;
        pezzi_nero[i].posizione = 63 - i;
    }
    for (int i = 0; i < 16; ++i) {
        pezzi_bianco[i].tipo = disposizione_iniziale[i];
        pezzi_nero[i].tipo = disposizione_iniziale[63 - i];
    }
}

int casella_partenza(char *stringa) {
    int mossa;
    if ((stringa[0] < 'a' || stringa[0] > 'h') || (stringa[1] < '1' || stringa[1] > '8'))
        return -1;
    mossa = (stringa[0] - 'a') + (8 * (stringa[1] - '0' -1));
    return mossa;
}

int casella_arrivo(char *stringa) {
    int mossa;
    if ((stringa[2] < 'a' || stringa[2] > 'h') || (stringa[3] < '1' || stringa[3] > '8'))
        return -1;
    mossa = (stringa[2] - 'a') + (8 * (stringa[3] - '0' -1));
    return mossa;
}

int muovi_pedone(int partenza, int arrivo, Pezzo posizione_bianchi[], Pezzo posizione_neri[], int squadra) {
    int possibili_mosse[63];
    if (squadra == 1) {
        for (int i = 0; i < 16; ++i) {
            if (posizione_bianchi[i].posizione == arrivo && !posizione_bianchi[i].eliminato)
                return 0;
        }
    }
    else if (squadra == 0) {
        for (int i = 0; i < 16; ++i) {
            if (posizione_neri[i].posizione == arrivo && !posizione_bianchi[i].eliminato)
                return 0;
        }
    }
    return 1;
}

int muovi_re(int partenza, int arrivo, Pezzo posizione_bianchi[], Pezzo posizione_neri[], int squadra) {
    int possibili_mosse[63];
    if (squadra == 1) {
        for (int i = 0; i < 16; ++i) {
            if (posizione_bianchi[i].posizione == arrivo && !posizione_bianchi[i].eliminato)
                return 0;
        }
    }
    else if (squadra == 0) {
        for (int i = 0; i < 16; ++i) {
            if (posizione_neri[i].posizione == arrivo && !posizione_bianchi[i].eliminato)
                return 0;
        }
    }
    return 1;
    return 1;
}

int muovi_regina(int partenza, int arrivo, Pezzo posizione_bianchi[], Pezzo posizione_neri[], int squadra) {
    int possibili_mosse[63];
    if (squadra == 1) {
        for (int i = 0; i < 16; ++i) {
            if (posizione_bianchi[i].posizione == arrivo && !posizione_bianchi[i].eliminato)
                return 0;
        }
    }
    else if (squadra == 0) {
        for (int i = 0; i < 16; ++i) {
            if (posizione_neri[i].posizione == arrivo && !posizione_bianchi[i].eliminato)
                return 0;
        }
    }
    return 1;
}

int muovi_alfiere(int partenza, int arrivo, Pezzo posizione_bianchi[], Pezzo posizione_neri[], int squadra) {
    int possibili_mosse[63];
    if (squadra == 1) {
        for (int i = 0; i < 16; ++i) {
            if (posizione_bianchi[i].posizione == arrivo && !posizione_bianchi[i].eliminato)
                return 0;
        }
    }
    else if (squadra == 0) {
        for (int i = 0; i < 16; ++i) {
            if (posizione_neri[i].posizione == arrivo && !posizione_bianchi[i].eliminato)
                return 0;
        }
    }
    return 1;
}

int muovi_cavallo(int partenza, int arrivo, Pezzo posizione_bianchi[], Pezzo posizione_neri[], int squadra) {
    int possibili_mosse[63];
    if (squadra == 1) {
        for (int i = 0; i < 16; ++i) {
            if (posizione_bianchi[i].posizione == arrivo && !posizione_bianchi[i].eliminato)
                return 0;
        }
    }
    else if (squadra == 0) {
        for (int i = 0; i < 16; ++i) {
            if (posizione_neri[i].posizione == arrivo && !posizione_bianchi[i].eliminato)
                return 0;
        }
    }
    return 1;
}

int muovi_torre(int partenza, int arrivo, Pezzo posizione_bianchi[], Pezzo posizione_neri[], int squadra) {
    int possibili_mosse[63];
    if (squadra == 1) {
        for (int i = 0; i < 16; ++i) {
            if (posizione_bianchi[i].posizione == arrivo && !posizione_bianchi[i].eliminato)
                return 0;
        }
    }
    else if (squadra == 0) {
        for (int i = 0; i < 16; ++i) {
            if (posizione_neri[i].posizione == arrivo && !posizione_neri[i].eliminato)
                return 0;
        }
    }
    return 1;
}

int mossa_valida(int posizione, int squadra, Pezzo posizione_bianchi[], Pezzo posizione_neri[], char tipo,
                 int eliminato, int partenza, int arrivo) {
    if (eliminato)
        return 0;
    switch (tipo) {
        case 'p':
        {
            if (muovi_pedone(partenza, arrivo, posizione_bianchi, posizione_neri, squadra) == 1)
                return 1;
            return 0;
        }
        case 'K':
        {
            if (muovi_re(partenza, arrivo, posizione_bianchi, posizione_neri, squadra) == 1)
                return 1;
            return 0;
        }
        case 'Q':
        {
            if (muovi_regina(partenza, arrivo, posizione_bianchi, posizione_neri, squadra) == 1)
                return 1;
            return 0;
        }
        case 'B':
        {
            if(muovi_alfiere(partenza, arrivo, posizione_bianchi, posizione_neri, squadra) == 1)
                return 1;
            return 0;
        }
        case 'R':
        {
            if (muovi_torre(partenza, arrivo, posizione_bianchi, posizione_neri, squadra) == 1)
                return 1;
            return 0;
        }
        case 'N':
        {
            if (muovi_cavallo(partenza, arrivo, posizione_bianchi, posizione_neri, squadra) == 1)
                return 1;
            return 0;
        }
        default:
            return 0;
    }
}

int main() {
    Pezzo pezzi_bianco[16], pezzi_nero[16];
    int turno = 1, turno_backup, trovato;
    int partita = 1;
    printf("-----BENVENUTI AL GIOCO DEGLI SCACCHI-----\n"
           "Per uscire dal gioco digitare C\n"
           "Buona partita!\n");
    char scacchiera_corrente[N_CASELLE];
    inizializza_scacchiera(scacchiera_corrente, pezzi_bianco, pezzi_nero);
    while (partita) {
        trovato = 0;
        char mossa_stringa[20];
        int mossa[2];
        disegna_scacchiera(scacchiera_corrente);
        if (turno == 1)
            printf("Tocca al bianco\n");
        else
            printf("Tocca al nero\n");
        printf("Inserisci la mossa: ");
        scanf("%s", mossa_stringa);
        while (mossa_stringa[0] == 'C') {
            char risposta[1];
            printf("Sei sicuro di voler abbandonare? y/n ");
            scanf("%s", risposta);
            if (risposta[0] == 'y') {
                partita = 0;
                break;
            }
            else {
                printf("Inserisci la mossa: ");
                scanf("%s", mossa_stringa);
            }
        }
        mossa[0] = casella_partenza(mossa_stringa);
        mossa[1] = casella_arrivo(mossa_stringa);
        if (mossa[0] == -1 || mossa[1] == -1) {
            printf("Casella non valida!\n");
            turno_backup = turno;
            turno = -1;
        }

        if (turno == 1) {
            for (int i = 0; i < 16; ++i) {
                if (pezzi_bianco[i].posizione == mossa[0] && mossa_valida(pezzi_bianco[i].posizione, 1, pezzi_bianco,
                                                                        pezzi_nero, pezzi_bianco[i].tipo,
                                                                        pezzi_bianco[i].eliminato, mossa[0], mossa[1])) {
                    scacchiera_corrente[mossa[1]] = scacchiera_corrente[mossa[0]];
                    scacchiera_corrente[mossa[0]] = '_';
                    pezzi_bianco[i].posizione = mossa[1];
                    for (int j = 0; j < 16; ++j) {
                        if (pezzi_bianco[i].posizione == pezzi_nero[j].posizione)
                            pezzi_nero[j].eliminato = 1;
                    }
                    trovato = 1;
                }
            }
            if (!trovato) {
                turno = 0;
                printf("Mossa non valida!\n");
            }
        }
        else if (turno == 0) {
            for (int i = 0; i < 16; ++i) {
                if (pezzi_nero[i].posizione == mossa[0] && mossa_valida(pezzi_bianco[i].posizione, 0, pezzi_bianco,
                                                                        pezzi_nero, pezzi_bianco[i].tipo,
                                                                        pezzi_bianco[i].eliminato, mossa[0], mossa[1])) {
                    scacchiera_corrente[mossa[1]] = scacchiera_corrente[mossa[0]];
                    scacchiera_corrente[mossa[0]] = '_';
                    pezzi_nero[i].posizione = mossa[1];
                    trovato = 1;
                }
            }
            if (!trovato) {
                turno = 1;
                printf("Mossa non valida!\n");
            }
        }
        if (turno == -1)
            turno = !turno_backup;
        turno = (turno == 1) ? 0 : 1;
    }

    return 0;
}

