case class Car(model:String, year:Int, owner:String)

object A1Main extends App {
    val cars = List(Car("Tesla Model X", 2017, "Elon"),
                    Car("Open Zafira", 2008, "Anna"),
                    Car("Audi Quattro", 2013, "Ron"),
                    Car("Rover 220 SDI", 1999, "Anna"),
                    Car("Audidue", 2020, "Ron"),
                    Car("Rover 345", 2015, "Anna")
                    )
    val owners = List("Elon", "Anna","Ron")
    val res:List[String] = A1.select(cars, owners)
    println(res + " - corretto: List(Tesla Model X, Open Zafira)")
}
