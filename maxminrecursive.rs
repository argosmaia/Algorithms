use std::io;

fn min_max_rec (arr:&[i32], start:usize, end:usize)->(i32, i32){
  if start == end{
        return (arr[start], arr[start]);
    }else if start + 1 == end{
        return (arr[start].min (arr[end]), arr[start].max (arr[end]));
    } else {
        let mid = (start + end) / 2;
        let (left_min, left_max) = min_max_rec(arr, start, mid);
        let (right_min, right_max) = min_max_rec(arr, mid + 1, end);
        return(left_min.min(right_min), left_max.max(right_max));
    }
}

fn main() {
    let mut arr: Vec<i32> = Vec::new();
    
    loop {
        println!("\nDigite um número na lista ou (sair) para encerrar: ");
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Erro ao ler entrada de usuário.");
        
        if input.trim() == "sair" {
            break;
        } else {
            match input.trim().parse() {
                Ok(num) => arr.push(num),
                Err(_) => println!("Entrada inválida!"),
            }
        }
    }
    
    if arr.is_empty() {
        println!("Lista vazia!");
    } else {
        let (min, max) = min_max_rec(&arr, 0, arr.len() - 1);
        println!("Mínimo: {}", min);
        println!("Máximo: {}", max);
    }
    
    loop {
        println!("\nDigite o indice na lista para remover ou (sair) para encerrar: ");
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Erro ao ler entrada de usuário.");
        
        if input.trim() == "sair" {
            break;
        } else {
            match input.trim().parse() {
                Ok(indice) => {
                    if indice >= arr.len() {
                        println!("Índice inválido! Tente novamente");
                    } else {
                        arr.remove(index);
                        println!("Número removido com sucesso!");
                    }
                }
                Err(_) => println("Entrada inválida!"),
            }
        }
    }
}
