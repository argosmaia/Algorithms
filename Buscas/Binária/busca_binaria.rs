use std::io::{self, Write};
use rand::Rng;

// Função para realizar a busca binária em uma lista ordenada
fn binary_search(arr: &[i32], n: usize, x: i32) -> i32 {
    let mut left = 0;
    let mut right = n - 1;

    while left <= right {
        let mid = left + (right - left) / 2;

        if arr[mid] == x {
            return mid as i32; // Elemento encontrado, retorna o índice
        } else if arr[mid] < x {
            left = mid + 1; // Elemento está na metade direita
        } else {
            right = mid - 1; // Elemento está na metade esquerda
        }
    }

    -1 // Elemento não encontrado
}

fn main() {
    // Seed para geração de números aleatórios
    let mut rng = rand::thread_rng();

    // Tamanho da lista de dados
    let n = 10;

    // Geração aleatória dos dados
    let mut arr = Vec::new();
    for _ in 0..n {
        arr.push(rng.gen_range(0..100)); // Números aleatórios de 0 a 99
    }

    // Ordenação da lista de dados
    arr.sort();

    // Imprime a lista de dados
    print!("Lista de Dados: ");
    for i in &arr {
        print!("{} ", i);
    }
    println!();

    // Loop para permitir ao usuário fazer buscas ou sair
    let mut choice: i32;
    let mut search_value: i32;
    loop {
        print!("Digite o valor a ser buscado (ou -1 para sair): ");
        io::stdout().flush().unwrap();
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();

        choice = input.trim().parse().unwrap();

        if choice == -1 {
            println!("Saindo...");
            break;
        }

        // Realiza a busca binária e imprime o resultado
        let result = binary_search(&arr, n, choice);
        if result == -1 {
            println!("Valor nao encontrado na lista.");
        } else {
            println!("Valor encontrado na posicao {} da lista.", result);
        }
    }
}
