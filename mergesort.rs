use rand::Rng;

fn main() {
    // Gerando os 500 dados aleatórios de entrada
    let mut arr = [0; 500];
    let mut rng = rand::thread_rng();
    for i in 0..500 {
        arr[i] = rng.gen_range(0..=1000);
    }
    
    // Ordenando o vetor usando o Merge Sort
    merge_sort(&mut arr, 0, 499);
    
    // Exibindo o vetor ordenado
    println!("Vetor ordenado: {:?}", arr);
}

fn merge_sort(arr: &mut [i32], start: usize, end: usize) {
    if start >= end {
        return;
    }
    
    let mid = (start + end) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    
    if arr[mid] > arr[mid + 1] {
        merge(arr, start, mid, end);
    }
}

fn merge(arr: &mut [i32], start: usize, mid: usize, end: usize) {
    let mut i = start;
    let mut j = mid + 1;
    let mut k = 0;
    let mut temp = vec![0; end - start + 1];
    
    while i <= mid && j <= end {
        if arr[i] <= arr[j] {
            temp[k] = arr[i];
            i += 1;
        } else {
            temp[k] = arr[j];
            j += 1;
        }
        k += 1;
    }
    
    while i <= mid {
        temp[k] = arr[i];
        i += 1;
        k += 1;
    }
    
    while j <= end {
        temp[k] = arr[j];
        j += 1;
        k += 1;
    }
    
    for i in 0..(end - start + 1) {
        arr[start + i] = temp[i];
    }
}
