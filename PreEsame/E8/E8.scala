object E8 {
	/*def isSorted(l: List[Int]) : Boolean = {
		l.sliding(2,1).toList.exists(x => x(0) < x(1))
	}*/
	def isSorted(l: List[Int]) : Boolean = {
		def aux(r:List[Int],prec :Int) : Boolean = {
			if(r.isEmpty) true
			else r.head <= prec && aux(r.tail,r.head)
		}
		if(!l.isEmpty) !aux(l.tail,l.head)
		else true
	}
}
