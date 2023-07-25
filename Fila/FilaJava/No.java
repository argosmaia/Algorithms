package fila;

public class No {
	private Object object;
	private No refNo;
	/**
	 * @param object
	 */
	public No(Object object) {
		this.object = object;
		this.refNo = refNo;
	}
	
	public No() {
		
	}

	/**
	 * @return the object
	 */
	public Object getObject() {
		return object;
	}

	/**
	 * @param object the object to set
	 */
	public void setObject(Object object) {
		this.object = object;
	}

	/**
	 * @return the refNo
	 */
	public No getRefNo() {
		return refNo;
	}

	/**
	 * @param refNo the refNo to set
	 */
	public void setRefNo(No refNo) {
		this.refNo = refNo;
	}
}
