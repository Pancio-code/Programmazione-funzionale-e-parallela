// Scrivere una versione parallela `fibPar` del metodo `fib` definito nel file `Fib.scala` usando
// fork-join in Scala mediante il costrutto `par`.

// Scrivere la soluzione qui...
object E2 {
	def fibPar(a:Int, b:Int)(n:Int):Long = {
		if (n < 2) a
		else if (n == 2) b
		else {
			val (r: Long,r1: Long) = Par.par {
				Fib.fib(a,b)(n-1)
			}{
				Fib.fib(a,b)(n-2)
			}
			r + r1
		}
	}
}
