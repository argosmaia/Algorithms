package main;

import arvorebinaria.ArvoreBinaria;
import model.Obj;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		ArvoreBinaria<Obj> minhaArvore = new ArvoreBinaria<>();
		minhaArvore.inserir(new Obj(13));
		minhaArvore.inserir(new Obj(10));
		minhaArvore.inserir(new Obj(25));
		minhaArvore.inserir(new Obj(2));
		minhaArvore.inserir(new Obj(12));
		minhaArvore.inserir(new Obj(20));
		minhaArvore.inserir(new Obj(31));
		minhaArvore.inserir(new Obj(29));
		
		minhaArvore.InOrdem();
		minhaArvore.PosOrdem();
		minhaArvore.PreOrdem();
	}

}
