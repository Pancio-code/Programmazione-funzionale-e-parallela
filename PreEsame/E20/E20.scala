object E20 extends App {
	def longestSublist[T](p:T=>Boolean)(l:List[T]) : List[T] = {
		val vuota = List[T]()
        val (curr,max) = l.foldLeft((vuota,vuota))(
            (acc,x) => {
                val (curr,max) = acc
                if (p(x)) (x::curr, max)
                else (vuota, if (curr.size > max.size) curr else max)
            }
        )
        (if (curr.size > max.size) curr else max).reverse
	}
	println(longestSublist((_:Int)>0)(List(-4,5,3,6,0,3,4,-1)))
}
