#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 50

// A Fábrica de Queijo Rio Novense deseja elaborar um algoritmo para controlar o estoque e as vendas. Inicialmente, deverão ser lidos e armazenados em vetores: o código, a quantidade disponível em estoque e o preço de venda dos produtos. O término do cadastramento é determinado quando se digita - 1 para o código do produto. Sabe-se que a Fábrica de Queijo Rio Novense trabalha com no máximo 50 produtos diferentes.

struct codigoCompleto{
    //Int para usar nos whiles
    int menu;
    //Primeira função cadastro de produtos
    int codigo[max];
    int quantidade[max];
    float precoVenda[max];
    //Segunda função venda de produtos
    int escolhaCodigo;
    int escolhaQuantidade;
    float valorVenda[max];
    //Terceira função, contagem e organização de vendas
    float vendasTotais;
};

    //Declarando struct para uso em todas as funções e no main
    struct codigoCompleto cc;

//Função para primeira parte do sistema, cadastro de produtos
//Pedindo valores como Código, quantidade e valor do produto
void cadastrarProduto(){

    do{
        for(int i = 0; i < max; i++){
            system("cls");//limpar tela
            if(cc.codigo[i]==0){//Sistema para não substituir dados nos vetores já preenchidos
                printf("Digite -1 para sair ou cadastre um produto ⤵️");//Sistema para pedir informações
                printf("\n\nProduto #%d\n", i+1);
                printf("Digite o código do produto: ");
                scanf("%d", &cc.codigo[i]);//Sistema para caso digitado -1, finalizar função e sair do laço de repetição
                if(cc.codigo[i] == -1){
                    cc.codigo[i] = 0; //Cado digitado -1, sistema para não armazenar esse valor em um vetor
                    break;
                }
                printf("Digite a quantidade do produto: ");
                scanf("%d", &cc.quantidade[i]);
                printf("Digite o preço de venda do produto: ");
                scanf("%f", &cc.precoVenda[i]);
            }else if(cc.codigo[max] != 0){
                printf("\nSem espaços para novos produtos!");//Sistema para informar lotação de produtos
            }
        }

        printf("\nSistema de cadastro finalizado!");//Sistema para sair da função e voltar para menu
        printf("\nDigite 1 para voltar ao menu: ");
        scanf("%d", &cc.menu);
        if(cc.menu!=1){
            do{
                printf("Digite 1 para voltar ao menu: ");
                scanf("%d", &cc.menu);
            }while(cc.menu!=1);
        }
    }while(cc.menu != 1);
}

// A segunda fase do algoritmo é a venda. Deverá ser lido o código do produto a ser vendido e a quantidade requerida. Se o código do produto estiver cadastrado, a venda poderá ser realizada; caso contrário, a mensagem Produto Não-Cadastrado deverá ser exibida no monitor. Caso o produto esteja disponível, a venda só poderá ser realizada se a quantidade disponível no estoque for suficiente para atender ao pedido. Nesse caso, você deverá abater do estoque a quantidade vendida. Se o estoque não for suficiente para atender ao pedido, a mensagem Estoque Insuficiente deverá ser exibida no monitor. O final das vendas será detectado  quando o código do produto for igual a zero.

//Função para segunda parte do sistema, venda de produtos
void vendaProduto(){

    int c = 0;//Iniciando variavel que sera responsavel por validar as vendas
    cc.vendasTotais = 0;//Inicializando a variavel que vai ser responsavel por acumular as vendas

    do{
        
        system("cls");//limpar tela
        printf("Venda de produtos\n\n");

        printf("Digite o codigo do produto que deseja ou 0 para sair: ");
        scanf("%d", &cc.escolhaCodigo);

        if(cc.escolhaCodigo == 0){
            break;//Sistema para finalizar caso digitado 0
        }

        for(int i = 0; i < max; i++){
            if(cc.escolhaCodigo==cc.codigo[i]){//Sistema infinito até achar codigo cadastrado
                printf("\nProduto numero %d\n", i+1);

                do{//Sistema para só finalizar venda apos todas as condições verdadeiras
                    printf("Digite a quantidade que deseja do produto: ");
                    scanf("%d", &cc.escolhaQuantidade);

                    cc.valorVenda[i] = cc.precoVenda[i] * cc.escolhaQuantidade;//Finaliza o valor total da venda
                    cc.vendasTotais += cc.valorVenda[i];//Soma todas as vendas para ter um lucro final
                    if(cc.escolhaQuantidade <= cc.quantidade[i] && c == 0){//Condição para quantidade permitida
                        printf("\nCodigo do produto: %d", cc.codigo[i]);
                        printf("\nQuantidade atual do estoque: %d", cc.quantidade[i]);  
                        printf("\nQuantidade escolhida: %d", cc.escolhaQuantidade);  
                        printf("\nValor de venda: %.2f", cc.valorVenda[i]);
                        cc.quantidade[i] -= cc.escolhaQuantidade;
                        printf("\nQuantidade restante do estoque: %d", cc.quantidade[i]);  
                        sleep(2);
                        printf("\n\nVenda concluida com sucesso!!\n\n");
                        c++;//Sistema para cadastrar funcionalidade da função. A venda, caso não feita permanece em 0
                    }else{//Sistema para informar estoque insuficiente, caso if seja falso
                        printf("\nEstoque insuficiente!!");
                        printf("\nQuantidade atual do estoque: %d\n\n", cc.quantidade[i]); 
                    }
                }while(cc.escolhaQuantidade > cc.quantidade[i] && c == 0);
            }
        }

        if(c==0){//Se venda não feita = produto não encontrado
                printf("\nProduto não cadastrado!\n\n");
            }

        //Sistema para sair da função e voltar para menu
        printf("\nDigite 1 para voltar ao menu ou qualquer numero para repetir: ");
        scanf("%d", &cc.menu);
        c=0;
    }while(cc.menu!=1);

}

