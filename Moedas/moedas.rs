const MAX_N: usize = 100;
const MAX_M: usize = 100;

fn moedas(n: i32, m: i32, v: &Vec<i32>) -> Vec<Vec<i32>> {
    let mut t = vec![vec![0; (n + 1) as usize]; (m + 1) as usize];

    for j in 0..=n {
        t[0][j as usize] = 0;
    }

    for i in 0..=m {
        t[i as usize][0] = 1;
    }

    for i in 1..=m {
        for j in 1..=n {
            if j >= v[i as usize] {
                t[i as usize][j as usize] = t[i as usize][j as usize - v[i as usize] as usize]
                    + t[(i - 1) as usize][j as usize];
            } else {
                t[i as usize][j as usize] = t[(i - 1) as usize][j as usize];
            }
        }
    }

    t
}

fn main() {
    let mut input = String::new();
    println!("Digite o valor a ser trocado: ");
    std::io::stdin().read_line(&mut input).unwrap();
    let n: i32 = input.trim().parse().unwrap();

    let mut input = String::new();
    println!("Digite o numero de moedas: ");
    std::io::stdin().read_line(&mut input).unwrap();
    let m: i32 = input.trim().parse().unwrap();

    let mut v = vec![0; (m + 1) as usize];
    println!("Digite os valores das moedas:");
    for i in 1..=m {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        v[i as usize] = input.trim().parse().unwrap();
    }

    let result = moedas(n, m, &v);

    println!("Tabela de troco:");
    for i in 0..=m {
        for j in 0..=n {
            print!("{} ", result[i as usize][j as usize]);
        }
        println!();
    }
}
