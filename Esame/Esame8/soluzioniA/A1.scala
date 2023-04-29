import scala.language.implicitConversions

case class MyRichSet(s:Set[Int]) {
    def +(o:Set[Int]) = s.union(o)
    def -(o:Set[Int]) = s.diff(o)
}

object MyRichSet {
    implicit def set2MyRichSet(s:Set[Int]) = MyRichSet(s)
}
