object A2 {
	def mywhile(cond: =>Boolean, s: =>Any)(body: =>Unit):Unit = {
		if(!cond) ()
		else {
			println(s)
			body
			mywhile(cond,s)(body)
		}
	}
}
