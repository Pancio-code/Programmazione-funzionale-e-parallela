object E15 {
	def minMax(l: List[Int]) : (Int,Int) = {
		//(l.min,l.max)
		def aux(l: List[Int],c : (Int,Int)) : (Int,Int) = {
			if(l.isEmpty) c
			else if(l.head < c._1) aux(l.tail,(l.head,c._2))
			else if(l.head > c._2) aux(l.tail,(c._1,l.head))
			else aux(l.tail,c)
		}
		aux(l.tail,(l.head,l.head))
	}
}
