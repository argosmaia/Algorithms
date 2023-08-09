package arvorebinaria;

import no.No;

public class ArvoreBinaria<T extends Comparable<T>> {
	
	private No<T> raiz;
	
	public ArvoreBinaria() {
		this.raiz = null;
	}
	
	public void inserir(T conteudo) {
		No<T> novoNo = new No<>(conteudo);
		raiz = inserir(raiz, novoNo);
	}
	
	private No<T> inserir(No<T> atual, No<T> novoNo) {
		if(atual == null) {
			return novoNo;
		} else if(novoNo.getConteudo().compareTo(atual.getConteudo()) < 0) {
			atual.setNoEsq(inserir(atual.getNoEsq(), novoNo));
		} else {
			atual.setNoDir(inserir(atual.getNoDir(), novoNo));
		}
		
		return atual;
	}
	
	public void InOrdem() {
		System.out.print("\nExibindo In Ordem: ");
		InOrdem(this.raiz);
	}
	
	private void InOrdem(No<T> atual) {
		if(atual != null) {
			InOrdem(atual.getNoEsq());
			System.out.print(atual.getConteudo() + ", ");
			InOrdem(atual.getNoDir());
		}
	}
	
	public void PosOrdem() {
		System.out.print("\nExibindo Pos Ordem: ");
		PosOrdem(this.raiz);
	}
	
	private void PosOrdem(No<T> atual) {
		if(atual != null) {
			PosOrdem(atual.getNoEsq());
			PosOrdem(atual.getNoDir());
			System.out.print(atual.getConteudo() + ", ");
		}
	}
	
	public void PreOrdem() {
		System.out.print("\nExibindo Pos Ordem: ");
		PreOrdem(this.raiz);
	}
	
	private void PreOrdem(No<T> atual) {
		if(atual != null) {
			System.out.print(atual.getConteudo() + ", ");
			PreOrdem(atual.getNoEsq());
			PreOrdem(atual.getNoDir());
		}
	}
	
	public void remover(T conteudo) {
		try {
			No<T> atual = this.raiz;
			No<T> pai = this.raiz;
			No<T> filho = this.raiz;
			No<T> temp = this.raiz;
			
			while(atual != null && !atual.getConteudo().equals(conteudo)) {
				pai = atual;
				if (conteudo.compareTo(atual.getConteudo()) < 0) {
					atual = atual.getNoEsq();
				} else {
					atual = atual.getNoDir();
				}
			}
			
			if(atual == null) {
				System.out.println("Conteúdo não encontrado. Bloco try (de remover)");
			}
			
			if(pai == null) {
				if(atual.getNoDir() == null) {
					this.raiz = atual.getNoEsq();
				} else if(atual.getNoEsq() == null) {
					this.raiz = atual.getNoDir();
				} else {
					for(temp = atual, filho = atual.getNoEsq(); 
						filho.getNoDir() != null; 
						temp = filho, filho = filho.getNoEsq()) {
						if(filho != atual.getNoEsq()) {
							temp.setNoDir(filho.getNoEsq());
							filho.setNoEsq(raiz.getNoEsq());
						}
					}
					filho.setNoDir(raiz.getNoDir().getNoDir());
					raiz = filho;
				}
			} else if(atual.getNoDir() == null) {
				if(pai.getNoEsq() == atual) {
					pai.setNoEsq(atual.getNoEsq());
				} else {
					pai.setNoDir(atual.getNoEsq());
				}
			} else if(atual.getNoEsq() == null) {
				if(pai.getNoEsq() == atual) {
					pai.setNoEsq(atual.getNoDir());
				} else {
					pai.setNoDir(atual.getNoDir());
				}
			} else {
				for(temp = atual, filho = atual.getNoEsq();
					filho.getNoDir() != null; 
					temp = filho, filho = filho.getNoDir()) {
					if (filho != atual.getNoEsq()) {
						temp.setNoDir(filho.getNoEsq());
						filho.setNoEsq(atual.getNoEsq());
					}
					filho.setNoDir(atual.getNoDir());
					if (pai.getNoEsq() == atual) {
						pai.setNoEsq(filho);
					} else {
						pai.setNoDir(filho);
					}
				}
			}
		} catch (NullPointerException erro) {
			System.out.println("Conteúdo não encontrado. Bloco catch (de remover)");
		}
	}
}
