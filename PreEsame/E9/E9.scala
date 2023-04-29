object E9 {
	def consecutivi[T](l: List[T]) : List[(T,T)] = {
		if(l.size < 2) Nil
		else l.sliding(2,1).toList.map(x => (x(0),x(1)))
	}
}
