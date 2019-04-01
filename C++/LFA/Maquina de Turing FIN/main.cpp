#include"estado.h"
#include"transicao.h"
#include"arquivo.h"
#include"maquinaturing.h"
#include<string.h>

int main(int argc, char const* argv[]){

    char palavra[MAX] = {0};
    Arquivo *mtLeitor = NULL;
    maquinaTuring *maqTuring = NULL;
    char op = 0;
    bool saida = false;

    system("cls");

    if(argc > 1){

        // inicializa o arquivo e a maquina
        mtLeitor = new Arquivo(argv[1]);
        maqTuring = mtLeitor->inicializarMaquina();
        system("pause");

    }else{

        cerr << "Arquivo de entrada não encontrado" << endl;
        system("pause");
    }

    if(!maqTuring) return 1;

    while(saida != true){

        system("cls");
        cout << "\n\n";
        cout << "       << MAQUINA DE TURING COM FITA LIMITADA >>\n" << endl;
        cout << "              < 1 > Testar a Gramatica" << endl;
        cout << "              < 2 > Sair\n" << endl;

        cout << "              Digite a opcao >> " ;
        cin >> op;

        if(op == '1'){

            cout << "              Entre com a palavra >> ";
            fflush(stdin);
            scanf("%[^\n]%*c", palavra);

            cout << "\n";
            char str[MAX];

            strcpy(str, "*");
            strcat(str, palavra);
            strcat(str, "$" );

            string sequencia = string( str );
            maqTuring->testaSequencia( &sequencia );

        }else if(op == '2'){

            cout << "Saindo do Programa!" << endl;
            saida = true;

        }else
            cout << "Comando " << op << " inexistente" << endl;

        fflush(stdin);
        getchar();
    }

    delete mtLeitor;

}
