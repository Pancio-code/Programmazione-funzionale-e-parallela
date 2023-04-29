object E6 {
	def equalInRange(f1 : Int => Int, f2 : Int => Int, a : Int , b : Int) :Boolean = {
		for( i <- a to b) {
			if(f1(i) != f2(i)) return false
		}
		return true
	}
}
