import scala.language.implicitConversions

class MyList[T](l:List[T]) {
    def getDup = l.groupBy(identity).filter(p => p._2.size > 1).map(_._1).toSet
}

object E1 {
    implicit def listToMyList[T](l:List[T]) = new MyList(l)
}
