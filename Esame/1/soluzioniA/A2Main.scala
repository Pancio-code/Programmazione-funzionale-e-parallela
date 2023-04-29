import A2._

object A2Main extends App {
    val r1:(Int,Int) = 8 minMax 5
    println(r1+" [corretto=(5,8)]")
    val r2 = 1 minMax 2
    println(r2+" [corretto=(1,2)]")
}
