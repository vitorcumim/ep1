#!/bin/bash

#   Nome: Rafael Urbanek Laurentino
#   GRR: 20224381
#   Nome: Vitor Lorenzo Cumim
#   GRR: 20224757

# Verifica se o argumento 1 existe.
if [ $# -ne 1 ]; then
    echo "Uso: $0 <núcleo>"
    exit 1
fi
# Define o arguento 1 como o core desejado para usar o likwid.
core=$1

# Verifica se o arquivo perfSl existe no diretório atual.
if [ -e "perfSl" ]; then
    echo "O arquivo perfSl já existe."
else
    echo "O arquivo perfSl não existe. Executando o comando make..."
    # Executa o comando make.
    make
fi

# Executa o comando likwid-perfctr com os parâmetros fornecidos.
echo "Executando likwid-perfctr..."
output=$(likwid-perfctr -C "$core" -g FLOPS_DP -m ./perfSl)

# Filtra a saída do likwid recortando a saída original do perfSl.
filtered_output=$(echo "$output" | sed -n '/Region/q;p')
filtered_output=$(echo "$filtered_output" | tail -n +5)

# Filtra a saída do likwid usando grep para mostrar somente o DP_FLOPS.
grep_dp_output=$(echo "$output" | grep DP | grep -v AVX)

echo "$filtered_output"

echo "$grep_dp_output"