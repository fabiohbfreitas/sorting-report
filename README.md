# Comparação de Algoritmos de Ordenação

## Instruções

### Gerando os Dados CSV

1. Certifique-se de que as seguintes dependências estejam instaladas:

   - Compilador `clang`
   - `clang-format` (para formatação de código)
   - `make`

2. Navegue até o diretório contendo o arquivo Makefile e `main.c`.

3. Para compilar e executar o programa C a fim de gerar o arquivo `sorting_times.csv`:
   ```
   make
   ```

### Gerando a Imagem do Gráfico

1. Crie um ambiente virtual Python e ative-o.

2. Instale as dependências Python necessárias usando o arquivo `requirements.txt`:

   ```
   pip install -r requirements.txt
   ```

3. Execute o script Python para gerar o gráfico de colunas e salvá-lo como um arquivo de imagem:

   ```
   python graph.py
   ```

4. Desative o ambiente virtual.

### Comandos Adicionais do Make

- Para formatar o código C usando `clang-format`:

  ```
  make format
  ```

- Para limpar os arquivos gerados:
  ```
  make clean
  ```

### Sobre o Makefile

O Makefile fornecido contém as seguintes informações:

1. **Compilador**: O compilador utilizado é o `clang`.

2. **Flags do Compilador**: As flags de compilação definidas incluem opções para habilitar avisos e erros, bem como algumas exceções para evitar avisos desnecessários.

3. **Clang-format**: O `clang-format` é usado para formatar o código-fonte C de acordo com as regras especificadas.

4. **Targets**:
   - `all`: Compila o programa principal `main`.
   - `out`: Compila o programa `main` com a opção `SHOULD_PRINT_ARRAY=1` e redireciona a saída para o arquivo `out.txt`.
   - `format`: Formata todos os arquivos `*.c` e `*.h` usando o `clang-format`.
   - `clean`: Remove os arquivos gerados, como o executável `main`, arquivos de texto, CSV e PNG.
