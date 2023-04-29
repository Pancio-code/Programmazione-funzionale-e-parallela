object E7 {
	def findIndices[T](l : List[T], x : T) : List[Int] = {
		def aux_findIndices(i : Int) : List[Int] = {
			if(i < 0) Nil
			else if(l(i) == x) aux_findIndices(i-1) :+ i
			else aux_findIndices(i-1)	
		}
		aux_findIndices(l.size -1)
	}
}
