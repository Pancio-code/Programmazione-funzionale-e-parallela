import B2._

object B2Main extends App {
    var i = 1
    mioFor(i <= 10, i += 1) { print(i+" ") }
    println("[corretto: 1 2 3 4 5 6 7 8 9 10]")
}
