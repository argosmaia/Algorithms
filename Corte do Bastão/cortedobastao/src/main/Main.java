package main;

import java.util.Arrays;

import cutrod.CorteDoBastao;
import max.Max;

public class Main {
    public static void main(String[] args) {
        Integer[] preco = {1, 5, 8, 9, 10, 17, 17, 20};
        int n = preco.length;
        Integer[] memo = new Integer[n + 1];
        Arrays.fill(memo, null);

        Max<Integer> maxHelper = new Max<>(0, 0);
        CorteDoBastao<Integer> corteHelper = new CorteDoBastao<>();

        System.out.println("VALOR MÁXIMO " + corteHelper.cortarBastao(preco, n, memo));
    }
}
