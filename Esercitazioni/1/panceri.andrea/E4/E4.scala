object E4 {
	def ugualiIn(f1: Int => Int, f2: Int => Int,n : Int) : Boolean = {
		if(n == 0) f1(0) == f2(0) else f1(n) == f2(n) && ugualiIn(f1,f2,n-1)
	}
}
