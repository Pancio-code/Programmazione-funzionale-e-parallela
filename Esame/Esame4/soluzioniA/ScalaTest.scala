object ScalaTest {

    val TIMEOUT = 10000
    var cnt = 0
    var ok  = 0

    private def inc(t:Boolean) {
        cnt = cnt + 1
        ok = ok + (if (t) 1 else 0)
    }
    
    def check(body: =>Unit):Unit = {
        val r = new Runnable {
            def run() {
                try {
                    Thread.sleep(TIMEOUT)
                    println("Report: *** Timeout error - possibly infinite loop")
                    System.exit(1)
                }
                catch {
                    case e:Throwable => {
                    }
                }
            }
        }
        val t = new Thread(r)
        t.start
        try {
            body
        }
        catch {
            case e:Throwable => {
                inc(false)
                println("[exception: "+e+"]")
            }
        }
        t.interrupt
        t.join
    }

    def test(c:Any, o:Any):Unit = test(c, o, c==o)

    def test(c:Any, o:Any, t:Boolean) = {
        inc(t)
        println(c+" [corretto: "+o+"] - " + t)
    }

    def report = println("Report: "+ok+"/"+cnt)
}
