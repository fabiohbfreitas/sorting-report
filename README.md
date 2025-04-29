# Comparação de Algoritmos de Ordenação

## Instruções

### Gerando os Dados CSV

1. Certifique-se de que as seguintes dependências estejam instaladas:

   - Compilador `clang`
   - `clang-format` (para formatação de código)
   - `make`

2. Navegue até o diretório contendo o arquivo Makefile e `main.c`.

3. Para compilar e executar o programa C a fim de gerar o arquivo `sort.csv`:
   ```
   make
   ```

### Gerando a Imagem do Gráfico

1. Crie um ambiente virtual Python e ative-o.

   ```
   python -m venv env
   source env/bin/activate  # No Windows, use `env\Scripts\activate`
   ```

2. Instale as dependências Python necessárias usando o arquivo `requirements.txt`:

   ```
   pip3 install -r requirements.txt
   ```

3. Execute o script Python para gerar o gráfico de colunas e salvá-lo como um arquivo de imagem:

   ```
   python3 graph.py
   ```

4. Desative o ambiente virtual.
   ```
   deactivate
   ```

### Comandos Adicionais do Make

- Para formatar o código C usando `clang-format`:

  ```
  make format
  ```

- Para limpar os arquivos gerados:
  ```
  make clean
  ```
