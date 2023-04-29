class MyInt(x: Int) {
	def isPrime : Boolean = {
		!(2 to x/2).toList.exists(d => x % d == 0)
	}
}

object E3 {
	implicit def IntToMyInt(x :Int) = new MyInt(x)
}

