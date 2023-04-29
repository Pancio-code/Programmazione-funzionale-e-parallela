object E3 {
	def testPrimalita(x : Int) : Boolean = {
		for( a <- 2 to x/2) {
			if( x % a == 0) return false
		}
		return true
	}
}
