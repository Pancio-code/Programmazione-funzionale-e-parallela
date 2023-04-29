// trasformare il seguente medodo in modo che usi la ricorsione di coda

object E1 {
    def sum(n:Int):Int = {        
		@scala.annotation.tailrec
		def sumIter(n:Int, f:Int):Int =
			if (n<1) f else sumIter(n-1,f+n)
			sumIter(n,0)
		}
}

