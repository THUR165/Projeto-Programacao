# Definições
CC = gcc
CFLAGS = -Wall -g

# Diretórios e arquivos de origem
SRC_CLIENTES = Projeto/src/clientes/cadastrarc.c
SRC_FUNCIONARIOS = Projeto/src/funcionario/cadastrarf.c
SRC_PRODUTOS = Projeto/src/produto/cadastrarp.c
SRC_VENDAS = Projeto/src/vendas/cadastrarv.c
SRC_RELATORIO = Projeto/src/relatorio.c
SRC_SOBRE = Projeto/src/sobre.c

# Arquivos do projeto principal
SRC_INTERFACE = Projeto/interface.c
SRC_VALIDA = Projeto/valida.c
MAIN = main.c

# Arquivos objeto (apenas os principais a serem gerados)
OBJ_INTERFACE = Projeto/interface.o
OBJ_VALIDA = Projeto/valida.o
OBJ_MAIN = main.o

# Executável
TARGET = main

# Regra principal: compilar e linkar todos os objetos necessários
all: $(TARGET)

# Linkar os objetos para criar o executável final
$(TARGET): $(OBJ_MAIN) $(OBJ_INTERFACE) $(OBJ_VALIDA)
	$(CC) -o $(TARGET) $(OBJ_MAIN) $(OBJ_INTERFACE) $(OBJ_VALIDA)

# Compilar os arquivos da pasta Projeto
$(OBJ_INTERFACE): $(SRC_INTERFACE)
	$(CC) $(CFLAGS) -c $(SRC_INTERFACE) -o $(OBJ_INTERFACE)

$(OBJ_VALIDA): $(SRC_VALIDA)
	$(CC) $(CFLAGS) -c $(SRC_VALIDA) -o $(OBJ_VALIDA)

# Compilar o main.c
$(OBJ_MAIN): $(MAIN)
	$(CC) $(CFLAGS) -c $(MAIN) -o $(OBJ_MAIN)

# Compilar as partes dos CRUDs (sem gerar .o, apenas vinculados durante a execução)
compilar_cruds:
	$(CC) $(CFLAGS) -c $(SRC_CLIENTES) -o /dev/null
	$(CC) $(CFLAGS) -c $(SRC_FUNCIONARIOS) -o /dev/null
	$(CC) $(CFLAGS) -c $(SRC_PRODUTOS) -o /dev/null
	$(CC) $(CFLAGS) -c $(SRC_VENDAS) -o /dev/null
	$(CC) $(CFLAGS) -c $(SRC_RELATORIO) -o /dev/null
	$(CC) $(CFLAGS) -c $(SRC_SOBRE) -o /dev/null

# Limpar arquivos objeto e executável
clean:
	rm -f $(OBJ_INTERFACE) $(OBJ_VALIDA) $(OBJ_MAIN) $(TARGET)

# Executar o programa
run: all
	./$(TARGET)
