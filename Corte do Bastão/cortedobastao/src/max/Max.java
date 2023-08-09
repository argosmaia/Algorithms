package max;

public class Max<T extends Comparable<T>> {
	private T a;
	private T b;
	
	/**
	 * @param a
	 * @param b
	 */
	public Max(T a, T b) {
		this.a = a;
		this.b = b;
	}
	
	/**
	 * @return the a
	 */
	public T getA() {
		return a;
	}



	/**
	 * @param a the a to set
	 */
	public void setA(T a) {
		this.a = a;
	}



	/**
	 * @return the b
	 */
	public T getB() {
		return b;
	}



	/**
	 * @param b the b to set
	 */
	public void setB(T b) {
		this.b = b;
	}



	public T max(T a, T b) {
        return a.compareTo(b) > 0 ? a : b;
    }

	@Override
	public String toString() {
		return "Max [a=" + a + ", b=" + b + "]";
	}
		
}
