use std::cmp;

const MAX: usize = 1005;

fn distancia_edicao(a: &str, b: &str, i: usize, j: usize, dp: &mut [[i32; MAX]; MAX]) -> i32 {

    if i == 0 { return j as i32; }

    if j == 0 { return i as i32; }

    if dp[i][j] != -1 { return dp[i][j]; }

    let cost = if a.as_bytes()[i - 1] == b.as_bytes()[j - 1] { 0 } else { 1 };

    let del = distancia_edicao(a, b, i - 1, j, dp) + 1;

    let ins = distancia_edicao(a, b, i, j + 1, dp) + 1;

    let sub = distancia_edicao(a, b, i - 1, j - 1, dp) + cost;

    dp[i][j] = cmp::min(del, cmp::min(ins, sub));

    dp[i][j]

}

fn main() {

    let mut dp = [[-1; MAX]; MAX];

    let mut a = String::new();

    let mut b = String::new();

    std::io::stdin().read_line(&mut a).unwrap();

    std::io::stdin().read_line(&mut b).unwrap();

    let a = a.trim();

    let b = b.trim();

    for i in 0..=a.len() {

        dp[i][0] = i as i32;

    }

    for j in 0..=b.len() {

        dp[0][j] = j as i32;

    }

    println!("{}", distancia_edicao(&a, &b, a.len(), b.len(), &mut dp));

    // Não é necessário desalocar a memória em Rust, pois o garbage collector cuida disso

}

