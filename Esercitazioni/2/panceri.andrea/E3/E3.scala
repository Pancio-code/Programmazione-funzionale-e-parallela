object E3 {
	def maxPrefisso(l:List[Int], x:Int):Int = {
		if(l == Nil) 0
		else if(l.head <= x) 1 + maxPrefisso(l.tail,x - l.head)
		else 0
	}
	/*altrimenti con ricorsione di coda
	def maxPrefisso_aux(l1:List[Int], somma:Int, i:Int):Int = 
		if (l1.isEmpty || somma + l1.head > x) i
		else aux(l1.tail, somma + l1.head, i+1)
    maxPrefisso_aux(l, 0, 0)*/
}
