object E1 {
	def sommaFun(f1:Double=>Double, f2:Double=>Double):Double=>Double = {
		x => f1(x) + f2(x)
	}
}
