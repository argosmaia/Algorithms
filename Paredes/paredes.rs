use std::io;

const MAX_N: usize = 100;
const UNKNOWN: i32 = -1;

// Memoization table
static mut MEMO: [[i32; 3]; MAX_N] = [[UNKNOWN; 3]; MAX_N];

// Azulejos a wall with n columns, starting at row 'linha'
fn azulejar_parede(n: usize, linha: usize) -> i32 {
    // Base case
    if n == 0 { return 1; }

    // Check memoization table
    unsafe {
        if MEMO[n][linha] != UNKNOWN {
            return MEMO[n][linha];
        }
    }

    let mut cont = 0;

    // Recursive calls
    match linha {
        0 => {
            cont += azulejar_parede(n - 1, 1);
        },
        1 => {
            cont += azulejar_parede(n - 1, 0);
            cont += azulejar_parede(n - 1, 2);
        },
        _ => {
            cont += azulejar_parede(n - 1, 1);
        },
    }

    // Update memoization table
    unsafe {
        MEMO[n][linha] = cont;
    }

    cont
}

// Prints the current state of the wall
fn imprimir_estado_da_parede(n: usize) {
    println!("Estado da parede:");
    for i in 0..2 {
        for j in 0..n {
            let state = unsafe { MEMO[j+1][i] };
            match state {
                UNKNOWN => print!("?"),
                0 => print!("X"),
                _ => print!("O"),
            }
        }
        println!();
    }
}

// Inserts a tile at (linha, coluna) with orientation 'orientacao'
fn inserir_azuleijo(n: usize, linha: usize, coluna: usize, orientacao: char) {
    unsafe {
        if orientacao == 'h' {
            MEMO[coluna][linha] = 0;
            MEMO[coluna+1][linha] = 0;
        } else {
            MEMO[coluna][linha] = 0;
            MEMO[coluna][linha+1] = 0;
        }
    }
}

fn main() {
    let mut input = String::new();

    // Read input
    println!("Insira o número de colunas da parede: ");
    io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();

    // Initialize memoization table
    unsafe {
        for i in 0..=n {
            for j in 0..3 {
                MEMO[i][j] = UNKNOWN;
            }
        }
    }

    let mut opcao: i32;

    loop {
        // Menu
        println!("\nEscolha uma opção:");
        println!("1 - Ver estado da parede");
        println!("2 - Inserir azuleijo");
        println!("3 - Ver número de maneiras distintas");
        println!("0 - Sair");

        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        opcao = input.trim().parse().unwrap();

        match opcao {
            1 => imprimir_estado_da_parede(n),
            2 => {
                println!("Insira a linha e a coluna onde deseja inserir o azuleijo e a orientação (h para horizontal, v para vertical) (exemplo: 1 3 h): ");
                input.clear();
                io::stdin().read_line(&mut input).expect("Erro ao ler a entrada");
                let parts: Vec<&str> = input.trim().split(' ').collect();
                let linha: usize = parts[0].parse().expect("Erro ao ler a linha");
                let coluna: usize = parts[1].parse().expect("Erro ao ler a coluna");
                let orientacao: char = parts[2].chars().next().expect("Erro ao ler a orientação");
    
                if orientacao == 'h' {
                    inserir_azuleijo(n, linha-1, coluna-1, 'h');
                } else if orientacao == 'v' {
                    inserir_azuleijo(n, linha-1, coluna-1, 'v');
                } else {
                    println!("Orientação inválida");
                }
            }
            3 => break,
            _ => println!("Opção inválida!");
       }
  }
},

// INCOMPLETO
