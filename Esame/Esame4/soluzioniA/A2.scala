object A2 {

    def mywhile(test: =>Boolean, s: =>Any)(body: =>Unit):Unit =
        if (!test) ()
        else {
            println(s)
            body
            mywhile(test,s)(body)
        }
}
