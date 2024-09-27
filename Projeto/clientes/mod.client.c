void tela_client(void){
    int resp;
    printf("\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══                SIG-Building                       ═════\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══    Sistema de gestão de material de construção    ═════\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══                [1] - Cadastrar Clientes           ═════\n");
    printf("═══                [2] - Fazer Compras                ═════\n");
    scanf("%i", &resp);
    printf("═══════════════════════════════════════════════════════════\n");
    if (resp == 1 ){
        printf(" Modulo Clientes \n"); //função fazer compras
    } else if (resp == 2){
        printf("Modulo Funcionário \n"); //function de cadastrar cliente
    } else{
        printf("Resposta inválida. \n");
    }
    
}