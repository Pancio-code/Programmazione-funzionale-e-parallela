object E29 {
	sealed abstract class BinTree {
		def sum : Int = this match {
			case (t1,e,t2) => e + t1.sum + t2.sum
			case E() => 0
		}
	}

	// albero non vuoto
	case class T(l:BinTree, e:Int, r:BinTree) extends BinTree 

	// albero vuoto
	case class E() extends BinTree

}
