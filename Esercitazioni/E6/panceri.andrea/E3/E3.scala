// Scrivere un metodo `def subList(l:List[T]):Boolean` applicabile su un oggetto `List[T]` `s` che restituisce `true` 
// se e solo se tutti gli elementi di `l` appaiono anche in `s` nello stesso ordine, anche non consecutivamente.

import scala.language.implicitConversions

object E3 { 
    implicit def seq2MySeq[T](s:List[T]):MyList[T] = new MyList(s)
}

class MyList[T](s:List[T]) {
	import E3._
    def subList(l:List[T]):Boolean = {
	def aux(v : List[T],s1: List[T],i : Int,r:List[Int]) : List[Int] ={
		if(v.isEmpty || s1.isEmpty) r
		else if(v.head == s1.head) aux(v.tail,s1.tail,i+1,r :+ i)
		else aux(v,s1.tail,i+1,r)
	}
	val res = aux(l,s,0,Nil)
	res.size == l.size 
    }
}
