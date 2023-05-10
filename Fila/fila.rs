use std::io::{stdin, stdout, Write};

const SIZE: usize = 10;

struct Fila {
    dado: [i32; SIZE],
    frente: i32,
    fim: i32,
}

fn inicializa(fila: &mut Fila) {
    fila.frente = -1;
    fila.fim = -1;
}

fn vazio(fila: &Fila) -> bool {
    fila.frente = -1
}

fn cheio(fila: &Fila) -> bool {
    (fila.fim + 1) % SIZE as i32 == fila.frente
}

fn enfileira(fila: &mut Fila, valor: i32) {
    if cheio(fila) {
        println!("Fila cheia");
        return;
    }
    
    if vazio(fila) {
        fila.frente = 0;
        fila.fim = 0;
    } else {
        fila.fim = (fila.fim + 1) % SIZE as i32;
    }
    
    fila.dado[fila.fim as usize] = valor;
    
}

fn desenfileira(fila: &mut Fila) {
    if vazio(fila) {
        println!("\nFila vazia!");
        return;
    }
    
    if fila.frente == fila.fim {
        fila.frente = -1;
        fila.fim = -1;
    } else {
        fila.frente = (fila.frente + 1) % SIZE as i32;
    }
}

// Função para ver o elemento do início da fila
fn frente(fila: &Fila) {
    if vazio(fila) {
        println!("A fila está vazia!");
        return;
    }

    println!("Elemento do inicio da fila: {}", fila.dado[fila.frente as usize]);
}

// Função para ver o elemento do fim da fila
fn fim(fila: &Fila) {
    if vazio(fila) {
        println!("A fila está vazia!");
        return;
    }

    println!("Elemento do fim da fila: {}", fila.dado[fila.fim as usize]);
}

// Função para ver toda a fila
fn mostrar(fila: &Fila) {
    if vazio(fila) {
        println!("A fila está vazia!");
        return;
    }

    print!("Elementos da fila: ");
    let mut i = fila.frente;
    while i != fila.fim {
        print!("{} ", fila.dado[i as usize]);
        i = (i + 1) % SIZE as i32;
    }
    println!("{}", fila.dado[fila.fim as usize]);
}

fn main() {
    let mut fila = Fila {
        // INCOMPLETO
    }
}