// No final deverá aparecer uma listagem no vídeo contendo o total vendido no dia  e a relação de todos os produtos do estoque, com suas respectivas quantidades, em ordem decrescente de quantidades disponíveis.

void listagemProdutos(){

    int aux, aux2;//Variaveis responsaveis por armazenar valor a ser trocado na organização

    do{

        system("cls");//limpar tela
        printf("Listagem do dia");

        do{//Sistema feito para organização decrescente dos valores
            for(int i =0; i < max; i++){
                    if(cc.codigo[i]!= 0 && cc.quantidade[i] < cc.quantidade[i+1]){//Se valor for menor que o proximo, tem a troca dos valores
                    aux = cc.quantidade[i];
                    aux2 = cc.codigo[i];
                    cc.quantidade[i] = cc.quantidade[i+1];
                    cc.quantidade[i+1] = aux;
                    cc.codigo[i] = cc.codigo[i+1];
                    cc.codigo[i+1] = aux2;
                    }
            }
        }while(cc.quantidade[0] < cc.quantidade[1]);//Sistema funciona até primeira variavel ser maior que a segunda = todos os vetores foram percorridos e trocados

        printf("\nEstoque organizado\n");
        for (int i = 0; i < max; i++){//Sistema para imprimir lista em ordem
            if(cc.codigo[i] != 0){
                printf("\nProduto %d. Estoque %d", cc.codigo[i], cc.quantidade[i]);
            }
        }
        
        printf("\n\nVendas totais: %.2f\n", cc.vendasTotais);

        //Sistema para sair da função e voltar para menu
        printf("\nDigite 1 para voltar ao menu: ");
        scanf("%d", &cc.menu);
        if(cc.menu!=1){
            do{
                printf("Digite 1 para voltar ao menu: ");
                scanf("%d", &cc.menu);
            }while(cc.menu!=1);
        }
    }while(cc.menu!=1);

}

// Sistema para exportar em arquivo de texto os resultados das vendas do dia 
void exportacao(){

    struct tm *data_hora_atual;     //Importação da biblioteca time.h que é usada para pegar a data e hora atual 
    time_t segundos;
    time(&segundos);   
    data_hora_atual = localtime(&segundos);

    FILE *arquivo = fopen("Recibos.txt", "a"); //Iniciação do ponteiro que faz a criação do arquivo de texto 

    int aux, aux2;
    do{

        //Todos comandos fprintf(arquivo, "...") não aparecem no terminal porem são escritos no arquivo de texto

        system("cls");
        fprintf(arquivo, "Listagem do dia %d/%d/%d  %d:%d:%d", data_hora_atual->tm_mday, data_hora_atual->tm_mon+1, data_hora_atual->tm_year+1900,
        data_hora_atual->tm_hour, data_hora_atual->tm_min, data_hora_atual->tm_sec);

        do{
            for(int i =0; i < max; i++){
                    if(cc.codigo[i]!= 0 && cc.quantidade[i] < cc.quantidade[i+1]){
                    aux = cc.quantidade[i];
                    aux2 = cc.codigo[i];
                    cc.quantidade[i] = cc.quantidade[i+1];
                    cc.quantidade[i+1] = aux;
                    cc.codigo[i] = cc.codigo[i+1];
                    cc.codigo[i+1] = aux2;
                    }
            }
        }while(cc.quantidade[0] < cc.quantidade[1]);

        fprintf(arquivo, "\nEstoque organizado\n");
        for (int i = 0; i < max; i++){
            if(cc.codigo[i] != 0){
                fprintf(arquivo ,"\nProduto %d. Estoque %d", cc.codigo[i], cc.quantidade[i]);
            }
        }
        
        fprintf(arquivo, "\n\nVendas totais: %.2f\n\n", cc.vendasTotais);

        printf("Exportação concluida com sucesso!!\n");

       
        printf("\nDigite 1 para voltar ao menu: ");
        scanf("%d", &cc.menu);
        if(cc.menu!=1){
            do{
                printf("Digite 1 para voltar ao menu: ");
                scanf("%d", &cc.menu);
            }while(cc.menu!=1);
        }
    }while(cc.menu!=1);


}

//Função principal do codigo, menu que ira selecionar as funções
int main(){

    do{
        system("cls");
        printf("1 - Cadastro de produtos\n");
        printf("2 - Venda de produtos\n");
        printf("3 - Listagem total dia\n");
        printf("4 - Exporta recibo diario\n");
        printf("5 - Fechar sistema\n:");
        scanf("%d", &cc.menu);

        switch(cc.menu){
            case 1:
                cadastrarProduto();
                break;
            case 2:
                vendaProduto();
                break;
            case 3:
                listagemProdutos();
                break;
            case 4:
                exportacao();
                break;
            case 5:
                printf("\n\nFechando sistema!!");
                exit(0);
                break;
            default:
                printf("\n\nDigite um numero valido!");
                sleep(2);
                break;
        }

    }while(cc.menu!=4);

    return 0;
}