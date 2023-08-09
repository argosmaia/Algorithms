package cutrod;

import max.Max;

public class CorteDoBastao<T extends Comparable<T>> {
	public T max(T a, T b) {
        return a.compareTo(b) > 0 ? a : b;
    }
    public T cortarBastao(T[] preco, int n, T[] memo) {
        if (n == 0) {
            return memo[0];
        }
        if (memo[n] != null) {
            return memo[n];
        }

        T max_value = memo[0];

        for (int i = 0; i < n; i++) {
            Max<T> maxHelper = new Max<>(max_value, max(max_value, cortarBastao(preco, n - i - 1, memo)));
            max_value = maxHelper.max(max_value, maxHelper.max(preco[i], cortarBastao(preco, n - i - 1, memo)));
        }

        memo[n] = max_value;
        return max_value;
    }
}
