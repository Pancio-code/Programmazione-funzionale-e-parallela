sealed abstract class BinTree {
    def map(f:Int=>Int):BinTree = this match {
		case T(l,e,r) => T(l.map(f),f(e),r.map(f))
		case E() => E()
	}
}

// albero non vuoto
case class T(l:BinTree, e:Int, r:BinTree) extends BinTree 

// albero vuoto
case class E() extends BinTree


object E30Main extends App {
    val t1 = T(E(), 10, E())
    val t2 = T(E(), 5, E())
    val t3 = T(t1, 7, t2)
    val t4 = T(t3, 2, E())
    val t = t4.map(_*2)
    println(t + " (corretto: T(T(T(E(),20,E()),14,T(E(),10,E())),4,E()))")
}
