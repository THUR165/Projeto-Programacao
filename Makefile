# Definições
CC = gcc
CFLAGS = -Wall -g

# Diretórios e arquivos de origem
SRC_CLIENTES_DIR = Projeto/src/clientes
SRC_FUNCIONARIOS_DIR = Projeto/src/funcionario
SRC_PRODUTOS_DIR = Projeto/src/produto
SRC_VENDAS_DIR = Projeto/src/vendas
SRC_RELATORIO_DIR = Projeto/src/relatorio

# Coleta todos os arquivos .c em cada pasta
SRC_CLIENTES = $(wildcard $(SRC_CLIENTES_DIR)/*.c)
SRC_FUNCIONARIOS = $(wildcard $(SRC_FUNCIONARIOS_DIR)/*.c)
SRC_PRODUTOS = $(wildcard $(SRC_PRODUTOS_DIR)/*.c)
SRC_VENDAS = $(wildcard $(SRC_VENDAS_DIR)/*.c)
SRC_RELATORIO = $(wildcard $(SRC_RELATORIO_DIR)/*.c)

# Arquivos do projeto principal
SRC_INTERFACE = Projeto/interface.c
SRC_VALIDA = Projeto/valida.c
MAIN = main.c

# Cabeçalhos
HEADER_INTERFACE = Projeto/interface.h
HEADER_VALIDA = Projeto/valida.h

# Arquivos objeto
OBJ_INTERFACE = Projeto/interface.o
OBJ_VALIDA = Projeto/valida.o
OBJ_MAIN = main.o

# Executável
TARGET = main

# Regra principal: compilar e linkar apenas main, interface e valida
all: $(TARGET)

# Linkar os objetos para criar o executável final
$(TARGET): $(OBJ_MAIN) $(OBJ_INTERFACE) $(OBJ_VALIDA)
	$(CC) -o $(TARGET) $(OBJ_MAIN) $(OBJ_INTERFACE) $(OBJ_VALIDA)

# Compilar os arquivos da pasta Projeto com dependências de cabeçalhos
$(OBJ_INTERFACE): $(SRC_INTERFACE) $(HEADER_INTERFACE)
	$(CC) $(CFLAGS) -c $(SRC_INTERFACE) -o $(OBJ_INTERFACE)

$(OBJ_VALIDA): $(SRC_VALIDA) $(HEADER_VALIDA)
	$(CC) $(CFLAGS) -c $(SRC_VALIDA) -o $(OBJ_VALIDA)

# Compilar o main.c (sem dependência de cabeçalho)
$(OBJ_MAIN): $(MAIN)
	$(CC) $(CFLAGS) -c $(MAIN) -o $(OBJ_MAIN)

# Compilar todos os arquivos nas pastas de CRUDs automaticamente (não será usado na regra 'all')
$(SRC_CLIENTES_DIR)/%.o: $(SRC_CLIENTES_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_FUNCIONARIOS_DIR)/%.o: $(SRC_FUNCIONARIOS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_PRODUTOS_DIR)/%.o: $(SRC_PRODUTOS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_VENDAS_DIR)/%.o: $(SRC_VENDAS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_RELATORIO_DIR)/%.o: $(SRC_RELATORIO_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar arquivos objeto e executável
clean:
	rm -f $(OBJ_INTERFACE) $(OBJ_VALIDA) $(OBJ_MAIN) $(TARGET)

# Executar o programa
run: all
	./$(TARGET)
