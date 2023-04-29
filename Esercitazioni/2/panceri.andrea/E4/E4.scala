object E4 {
	def checkBitonic(l:List[Int]):(List[Int],List[Int]) = {
		if(l.isEmpty) (Nil,Nil)
		else {
			val max = l.max
			val crescente = l.takeWhile(x => x != max) :+ max
			val decrescente = l.dropWhile(x => x != max).drop(1)
			if(crescente == crescente.sorted && decrescente != Nil && decrescente.reverse == decrescente.sorted) (crescente,decrescente)
			else (Nil,Nil)
		}
	}
}
