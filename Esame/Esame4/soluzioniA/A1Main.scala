case class Owner(name:String, age:Int)
case class Car(model:String, year:Int, owner:Owner)

object A1Main extends App {
    val cars = List(Car("Tesla Model X", 2017, Owner("Elon", 50)),
                    Car("Open Zafira", 2008, Owner("Anna", 25)),
                    Car("Audi Quattro", 2008, Owner("Ron", 34)),
                    Car("Rover 220 SDI", 2017, Owner("Lucy", 19)))
    val res:List[(Int,String)] = A1.select(cars)
    println(res + " - corretto: List((2017,Lucy),(2008,Anna))")
}
