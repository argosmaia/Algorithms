package fila;

package fila;

public class No<T> {
    private T object;
    private No<T> refNo;

    public No(T object) {
        this.object = object;
        this.refNo = null;
    }

    public T getObject() {
        return object;
    }

    public void setObject(T object) {
        this.object = object;
    }

    public No<T> getRefNo() {
        return refNo;
    }

    public void setRefNo(No<T> refNo) {
        this.refNo = refNo;
    }

    @Override
    public String toString() {
        return "No [object=" + object + ", refNo=" + refNo + "]";
    }
}


/*public class No {
	private Object object;
	private No refNo;
	
	public No(Object object) {
		this.object = object;
		this.refNo = refNo;
	}
	
	public No() {
		
	}

	
	public Object getObject() {
		return object;
	}

	
	public void setObject(Object object) {
		this.object = object;
	}

	
	public No getRefNo() {
		return refNo;
	}

	
	public void setRefNo(No refNo) {
		this.refNo = refNo;
	}
}
*/
