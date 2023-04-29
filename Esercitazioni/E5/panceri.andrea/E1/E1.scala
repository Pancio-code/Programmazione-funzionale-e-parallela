object E1 {
    	def annataPiuVecchia(produttori:List[Produttore],vitigni:List[Vitigno],vini:List[Vino],produttore:String):Option[Int] = {
		if(!produttori.exists( _.nome == produttore) || !produttori.exists( x => x.nome == produttore && vini.exists(y => y.idProd == x.idProd))) None
		else Some(vini.filter(v => produttori.exists(y => y.idProd == v.idProd && y.nome == produttore)).minBy(_.annata).annata)
	}
}
