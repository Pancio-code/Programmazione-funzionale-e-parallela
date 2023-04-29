object E17Main extends App {
	def sqrt(x:Double) = {
	   def valoreAssoluto(x:Double) : Double = x match {
			case x if(x>=0) => x
			case _ => -x
		}
		def aux(x:Double,y:Double) : Double = {
			if(valoreAssoluto(x - y*y) < 0.0001) return y
			else aux(x, (y + x/y)/2)
		}
		aux(x,1)
	}
	println("Radice quadrata di 2 ~ "+sqrt(2))
}
