object E2 {
	def applicaDueVolte(f: Int => Int)(x:Int) = f(f(x))
}
