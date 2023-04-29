import scala.language.implicitConversions

object A2 {
    implicit def toMyString(x:Int) = MyInt(x)
}

case class MyInt(x:Int) {
    def minMax(y:Int) = if (x<=y) (x,y) else (y,x)
}
