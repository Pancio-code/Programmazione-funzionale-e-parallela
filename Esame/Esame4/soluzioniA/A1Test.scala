case class Owner(name:String, age:Int)
case class Car(model:String, year:Int, owner:Owner)

object A1Test extends App {
    
    val cars0 = List(Car("A", 2000, Owner("Elon", 50)),
                     Car("B", 2001, Owner("Annette", 25)),
                     Car("C", 2000, Owner("Susie", 18)),
                     Car("D", 2001, Owner("Lucy", 19)),
                     Car("E", 2000, Owner("Ron", 34))
                )

    val cars1 = List(Car("Tesla Model X", 2017, Owner("Elon", 50)),
                     Car("Open Zafira", 2008, Owner("Annette", 25)),
                     Car("Audi Quattro", 2008, Owner("Ron", 34)),
                     Car("Rover 220 SDI", 2017, Owner("Lucy", 19)))

    val cars2 = List(Car("Tesla Model X", 2017, Owner("Elon", 50)))

    val cars3 = List()

    ScalaTest.check {
        val res:List[(Int,String)] = A1.select(cars0).sorted
        val sol = List((2000,"Susie"),(2001,"Lucy")).sorted
        ScalaTest.test(res, sol, res == sol)
    }

    ScalaTest.check {
        val res:List[(Int,String)] = A1.select(cars1).sorted
        val sol = List((2017,"Lucy"),(2008,"Annette")).sorted
        ScalaTest.test(res, sol, res == sol)
    }

    ScalaTest.check {
        val res:List[(Int,String)] = A1.select(cars2)
        val sol = List((2017,"Elon"))
        ScalaTest.test(res, sol, res == sol)
    }

    ScalaTest.check {
        val res:List[(Int,String)] = A1.select(cars3)
        val sol = List()
        ScalaTest.test(res, sol, res == sol)
    }

    ScalaTest.report
}
