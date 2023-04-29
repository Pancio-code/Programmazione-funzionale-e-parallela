object E4 {
	def checkBitonic(l:List[Int]) :(List[Int],List[Int]) = {
		if( l == Nil) (Nil,Nil)
		else {
			val (inc,dec) = l.splitAt(l.indexOf(l.max) + 1)
			if(inc == inc.sorted && dec.sorted.reverse == dec) (inc,dec)
			else (Nil,Nil)
		}
	}
}
