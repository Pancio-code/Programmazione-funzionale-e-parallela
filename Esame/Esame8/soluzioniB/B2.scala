object B2 {
    def mioFor(test: =>Boolean, incr: =>Unit)(body: =>Unit):Unit = {
        /* 
        // soluzione 1:
        while (test) {
            body
            incr
        }
        */
        
        // soluzione 2:
        if (!test) ()
        else {
            body
            incr
            mioFor(test, incr)(body)
        }
    }
}
