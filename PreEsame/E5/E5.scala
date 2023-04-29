object E5 {
	def concatena(f1: Double => Double,f2: Double => Double,f3: Double => Double,a : Double,b : Double) : Double => Double = {
		def aux_concatena(n : Double) : Double = { 
			if( n < a) f1(n)
			else if(n >= a && n <= b) f2(n)
			else f3(n)
		}
		aux_concatena _
	}
}
