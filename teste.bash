#!/bin/bash

# Verifica se o arquivo perfSl existe no diretório atual
if [ -e "perfSl" ]; then
    echo "O arquivo perfSl já existe."
else
    echo "O arquivo perfSl não existe. Executando o comando make..."
    # Executa o comando make
    make
fi

# Executa o comando liwid-perfctr com os parâmetros fornecidos
echo "Executando liwid-perfctr..."
output=$(likwid-perfctr -C 7 -g FLOPS_DP -m ./perfSl)

# Filtra a saída até a parte desejada usando grep
filtered_output=$(echo "$output" | sed -n '/Region/q;p')

grep_dp_output=$(echo "$output" | grep DP | grep -v AVX)

echo "$filtered_output"

echo "$grep_dp_output"