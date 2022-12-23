#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <locale.h>

struct hrAgr{

int dia,mes,ano,hora,min,seg;
};


typedef struct{
    char login[30];
    char senha[30];
} pessoa; pessoa p[1];

typedef struct{
    char adm[30];
    char adm2[30];
} adm3; adm3 k[1];

int a,b,L,L2;

void gotoxy(int x,int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void limpa_linha() {
    scanf("%*[^\n]");
    scanf("%*c");
}

int main(){


//inicio Definição de tempo para o programa extrair do proprio PC
    struct tm tempo;
    time_t temp;

    time(&temp);
    tempo = *localtime(&temp);

    struct hrAgr agr;
    agr.dia = tempo.tm_mday;
    agr.mes = tempo.tm_mon + 1;
    agr.ano = tempo.tm_year + 1900;
    agr.hora = tempo.tm_hour;
    agr.min = tempo.tm_min;
    agr.seg = tempo.tm_sec;
//Fim Definição de tempo para o programa extrair do proprio PC

    setlocale(LC_ALL, "Portuguese");

    char exibir[100];char op[10];char CPF[100];char login[30];char senha[30];char adm[30];char adm2[30];char doenca[100];char ecenf[10];char loog[100];char assel[100];

    int i, j, c, t, mk;
    int ret,w;
    FILE *novousu;

    strcpy(p[0].login, "Bruno");strcpy(p[0].senha, "123");strcpy(p[1].login, "Adm");
    strcpy(p[1].senha, "123");strcpy(k[0].adm, "Adm");strcpy(k[0].adm2, "123");

    while(t <= 5){
        j++;
        if(j > 120){
            printf("\n                 Números de tentativas esgotadas\n\n");
            system("pause");
            system("cls");
            return 0;
    }else{
        printf("\n\n\n                           LOGIN:");
        scanf("%s", login);
        for(i = 0; i < 3; i++){
            if (strcmp(login,p[i].login)==0){
                printf("                           Olá Sr %s", login,p[i]);
                strcpy(assel, login);
                t = 6;
                break;}
            else{
                novousu = fopen("usuarios.txt", "r");
                char loga[100] = "Login: ";
                strncat(loga,login, 100);
                strncat(loga,"\n", 100);
                while(fgets(loog, 100, novousu) != NULL){
                    ret = strcmp(loog, loga);
                    if(ret == 0){
                        t = 6;
                        strcpy(assel, login);
                        break;}}}}}}
    j = 0;
    t = 0;
    while(t <= 5){
        j++;
        if(j > 120){
            printf("\n                 Números de tentativas esgotadas");
            system("cls");
            Sleep(3000);
            return 0;
    }else{
        printf("\n                           SENHA:");
        scanf("%s", senha);
        for(i = 0; i < 3; i++){
            if (strcmp(senha,p[i].senha)==0){
                printf("\n                           Senha Correta\n                           Seja bem vindo");
                Sleep(1500);
                t = 6;
                break;}
            else{
                char loga[100] = "Senha: ";
                strncat(loga,senha, 100);
                while(fgets(loog, 100, novousu) != NULL){
                    ret = strcmp(loog, loga);
                    if(ret == 0){
                        printf("                           Senha correta");
                        Sleep(1500);
                        t = 6;
                        break;}}}}}}
    ///menu/
    int opcao;
    FILE *cadastro;
    do{
        inicio:
        mk = 0;
        opcao=0;
        L=2;L2=2;b=2;
        system("cls");
        system("color 0f");
        printf("\t\t               MENU PRINCIPAL\n ");
        printf("\n\t\t\t    1 - CADASTRAR NOVO PACIENTE \n\t\t\t    2 - PESQUISAR CPF \n\t\t\t    3 - CASOS DE COVID-19 \n\t\t\t    4 - CADASTRAR NOVO USUARIO\n\t\t\t    5 - SAIR");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t     ");
        do{
            gotoxy(1,L);
            printf("\t\t\t-->");
            gotoxy(10,5);
            if(kbhit){a=getch();}
            if(a == 80 && b < 6){L2=L;L++;b++;}/*seta p/baixo*/
            if(a == 72 && b > 2){L2=L;L--;b--;}/*seta p/cima */
            if(L!=L2){gotoxy(1,L2);printf("\t\t\t   ");L2=L;}
            if(a == 13){opcao=b-1;}
        }while(opcao == 0);
        switch (opcao){
            case 1:
                {
                system("cls");
                char pri[100],anod1[100];//Usuario digita
                int contcpf,idd,anod;

                printf("\n\t                 CADASTRAR NOVO PACIENTE\n");
                cadastro = fopen("casos.txt", "a");

                printf("\tIdade: ");
                scanf("%d", &idd);

                inicpf:
                if(mk > 6){goto inicio;}
                limpa_linha();
                printf("\tCPF [Somente numeros]: ");
                scanf("%[^\n]s", pri);
                contcpf = strlen(pri);
                if(contcpf < 11){
                    printf("\n\tFalta números!!!\n");
                    mk++;
                    goto inicpf;
                }
                else if(contcpf > 11){
                    printf("\n\tNúmero a mais CPF's possuem 11 números!!!\n");
                    mk++;
                    goto inicpf;
                }
                fprintf(cadastro, "CPF:");
                fprintf(cadastro, "%s\n", pri);//Primeiro que irá receber o CPF


                limpa_linha();
                printf("\tNome: ");
                scanf("%100[^\n]s", pri);
                fprintf(cadastro, "Nome:");
                fprintf(cadastro, "%s\n", pri);//Segundo que irá receber o Nome


                limpa_linha();
                printf("\tTelefone C/DDD: ");
                scanf("%12[^\n]s\n", pri);
                fprintf(cadastro, "Telefone: ");
                fprintf(cadastro, "%s\n", pri);//Segundo que irá receber o Telefone


                limpa_linha();
                printf("\tRua: ");
                scanf("%100[^\n]s\n", pri);
                fprintf(cadastro, "Rua: ");
                fprintf(cadastro, "%s\n", pri);//Terceiro que irá receber a Rua


                limpa_linha();
                printf("\tNúmero: ");
                scanf("%100[^\n]s\n", pri);
                fprintf(cadastro, "Número: ");
                fprintf(cadastro, "%s\n", pri);//Quarto que irá receber o Número da casa


                limpa_linha();
                printf("\tBairro: ");
                scanf("%100[^\n]s\n", pri);
                fprintf(cadastro, "Bairro: ");
                fprintf(cadastro, "%s\n", pri);//Quinto que irá receber o Bairro


                limpa_linha();
                printf("\tCidade: ");
                scanf("%100[^\n]s\n", pri);
                fprintf(cadastro, "Cidade: ");
                fprintf(cadastro, "%s\n", pri);//Sexto que irá receber a Cidade


                limpa_linha();
                printf("\tEstado: ");
                scanf("%100[^\n]s\n", pri);
                fprintf(cadastro, "Estado: ");
                fprintf(cadastro, "%s\n", pri);//Setimo que irá receber o Estado


                limpa_linha();
                printf("\tCEP: ");
                scanf("%100[^\n]s\n", anod1);
                fprintf(cadastro, "CEP: ");
                fprintf(cadastro, "%s\n", anod1);//Oitavo que irá receber o CEP


                limpa_linha();
                printf("\tEmail: ");
                scanf("%100[^\n]s\n", pri);
                fprintf(cadastro, "Email: ");
                fprintf(cadastro, "%s\n", pri);//Decimo que irá receber o Email

                limpa_linha();
                printf("\tEsse paciente possui Fatores de Risco, \n\tVulnerabilidade em Saúde?[S/N]: ");
                scanf("%s", ecenf);
                int stden = strcmp(ecenf,"s");
                if(stden == 0){
                    limpa_linha();
                    printf("\n\tQual a doença: ");
                    scanf("%s", doenca);
                }

                if(idd>=65){
                    printf("\tEste paciente possui mais de 65 anos\n");
                    Sleep(1000);
                    printf("\tInforme ao mesmo que se cuide e cumpra a quarentena\n");
                    Sleep(1000);
                    printf("\tO cep do páciente será enviado para secretaria de saude\n");
                    Sleep(1200);
                    printf("\tPara que o mesmo seje acompanhado e localizar possiveis focos principais....\n\n");
                    Sleep(1200);
                    system("pause");
                    FILE *SecretariaDeSaude;
                    SecretariaDeSaude = fopen("Secretaria.txt", "a");
                    fprintf(SecretariaDeSaude, "Idade: ");
                    fprintf(SecretariaDeSaude, "%d\n", idd);
                    fprintf(SecretariaDeSaude, "CEP: ");
                    fprintf(SecretariaDeSaude, "%s\n", anod1);
                    fclose(SecretariaDeSaude);
                    fprintf(cadastro, "Hora.....: %02d:%02d:%02d\n", agr.hora, agr.min, agr.seg);
                    fprintf(cadastro, "Data do diagnostico: %02d/%02d/%02d\n", agr.dia, agr.mes, agr.ano);
                    fprintf(cadastro, "========================= %s\n", assel);

                    fprintf(cadastro, "Idade: ");
                    fprintf(cadastro, "%d\n", idd);//Nono que irá receber a Idade
                    stden = strcmp(ecenf,"s");
                    if(stden == 0){
                        fprintf(SecretariaDeSaude, "Doença: ");
                        fprintf(SecretariaDeSaude, "%s\n", doenca);
                        fprintf(SecretariaDeSaude, "Data do diagnostico: %02d/%02d/%02d\n", agr.dia, agr.mes, agr.ano);
                    }


                    fclose(cadastro);
                    break;}
                fprintf(cadastro, "Idade: ");
                fprintf(cadastro, "%d\n", idd);//Nono que irá receber a Idade

                stden = strcmp(ecenf,"s");
                if(stden == 0){
                    printf("\tEste paciente tem %s\n", doenca);
                    Sleep(1000);
                    printf("\tInforme ao mesmo que se cuide e cumpra a quarentena\n");
                    Sleep(1000);
                    printf("\tO cep do páciente será enviado para secretaria de saude\n");
                    Sleep(1200);
                    printf("\tPara que o mesmo seje acompanhado e localizar possiveis focos principais....");
                    Sleep(1200);
                    FILE *SecretariaDeSaude;
                    SecretariaDeSaude = fopen("Secretaria.txt", "a");
                    fprintf(SecretariaDeSaude, "Idade: ");
                    fprintf(SecretariaDeSaude, "%d\n", idd);
                    fprintf(SecretariaDeSaude, "CEP: ");
                    fprintf(SecretariaDeSaude, "%s\n", anod1);
                    fprintf(SecretariaDeSaude, "========================= %s\n", assel);
                    fclose(SecretariaDeSaude);
                }


                fprintf(cadastro, "Hora.....: %02d:%02d:%02d\n", agr.hora, agr.min, agr.seg);
                fprintf(cadastro, "Data do diagnostico: %02d/%02d/%02d\n", agr.dia, agr.mes, agr.ano);
                fprintf(cadastro, "========================= %s\n", assel);


                fclose(cadastro);
                break;}

            case 2:
                {
                system("cls");
                printf("\n\t                 PESQUISAR CPF\n");
                char pesquisa[50];
                system("cls");
                inipesq:
                printf("\n\n\tDigite o CPF do paciente [Somente números]: ");
                w = 0;
                scanf("%s", pesquisa);
                char CPF[50] = "CPF:";
                strncat(CPF,pesquisa, 100);
                printf("%s", CPF);
                strncat(CPF,"\n", 100);
                cadastro = fopen("casos.txt", "r");
                while(fgets(exibir, 100, cadastro) != NULL){
                    ret = strcmp(exibir, CPF);
                    if(ret == 0){
                        while(w != 13){
                            fgets(exibir, 100, cadastro);
                            printf("\n%s",exibir);
                            w++;
                            if(w == 13){
                                system("pause");
                                printf("\n\n\tDeseja realiza nova pesquisa?[s/n]: ");
                                scanf("%s", op);
                                if(strcmp(op,"s")==0){
                                    goto inipesq;
                                }else{
                                    goto inicio;}}}}}
                    if (w == 0){
                    printf("\n\n\n\tNenhum cadastro encontrado\n\n\n");
                    system("pause");
                    system("cls");
                    printf("\n\n\tDeseja realiza nova pesquisa?[s/n]: ");
                    scanf("%s", op);
                    if(strcmp(op,"s")==0){
                        goto inipesq;
                    }else{
                        goto inicio;}
                    system("cls");
                    goto inipesq;}
                fclose(cadastro);
                Sleep(2000);
                break;}
            case 3:
                {
                system("cls");
                printf("\n\t                 CASOS DE COVID-19\n\n\n\n");
                cadastro = fopen("casos.txt", "r");
                while(fgets(exibir, 100, cadastro) != NULL){
                        printf("\t%s", exibir);
                        Sleep(500);
                }
                system("pause");
                fclose(cadastro);
                Sleep(2000);
                break;
                }
            case 4:{

                system("cls");
                int Usunovo;
                char usuarioNovo[100];
                printf("\n\t                 CADASTRAR NOVO USUARIO\n\n\n\n");
                novousu = fopen("usuarios.txt", "a");
                printf("\nDigite o login do ADM: ");
                scanf("%s", usuarioNovo);
                Usunovo = strcmp(usuarioNovo,k[0].adm);
                if(Usunovo == 0){
                    printf("\nDigite a senha do ADM: ");
                    scanf("%s", usuarioNovo);
                    Usunovo = strcmp(usuarioNovo,k[0].adm2);
                    if(Usunovo == 0){
                        printf("Correto");
                        Sleep(1000);
                        system("cls");
                        limpa_linha();
                        printf("\t\t\n\n\nNovo login: ");
                        scanf("%100[^\n]s\n", usuarioNovo);
                        fprintf(novousu, "Login: %s", usuarioNovo);
                        limpa_linha();
                        printf("\t\t\nSenha do login %s: ", usuarioNovo);
                        scanf("%100[^\n]s\n", usuarioNovo);
                        fprintf(novousu, "\nSenha: %s", usuarioNovo);
                        fprintf(novousu, "\n==================\n");
                    }

                }
                fclose(novousu);
                break;}
            case 5:
                {
                system("cls");
                printf("\tVoce pediu para sair, prencione qualquer tecla para continuar\n\n\n");
                return 0;
                break;
            default:
                printf("\tVocê deve escolher uma opcao valida\n");
                printf("\tPrecione qualquer tecla para voltar ao menu\n");
                system("pause");
                goto inicio;}}
    }while(opcao != 6 );
    return (0);}

