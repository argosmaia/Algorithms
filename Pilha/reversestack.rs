use std::ptr;

// Estrutura encadeada
struct No {
    dado: i32,
    prox: Option<Box<No>>,
}

// Estrutura da pilha encadeada
struct Pilha {
    topo: Option<Box<No>>,
}

// Estrutura da fila encadeada
struct Fila {
    frente: Option<Box<No>>,
    fim: Option<Box<No>>,
}

// Funções da Pilha
fn inicializar(pilha: &mut Pilha) {
    pilha.topo = None;
}

fn cheia() -> bool {
    false
}

fn vazia(pilha: &Pilha) -> bool {
    pilha.topo.is_none()
}

fn insere(pilha: &mut Pilha, dado: i32) {
    if cheia() {
        println!("\nPilha cheia!");
        return;
    }

    let mut no = Box::new(No {
        dado: dado,
        prox: pilha.topo.take(),
    });

    pilha.topo = Some(no);
}

fn remover(pilha: &mut Pilha) -> i32 {
    if vazia(pilha) {
        println!("\nPilha está vazia!");
        return -1;
    }

    let temp = pilha.topo.take().unwrap();
    let dado = temp.dado;
    pilha.topo = temp.prox;
    dado
}

fn topo(pilha: &Pilha) -> i32 {
    if vazia(pilha) {
        println!("\nPilha vazia!");
        return -1;
    }

    pilha.topo.as_ref().unwrap().dado
}

// Funções da Fila
fn inicializafila(fila: &mut Fila) {
    fila.frente = None;
    fila.fim = None;
}

fn filavazia(fila: &Fila) -> bool {
    fila.frente.is_none()
}

fn enfileirar(fila: &mut Fila, dado: i32) {
    let no = Box::new(No {
        dado: dado,
        prox: None,
    });

    if fila.fim.is_none() {
        fila.frente = Some(no.clone());
        fila.fim = Some(no);
    } else {
        fila.fim.as_mut().unwrap().prox = Some(no);
        fila.fim = Some(no);
    }
}

fn desenfileirar(fila: &mut Fila) -> i32 {
    if filavazia(fila) {
        println!("\nFila vazia!");
        return -1;
    }

    let saida = fila.frente.take().unwrap();
    let dado = saida.dado;
    fila.frente = saida.prox;
    if fila.frente.is_none() {
        fila.fim = None;
    }
    dado
}

// Função para inverter a pilha por meio da fila
fn inverter(pilha: &mut Pilha) {
    if vazia(pilha) {
        println!("\nPilha vazia");
        return;
    }

    let mut temp: Option<Box<No>> = None;
    let mut fila = Fila {
        frente: None,
        fim: None,
    };
    let mut atual = pilha.topo.take();

    // Passo 1: Enfileira todos os dados da pilha na fila
    while let Some(mut node) = atual.take() {
        enfileirar(&mut fila, node.dado);
        atual = node.prox.take();
    }
    
    // Passo 2: Desenfileira todos os dados da fila e empilha na pilha temporária
    while let Some(dado) = desenfileirar(&mut fila) {
        insere(&mut temp, dado);
    }

    // Passo 3: Desempilha todos os dados da pilha temporária e empilha na pilha original
    while let Some(dado) = remover(&mut temp) {
        insere(pilha, dado);
    }
}
    // Função principal
fn main() {
    let mut pilha = Pilha {topo: None,};
    // Inicializa a pilha com alguns valores
    insere(&mut pilha, 1);
    insere(&mut pilha, 2);
    insere(&mut pilha, 3);
    insere(&mut pilha, 4);

    println!("Pilha original:");
    while !vazia(&pilha) {
       println!("{}", remover(&mut pilha));
}

    inverter(&mut pilha);

    println!("Pilha invertida:");
    while !vazia(&pilha) {
       println!("{}", remover(&mut pilha));
    }
}
