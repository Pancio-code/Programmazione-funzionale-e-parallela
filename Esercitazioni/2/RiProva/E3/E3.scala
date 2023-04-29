object E3 {
	def maxPrefisso(l:List[Int], x:Int):Int = {
		if(l.isEmpty) 0
		else if(l.head > x) 0
		else 1 + maxPrefisso(l.tail, x - l.head)
	}
}
