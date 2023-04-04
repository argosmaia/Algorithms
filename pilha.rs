const MAX: usize = 15; // tamanho máximo da pilha

struct Pilha {
    top: i32,
    items: [i32; MAX],
}

impl Pilha {
    fn new() -> Pilha {
        Pilha {
            top: -1,
            items: [0; MAX],
        }
    }

    fn is_empty(&self) -> bool {
        self.top == -1
    }

    fn is_full(&self) -> bool {
        self.top as usize == MAX - 1
    }

    fn push(&mut self, x: i32) {
        if self.is_full() {
            println!("Erro: a pilha está cheia");
        } else {
            self.top += 1;
            self.items[self.top as usize] = x;
        }
    }

    fn pop(&mut self) -> Option<i32> {
        if self.is_empty() {
            println!("Erro: a pilha está vazia");
            None
        } else {
            let x = self.items[self.top as usize];
            self.top -= 1;
            Some(x)
        }
    }

    fn peek(&self) -> Option<i32> {
        if self.is_empty() {
            println!("Erro: a pilha está vazia");
            None
        } else {
            let x = self.items[self.top as usize];
            Some(x)
        }
    }

    fn display(&self) {
        if self.is_empty() {
            println!("A pilha está vazia");
        } else {
            println!("Itens na pilha:");
            for i in (0..=self.top).rev() {
                println!("{}", self.items[i as usize]);
            }
        }
    }
}

fn main() {
    let mut p = Pilha::new();

    loop {
        println!("Escolha uma opção:");
        println!("1 - Inserir elemento");
        println!("2 - Retirar elemento");
        println!("3 - Ver elemento no topo");
        println!("4 - Ver pilha toda");
        println!("0 - Sair");

        let mut opcao = String::new();
        std::io::stdin().read_line(&mut opcao).expect("Erro ao ler a opção");

        match opcao.trim().parse::<i32>() {
            Ok(0) => break,
            Ok(1) => {
                println!("Digite o elemento a ser inserido:");
                let mut elem = String::new();
                std::io::stdin().read_line(&mut elem).expect("Erro ao ler o elemento");
                let x = elem.trim().parse::<i32>().expect("Erro ao converter o elemento");
                p.push(x);
            }
            Ok(2) => {
                match p.pop() {
                    Some(x) => println!("Elemento retirado: {}", x),
                    None => (),
                }
            }
            Ok(3) => {
                match p.peek() {
                    Some(x) => println!("Elemento no topo: {}", x),
                    None => (),
                }
            }
            Ok(4) => p.display(),
            _ => println!("Opção inválida"),
        }
    }
}
