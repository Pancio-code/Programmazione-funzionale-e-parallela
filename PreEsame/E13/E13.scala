object E13 {
	def equal(a:List[Int],b:List[Int]) : Boolean = {
		if(a.isEmpty && b.isEmpty) true
		else if(a.isEmpty || b.isEmpty) false
		else a.head == b.head && equal(a.tail,b.tail)
	}
}
