fn max(a: i32, b: i32) -> i32 {
    if a > b { a } else { b }
}

fn cortar_bastao(preco: &[i32], n: i32, memo: &mut [i32]) -> i32 {
    if n == 0 {
        return 0;
    }
    if memo[n as usize] != -1 {
        return memo[n as usize];
    }
    let mut max_value = -1;

    for i in 0..n {
        max_value = max(max_value, preco[i as usize] + cortar_bastao(preco, n - i - 1, memo));
    }

    memo[n as usize] = max_value;
    return max_value;
}

fn main() {
    let preco = [1, 5, 8, 9, 10, 17, 17, 20];
    let n = preco.len() as i32;
    let mut memo = vec![-1; (n + 1) as usize];
    println!("VALOR MÁXIMO {}", cortar_bastao(&preco, n, &mut memo));
}
