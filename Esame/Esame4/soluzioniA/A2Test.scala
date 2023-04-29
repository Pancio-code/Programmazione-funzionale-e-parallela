import A2._

object A2Test extends App {

    ScalaTest.check {

        var i = 0
        var s = ""

        mywhile(i<6, "i="+i) {
            i+=1
            s+=i+" "
        }
        
        ScalaTest.test(s, "1 2 3 4 5 6 ", s == "1 2 3 4 5 6 ")
    }

    ScalaTest.report
}
